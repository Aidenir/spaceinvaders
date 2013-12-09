//--- � 2013 Blankycan -----------------------------------------------------------------------------
// File:	Vertex2.h
// Author:	Blankycan
// Date:	2013-08-27
//--------------------------------------------------------------------------------------------------
#ifndef Vertex2_H
#define Vertex2_H
//--------------------------------------------------------------------------------------------------

/*	Vertex2
	A 2D vertex (point), can work with float and double types.
*/
template <class T>
class Vertex2{
public:

	/** Vertex2()
		Default constructor, fills vertex with zeros.*/
	Vertex2();
	/** Vertex2(T, T)
		Constructor that takes two T values as x,y.*/
	Vertex2(T x, T y);
	/** Vertex2(T[2])
		Constructor that takes a three long T array as x,y,z.*/
	Vertex2(T ver[2]);
	/** Vertex2(Vertex2<T>&)
		Constructor that takes another Vertex2.*/
	Vertex2(const Vertex2<T>& vertex);

	/** coord[2]
		Represent the two coordinates of a vertex, x,y.*/
	T coord[2];
	/** operator == (Vertex2<T>& vertex)
		Checks whether both coordinates are the same.*/
	bool				operator ==	(const Vertex2<T>& vertex);
	/** operator != (Vertex2<T>& vertex)
		Checks whether coordinates differs.*/
	bool				operator !=	(const Vertex2<T>& vertex);

	T operator ()(unsigned char n) const;
	T operator [](unsigned char n) const;
	T& operator ()(unsigned char n);
	T& operator [](unsigned char n);
    
	void				add			(const Vertex2<T>& vertex);
	void				operator +=	(const Vertex2<T>& vertex);
	Vertex2<T>			operator +	(const Vertex2<T>& vertex);
	static Vertex2<T>	add			(const Vertex2<T>& vertex1, const Vertex2<T>& vertex2);

	void				sub			(const Vertex2<T>& vertex);
	void				operator -=	(const Vertex2<T>& vertex);
	Vertex2<T>			operator -	(const Vertex2<T>& vertex);
	static Vertex2<T>	sub			(const Vertex2<T>& vertex1, const Vertex2<T>& vertex2);

	void				mult		(const Vertex2<T>& vertex);
	void				mult		(T value);
	void				operator *=	(const Vertex2<T>& vertex);
	void				operator *=	(T value);
	Vertex2<T>			operator *	(const Vertex2<T>& vertex);
	Vertex2<T>			operator *	(T value);
	static Vertex2<T>	mult		(const Vertex2<T>& vertex1, const Vertex2<T>& vertex2);
	static Vertex2<T>	mult		(const Vertex2<T>& vertex1, T value);

	void				div			(const Vertex2<T>& vertex);
	void				div			(T value);
	void				operator /=	(const Vertex2<T>& vertex);
	void				operator /=	(T value);
	Vertex2<T>			operator /	(const Vertex2<T>& vertex);
	Vertex2<T>			operator /	(T value);
	static Vertex2<T>	div			(const Vertex2<T>& vertex1, const Vertex2<T>& vertex2);
	static Vertex2<T>	div			(const Vertex2<T>& vertex1, T value);
	
};


//--------------------------------------------------------------------------------------------------
//	Implementation
//--------------------------------------------------------------------------------------------------

template <class T>
Vertex2<T>::Vertex2(){
	coord[0] = coord[1] = T(0);
}
template <class T>
Vertex2<T>::Vertex2(T x, T y){
	coord[0] = x;
	coord[1] = y;
}
template <class T>
Vertex2<T>::Vertex2(T ver[2]){
	coord[0] = ver[0];
	coord[1] = ver[1];
}
template <class T>
Vertex2<T>::Vertex2(const Vertex2& vertex){
	coord[0] = vertex.coord[0];
	coord[1] = vertex.coord[1];
}

template <class T>
bool Vertex2<T>::operator ==(const Vertex2& vert){
	return (
		coord[0] == vert.coord[0] &&
		coord[1] == vert.coord[1]);
}
template <class T>
bool Vertex2<T>::operator !=(const Vertex2& vert){
	char count = 0;
	if(coord[0] == vert.coord[0])
		++count;
	if(coord[1] == vert.coord[1])
		++count;
	if(count == 2)
		return false;
	return true;
}

template <class T>
T Vertex2<T>::operator ()(unsigned char n) const{
	return coord[n];
}
template <class T>
T Vertex2<T>::operator [](unsigned char n) const{
	return coord[n];
}
template <class T>
T& Vertex2<T>::operator ()(unsigned char n){
	return coord[n];
}
template <class T>
T& Vertex2<T>::operator [](unsigned char n){
	return coord[n];
}

