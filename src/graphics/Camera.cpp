/* /////////////////////////////////////////////////////////////////////
//  File:       Camera.cpp
//  Author      Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "Camera.h"
////////////////////////////////////////////////////////////////////////

Camera::Camera()
{
    zoom = 1.0;
    SetUpCamera();
}
Camera::Camera(Vertex3f pos, Vertex3f rot, float zoom)
{
    position = pos;
    rotation = rot;
    this->zoom = zoom;
    SetUpCamera();
}
Camera::~Camera()
{
    
}

void Camera::SetUpCamera()
{
    float onetwelfth = 1.f/12.f;
    float height = 1.f, width = 1.f, depth = 1.f;
    float mass = 1.f;
    Matrix3f Ibody = Matrix3f(
            (onetwelfth)*mass*(height*height + depth*depth) , 0                                             , 0,
            0                                               , (onetwelfth)*mass*(width*width + depth*depth) , 0,
            0                                               , 0                                             , (onetwelfth)*mass*(width*width + height*height) );
    Ibodyinv = Ibody.inversed();
}

Vertex3f& Camera::GetPosition() { return position; }
float Camera::GetPositionX() { return position.coord[X]; }
float Camera::GetPositionY() { return position.coord[Y]; }
float Camera::GetPositionZ() { return position.coord[Z]; }

Vertex3f& Camera::GetRotation() { return rotation; }
float Camera::GetRotationX() { return rotation.coord[X]; }
float Camera::GetRotationY() { return rotation.coord[Y]; }
float Camera::GetRotationZ() { return rotation.coord[Z]; }

float Camera::GetZoom() { return zoom; }


void Camera::SetPosition(Vertex3f& pos) { position = pos; }
void Camera::SetPositionX(float x) { position.coord[X] = x; }
void Camera::SetPositionY(float y) { position.coord[Y] = y; }
void Camera::SetPositionZ(float z) { position.coord[Z] = z; }

void Camera::Move(const Vector3f& movement)
{
    /*
    Vector3f moveVec = R.mult(movement);
    position += moveVec;
     */
    Matrix3f rotMat;
    rotMat *= Matrix3f::getRotateY(rotation[X]);
    rotMat *= Matrix3f::getRotateX(rotation[Z]);
    //rotMat *= Matrix3f::getRotateY(rotation[Y]);
    position += rotMat.mult(movement);
}
void Camera::Move(const Vertex3f& movement) 
{
    /*
    Vector3f moveVec = R.mult(movement);
    position += moveVec;
     */
    Matrix3f rotMat;
    rotMat *= Matrix3f::getRotateY(rotation[X]);
    rotMat *= Matrix3f::getRotateX(rotation[Z]);
    //rotMat *= Matrix3f::getRotateY(rotation[Y]);
    position += rotMat.mult(movement);
}


void Camera::SetRotation(Vertex3f& rot)
{
    rotation = rot;
    Matrix3f Iinv = R*Ibodyinv*R.transposed();
    Vector3f omega = Iinv * rotation;

    Quaternionf quat(omega);
    Quaternionf dq = quat * q * (0.5f * 0.01f);
    q = q + dq;
    q.Normalize();
    R = q.ToMatrix3();
}
void Camera::SetRotationX(float x)
{
    rotation.coord[X] = x;
    SetRotation(rotation);
}
void Camera::SetRotationY(float y)
{
    rotation.coord[Y] = y;
    SetRotation(rotation);
}
void Camera::SetRotationZ(float z)
{
    rotation.coord[Z] = z;
    SetRotation(rotation);
}

void Camera::Rotate(const Vector3f& rotate) 
{
    this->rotation += Vertex3f(rotate);
    SetRotation(rotation);
}
void Camera::Rotate(const Vertex3f& rotate) 
{
    this->rotation += rotate;
    SetRotation(rotation);
}


void Camera::SetZoom(float zoom) { this->zoom = zoom; }
void Camera::Zoom(float zoom) { this->zoom += zoom; }
