//--- � 2013 Blankycan -----------------------------------------------------------------------------
// File:	Vector4.h
// Author:	Blankycan
// Date:	2013-08-31
//--------------------------------------------------------------------------------------------------
#ifndef Vector4_H
#define Vector4_H
//--------------------------------------------------------------------------------------------------
#include <iostream>
#include <math.h>
//--------------------------------------------------------------------------------------------------
#include "MathLibrary.h"
//--------------------------------------------------------------------------------------------------

/** Vector4
	A 4 long vector consisting of T values.'
*/
template <class T>
class Vector4{
public:
	// ----------------------------------------------------------
	// Constructors

	/** Vector4()
		Default constructor, defaults the vector to a (0,0,0,0) vector.*/
	Vector4();
	/** Vector4(T, T, T, T)
		Constructor that takes three T values and creates a vector
		that uses them as it's x, y, z and w values.*/
	Vector4(T x, T y, T z, T w);
	/** Vector4(T[4])
		A constructor that takes an 4-long T array.
		It uses the arrays values as x,y,z,w values for the vector.*/
	Vector4(T vec[4]);
	/** Vector3d(Vector3d&, T = 0)
		Constructor/Copy-constructor that takes another Vector3d as parameter.
		It copies the parameter's x,y and z values and uses them
		for it's own vector. It takes another T value as w.*/
	Vector4(const Vector3<T>& vec, T w = 0);
	/** Vector4(Vector4)
		Constructor/Copy-constructor that takes another Vector4 as parameter.
		It copies the parameter's x,y,z and w values and uses them
		for it's own vector.*/
	Vector4(const Vector4f& vec);
	Vector4(const Vector4d& vec);

	// ----------------------------------------------------------
	// Other Methods

	/** operator =(Vector4&)
		A copy function that copies the parameters values to the new vector's.
		Use: vector = vector
		Result: The vector calling the function have the same x,y,z,w values
				as the vector passed with the function have.*/
	void operator =(const Vector4<T>& vec);
	/** operator ==(Vector4&)
		Method to check if two vectors have the same x,y,z,w values.
		Use: vector == vector
		Result: Returns a boolean whether the two vectors are alike*/
	bool operator ==(const Vector4<T>& vec);
	/** friend operator ==(const Vector4&, const Vector4&)
		Method to check if two vectors have the same x,y,z,w values.
		Result: Returns a boolean whether the two vectors are alike*/
	//friend bool operator ==(const Vector4<T>& v1, const Vector4<T>& v2);
	/** operator !=(Vector4&)
		Method to check if two vectors don't have the same x,y,z,w values.
		Use: vector != vector
		Result: Returns a boolean whether the two vectors differs*/
	bool operator !=(const Vector4<T>& vec);
	/** operator ()(unsigned char) const
		A function to easily find what's in a specific position
		in the vector.
		Precondition: n may never exceed 3.
		Use: vector(n)
		Result: Returns T value in position n in vector.
				If precondition isn't met suspect the unsuspected.*/
	T operator ()(unsigned char n) const;
	/** operator [](unsigned char) const
		A function to easily find what's in a specific position
		in the vector.
		Precondition: n may never exceed 3.
		Use: vector[n]
		Result: Returns T value in position n in vector.
				If precondition isn't met suspect the unsuspected.*/
	T operator [](unsigned char n) const;
	/** operator ()(unsigned char)
		Function to make easy changes in the vector.
		Precondition: n may never exceed 3.
					  Only put in T values.
		Use: vector(n) = T
		Result: Inserts the T value into the vector.
				If precondition isn't met suspect the unsuspected.*/
	T& operator ()(unsigned char n);
	/** operator [](unsigned char)
		Function to make easy changes in the vector.
		Precondition: n may never exceed 3.
					  Only put in T values.
		Use: vector[n] = T
		Result: Inserts the T value into the vector.
				If precondition isn't met suspect the unsuspected.*/
	T& operator [](unsigned char n);
	/** getContent()
		Returns an array with all four coordinates.
		Use: vector.getContent()
		Result: Array with 4 values is returned.*/
	T* getContent();

	// ----------------------------------------------------------
	// Addition

