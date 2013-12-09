//--- (C) 2013 Blankycan ---------------------------------------------------------------------------
// File:	Vector3.h
// Author:	Blankycan
// Date:	2013-08-30
//--------------------------------------------------------------------------------------------------
#ifndef Vector3_H
#define Vector3_H
//--------------------------------------------------------------------------------------------------
#include <iostream>
#include <math.h>
//--------------------------------------------------------------------------------------------------
#include "MathLibrary.h"
//--------------------------------------------------------------------------------------------------

/** Vector3
	A 3 long vector consisting of T values.*/
template <class T>
class Vector3{
public:
	// ----------------------------------------------------------
	// Constructors

	/** Vector3()
		Default constructor, defaults the vector to a (0,0,0) vector.*/
	Vector3();
	/** Vector3(T, T, T)
		Constructor that takes three T values and creates a vector
		that uses them as it's x, y and z values.*/
	Vector3(T x, T y, T z);
	/** Vector3(T[3])
		A constructor that takes an 3-long T array.
		It uses the arrays values as x,y,z values for the vector.*/
	Vector3(T vec[3]);
	/** Vector3(Vector3<T>&)
		Constructor/Copy-constructor that takes another Vector3 as parameter.
		It copies the parameter's x,y and z values and uses them
		for it's own vector.*/
	Vector3(const Vector3f& vec);
	Vector3(const Vector3d& vec);
	/** Vector3(Vector4<T>&)
		Constructor/Copy-constructor that takes another Vector4f as parameter.
		It copies the parameter's x,y and z values and uses them
		for it's own vector. It skips the fourth w value.*/
	Vector3(const Vector4<T>& vec);
	/** Vector3(Vertex3<T>&, Vertex3<T>&)
		Constructor that creates vector from two points.*/
	Vector3(const Vertex3<T>& ver1, const Vertex3<T>& ver2);
	/** Vector3(Vertex3f&)
		Constructor that creates vector from one point.*/
	Vector3(const Vertex3<T>& vertex);

	// ----------------------------------------------------------
	// Other Methods

	/** operator =(Vector3&)
		A copy function that copies the parameters values to the new vector's.
		Use: vector = vector
		Result: The vector calling the function have the same x,y,z values
				as the vector passed with the function have.*/
	void operator =(const Vector3<T>& vec);
	/** operator ==(Vector3&)
		Method to check if two vectors have the same x,y,z values.
		Use: vector == vector
		Result: Returns a boolean whether the two vectors are alike*/
	bool operator ==(const Vector3<T>& vec) const;
	/** friend operator ==(const Vector3&, const Vector3&)
		Method to check if two vectors have the same x,y,z values.
		Result: Returns a boolean whether the two vectors are alike*/
	//friend bool operator ==(const Vector3<T>& v1, const Vector3<T>& v2);
	/** operator !=(Vector3&)
		Method to check if two vectors don't have the same x,y,z values.
		Use: vector != vector
		Result: Returns a boolean whether the two vectors differs*/
	bool operator !=(const Vector3<T>& vec) const;
	/** operator ()(unsigned char) const
		A function to easily find what's in a specific position
		in the vector.
		Precondition: n may never exceed 2.
		Use: vector(n)
		Result: Returns T value in position n in vector.
				If precondition isn't met suspect the unsuspected.*/
	T operator ()(unsigned char n) const;
	/** operator [](unsigned char) const
		A function to easily find what's in a specific position
		in the vector.
		Precondition: n may never exceed 2.
		Use: vector[n]
		Result: Returns T value in position n in vector.
				If precondition isn't met suspect the unsuspected.*/
	T operator [](unsigned char n) const;
	/** operator ()(unsigned char)
		Function to make easy changes in the vector.
		Precondition: n may never exceed 2.
					  Only put in T values.
		Use: vector(n) = T
		Result: Inserts the T value into the vector.
				If precondition isn't met suspect the unsuspected.*/
	T& operator ()(unsigned char n);
	/** operator [](unsigned char)
		Function to make easy changes in the vector.
		Precondition: n may never exceed 2.
					  Only put in T values.
		Use: vector[n] = T
		Result: Inserts the T value into the vector.
				If precondition isn't met suspect the unsuspected.*/
	T& operator [](unsigned char n);
    
    Vector3<T> ProjectedToB(const Vector3<T>& B);
    static Vector3<T> ProjectAtoB(const Vector3<T>& A, const Vector3<T>& B);

	// ----------------------------------------------------------
	// Addition

