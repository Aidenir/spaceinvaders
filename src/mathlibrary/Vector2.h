//--- � 2013 Blankycan -----------------------------------------------------------------------------
// File:	Vector2.h
// Author:	Blankycan
// Date:	2013-08-30
//--------------------------------------------------------------------------------------------------
#ifndef Vector2_H
#define Vector2_H
//--------------------------------------------------------------------------------------------------
#include <iostream>
#include <math.h>
//--------------------------------------------------------------------------------------------------
#include "MathLibrary.h"
//--------------------------------------------------------------------------------------------------

/** Vector2
	A 2 long vector consisting of T values.*/
template <class T>
class Vector2{
public:
	// ----------------------------------------------------------
	// Constructors

	/** Vector2()
		Default constructor, defaults the vector to a (0,0) vector.*/
	Vector2();
	/** Vector2(T, T)
		Constructor that takes three T values and creates a vector
		that uses them as it's x, and y values.*/
	Vector2(T x, T y);
	/** Vector2(T[2])
		A constructor that takes an 2-long T array.
		It uses the arrays values as x,y values for the vector.*/
	Vector2(T vec[2]);
	/** Vector2(Vector2&)
		Constructor/Copy-constructor that takes another Vector2 as parameter.
		It copies the parameter's x, and y values and uses them
		for it's own vector.*/
	Vector2(const Vector2& vec);
	/** Vector2(Vector3f&)
		Constructor/Copy-constructor that takes another Vector3f as parameter.
		It copies the parameter's x, and y values and uses them
		for it's own vector. It skips the z value.*/
	Vector2(const Vector3<T>& vec);
	/** Vector2(Vector4f&)
		Constructor/Copy-constructor that takes another Vector4f as parameter.
		It copies the parameter's x, and y values and uses them
		for it's own vector. It skips the z and w values.*/
	Vector2(const Vector4<T>& vec);
	/** Vector2(Vertex2f&, Vertex2f&)
		Constructor that creates vector from two points.*/
	Vector2(const Vertex2<T>& ver1, const Vertex2<T>& ver2);
	/** Vector2(Vertex2f&)
		Constructor that creates vector from one point.*/
	Vector2(const Vertex2<T>& vertex);

	// ----------------------------------------------------------
	// Other Methods

	/** operator =(Vector2&)
		A copy function that copies the parameters values to the new vector's.
		Use: vector = vector
		Result: The vector calling the function have the same x,y values
				as the vector passed with the function have.*/
	void operator =(const Vector2<T>& vec);
	/** operator ==(Vector2&)
		Method to check if two vectors have the same x,y values.
		Use: vector == vector
		Result: Returns a boolean whether the two vectors are alike*/
	bool operator ==(const Vector2<T>& vec);
	/** friend operator ==(const Vector2&, const Vector2&)
		Method to check if two vectors have the same x,y values.
		Result: Returns a boolean whether the two vectors are alike*/
	//friend bool operator ==(const Vector2<T>& v1, const Vector2<T>& v2);
	/** operator !=(Vector2&)
		Method to check if two vectors don't have the same x,y values.
		Use: vector != vector
		Result: Returns a boolean whether the two vectors differs*/
	bool operator !=(const Vector2<T>& vec);
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

	// ----------------------------------------------------------
	// Addition

	/** add(Vector2&)
		Add the vector values of the parameter to the
		vector that called the method.
		Use: vector1.add(vector2)
		Result: vector calling the method gets a new value*/
	void			add			(const Vector2<T>& vec);
	/** operator += (Vector2&)
		Add the vector values of the parameter to the
		vector that called the method.
		Use: vector1 += vector2
		Result: vector calling the method gets a new value*/
	void			operator +=	(const Vector2<T>& vec);
	/** add(Vector2&, Vector2&)
		A method to add two vectors values together and
		return the sum in form of a new vector.
		Use: Vector2::add(vector1, vector2)
		Result: Returns a new vector*/
	static Vector2<T> add			(const Vector2<T>& vec1, const Vector2<T>& vec2);
	/** operator + (Vector2&)
		A method to add two vectors values together and
		return the sum in form of a new vector.
		Use: add(vector1, vector2)
		Result: Returns a new vector*/
	Vector2<T>		operator +	(const Vector2<T>& vec);
	
	// ----------------------------------------------------------
	// Subtraction