	/** add(Vector4&)
		Add the vector values of the parameter to the
		vector that called the method.
		Use: vector1.add(vector2)
		Result: vector calling the method gets a new value*/
	void			add			(const Vector4<T>& vec);
	/** operator += (Vector4&)
		Add the vector values of the parameter to the
		vector that called the method.
		Use: vector1 += vector2
		Result: vector calling the method gets a new value*/
	void			operator +=	(const Vector4<T>& vec);
	/** add(Vector4&, Vector4&)
		A method to add two vectors values together and
		return the sum in form of a new vector.
		Use: Vector4::add(vector1, vector2)
		Result: Returns a new vector*/
	static Vector4<T> add			(const Vector4<T>& vec1, const Vector4<T>& vec2);
	/** operator + (Vector4&)
		A method to add two vectors values together and
		return the sum in form of a new vector.
		Use: add(vector1, vector2)
		Result: Returns a new vector*/
	Vector4<T>		operator +	(const Vector4<T>& vec);
	
	// ----------------------------------------------------------
	// Subtraction

	/** sub(Vector4&)
		Subtract the values from the vector calling the function
		with the parameter vector values.
		Use: vector1.sub(vector2)
		Result: vector calling the method gets a new value*/
	void			sub			(const Vector4<T>& vec);
	/** operator -= (Vector4&)
		Subtract the values from the vector calling the function
		with the parameter vector values.
		Use: vector1 -= vector2
		Result: vector calling the method gets a new value*/
	void			operator -=	(const Vector4<T>& vec);
	/** static sub(Vector4&, Vector4&)
		A static method to subtract two vectors values with each
		other and return the sum in form of a new vector.
		Use: Vector4::sub(vector1, vector2)
		Result: Returns a new vector*/
	static Vector4<T>	sub			(const Vector4<T>& vec1, const Vector4<T>& vec2);
	/** operator - (Vector4&)
		A method to subtract two vectors values with each other
		and return the sum in form of a new vector.
		Use: vector1 - vector2
		Result: Returns a new vector*/
	Vector4<T>		operator -	(const Vector4<T>& vec);
	
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
	/** mult(Vector4&, T)
		Multiplies the vector with the scalar.
		Use: Vector4::mult(vector, value);
		Result: New Vector4 is returned.*/
	static Vector4<T>	mult		(const Vector4<T>& vec, T value);
	/** mult(T, Vector4&)
		Multiplies the vector with the scalar.
		Use: Vector4::mult(value, vector);
		Result: New Vector4 is returned.*/
	static Vector4<T>	mult		(T value, const Vector4<T>& vec);
	/** operator * (T)
		Multiplies the vector with the scalar.
		Use: vector * value
		Result: New Vector4 is returned.*/
	Vector4<T>		operator *	(T value);
	/** friend operator * (Vector4&)
		Multiplies the vector with the scalar.
		Use: value * vector
		Result: New Vector4 is returned.*/
	//friend Vector4<T>	operator *	(T value, const Vector4<T>& vec);

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
	/** div(Vector4&, T)
		Divides the vector with the scalar.
		Use: Vector4::div(vector, value);
		Result: New Vector4 is returned.*/
	static Vector4<T>	div			(const Vector4<T>& vec, T value);
	/** div(T, Vector4&)
		Divides the vector with the scalar.
		Use: Vector4::div(value, vector);
		Result: New Vector4 is returned.*/
	static Vector4<T>	div			(T value, const Vector4<T>& vec);
	/** operator / (T)
		Divides the vector with the scalar.
		Use: vector / value
		Result: New Vector4 is returned.*/
	Vector4<T>		operator /	(T value);
	/** friend operator / (Vector3d&)
		Divides the vector with the scalar.
		Use: value / vector
		Result: New Vector4 is returned.*/
	//friend Vector4<T>	operator /	(T value, const Vector4<T>& vec);

	// ----------------------------------------------------------
	// Length

	/** length()
		Function to get the length of the vector.
		Use: vector.length()
		Result: The length of the vector is returned as a T value.*/
	T			length		();
	/** length(Vector4&)
		Function to get the length of the parameter vector.
		Use: Vector4::length(vector)
		Result: The length of the vector is returned as a T value.*/
	static T	length		(const Vector4<T>& vec);
	
	// ----------------------------------------------------------
	// Normalization
	