	/** add(Vector3&)
		Add the vector values of the parameter to the
		vector that called the method.
		Use: vector1.add(vector2)
		Result: vector calling the method gets a new value*/
	void			add			(const Vector3<T>& vec);
	/** operator += (Vector3&)
		Add the vector values of the parameter to the
		vector that called the method.
		Use: vector1 += vector2
		Result: vector calling the method gets a new value*/
	void			operator +=	(const Vector3<T>& vec);
	/** add(Vector3&, Vector3&)
		A method to add two vectors values together and
		return the sum in form of a new vector.
		Use: Vector3::add(vector1, vector2)
		Result: Returns a new vector*/
	static Vector3<T> add			(const Vector3<T>& vec1, const Vector3<T>& vec2);
	/** operator + (Vector3&)
		A method to add two vectors values together and
		return the sum in form of a new vector.
		Use: add(vector1, vector2)
		Result: Returns a new vector*/
	Vector3<T>		operator +	(const Vector3<T>& vec);
	
	// ----------------------------------------------------------
	// Subtraction

	/** sub(Vector3&)
		Subtract the values from the vector calling the function
		with the parameter vector values.
		Use: vector1.sub(vector2)
		Result: vector calling the method gets a new value*/
	void			sub			(const Vector3<T> &vec);
	/** operator -= (Vector3&)
		Subtract the values from the vector calling the function
		with the parameter vector values.
		Use: vector1 -= vector2
		Result: vector calling the method gets a new value*/
	void			operator -=	(const Vector3<T> &vec);
	/** static sub(Vector3&, Vector3&)
		A static method to subtract two vectors values with each
		other and return the sum in form of a new vector.
		Use: Vector3::sub(vector1, vector2)
		Result: Returns a new vector*/
	static Vector3<T>	sub			(const Vector3<T> &vec1, const Vector3<T> &vec2);
	/** operator - (Vector3&)
		A method to subtract two vectors values with each other
		and return the sum in form of a new vector.
		Use: vector1 - vector2
		Result: Returns a new vector*/
	Vector3<T>		operator -	(const Vector3 &vec);
	
	// ----------------------------------------------------------
	// Scalar Multiplication

	/** mult(T)
		Multiplies the vector with the scalar.
		Use: vector.mult(value)
		Result: Vector is changed.*/
	void			mult		(T value);
	/** operator *= (T)
		Multiplies the vector with the scalar.
		Use: vector *= value
		Result: Vector is changed.*/
	void			operator *=	(T value);
	void			operator *=	(const Vector3<T> &vec);
	/** mult(Vector3&, T)
		Multiplies the vector with the scalar.
		Use: Vector3::mult(vector, value);
		Result: New Vector3 is returned.*/
	static Vector3<T>	mult		(const Vector3<T> &vec, T value);
	/** mult(T, Vector3&)
		Multiplies the vector with the scalar.
		Use: Vector3::mult(value, vector);
		Result: New Vector3 is returned.*/
	static Vector3<T>	mult		(T value, const Vector3<T> &vec);
	/** operator * (T)
		Multiplies the vector with the scalar.
		Use: vector * value
		Result: New Vector3 is returned.*/
	Vector3<T>		operator *	(T value);
	/** friend operator * (Vector3&)
		Multiplies the vector with the scalar.
		Use: value * vector
		Result: New Vector3 is returned.*/
	//friend Vector3<T>	operator *	(T value, const Vector3<T> &vec);

	// ----------------------------------------------------------
	// Scalar Division
	
	/** div(T)
		Divides the vector with the scalar.
		Use: vector.div(value)
		Result: Vector is changed.*/
	void			div			(T value);
	/** operator /= (T)
		Divides the vector with the scalar.
		Use: vector /= value
		Result: Vector is changed.*/
	void			operator /=	(T value);
	/** div(Vector3&, T)
		Divides the vector with the scalar.
		Use: Vector3::div(vector, value);
		Result: New Vector3 is returned.*/
	static Vector3<T>	div			(const Vector3<T>& vec, T value);
	/** div(T, Vector3&)
		Divides the vector with the scalar.
		Use: Vector3::div(value, vector);
		Result: New Vector3 is returned.*/
	static Vector3<T>	div			(T value, const Vector3<T>& vec);
	/** operator / (T)
		Divides the vector with the scalar.
		Use: vector / value
		Result: New Vector3 is returned.*/
	Vector3<T>		operator /	(T value);
	/** friend operator / (Vector3&)
		Divides the vector with the scalar.
		Use: value / vector
		Result: New Vector3 is returned.*/
	//friend Vector3<T>	operator /	(T value, const Vector3<T>& vec);