template <class T>
void Vertex2<T>::add(const Vertex2& vertex){
	coord[0] += vertex.coord[0];
	coord[1] += vertex.coord[1];
}
template <class T>
void Vertex2<T>::operator +=(const Vertex2& vertex){
	coord[0] += vertex.coord[0];
	coord[1] += vertex.coord[1];
}
template <class T>
Vertex2<T> Vertex2<T>::operator +(const Vertex2& vertex){
	return Vertex2(
		coord[0] + vertex.coord[0],
		coord[1] + vertex.coord[1]);
}
template <class T>
Vertex2<T> Vertex2<T>::add(const Vertex2& vertex1, const Vertex2& vertex2){
	return Vertex2(
		vertex1.coord[0] += vertex2.coord[0],
		vertex1.coord[1] += vertex2.coord[1]);
}

template <class T>
void Vertex2<T>::sub(const Vertex2& vertex){
	coord[0] -= vertex.coord[0];
	coord[1] -= vertex.coord[1];
}
template <class T>
void Vertex2<T>::operator -=(const Vertex2& vertex){
	coord[0] -= vertex.coord[0];
	coord[1] -= vertex.coord[1];
}
template <class T>
Vertex2<T> Vertex2<T>::operator -(const Vertex2& vertex){
	return Vertex2(
		coord[0] - vertex.coord[0],
		coord[1] - vertex.coord[1]);
}
template <class T>
Vertex2<T> Vertex2<T>::sub(const Vertex2& vertex1, const Vertex2& vertex2){
	return Vertex2(
		vertex1.coord[0] -= vertex2.coord[0],
		vertex1.coord[1] -= vertex2.coord[1]);
}

template <class T>
void Vertex2<T>::mult(const Vertex2& vertex){
	coord[0] *= vertex.coord[0];
	coord[1] *= vertex.coord[1];
}
template <class T>
void Vertex2<T>::mult(T value){
	coord[0] *= value;
	coord[1] *= value;
}
template <class T>
void Vertex2<T>::operator *=(const Vertex2& vertex){
	coord[0] *= vertex.coord[0];
	coord[1] *= vertex.coord[1];
}
template <class T>
void Vertex2<T>::operator *=(T value){
	coord[0] *= value;
	coord[1] *= value;
}
template <class T>
Vertex2<T> Vertex2<T>::operator *(const Vertex2& vertex){
	return Vertex2(
		coord[0] * vertex.coord[0],
		coord[1] * vertex.coord[1]);
}
template <class T>
Vertex2<T> Vertex2<T>::operator *(T value){
	return Vertex2(
		coord[0] * value,
		coord[1] * value);
}
template <class T>
Vertex2<T> Vertex2<T>::mult(const Vertex2& vertex1, const Vertex2& vertex2){
	return Vertex2(
		vertex1.coord[0] * vertex2.coord[0],
		vertex1.coord[1] * vertex2.coord[1]);
}
template <class T>
Vertex2<T> Vertex2<T>::mult(const Vertex2& vertex1, T value){
	return Vertex2(
		vertex1.coord[0] * value,
		vertex1.coord[1] * value);
}

template <class T>
void Vertex2<T>::div(const Vertex2& vertex){
	coord[0] /= vertex.coord[0];
	coord[1] /= vertex.coord[1];
}
template <class T>
void Vertex2<T>::div(T value){
	coord[0] /= value;
	coord[1] /= value;
}
template <class T>
void Vertex2<T>::operator /=(const Vertex2& vertex){
	coord[0] /= vertex.coord[0];
	coord[1] /= vertex.coord[1];
}
template <class T>
void Vertex2<T>::operator /=(T value){
	coord[0] /= value;
	coord[1] /= value;
}
template <class T>
Vertex2<T> Vertex2<T>::operator /(const Vertex2& vertex){
	return Vertex2(
		coord[0] / vertex.coord[0],
		coord[1] / vertex.coord[1]);
}
template <class T>
Vertex2<T> Vertex2<T>::operator /(T value){
	return Vertex2(
		coord[0] / value,
		coord[1] / value);
}
template <class T>
Vertex2<T> Vertex2<T>::div(const Vertex2& vertex1, const Vertex2& vertex2){
	return Vertex2(
		vertex1.coord[0] / vertex2.coord[0],
		vertex1.coord[1] / vertex2.coord[1]);
}
template <class T>
Vertex2<T> Vertex2<T>::div(const Vertex2& vertex1, T value){
	return Vertex2(
		vertex1.coord[0] / value,
		vertex1.coord[1] / value);
}

//--------------------------------------------------------------------------------------------------
#endif