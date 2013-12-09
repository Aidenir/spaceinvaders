/*////////////////////////////////////////////////////////
 * File:        Quaternion.cpp
 * Author:      Blankycan
 * Date:        2013-09-10 // Yay, my birthday!! ^^ ~~
/////////////////////////////////////// © Blankycan 2013 */
#ifndef QUATERNION_H
#define	QUATERNION_H
///////////////////////////////////////////////////////////
#include "MathLibrary.h"
///////////////////////////////////////////////////////////

template <class T>
class Quaternion
{
public:
    // Constructors
    Quaternion();
    Quaternion(T x, T y, T z, T w);
    Quaternion(T value, T angle);
    Quaternion(Vector3<T> vec, T angle);
    Quaternion(Vector4<T> vec);
    
    Quaternion(T x, T y, T z);
    Quaternion(Vector3<T> vec);
    
    Quaternion<T> operator +(const Quaternion<T> &q);
    void operator +=(const Quaternion<T> &q);
    Quaternion<T> operator -(const Quaternion<T> &q);
    void operator -=(const Quaternion<T> &q);
    Quaternion<T> operator *(const Quaternion<T> &q);
    void operator *=(const Quaternion<T> &q);
    
    
    Quaternion<T> operator *(T scale);
    void operator *=(T scale);
    Quaternion<T> operator /(T scale);
    void operator /=(T scale);
    
    Matrix3<T> ToMatrix3();
    static Matrix3<T> QuaternionToMatrix3(const Quaternion<T> &q);
    static Quaternion<T> Matrix3ToQuaternion(const Matrix3<T> &mat);
    
    Vector3<T> ToEuler();
    
    T Length() const;
    void Normalize();
    Quaternion<T> Normalized();
    
    /* The three axis */
    Vector3<T> element;
    /* The angle */
    T angle;
};

///////////////////////////////////////////////////////////
// Implementation
///////////////////////////////////////////////////////////
template <class T>
Quaternion<T>::Quaternion()
{
    element = Vector3<T>((T)0.0, (T)0.0, (T)0.0); angle = (T)1.0;
}
template <class T>
Quaternion<T>::Quaternion(T x, T y, T z, T w)
{
    element = Vector3<T>(x, y, z); angle = w;
}
template <class T>
Quaternion<T>::Quaternion(T value, T angle)
{
    element = Vector3<T>(value, value, value); this->angle = angle;
}
template <class T>
Quaternion<T>::Quaternion(const Vector3<T> vec, T angle)
{
    element = vec; this->angle = angle;
}
template <class T>
Quaternion<T>::Quaternion(const Vector4<T> vec)
{
    element = vec; angle = vec[W];
}
template <class T>
Quaternion<T>::Quaternion(T x, T y, T z)
{
    float cosX = cos(0.5*x);
    float cosY = cos(0.5*y);
    float cosZ = cos(0.5*z);
    
    float sinX = sin(0.5*x);
    float sinY = sin(0.5*y);
    float sinZ = sin(0.5*z);
    
    angle       = cosX*cosY*cosZ+sinX*sinY*sinZ;
    element[X]  = sinX*cosY*cosZ-cosX*sinY*sinZ;
    element[Y]  = cosX*sinY*cosZ+sinX*cosY*sinZ;
    element[Z]  = cosX*cosY*sinZ-sinX*sinY*cosZ;
}
template <class T>
Quaternion<T>::Quaternion(Vector3<T> vec)
{
    float cosX = cos(0.5*vec[X]);
    float cosY = cos(0.5*vec[Y]);
    float cosZ = cos(0.5*vec[Z]);
    
    float sinX = sin(0.5*vec[X]);
    float sinY = sin(0.5*vec[Y]);
    float sinZ = sin(0.5*vec[Z]);
    
    angle       = cosX*cosY*cosZ+sinX*sinY*sinZ;
    element[X]  = sinX*cosY*cosZ-cosX*sinY*sinZ;
    element[Y]  = cosX*sinY*cosZ+sinX*cosY*sinZ;
    element[Z]  = cosX*cosY*sinZ-sinX*sinY*cosZ;
}