	// ----------------------------------------------------------
	// Length

	/** length()
		Function to get the length of the vector.
		Use: vector.length()
		Result: The length of the vector is returned as a T value.*/
	T			length		();
	/** length(Vector3&)
		Function to get the length of the parameter vector.
		Use: Vector3::length(vector)
		Result: The length of the vector is returned as a T value.*/
	static T	length		(const Vector3<T>& vec);
    /* Returns the squared magnitude */
    T SquaredMagnitude();
    /* Returns the squared magnitude */
    static T SquaredMagnitude(const Vector3<T>& vec);
	
	// ----------------------------------------------------------
	// Normalization
	
	/** normalize()
		Normalizes the vector.
		Precondition: The length of the vector must not be zero.
		Use: vector.normalize()
		Result: Vector calling the method gets normalized.
			    If precondition is not valid, overflow error will be thrown*/
	void normalize();
	/** normalize(Vector3&)
		Normalizes the parameter vector.
		Precondition: The length of the parameter vector must not be zero.
		Use: normalize(vector)
		Result: Vector passed as a parameter of the method gets normalized.
				If precondition is not valid, overflow error will be thrown*/
	static void normalize(const Vector3<T>& vec);
	/** normalized()
		Normalizes the vector.
		Precondition: The length of the vector must not be zero.
		Use: vector.normalizes()
		Result: Returns a normalized version of the vector using the method.
		If precondition is not valid, overflow error will be thrown*/
	Vector3<T> normalized();
	/** normalizes(Vector3&)
		Normalizes the parameter vector.
		Precondition: The length of the parameter vector must not be zero.
		Use: normalizes(vector)
		Result: Returns a normalized version of the vector passed as a parameter.
		If precondition is not valid, overflow error will be thrown*/
	static Vector3<T> normalized(const Vector3<T>& vec);

	// ----------------------------------------------------------
	// Dot Product

	/** dot(Vector3&)
		Calculates the dot product from the vectors.
		Use: vector.dot(vector)
		Result: Returns the dot product as a T value*/
	T			dot			(const Vector3<T>& vec);
	/** operator * (Vector3&)
		Calculates the dot product from the vectors.
		Use: vector * vector
		Result: Returns the dot product as a T value*/
	T			operator *	(const Vector3<T>& vec);
	/** dot(Vector3&, Vector3)
		Calculates the dot product from the vectors.
		Use: Vector3::dot(vector, vector)
		Result: Returns the dot product as a T value*/
	static T	dot			(const Vector3<T>& vec1, const Vector3<T>& vec2);

	// ----------------------------------------------------------
	// Cross Product
	
	/** cross(Vector3&)
		Cross product the vector with the vector passed as a parameter.
		Use: vector.cross(vector)
		Result: Vector calling the method is changed.*/
	void			cross		(const Vector3<T>& vec);
	/** operator ^=(Vector3&)
		Cross product the vector with the vector passed as a parameter.
		Use: vector ^= vector
		Result: Vector calling the method is changed.*/
	void			operator ^=	(const Vector3<T>& vec);
	/** cross(Vector3&, Vector3&)
		Cross product the two vectors.
		Use: cross(vector, vector)
		Result: A new vector with the value from the cross product is returned.*/
	static Vector3<T>	cross		(const Vector3<T>& vec1, const Vector3<T>& vec2);
	/** operator ^(Vector3&)
		Cross product the two vectors.
		Use: vector ^ vector
		Result: A new vector with the value from the cross product is returned.*/
	Vector3<T>		operator ^	(const Vector3<T>& vec);

	// ----------------------------------------------------------
	// Variables
	
	/** T coord[3]
		An array representing a vectors three values.
		In Vector3 the values are T type values.
		coord[0] = x, coord[1] = y, coord[2] = z*/
	T coord[3];
};


//--------------------------------------------------------------------------------------------------
//	Implementation
//--------------------------------------------------------------------------------------------------