	/** sub(Vector2&)
		Subtract the values from the vector calling the function
		with the parameter vector values.
		Use: vector1.sub(vector2)
		Result: vector calling the method gets a new value*/
	void			sub			(const Vector2<T>& vec);
	/** operator -= (Vector2&)
		Subtract the values from the vector calling the function
		with the parameter vector values.
		Use: vector1 -= vector2
		Result: vector calling the method gets a new value*/
	void			operator -=	(const Vector2<T>& vec);
	/** static sub(Vector2&, Vector2&)
		A static method to subtract two vectors values with each
		other and return the sum in form of a new vector.
		Use: Vector2::sub(vector1, vector2)
		Result: Returns a new vector*/
	static Vector2<T>	sub			(const Vector2<T>& vec1, const Vector2<T>& vec2);
	/** operator - (Vector2&)
		A method to subtract two vectors values with each other
		and return the sum in form of a new vector.
		Use: vector1 - vector2
		Result: Returns a new vector*/
	Vector2<T>		operator -	(const Vector2<T>& vec);
	
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
	/** mult(Vector2&, T)
		Multiplies the vector with the scalar.
		Use: Vector2::mult(vector, value);
		Result: New Vector2 is returned.*/
	static Vector2<T>	mult		(const Vector2<T>& vec, T value);
	/** mult(T, Vector2&)
		Multiplies the vector with the scalar.
		Use: Vector2::mult(value, vector);
		Result: New Vector2 is returned.*/
	static Vector2<T>	mult		(T value, const Vector2<T>& vec);
	/** operator * (T)
		Multiplies the vector with the scalar.
		Use: vector * value
		Result: New Vector2 is returned.*/
	Vector2<T>		operator *	(T value);
	/** friend operator * (Vector2&)
		Multiplies the vector with the scalar.
		Use: value * vector
		Result: New Vector2 is returned.*/
	//friend Vector2<T>	operator *	(T value, Vector2<T>& vec);

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
	/** div(Vector2&, T)
		Divides the vector with the scalar.
		Use: Vector2::div(vector, value);
		Result: New Vector2 is returned.*/
	static Vector2<T>	div			(const Vector2<T>& vec, T value);
	/** div(T, Vector2&)
		Divides the vector with the scalar.
		Use: Vector2::div(value, vector);
		Result: New Vector2 is returned.*/
	static Vector2<T>	div			(T value, const Vector2<T>& vec);
	/** operator / (T)
		Divides the vector with the scalar.
		Use: vector / value
		Result: New Vector2 is returned.*/
	Vector2<T>		operator /	(T value);
	/** friend operator / (Vector2&)
		Divides the vector with the scalar.
		Use: value / vector
		Result: New Vector2 is returned.*/
	//friend Vector2<T>	operator /	(T value, Vector2<T>& vec);

	// ----------------------------------------------------------
	// Length

	/** length()
		Function to get the length of the vector.
		Use: vector.length()
		Result: The length of the vector is returned as a T value.*/
	T			length		();
	/** length(Vector2&)
		Function to get the length of the parameter vector.
		Use: Vector2::length(vector)
		Result: The length of the vector is returned as a T value.*/
	static T	length		(const Vector2<T>& vec);
	
	// ----------------------------------------------------------
	// Normalization
	
	/** normalize()
		Normalizes the vector.
		Precondition: The length of the vector must not be zero.
		Use: vector.normalize()
		Result: Vector calling the method gets normalized.
		If precondition is not valid, length will be 1*/
	void normalize();
	/** normalize(Vector2&)
		Normalizes the parameter vector.
		Precondition: The length of the parameter vector must not be zero.
		Use: normalize(vector)
		Result: Vector passed as a parameter of the method gets normalized.
		If precondition is not valid, length will be 1*/
	static void normalize(const Vector2<T>& vec);
	/** normalized()
		Normalizes the vector.
		Precondition: The length of the vector must not be zero.
		Use: vector.normalizes()
		Result: Returns a normalized version of the vector using the method.
		If precondition is not valid, length will be 1*/
	Vector2<T> normalized();
	/** normalizes(Vector2&)
		Normalizes the parameter vector.
		Precondition: The length of the parameter vector must not be zero.
		Use: normalizes(vector)
		Result: Returns a normalized version of the vector passed as a parameter.
		If precondition is not valid, length will be 1*/
	static Vector2<T> normalized(const Vector2<T>& vec);

	// ----------------------------------------------------------
	// Dot Product

	/** dot(Vector2&)
		Calculates the dot product from the vectors.
		Use: vector.dot(vector)
		Result: Returns the dot product as a T value*/
	T			dot			(const Vector2<T>& vec);
	/** operator * (Vector2&)
		Calculates the dot product from the vectors.
		Use: vector * vector
		Result: Returns the dot product as a T value*/
	T			operator *	(const Vector2<T>& vec);
	/** dot(Vector2&, Vector2)
		Calculates the dot product from the vectors.
		Use: Vector2::dot(vector, vector)
		Result: Returns the dot product as a T value*/
	static T	dot			(const Vector2<T>& vec1, const Vector2<T>& vec2);