	/** normalize()
		Normalizes the vector.
		Precondition: The length of the vector must not be zero.
		Use: vector.normalize()
		Result: Vector calling the method gets normalized.
			    If precondition is not valid, overflow error will be thrown*/
	void normalize();
	/** normalize(Vector4&)
		Normalizes the parameter vector.
		Precondition: The length of the parameter vector must not be zero.
		Use: normalize(vector)
		Result: Vector passed as a parameter of the method gets normalized.
				If precondition is not valid, overflow error will be thrown*/
	static void normalize(const Vector4<T>& vec);
	/** normalized()
		Normalizes the vector.
		Precondition: The length of the vector must not be zero.
		Use: vector.normalizes()
		Result: Returns a normalized version of the vector using the method.
		If precondition is not valid, overflow error will be thrown*/
	Vector4<T> normalized();
	/** normalizes(Vector4&)
		Normalizes the parameter vector.
		Precondition: The length of the parameter vector must not be zero.
		Use: normalizes(vector)
		Result: Returns a normalized version of the vector passed as a parameter.
		If precondition is not valid, overflow error will be thrown*/
	static Vector4<T> normalized(const Vector4<T>& vec);

	// ----------------------------------------------------------
	// Dot Product

	/** dot(Vector4&)
		Calculates the dot product from the vectors.
		Use: vector.dot(vector)
		Result: Returns the dot product as a T value*/
	T			dot			(const Vector4<T>& vec);
	/** operator * (Vector4&)
		Calculates the dot product from the vectors.
		Use: vector * vector
		Result: Returns the dot product as a T value*/
	T			operator *	(const Vector4<T>& vec);
	/** dot(Vector4&, Vector4)
		Calculates the dot product from the vectors.
		Use: Vector4::dot(vector, vector)
		Result: Returns the dot product as a T value*/
	static T	dot			(const Vector4<T>& vec1, const Vector4<T>& vec2);

	// ----------------------------------------------------------
	// Variables
	
	/** T coord[4]
		An array representing a vectors three values.
		In Vector4 the values are T type values.
		coord[0] = x, coord[1] = y, coord[2] = z, coord[3] = w*/
	T coord[4];
};



// ----------------------------------------------------------
// Constructors
template <class T>
Vector4<T>::Vector4(){
	coord[X] = 0;
	coord[Y] = 0;
	coord[Z] = 0;
	coord[W] = 0;
}
template <class T>
Vector4<T>::Vector4(T x, T y, T z, T w){
	coord[X] = x;
	coord[Y] = y;
	coord[Z] = z;
	coord[W] = w;
}
template <class T>
Vector4<T>::Vector4(T vec[4]){
	coord[X] = vec[X];
	coord[Y] = vec[Y];
	coord[Z] = vec[Z];
	coord[W] = vec[W];
}
template <class T>
Vector4<T>::Vector4(const Vector3<T>& vec, T w){
	coord[X] = (T)vec.coord[X];
	coord[Y] = (T)vec.coord[Y];
	coord[Z] = (T)vec.coord[Z];
	coord[W] = w;
}
template <class T>
Vector4<T>::Vector4(const Vector4f& vec){
	coord[X] = (T)vec.coord[X];
	coord[Y] = (T)vec.coord[Y];
	coord[Z] = (T)vec.coord[Z];
	coord[W] = (T)vec.coord[W];
}
template <class T>
Vector4<T>::Vector4(const Vector4d& vec){
	coord[X] = (T)vec.coord[X];
	coord[Y] = (T)vec.coord[Y];
	coord[Z] = (T)vec.coord[Z];
	coord[W] = (T)vec.coord[W];
}

// ----------------------------------------------------------
// Other Methods
template <class T>
void Vector4<T>::operator =(const Vector4& vec){
	coord[X] = vec.coord[X];
	coord[Y] = vec.coord[Y];
	coord[Z] = vec.coord[Z];
	coord[W] = vec.coord[W];
}
template <class T>
bool Vector4<T>::operator ==(const Vector4& vec){
	bool result = true;
	if(coord[X] != vec.coord[X])
		result = false;
	if(coord[Y] != vec.coord[Y])
		result = false;
	if(coord[Z] != vec.coord[Z])
		result = false;
	if(coord[W] != vec.coord[W])
		result = false;
	return result;
}
template <class T>
bool operator ==(const Vector4<T>& v1, const Vector4<T>& v2){
	if(v1.coord[X] != v2.coord[X])
		return false;
	if(v1.coord[Y] != v2.coord[Y])
		return false;
	if(v1.coord[Z] != v2.coord[Z])
		return false;
	if(v1.coord[W] != v2.coord[W])
		return false;
	return true;
}
template <class T>
bool Vector4<T>::operator !=(const Vector4& vec){
	char count = 0;
	if(coord[X] == vec.coord[X])
		++count;
	if(coord[Y] == vec.coord[Y])
		++count;
	if(coord[Z] == vec.coord[Z])
		++count;
	if(coord[W] == vec.coord[W])
		++count;
	if(count == 4)
		return false;
	return true;
}
template <class T>
T Vector4<T>::operator ()(unsigned char n) const{
	return coord[n];
}
template <class T>
T Vector4<T>::operator [](unsigned char n) const{
	return coord[n];
}
template <class T>
T& Vector4<T>::operator ()(unsigned char n){
	return coord[n];
}
template <class T>
T& Vector4<T>::operator [](unsigned char n){
	return coord[n];
}
template <class T>
T* Vector4<T>::getContent(){
	return coord;
}