// ----------------------------------------------------------
// Constructors
template <class T>
Vector3<T>::Vector3(){
	coord[X] = 0;
	coord[Y] = 0;
	coord[Z] = 0;
}
template <class T>
Vector3<T>::Vector3(T x, T y, T z){
	coord[X] = x;
	coord[Y] = y;
	coord[Z] = z;
}
template <class T>
Vector3<T>::Vector3(T vec[3]){
	coord[X] = vec[X];
	coord[Y] = vec[Y];
	coord[Z] = vec[Z];
}
template <class T>
Vector3<T>::Vector3(const Vector3f& vec){
	coord[X] = (T)vec.coord[X];
	coord[Y] = (T)vec.coord[Y];
	coord[Z] = (T)vec.coord[Z];
}
template <class T>
Vector3<T>::Vector3(const Vector3d& vec){
	coord[X] = (T)vec.coord[X];
	coord[Y] = (T)vec.coord[Y];
	coord[Z] = (T)vec.coord[Z];
}
template <class T>
Vector3<T>::Vector3(const Vector4<T>& vec){
	coord[X] = (T)vec.coord[X];
	coord[Y] = (T)vec.coord[Y];
	coord[Z] = (T)vec.coord[Z];
}
template <class T>
Vector3<T>::Vector3(const Vertex3<T>& ver1,const  Vertex3<T>& ver2){
	coord[X] = ver2.coord[X] - ver1.coord[X];
	coord[Y] = ver2.coord[Y] - ver1.coord[Y];
	coord[Z] = ver2.coord[Z] - ver1.coord[Z];
}
template <class T>
Vector3<T>::Vector3(const Vertex3<T>& vertex){
	coord[X] = vertex.coord[X];
	coord[Y] = vertex.coord[Y];
	coord[Z] = vertex.coord[Z];
}

// ----------------------------------------------------------
// Other Methods
template <class T>
void Vector3<T>::operator =(const Vector3& vec){
	coord[X] = vec.coord[X];
	coord[Y] = vec.coord[Y];
	coord[Z] = vec.coord[Z];
}
template <class T>
bool Vector3<T>::operator ==(const Vector3& vec) const{
	bool result = true;
	if(coord[X] != vec.coord[X])
		result = false;
	if(coord[Y] != vec.coord[Y])
		result = false;
	if(coord[Z] != vec.coord[Z])
		result = false;
	return result;
}
template <class T>
bool operator ==(const Vector3<T>& v1, const Vector3<T>& v2){
	if(v1.coord[X] != v2.coord[X])
		return false;
	if(v1.coord[Y] != v2.coord[Y])
		return false;
	if(v1.coord[Z] != v2.coord[Z])
		return false;
	return true;
}
template <class T>
bool Vector3<T>::operator !=(const Vector3& vec) const{
	char count = 0;
	if(coord[X] == vec.coord[X])
		++count;
	if(coord[Y] == vec.coord[Y])
		++count;
	if(coord[Z] == vec.coord[Z])
		++count;
	if(count == 3)
		return false;
	return true;
}
template <class T>
T Vector3<T>::operator ()(unsigned char n) const{
	return coord[n];
}
template <class T>
T Vector3<T>::operator [](unsigned char n) const{
	return coord[n];
}
template <class T>
T& Vector3<T>::operator ()(unsigned char n){
	return coord[n];
}
template <class T>
T& Vector3<T>::operator [](unsigned char n){
	return coord[n];
}
template <class T>
Vector3<T> Vector3<T>::ProjectedToB(const Vector3& B)
{
    *this = ProjectAtoB(*this, B);
}
template <class T>
Vector3<T> Vector3<T>::ProjectAtoB(const Vector3& A, const Vector3& B)
{
    Vector3<T> projection = (dot(A,B) / dot(B,B)) * B;
    return projection;
}
// ----------------------------------------------------------
// Addition
template <class T>
void Vector3<T>::add(const Vector3& vec){
	coord[X] += vec.coord[X];
	coord[Y] += vec.coord[Y];
	coord[Z] += vec.coord[Z];
}
template <class T>
void Vector3<T>::operator +=(const Vector3& vec){
	coord[X] += vec.coord[X];
	coord[Y] += vec.coord[Y];
	coord[Z] += vec.coord[Z];
}
template <class T>
Vector3<T> Vector3<T>::add(const Vector3& vec1, const Vector3& vec2){
	return Vector3 (	vec1.coord[X] + vec2.coord[X],
		vec1.coord[Y] + vec2.coord[Y],
		vec1.coord[Z] + vec2.coord[Z]);
}
template <class T>
Vector3<T> Vector3<T>::operator +(const Vector3& vec)	{
	return Vector3 (	coord[X] + vec.coord[X],
		coord[Y] + vec.coord[Y],
		coord[Z] + vec.coord[Z]);
}