template <class T>
Quaternion<T> Quaternion<T>::operator +(const Quaternion<T> &q)
{
    return Quaternion<T>(element+q.element, angle+q.angle);
}
template <class T>
void Quaternion<T>::operator +=(const Quaternion<T> &q)
{
    element += q.element;
    angle += q.angle;
}
template <class T>
Quaternion<T> Quaternion<T>::operator -(const Quaternion<T> &q)
{
    return Quaternion<T>(element-q.element, angle-q.angle);
}
template <class T>
void Quaternion<T>::operator -=(const Quaternion<T> &q)
{
    element -= q.element;
    angle -= q.angle;
}
template <class T>
Quaternion<T> Quaternion<T>::operator *(const Quaternion<T> &q)
{
    /*
    return Quaternion<T>(
            element[Y]*q.element[Z] - element[Z]*q.element[Y] + angle*q.element[X] + element[X]*q.angle,
            element[Z]*q.element[X] - element[X]*q.element[Z] + angle*q.element[Y] + element[Y]*q.angle,
            element[X]*q.element[Y] - element[Y]*q.element[X] + angle*q.element[Z] + element[Z]*q.angle,
            angle*q.angle);
    */
    T w = angle*q.angle         - element[X]*q.element[X]   - element[Y]*q.element[Y]   - element[Z]*q.element[Z];
    T x = angle*q.element[X]    + element[X]*q.angle        + element[Y]*q.element[Z]   - element[Z]*q.element[Y];
    T y = angle*q.element[Y]    - element[X]*q.element[Z]   + element[Y]*q.angle        + element[Z]*q.element[X];
    T z = angle*q.element[Z]    + element[X]*q.element[Y]   - element[Y]*q.element[X]   + element[Z]*q.angle;
    return Quaternion<T>(x, y, z, w);
}
template <class T>
void Quaternion<T>::operator *=(const Quaternion<T> &q)
{
    /*
    Quaternion<T> quat(
            element[Y]*q.element[Z] - element[Z]*q.element[Y] + angle*q.element[X] + element[X]*q.angle,
            element[Z]*q.element[X] - element[X]*q.element[Z] + angle*q.element[Y] + element[Y]*q.angle,
            element[X]*q.element[Y] - element[Y]*q.element[X] + angle*q.element[Z] + element[Z]*q.angle,
            angle*q.angle);
    *this->element = quat.element; *this->angle = quat.angle;
    */
    T w = angle*q.angle         - element[X]*q.element[X]   - element[Y]*q.element[Y]   - element[Z]*q.element[Z];
    T x = angle*q.element[X]    + element[X]*q.angle        + element[Y]*q.element[Z]   - element[Z]*q.element[Y];
    T y = angle*q.element[Y]    - element[X]*q.element[Z]   + element[Y]*q.angle        + element[Z]*q.element[X];
    T z = angle*q.element[Z]    + element[X]*q.element[Y]   - element[Y]*q.element[X]   + element[Z]*q.angle;
    //element *= Quaternion<T>(x, y, z, w);
    *this->element = Vector3<T>(x, y, z); *this->angle = w;
}
template <class T>
Quaternion<T> operator *(T val, const Quaternion<T> &q)
{
    return Quaternion<T>(val * q.element[X], val * q.element[Y], val * q.element[Z], val * q.angle);
}
template <class T>
Quaternion<T> operator *(const Vector3<T> &vec, const Quaternion<T> &q)
{
    return Quaternion<T>(Vector3<T>(q.element[X] * vec[X], q.element[Y] * vec[Y], q.element[Z] * vec[Z]), q.angle);
}

template <class T>
Quaternion<T> Quaternion<T>::operator *(T scale)
{
    return Quaternion<T>(element * scale, angle * scale);
}
template <class T>
void Quaternion<T>::operator *=(T scale)
{
    element *= scale; angle *= scale;
}
template <class T>
Quaternion<T> Quaternion<T>::operator /(T scale)
{
    return Quaternion<T>(element / scale, angle / scale);
}
template <class T>
void Quaternion<T>::operator /=(T scale)
{
    element /= scale; angle /= scale;
}