// ----------------------------------------------------------
// Addition
template <class T>
void Vector4<T>::add(const Vector4& vec){
	coord[X] += vec.coord[X];
	coord[Y] += vec.coord[Y];
	coord[Z] += vec.coord[X];
	coord[W] += vec.coord[W];
}
template <class T>
void Vector4<T>::operator +=(const Vector4& vec){
	coord[X] += vec.coord[X];
	coord[Y] += vec.coord[Y];
	coord[Z] += vec.coord[Z];
	coord[W] += vec.coord[W];
}
template <class T>
Vector4<T> Vector4<T>::add(const Vector4& vec1, const Vector4& vec2){
	return Vector4 (	vec1.coord[X] + vec2.coord[X],
		vec1.coord[Y] + vec2.coord[Y],
		vec1.coord[Z] + vec2.coord[Z],
		vec1.coord[W] + vec2.coord[W]);
}
template <class T>
Vector4<T> Vector4<T>::operator +(const Vector4& vec)	{
	return Vector4 (	coord[X] + vec.coord[X],
		coord[Y] + vec.coord[Y],
		coord[Z] + vec.coord[Z],
		coord[W] + vec.coord[W]);
}

// ----------------------------------------------------------
// Subtraction

template <class T>
void Vector4<T>::sub(const Vector4& vec){
	coord[X] -= vec.coord[X];
	coord[Y] -= vec.coord[Y];
	coord[Z] -= vec.coord[X];
	coord[W] -= vec.coord[W];
}
template <class T>
void Vector4<T>::operator -=(const Vector4& vec){
	coord[X] -= vec.coord[X];
	coord[Y] -= vec.coord[Y];
	coord[Z] -= vec.coord[X];
	coord[W] -= vec.coord[W];
}
template <class T>
Vector4<T> Vector4<T>::sub(const Vector4& vec1, const Vector4& vec2){
	return Vector4 (	vec1.coord[X] - vec2.coord[X],
		vec1.coord[Y] - vec2.coord[Y],
		vec1.coord[Z] - vec2.coord[Z],
		vec1.coord[W] - vec2.coord[W]);
}
template <class T>
Vector4<T> Vector4<T>::operator -(const Vector4& vec)	{
	return Vector4 (	coord[X] - vec.coord[X],
		coord[Y] - vec.coord[Y],
		coord[Z] - vec.coord[Z],
		coord[W] - vec.coord[W]);
}

// ----------------------------------------------------------
// Scalar Multiplication

template <class T>
void Vector4<T>::mult(T value){
	coord[X] *= value;
	coord[Y] *= value;
	coord[Z] *= value;
	coord[W] *= value;
}
template <class T>
void Vector4<T>::operator *=(T value){
	coord[X] *= value;
	coord[Y] *= value;
	coord[Z] *= value;
	coord[W] *= value;
}
template <class T>
Vector4<T> Vector4<T>::mult(const Vector4& vec, T value){
	return Vector4(vec.coord[X] * value, vec.coord[Y] * value, vec.coord[Z] * value, vec.coord[W] * value);
}
template <class T>
Vector4<T> Vector4<T>::mult(T value, const Vector4& vec){
	return Vector4(vec.coord[X] * value, vec.coord[Y] * value, vec.coord[Z] * value, vec.coord[W] * value);
}
template <class T>
Vector4<T> Vector4<T>::operator *(T value){
	return Vector4(coord[X] * value, coord[Y] * value, coord[Z] * value, coord[W] * value);
}
template <class T>
Vector4<T> operator *(T value, const Vector4<T>& vec){
	return Vector4<T>(vec.coord[X] * value, vec.coord[Y] * value, vec.coord[Z] * value, vec.coord[W] * value);
}