// ----------------------------------------------------------
// Subtraction

template <class T>
void Vector3<T>::sub(const Vector3 &vec){
	coord[X] -= vec.coord[X];
	coord[Y] -= vec.coord[Y];
	coord[Z] -= vec.coord[Z];
}
template <class T>
void Vector3<T>::operator -=(const Vector3 &vec){
	coord[X] -= vec.coord[X];
	coord[Y] -= vec.coord[Y];
	coord[Z] -= vec.coord[Z];
}
template <class T>
Vector3<T> Vector3<T>::sub(const Vector3 &vec1, const Vector3 &vec2){
	return Vector3 (	vec1.coord[X] - vec2.coord[X],
		vec1.coord[Y] - vec2.coord[Y],
		vec1.coord[Z] - vec2.coord[Z]);
}
template <class T>
Vector3<T> Vector3<T>::operator -(const Vector3 &vec)	{
	return Vector3 (	coord[X] - vec.coord[X],
		coord[Y] - vec.coord[Y],
		coord[Z] - vec.coord[Z]);
}

// ----------------------------------------------------------
// Scalar Multiplication

template <class T>
void Vector3<T>::mult(T value){
	coord[X] *= value;
	coord[Y] *= value;
	coord[Z] *= value;
}
template <class T>
void Vector3<T>::operator *=(T value){
	coord[X] *= value;
	coord[Y] *= value;
	coord[Z] *= value;
}
template <class T>
void Vector3<T>::operator *=(const Vector3<T> &vec){
	coord[X] *= vec.coord[X];
	coord[Y] *= vec.coord[Y];
	coord[Z] *= vec.coord[Z];
}
template <class T>
Vector3<T> Vector3<T>::mult(const Vector3& vec, T value){
	return Vector3(vec.coord[X] * value, vec.coord[Y] * value, vec.coord[Z] * value);
}
template <class T>
Vector3<T> Vector3<T>::mult(T value, const Vector3 &vec){
	return Vector3(vec.coord[X] * value, vec.coord[Y] * value, vec.coord[Z] * value);
}
template <class T>
Vector3<T> Vector3<T>::operator *(T value){
	return Vector3(coord[X] * value, coord[Y] * value, coord[Z] * value);
}
template <class T>
Vector3<T> operator *(T value, const Vector3<T> &vec){
	return Vector3<T>(vec.coord[X] * value, vec.coord[Y] * value, vec.coord[Z] * value);
}

// ----------------------------------------------------------
// Scalar Division

template <class T>
void Vector3<T>::div(T value){
	coord[X] /= value;
	coord[Y] /= value;
	coord[Z] /= value;
}
template <class T>
void Vector3<T>::operator /=(T value){
	coord[X] /= value;
	coord[Y] /= value;
	coord[Z] /= value;
}
template <class T>
Vector3<T> Vector3<T>::div(const Vector3& vec, T value){
	return Vector3(vec.coord[X] / value, vec.coord[Y] / value, vec.coord[Z] / value);
}
template <class T>
Vector3<T> Vector3<T>::div(T value, const Vector3& vec){
	return Vector3(vec.coord[X] / value, vec.coord[Y] / value, vec.coord[Z] / value);
}
template <class T>
Vector3<T> Vector3<T>::operator /(T value){
	return Vector3(coord[X] / value, coord[Y] / value, coord[Z] / value);
}
template <class T>
Vector3<T> operator /(T value, const Vector3<T>& vec){
	return Vector3<T>(value / vec.coord[X], value / vec.coord[Y], value/ vec.coord[Z]);
}

// ----------------------------------------------------------
// Length

template <class T>
T Vector3<T>::length(){
	T cx = coord[X], cy = coord[Y], cz = coord[Z];
	return sqrt((cx*cx) + (cy*cy) + (cz*cz));
}
template <class T>
T Vector3<T>::length(const Vector3& vec){
	T cx = vec.coord[X], cy = vec.coord[Y], cz = vec.coord[Z];
	return sqrt((cx*cx) + (cy*cy) + (cz*cz));
}
template <class T>
T Vector3<T>::SquaredMagnitude(){
    return (coord[X]*coord[X]) + (coord[Y]*coord[Y]) + (coord[Z]*coord[Z]);
}
template <class T>
T Vector3<T>::SquaredMagnitude(const Vector3<T>& vec){
    return (vec.coord[X]*vec.coord[X]) + (vec.coord[Y]*vec.coord[Y]) + (vec.coord[Z]*vec.coord[Z]);
}

