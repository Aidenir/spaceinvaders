//--------------------------------------------------------------------------------------------------
// File:	MathLibrary.h
// Author:	Blankycan
// Date:	2013-05-01
//--------------------------------------------------------------------------------------------------
#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H
//--------------------------------------------------------------------------------------------------
//	PI
static double PI = 3.1415926535897;
//--------------------------------------------------------------------------------------------------
/*  enum Coordinates
	Used for easy accessing in 3 and 4 long vectors.
 */
enum Coordinates{
	X = 0,
	Y = 1,
	Z = 2,
	W = 3
};
//--------------------------------------------------------------------------------------------------
/*  ABS
    Gives absolute value.
 */
#define ABSf(value) ((value < 0.f)?value*-1.f:value)
//--------------------------------------------------------------------------------------------------
#include <math.h>
//--------------------------------------------------------------------------------------------------
//	Vertex2
template <class> class Vertex2;
typedef Vertex2<float> Vertex2f;
typedef Vertex2<double> Vertex2d;
//	Vertex3
template <class> class Vertex3;
typedef Vertex3<float> Vertex3f;
typedef Vertex3<double> Vertex3d;
//	Matrices
template <class> class Matrix3;
typedef Matrix3<float> Matrix3f;
typedef Matrix3<double> Matrix3d;
template <class> class Matrix4;
typedef Matrix4<float> Matrix4f;
typedef Matrix4<double> Matrix4d;
//	Vectors
template <class> class Vector2;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;
//	Vector3
template <class> class Vector3;
typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;
//	Vector4
template <class> class Vector4;
typedef Vector4<float> Vector4f;
typedef Vector4<double> Vector4d;
// Quaternion
template <class> class Quaternion;
typedef Quaternion<float> Quaternionf;
typedef Quaternion<double> Quaterniond;
//--------------------------------------------------------------------------------------------------
#include "Matrix3.h"
#include "Matrix4.h"

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include "Vertex2.h"
#include "Vertex3.h"

#include "Quaternion.h"
//--------------------------------------------------------------------------------------------------
#endif