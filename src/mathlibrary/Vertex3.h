//--- � 2013 Blankycan -----------------------------------------------------------------------------
// File:	Vertex3.h
// Author:	Blankycan
// Date:	2013-08-28
//--------------------------------------------------------------------------------------------------
#ifndef VERTEX3_H
#define VERTEX3_H
//--------------------------------------------------------------------------------------------------

#include "MathLibrary.h"

/*	Vertex3
	A 3D vertex (point), can handle T and double types.
*/
template <class T>
class Vertex3{
public:

	/** Vertex3()
		Default constructor, fills vertex with zeros.*/
	Vertex3<T>();
	/** Vertex3(T, T, T)
		Constructor that takes three T values as x,y,z.*/
	Vertex3<T>(T x, T y, T z);
	/** Vertex3(T[3])
		Constructor that takes a three long T array as x,y,z.*/
	Vertex3(T ver[3]);
	/** Vertex3(Vertex3&)
		Constructor that takes another Vertex3.*/
	Vertex3<T>(const Vertex3<T>& vertex);
	Vertex3<T>(const Vector3<T>& vec);
	Vertex3<T>(const Vertex2<T>& vertex);

	/** coord[3]
		Represent the three coordinates of a vertex, x,y,z.*/
	T coord[3];
	/** operator == (Vertex3& vertex)
		Checks whether all three coordinates are the same.*/
	bool				operator ==	(const Vertex3<T>& vertex);
	/** operator != (Vertex3& vertex)
		Checks whether the three differs.*/
	bool				operator !=	(const Vertex3<T>& vertex);
    
	T operator ()(unsigned char n) const;
	T operator [](unsigned char n) const;
	T& operator ()(unsigned char n);
	T& operator [](unsigned char n);
    
    bool operator <(const Vertex3<T>& vertex);
    bool operator >(const Vertex3<T>& vertex);

	void				add			(const Vertex3<T>& vertex);
	void				operator +=	(const Vertex3<T>& vertex);
	Vertex3<T>			operator +	(const Vertex3<T>& vertex);
	static Vertex3<T>	add			(const Vertex3<T>& vertex1, const Vertex3<T>& vertex2);

	void				sub			(const Vertex3<T>& vertex);
	void				operator -=	(const Vertex3<T>& vertex);
	Vertex3<T>			operator -	(const Vertex3<T>& vertex);
	static Vertex3<T>	sub			(const Vertex3<T>& vertex1, const Vertex3<T>& vertex2);

	void				mult		(const Vertex3<T>& vertex);
	void				operator *=	(const Vertex3<T>& vertex);
	Vertex3<T>			operator *	(const Vertex3<T>& vertex);
	static Vertex3<T>	mult		(const Vertex3<T>& vertex1, const Vertex3<T>& vertex2);
	void				mult		(T value);
	void				operator *=	(T value);
	Vertex3<T>			operator *	(T value);
	static Vertex3<T>	mult		(const Vertex3<T>& vertex, T value);
	static Vertex3<T>	mult		(T value, const Vertex3<T>& vertex);
	//friend Vertex3<T>	operator *	(T value, const Vertex3<T>& vec);

	void				div			(const Vertex3<T>& vertex);
	void				div			(T value);
	void				operator /=	(const Vertex3<T>& vertex);
	void				operator /=	(T value);
	Vertex3<T>			operator /	(const Vertex3<T>& vertex);
	Vertex3<T>			operator /	(T value);
	static Vertex3<T>	div			(const Vertex3<T>& vertex1, const Vertex3<T>& vertex2);
	static Vertex3<T>	div			(const Vertex3<T>& vertex1, T value);
	
	/** vector(Vertex3&, Vertex3&)
		Creates a vector, v1 - v2.*/
	Vector3f			vector		(const Vertex3<T>& v1, const Vertex3<T>& v2);
};


//--------------------------------------------------------------------------------------------------
//	Implementation
//--------------------------------------------------------------------------------------------------