	// ----------------------------------------------------------
	// Variables
	
	/** T coord[2]
		An array representing a vectors three values.
		In Vector2 the values are T type values.
		coord[0] = x, coord[1] = y*/
	T coord[2];
};


//--------------------------------------------------------------------------------------------------
//	Implementation
//--------------------------------------------------------------------------------------------------

// ----------------------------------------------------------
// Constructors
template <class T>
Vector2<T>::Vector2(){
	coord[X] = 0;
	coord[Y] = 0;
}
template <class T>
Vector2<T>::Vector2(T x, T y){
	coord[X] = x;
	coord[Y] = y;
}
template <class T>
Vector2<T>::Vector2(T vec[2]){
	coord[X] = vec[X];
	coord[Y] = vec[Y];
}
template <class T>
Vector2<T>::Vector2(const Vector2& vec){
	coord[X] = (T)vec.coord[X];
	coord[Y] = (T)vec.coord[Y];
}
template <class T>
Vector2<T>::Vector2(const Vector3<T>& vec){
	coord[X] = vec.coord[X];
	coord[Y] = vec.coord[Y];
}
template <class T>
Vector2<T>::Vector2(const Vector4<T>& vec){
	coord[X] = vec.coord[X];
	coord[Y] = vec.coord[Y];
}
template <class T>
Vector2<T>::Vector2(const Vertex2<T>& ver1, const Vertex2<T>& ver2){
	coord[X] = ver2.coord[X] - ver1.coord[X];
	coord[Y] = ver2.coord[Y] - ver1.coord[Y];
}
template <class T>
Vector2<T>::Vector2(const Vertex2<T>& vertex){
	coord[X] = vertex.coord[X];
	coord[Y] = vertex.coord[Y];
}

// ----------------------------------------------------------
// Other Methods
template <class T>
void Vector2<T>::operator =(const Vector2& vec){
	coord[X] = vec.coord[X];
	coord[Y] = vec.coord[Y];
}
template <class T>
bool Vector2<T>::operator ==(const Vector2& vec){
	bool result = true;
	if(coord[X] != vec.coord[X])
		result = false;
	if(coord[Y] != vec.coord[Y])
		result = false;
	return result;
}
template <class T>
bool operator ==(const Vector2<T>& v1, const Vector2<T>& v2){
	if(v1.coord[X] != v2.coord[X])
		return false;
	if(v1.coord[Y] != v2.coord[Y])
		return false;
	return true;
}
template <class T>
bool Vector2<T>::operator !=(const Vector2& vec){
	char count = 0;
	if(coord[X] == vec.coord[X])
		++count;
	if(coord[Y] == vec.coord[Y])
		++count;
	if(count == 2)
		return false;
	return true;
}
template <class T>
T Vector2<T>::operator ()(unsigned char n) const{
	return coord[n];
}
template <class T>
T Vector2<T>::operator [](unsigned char n) const{
	return coord[n];
}
template <class T>
T& Vector2<T>::operator ()(unsigned char n){
	return coord[n];
}
template <class T>
T& Vector2<T>::operator [](unsigned char n){
	return coord[n];
}

// ----------------------------------------------------------
// Addition
template <class T>
void Vector2<T>::add(const Vector2& vec){
	coord[X] += vec.coord[X];
	coord[Y] += vec.coord[Y];
}
template <class T>
void Vector2<T>::operator +=(const Vector2& vec){
	coord[X] += vec.coord[X];
	coord[Y] += vec.coord[Y];
}
template <class T>
Vector2<T> Vector2<T>::add(const Vector2& vec1, const Vector2& vec2){
	return Vector2 (	vec1.coord[X] + vec2.coord[X],
		vec1.coord[Y] + vec2.coord[Y]);
}
template <class T>
Vector2<T> Vector2<T>::operator +(const Vector2& vec)	{
	return Vector2 (	coord[X] + vec.coord[X],
		coord[Y] + vec.coord[Y]);
}

// ----------------------------------------------------------
// Subtraction

template <class T>
void Vector2<T>::sub(const Vector2& vec){
	coord[X] -= vec.coord[X];
	coord[Y] -= vec.coord[Y];
}
template <class T>
void Vector2<T>::operator -=(const Vector2& vec){
	coord[X] -= vec.coord[X];
	coord[Y] -= vec.coord[Y];
}
template <class T>
Vector2<T> Vector2<T>::sub(const Vector2& vec1, const Vector2& vec2){
	return Vector2 (	vec1.coord[X] - vec2.coord[X],
		vec1.coord[Y] - vec2.coord[Y]);
}
template <class T>
Vector2<T> Vector2<T>::operator -(const Vector2& vec)	{
	return Vector2 (	coord[X] - vec.coord[X],
		coord[Y] - vec.coord[Y]);
}

