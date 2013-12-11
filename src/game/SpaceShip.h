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
#include "RenderState.h"
////////////////////////////////////////////////////////////////////////
#define MAX_LASERS			128
////////////////////////////////////////////////////////////////////////

struct Laser
{
	Laser(GLuint meshID, GLuint texID, const Vector2f &pos, const Vector2f &vel)
	{
		this->meshID = meshID;
		this->texID = texID;
		this->pos = pos;
		this->vel = vel;
	}
	GLuint meshID, texID;
	Vector2f pos;
	Vector2f vel;
};

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
	/**	Fire laser. */
	void Fire();
	/** Render spaceship and lasers. */
	void Render(RenderState *renderState);
	/**	Update all lasers. */
	void Update(float dt);

private:
	///	Position of the spaceship
	Vector2f pos;
	/// Fire velocity
	Vector2f fireVelocity;
	/// ID of the mesh of the spaceship
	GLuint meshId;
	/// Laser mesh ID
	GLuint laserID;
	/// Laser texture ID
	GLuint laserTexID;
	/// Laser array
	Laser *lasers[MAX_LASERS];
	/// Amount used lasers
	int laserAmount;
};

////////////////////////////////////////////////////////////////////////
#endif	// SPACESHIP_H
////////////////////////////////////////////////////////////////////////