template <class T>
Matrix3<T> Quaternion<T>::ToMatrix3()
{
    return Matrix3<T>(
            1.0 - 2*(element[Y]*element[Y] + element[Z]*element[Z]) , 2*(element[X]*element[Y] - angle*element[Z])              , 2*(element[X]*element[Z] + angle*element[Y]),
            2*(element[X]*element[Y] + angle*element[Z])            , 1.0 - 2*(element[X]*element[X] + element[Z]*element[Z])   , 2*(element[Y]*element[Z] - angle*element[X]),
            2*(element[X]*element[Z] - angle*element[Y])            , 2*(element[Y]*element[Z] + angle*element[X])              , 1.0 - 2*(element[X]*element[X] + element[Y]*element[Y]));
}
template <class T>
Matrix3<T> Quaternion<T>::QuaternionToMatrix3(const Quaternion<T> &q)
{
    return Matrix3<T>(
            1.0 - 2*(q.element[Y]*q.element[Y] + q.element[Z]*q.element[Z]) , 2*(q.element[X]*q.element[Y] - q.angle*q.element[Z])              , 2*(q.element[X]*q.element[Z] + q.angle*q.element[Y]),
            2*(q.element[X]*q.element[Y] + q.angle*q.element[Z])            , 1.0 - 2*(q.element[X]*q.element[X] + q.element[Z]*q.element[Z])   , 2*(q.element[Y]*q.element[Z] - q.angle*q.element[X]),
            2*(q.element[X]*q.element[Z] - q.angle*q.element[Y])            , 2*(q.element[Y]*q.element[Z] + q.angle*q.element[X])              , 1.0 - 2(*q.element[X]*q.element[X] + q.element[Y]*q.element[Y]));
}
template <class T>
Quaternion<T> Quaternion<T>::Matrix3ToQuaternion(const Matrix3<T> &mat)
{
    Quaternion<T> q;
    float tr, s;
    tr = mat(0,0) + mat(1,1) + mat(2,2);
    
    if(tr >= 0)
    {
        s = sqrt(tr + 1);
        q.angle = 0.5 * s;
        s = 0.5 / s;
        q.element[X] = (mat(2,1) - mat(1,2)) * s;
        q.element[Y] = (mat(0,2) - mat(2,0)) * s;
        q.element[Z] = (mat(1,0) - mat(0,1)) * s;
    }
    else
    {
        int i = 0;
        
        if(mat(1,1) > mat(0,0))
            i = 1;
        if(mat(2,2) > mat(i,i))
            i = 2;
        
        switch(i)
        {
            case 0:
                s = sqrt((mat(0,0) - (mat(1,1) + mat(2,2))) + 1);
                q.element[X] = 0.5 * s;
                s = 0.5 / s;
                q.element[Y] = (mat(0,1) + mat(1,0)) * s;
                q.element[Z] = (mat(2,0) + mat(0,2)) * s;
                q.angle = (mat(2,1) + mat(1,2)) * s;
                break;
            case 1:
                s = sqrt((mat(1,1) - (mat(2,2) + mat(0,0))) + 1);
                q.element[Y] = 0.5 * s;
                s = 0.5 / s;
                q.element[Z] = (mat(1,1) + mat(2,1)) * s;
                q.element[X] = (mat(0,1) + mat(1,0)) * s;
                q.angle = (mat(0,2) + mat(2,0)) * s;
                break;
            case 2:
                s = sqrt((mat(2,2) - (mat(0,0) + mat(1,1))) + 1);
                q.element[Z] = 0.5 * s;
                s = 0.5 / s;
                q.element[X] = (mat(2,0) + mat(0,2)) * s;
                q.element[Y] = (mat(1,2) + mat(2,1)) * s;
                q.angle = (mat(1,0) + mat(0,1)) * s;
                break;
        }
    }
    return q;
}

template <class T>
Vector3<T> Quaternion<T>::ToEuler()
{
    T sqw = angle * angle;
    T sqx = element[X] * element[X];
    T sqy = element[Y] * element[Y];
    T sqz = element[Z] * element[Z];
    Vector3<T> euler;
    euler[X] = atan2(2.f * (element[X]*element[Y] + element[Z]*angle), sqx-sqy-sqz+sqw);
    euler[Y] = asin(-2.f * (element[X]*element[Z] - element[Y]*angle));
    euler[Z] = atan2(2.f * (element[Y]*element[Z] + element[X]*angle), -sqx-sqy+sqz+sqw);
    return euler;
}

template <class T>
T Quaternion<T>::Length() const
{
    float lengthSquared = Vector3<T>::dot(element, element) + (angle * angle);
    if(lengthSquared > 0.99f && lengthSquared < 1.01)
        return 1.0f;
    return sqrt(lengthSquared);
}
template <class T>
void Quaternion<T>::Normalize()
{
    T length = Length();
    // Check if it is kind of normalized already
    if(length > 0.99f && length < 1.01)
        return;
    angle /= length;
    element /= length;
}
template <class T>
Quaternion<T> Quaternion<T>::Normalized()
{
    T length = Length();
    // Check if it is kind of normalized already
    if(length > 0.99f && length < 1.01)
        return *this;
    return Quaternion<T>(element / length, angle / length);
}

///////////////////////////////////////////////////////////
#endif	/* QUATERNION_H */