// ----------------------------------------------------------
// Scalar Division

template <class T>
void Vector4<T>::div(T value){
	coord[X] /= value;
	coord[Y] /= value;
	coord[Z] /= value;
	coord[W] /= value;
}
template <class T>
void Vector4<T>::operator /=(T value){
	coord[X] /= value;
	coord[Y] /= value;
	coord[Z] /= value;
	coord[W] /= value;
}
template <class T>
Vector4<T> Vector4<T>::div(const Vector4& vec, T value){
	return Vector4(vec.coord[X] / value, vec.coord[Y] / value, vec.coord[Z] / value, vec.coord[W] / value);
}
template <class T>
Vector4<T> Vector4<T>::div(T value, const Vector4& vec){
	return Vector4(vec.coord[X] / value, vec.coord[Y] / value, vec.coord[Z] / value, vec.coord[W] / value);
}
template <class T>
Vector4<T> Vector4<T>::operator /(T value){
	return Vector4(coord[X] / value, coord[Y] / value, coord[Z] / value, coord[W] / value);
}
template <class T>
Vector4<T> operator /(T value, const Vector4<T>& vec){
	return Vector4<T>(vec.coord[X] / value, vec.coord[Y] / value, vec.coord[Z] / value, vec.coord[W] / value);
}

// ----------------------------------------------------------
// Length

template <class T>
T Vector4<T>::length(){
	T cx = coord[X], cy = coord[Y], cz = coord[Z], cw = coord[W];
	return sqrt((cx*cx) + (cy*cy) + (cz*cz) + (cw*cw));
}
template <class T>
T Vector4<T>::length(const Vector4& vec){
	T cx = vec.coord[X], cy = vec.coord[Y], cz = vec.coord[Z], cw = vec.coord[W];
	return sqrt((cx*cx) + (cy*cy) + (cz*cz) + (cw*cw));
}

// ----------------------------------------------------------
// Normalization

template <class T>
void Vector4<T>::normalize(){
	T len = length();

	if(len == 0.0)
		return;

	coord[X] = coord[X]/len;
	coord[Y] = coord[Y]/len;
	coord[Z] = coord[Z]/len;
	coord[W] = coord[W]/len;
}
template <class T>
void Vector4<T>::normalize(const Vector4& vec){
	T len = vec.length();

	if(len == 0.0)
		return;

	vec.coord[X] = vec.coord[X]/len;
	vec.coord[Y] = vec.coord[Y]/len;
	vec.coord[Z] = vec.coord[Z]/len;
	vec.coord[W] = vec.coord[W]/len;
}
template <class T>
Vector4<T> Vector4<T>::normalized(){
	T len = length();

	if(len == 0.0)
		return;

	Vector4 newVec;
	newVec.coord[X] = coord[X]/len;
	newVec.coord[Y] = coord[Y]/len;
	newVec.coord[Z] = coord[Z]/len;
	newVec.coord[W] = coord[W]/len;

	return newVec;
}
template <class T>
Vector4<T> Vector4<T>::normalized(const Vector4& vec){
	T len = vec.length();

	if(len == 0.0)
		return;

	Vector4 newVec;
	newVec.coord[X] = vec.coord[X]/len;
	newVec.coord[Y] = vec.coord[Y]/len;
	newVec.coord[Z] = vec.coord[Z]/len;
	newVec.coord[W] = vec.coord[W]/len;

	return newVec;
}

// ----------------------------------------------------------
// Dot Product

template <class T>
T Vector4<T>::dot(const Vector4& vec){
	T product = 0;
	for(int i = 0; i < 4; ++i){
		product += coord[i]*vec.coord[i];
	}
	return product;
}
template <class T>
T Vector4<T>::operator * (const Vector4& vec){
	T product = 0;
	for(int i = 0; i < 4; ++i){
		product += coord[i]*vec.coord[i];
	}
	return product;
}
template <class T>
T Vector4<T>::dot(const Vector4& vec1, const Vector4& vec2){
	T product = 0;
	for(int i = 0; i < 4; ++i){
		product += vec1.coord[i]*vec2.coord[i];
	}
	return product;
}

#endif