template <class T>
Vertex3<T>::Vertex3(){
	coord[0] = coord[1] = coord[2] = 0;
}
template <class T>
Vertex3<T>::Vertex3(T x, T y, T z){
	coord[0] = x;
	coord[1] = y;
	coord[2] = z;
}
template <class T>
Vertex3<T>::Vertex3(T ver[3]){
	coord[0] = ver[0];
	coord[1] = ver[1];
	coord[2] = ver[2];
}
template <class T>
Vertex3<T>::Vertex3(const Vertex3& vertex){
	coord[0] = vertex.coord[0];
	coord[1] = vertex.coord[1];
	coord[2] = vertex.coord[2];
}
template <class T>
Vertex3<T>::Vertex3(const Vector3<T>& vec){
	coord[0] = (T)vec.coord[0];
	coord[1] = (T)vec.coord[1];
	coord[2] = (T)vec.coord[2];
}
template <class T>
Vertex3<T>::Vertex3(const Vertex2<T>& vec){
	coord[0] = (T)vec.coord[0];
	coord[1] = (T)vec.coord[1];
	coord[2] = (T)0.0;
}

template <class T>
bool Vertex3<T>::operator ==(const Vertex3& vert){
	return (
		coord[0] == vert.coord[0] &&
		coord[1] == vert.coord[1] &&
		coord[2] == vert.coord[2]);
}
template <class T>
bool Vertex3<T>::operator !=(const Vertex3& vert){
	char count = 0;
	if(coord[X] == vert.coord[X])
		++count;
	if(coord[Y] == vert.coord[Y])
		++count;
	if(coord[Z] == vert.coord[Z])
		++count;
	if(count == 3)
		return false;
	return true;
}

template <class T>
T Vertex3<T>::operator ()(unsigned char n) const{
	return coord[n];
}
template <class T>
T Vertex3<T>::operator [](unsigned char n) const{
	return coord[n];
}
template <class T>
T& Vertex3<T>::operator ()(unsigned char n){
	return coord[n];
}
template <class T>
T& Vertex3<T>::operator [](unsigned char n){
	return coord[n];
}

template <class T>
bool Vertex3<T>::operator <(const Vertex3<T>& vertex){
    if(coord[X] > vertex.coord[X])
        return false;
    if(coord[Y] > vertex.coord[Y])
        return false;
    if(coord[Z] > vertex.coord[Z])
        return false;
    return true;
}

template <class T>
bool Vertex3<T>::operator >(const Vertex3<T>& vertex){
    if(coord[X] < vertex.coord[X])
        return false;
    if(coord[Y] < vertex.coord[Y])
        return false;
    if(coord[Z] < vertex.coord[Z])
        return false;
    return true;
}

template <class T>
void Vertex3<T>::add(const Vertex3& vertex){
	coord[0] += vertex.coord[0];
	coord[1] += vertex.coord[1];
	coord[2] += vertex.coord[2];
}
template <class T>
void Vertex3<T>::operator +=(const Vertex3& vertex){
	coord[0] += vertex.coord[0];
	coord[1] += vertex.coord[1];
	coord[2] += vertex.coord[2];
}
template <class T>
Vertex3<T> Vertex3<T>::operator +(const Vertex3& vertex){
	return Vertex3(
		coord[0] + vertex.coord[0],
		coord[1] + vertex.coord[1],
		coord[2] + vertex.coord[2]);
}
template <class T>
Vertex3<T> Vertex3<T>::add(const Vertex3& vertex1, const Vertex3& vertex2){
	return Vertex3(
		vertex1.coord[0] + vertex2.coord[0],
		vertex1.coord[1] + vertex2.coord[1],
		vertex1.coord[2] + vertex2.coord[2]);
}

template <class T>
void Vertex3<T>::sub(const Vertex3& vertex){
	coord[0] -= vertex.coord[0];
	coord[1] -= vertex.coord[1];
	coord[2] -= vertex.coord[2];
}
template <class T>
void Vertex3<T>::operator -=(const Vertex3& vertex){
	coord[0] -= vertex.coord[0];
	coord[1] -= vertex.coord[1];
	coord[2] -= vertex.coord[2];
}
template <class T>
Vertex3<T> Vertex3<T>::operator -(const Vertex3& vertex){
	return Vertex3(
		coord[0] - vertex.coord[0],
		coord[1] - vertex.coord[1],
		coord[2] - vertex.coord[2]);
}
template <class T>
Vertex3<T> Vertex3<T>::sub(const Vertex3& vertex1, const Vertex3& vertex2){
	return Vertex3(
		vertex1.coord[0] - vertex2.coord[0],
		vertex1.coord[1] - vertex2.coord[1],
		vertex1.coord[2] - vertex2.coord[2]);
}

