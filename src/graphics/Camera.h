/* /////////////////////////////////////////////////////////////////////
//	File:		Camera.h
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef CAMERA_H
#define CAMERA_H
////////////////////////////////////////////////////////////////////////
// Application includes
#include "MathLibrary.h"
////////////////////////////////////////////////////////////////////////

/*  Camera
 * Keeps track of orientation in space,
 * position, rotation, zoom
 */
class Camera
{
public:
    /* Default constructor */
    Camera();
	/* Constructor, can take starting position, rotation and zoom-level */
	Camera(Vertex3f pos, Vertex3f rot, float zoom = 1.f);
    /* Default destructor */
	~Camera();
	
	/* Returns position */
	Vertex3f& GetPosition();
	/* Returns X-position */
	float GetPositionX();
	/* Returns Y-position */
	float GetPositionY();
	/*Returns Z-position */
	float GetPositionZ();
	/* Returns rotation */
	Vertex3f& GetRotation();
	/* Returns X-rotation */
	float GetRotationX();
	/* Returns Y-rotation */
	float GetRotationY();
	/* Returns Z-rotation */
	float GetRotationZ();
	/* Returns zoom */
	float GetZoom();

	/* Set position */
	void SetPosition(Vertex3f& pos);
	/* Set X-position */
	void SetPositionX(float x);
	/* Set Y-position */
	void SetPositionY(float y);
	/* Set Z-position */
	void SetPositionZ(float z);
	/* Move camera, add vector */
	void Move(const Vector3f& movement);
	/* Move camera, add vector */
	void Move(const Vertex3f& movement);

	/* Set rotation */
	void SetRotation(Vertex3f& rot);
	/* Set X-Rotation */
	void SetRotationX(float x);
	/* Set Y-Rotation */
	void SetRotationY(float y);
	/* Set Z-Rotation */
	void SetRotationZ(float z);
	/* Rotate, add rotation */
	void Rotate(const Vector3f& rotate);
	/* Rotate, add rotation */
	void Rotate(const Vertex3f& rotate);
	
	/* Set zoom */
	void SetZoom(float zoom);
	/* Zoom, add/decrease the zoom level */
	void Zoom(float zoom);

private:
    /* Setups camera */
    void SetUpCamera();
    
    Quaternionf q;
    Matrix3f R, Ibodyinv;
	Vertex3f position;
	Vertex3f rotation;
	float zoom;
};

////////////////////////////////////////////////////////////////////////
#endif	// CAMERA_H
////////////////////////////////////////////////////////////////////////