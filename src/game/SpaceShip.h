/* /////////////////////////////////////////////////////////////////////
//	File:		SpaceShip.h
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#ifndef SPACESHIP_H
#define SPACESHIP_H
////////////////////////////////////////////////////////////////////////
// Application includes
#include "MathLibrary.h"
#include "Mesh.h"
////////////////////////////////////////////////////////////////////////

class SpaceShip
{
public:
	/**	Constructor. */
	SpaceShip(GLuint meshId);
	/**	Destructor. */
	~SpaceShip();
	/**	Sets the spaceship's position. */
	void SetPosition(const Vector2f &pos) { this->pos = pos; }
	/**	Returns the spaceship's position. */
	Vector2f GetPosition() { return pos; }
	/** Adds movement to spaceship's position. */
	void AddMovement(const Vector2f &movement) { this->pos += movement; }
	/** Returns mesh ID. */
	GLuint GetMeshId() { return meshId; }

private:
	///	Position of the spaceship
	Vector2f pos;
	/// ID of the mesh of the spaceship
	GLuint meshId;
};

////////////////////////////////////////////////////////////////////////
#endif	// SPACESHIP_H
////////////////////////////////////////////////////////////////////////