template <class T>
void Vertex3<T>::mult(const Vertex3& vertex){
	coord[0] *= vertex.coord[0];
	coord[1] *= vertex.coord[1];
	coord[2] *= vertex.coord[2];
}
template <class T>
void Vertex3<T>::operator *=(const Vertex3& vertex){
	coord[0] *= vertex.coord[0];
	coord[1] *= vertex.coord[1];
	coord[2] *= vertex.coord[2];
}
template <class T>
Vertex3<T> Vertex3<T>::operator *(const Vertex3& vertex){
	return Vertex3(
		coord[0] * vertex.coord[0],
		coord[1] * vertex.coord[1],
		coord[2] * vertex.coord[2]);
}
template <class T>
Vertex3<T> Vertex3<T>::mult(const Vertex3& vertex1, const Vertex3& vertex2){
	return Vertex3(
		vertex1.coord[0] * vertex2.coord[0],
		vertex1.coord[1] * vertex2.coord[1],
		vertex1.coord[2] * vertex2.coord[2]);
}
template <class T>
void Vertex3<T>::mult(T value){
	coord[0] *= value;
	coord[1] *= value;
	coord[2] *= value;
}
template <class T>
void Vertex3<T>::operator *=(T value){
	coord[0] *= value;
	coord[1] *= value;
	coord[2] *= value;
}
template <class T>
Vertex3<T> Vertex3<T>::operator *(T value){
	return Vertex3(
		coord[0] * value,
		coord[1] * value,
		coord[2] * value);
}
template <class T>
Vertex3<T> Vertex3<T>::mult(const Vertex3& vertex, T value){
	return Vertex3(
		vertex.coord[0] * value,
		vertex.coord[1] * value,
		vertex.coord[2] * value);
}
template <class T>
Vertex3<T> Vertex3<T>::mult(T value, const Vertex3& vertex){
	return Vertex3(
		vertex.coord[0] * value,
		vertex.coord[1] * value,
		vertex.coord[2] * value);
}
template <class T>
Vertex3<T> operator *(T value, const Vertex3<T>& vec){
	return Vertex3<T>(
		vec.coord[0] * value,
		vec.coord[1] * value,
		vec.coord[2] * value);
}

template <class T>
void Vertex3<T>::div(const Vertex3& vertex){
	coord[0] /= vertex.coord[0];
	coord[1] /= vertex.coord[1];
	coord[2] /= vertex.coord[2];
}
template <class T>
void Vertex3<T>::div(T value){
	coord[0] /= value;
	coord[1] /= value;
	coord[2] /= value;
}
template <class T>
void Vertex3<T>::operator /=(const Vertex3& vertex){
	coord[0] /= vertex.coord[0];
	coord[1] /= vertex.coord[1];
	coord[2] /= vertex.coord[2];
}
template <class T>
void Vertex3<T>::operator /=(T value){
	coord[0] /= value;
	coord[1] /= value;
	coord[2] /= value;
}
template <class T>
Vertex3<T> Vertex3<T>::operator /(const Vertex3& vertex){
	return Vertex3(
		coord[0] / vertex.coord[0],
		coord[1] / vertex.coord[1],
		coord[2] / vertex.coord[2]);
}
template <class T>
Vertex3<T> Vertex3<T>::operator /(T value){
	return Vertex3(
		coord[0] / value,
		coord[1] / value,
		coord[2] / value);
}
template <class T>
Vertex3<T> Vertex3<T>::div(const Vertex3& vertex1, const Vertex3& vertex2){
	return Vertex3(
		vertex1.coord[0] / vertex2.coord[0],
		vertex1.coord[1] / vertex2.coord[1],
		vertex1.coord[2] / vertex2.coord[2]);
}
template <class T>
Vertex3<T> Vertex3<T>::div(const Vertex3& vertex1, T value){
	return Vertex3(
		vertex1.coord[0] / value,
		vertex1.coord[1] / value,
		vertex1.coord[2] / value);
}

template <class T>
Vector3f Vertex3<T>::vector(const Vertex3& v1, const Vertex3& v2){
	return Vector3f(v1, v2);
}

#endif