// ----------------------------------------------------------
// Normalization

template <class T>
void Vector3<T>::normalize(){
	T len = length();

	if(len == 0.0)
		len = 1.0f;//throw std::overflow_error("Divide by zero exception");

	coord[X] = coord[X]/len;
	coord[Y] = coord[Y]/len;
	coord[Z] = coord[Z]/len;
}
template <class T>
void Vector3<T>::normalize(const Vector3& vec){
	T len = vec.length();

	if(len == 0.0)
		len = 1.0f;//throw std::overflow_error("Divide by zero exception");

	vec.coord[X] = vec.coord[X]/len;
	vec.coord[Y] = vec.coord[Y]/len;
	vec.coord[Z] = vec.coord[Z]/len;
}
template <class T>
Vector3<T> Vector3<T>::normalized(){
	T len = length();

	if(len == 0.0)
		len = 1.0f;//throw std::overflow_error("Divide by zero exception");

	Vector3 newVec;
	newVec.coord[X] = coord[X]/len;
	newVec.coord[Y] = coord[Y]/len;
	newVec.coord[Z] = coord[Z]/len;

	return newVec;
}
template <class T>
Vector3<T> Vector3<T>::normalized(const Vector3& vec){
	T len = vec.length();

	if(len == 0.0f)
		len = 1.0f;//throw std::overflow_error("Divide by zero exception");

	Vector3 newVec;
	newVec.coord[X] = vec.coord[X]/len;
	newVec.coord[Y] = vec.coord[Y]/len;
	newVec.coord[Z] = vec.coord[Z]/len;

	return newVec;
}

// ----------------------------------------------------------
// Dot Product

template <class T>
T Vector3<T>::dot(const Vector3& vec){
	T product = 0;
	for(int i = 0; i < 3; ++i){
		product += coord[i]*vec.coord[i];
	}
	return product;
}
template <class T>
T Vector3<T>::operator * (const Vector3& vec){
	T product = 0;
	for(int i = 0; i < 3; ++i){
		product += coord[i]*vec.coord[i];
	}
	return product;
}
template <class T>
T Vector3<T>::dot(const Vector3& vec1, const Vector3& vec2){
	T product = 0;
	for(int i = 0; i < 3; ++i){
		product += vec1.coord[i]*vec2.coord[i];
	}
	return product;
}

// ----------------------------------------------------------
// Cross Product

template <class T>
void Vector3<T>::cross(const Vector3& vec){
	T x1 = coord[X],		y1 = coord[Y],		z1 = coord[Z];
	T x2 = vec.coord[X],	y2 = vec.coord[Y],	z2 = vec.coord[Z];

	coord[X] = (y1 * z2)-(y2 * z1);
	coord[Y] = (z1 * x2)-(z2 * x1);
	coord[Z] = (x1 * y2)-(x2 * y1);
}
template <class T>
void Vector3<T>::operator ^=(const Vector3& vec){
	T x1 = coord[X],		y1 = coord[Y],		z1 = coord[Z];
	T x2 = vec.coord[X],	y2 = vec.coord[Y],	z2 = vec.coord[Z];

	coord[X] = (y1 * z2)-(y2 * z1);
	coord[Y] = (z1 * x2)-(z2 * x1);
	coord[Z] = (x1 * y2)-(x2 * y1);
}
template <class T>
Vector3<T> Vector3<T>::cross(const Vector3& vec1, const Vector3& vec2){
	T x1 = vec1.coord[X], y1 = vec1.coord[Y], z1 = vec1.coord[Z];
	T x2 = vec2.coord[X], y2 = vec2.coord[Y], z2 = vec2.coord[Z];

	Vector3 newVec;
	newVec.coord[X] = (y1 * z2)-(y2 * z1);
	newVec.coord[Y] = (z1 * x2)-(z2 * x1);
	newVec.coord[Z] = (x1 * y2)-(x2 * y1);
	return newVec;
}
template <class T>
Vector3<T> Vector3<T>::operator ^(const Vector3& vec){
	T x1 = coord[X],		y1 = coord[Y],		z1 = coord[Z];
	T x2 = vec.coord[X],	y2 = vec.coord[Y],	z2 = vec.coord[Z];

	Vector3 newVec;
	newVec.coord[X] = (y1 * z2)-(y2 * z1);
	newVec.coord[Y] = (z1 * x2)-(z2 * x1);
	newVec.coord[Z] = (x1 * y2)-(x2 * y1);
	return newVec;
}

#endif