// ----------------------------------------------------------
// Scalar Multiplication

template <class T>
void Vector2<T>::mult(T value){
	coord[X] *= value;
	coord[Y] *= value;
}
template <class T>
void Vector2<T>::operator *=(T value){
	coord[X] *= value;
	coord[Y] *= value;
}
template <class T>
Vector2<T> Vector2<T>::mult(const Vector2& vec, T value){
	return Vector2(vec.coord[X] * value, vec.coord[Y] * value);
}
template <class T>
Vector2<T> Vector2<T>::mult(T value, const Vector2& vec){
	return Vector2(vec.coord[X] * value, vec.coord[Y] * value);
}
template <class T>
Vector2<T> Vector2<T>::operator *(T value){
	return Vector2(coord[X] * value, coord[Y] * value);
}
template <class T>
Vector2<T> operator *(T value, const Vector2<T>& vec){
	return Vector2<T>(vec.coord[X] * value, vec.coord[Y] * value);
}

// ----------------------------------------------------------
// Scalar Division

template <class T>
void Vector2<T>::div(T value){
	coord[X] /= value;
	coord[Y] /= value;
}
template <class T>
void Vector2<T>::operator /=(T value){
	coord[X] /= value;
	coord[Y] /= value;
}
template <class T>
Vector2<T> Vector2<T>::div(const Vector2& vec, T value){
	return Vector2(vec.coord[X] / value, vec.coord[Y] / value);
}
template <class T>
Vector2<T> Vector2<T>::div(T value, const Vector2& vec){
	return Vector2(vec.coord[X] / value, vec.coord[Y] / value);
}
template <class T>
Vector2<T> Vector2<T>::operator /(T value){
	return Vector2(coord[X] / value, coord[Y] / value);
}
template <class T>
Vector2<T> operator /(T value, const Vector2<T>& vec){
	return Vector2<T>(vec.coord[X] / value, vec.coord[Y] / value);
}

// ----------------------------------------------------------
// Length

template <class T>
T Vector2<T>::length(){
	T cx = coord[X], cy = coord[Y];
	return sqrt((cx*cx) + (cy*cy));
}
template <class T>
T Vector2<T>::length(const Vector2& vec){
	T cx = vec.coord[X], cy = vec.coord[Y];
	return sqrt((cx*cx) + (cy*cy));
}

// ----------------------------------------------------------
// Normalization

template <class T>
void Vector2<T>::normalize(){
	T len = length();

	if(len == 0.0)
		len = 1.0f;//throw std::overflow_error("Divide by zero exception");

	coord[X] = coord[X]/len;
	coord[Y] = coord[Y]/len;
}
template <class T>
void Vector2<T>::normalize(const Vector2& vec){
	T len = vec.length();

	if(len == 0.0)
		len = 1.0f;//throw std::overflow_error("Divide by zero exception");

	vec.coord[X] = vec.coord[X]/len;
	vec.coord[Y] = vec.coord[Y]/len;
}
template <class T>
Vector2<T> Vector2<T>::normalized(){
	T len = length();

	if(len == 0.0)
		len = 1.0f;//throw std::overflow_error("Divide by zero exception");

	Vector2<T> newVec;
	newVec.coord[X] = coord[X]/len;
	newVec.coord[Y] = coord[Y]/len;

	return newVec;
}
template <class T>
Vector2<T> Vector2<T>::normalized(const Vector2& vec){
	T len = vec.length();

	if(len == 0.0f)
		len = 1.0f;//throw std::overflow_error("Divide by zero exception");

	Vector2 newVec;
	newVec.coord[X] = vec.coord[X]/len;
	newVec.coord[Y] = vec.coord[Y]/len;

	return newVec;
}

// ----------------------------------------------------------
// Dot Product

template <class T>
T Vector2<T>::dot(const Vector2& vec){
	T product = 0;
	for(int i = 0; i < 2; ++i){
		product += coord[i]*vec.coord[i];
	}
	return product;
}
template <class T>
T Vector2<T>::operator * (const Vector2& vec){
	T product = 0;
	for(int i = 0; i < 2; ++i){
		product += coord[i]*vec.coord[i];
	}
	return product;
}
template <class T>
T Vector2<T>::dot(const Vector2& vec1, const Vector2& vec2){
	T product = 0;
	for(int i = 0; i < 2; ++i){
		product += vec1.coord[i]*vec2.coord[i];
	}
	return product;
}

#endif