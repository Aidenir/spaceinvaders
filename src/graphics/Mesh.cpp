/* /////////////////////////////////////////////////////////////////////
//	File:		Mesh.cpp
//	Author		Blankycan
// Copyright 2013 Blankycan
///////////////////////////////////////////////////////////////////// */
#include "Mesh.h"
// Application includes
#include "GraphicsManager.h"
#include "ShaderManager.h"
////////////////////////////////////////////////////////////////////////

Mesh::Mesh(){
	this->vao = -1;
	this->vbo = -1;
	this->tbo = -1;
	this->nbo = -1;
	this->vboVertexCount = 0;
	this->name = NULL;
	this->width = 0.1f;
	this->height = 0.1f;
    this->depth = 0;
	color[0] = 0.5f;
	color[1] = 0.5f;
	color[2] = 0.5f;
	color[3] = 1.0f;
	hasColor = false;
    aabbId = -1;
    intersectable = false;
    type = MESH_TYPE_NULL;
}
Mesh::Mesh(GLuint vao, GLuint vbo, GLuint tbo, GLuint nbo){
	this->vao = vao;
	this->vbo = vbo;
	this->tbo = tbo;
	this->nbo = nbo;
	this->vboVertexCount = 0;
	this->name = NULL;
	this->width = 0;
	this->height = 0;
    this->depth = 0;
	color[0] = 0.5f;
	color[1] = 0.5f;
	color[2] = 0.5f;
	color[3] = 1.0f;
	hasColor = false;
	textureIndex = -1;
    aabbId = -1;
    intersectable = false;
    type = MESH_TYPE_NULL;
}
Mesh::Mesh(GLuint vao, GLuint vbo, GLuint tbo, GLuint nbo, float width, float height){
	this->vao = vao;
	this->vbo = vbo;
	this->tbo = tbo;
	this->nbo = nbo;
	this->vboVertexCount = 0;
	this->name = NULL;
	this->width = width;
	this->height = height;
    this->depth = 0;
	color[0] = 0.5f;
	color[1] = 0.5f;
	color[2] = 0.5f;
	color[3] = 1.0f;
	hasColor = false;
	textureIndex = -1;
    aabbId = -1;
    intersectable = false;
    type = MESH_TYPE_NULL;
}
Mesh::~Mesh(){
	if(name)
		delete[] name;
}

void Mesh::Render(RenderState* renderState)
{
	if(tbo >= 0 && textureIndex != -1){
		//glColor4ub(255, 255, 255, 255);
		//glTexImage2D(GL_TEXTURE_2D, 0, 4, graphics->textures[textureIndex]->u2, graphics->textures[textureIndex]->v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &graphics->textures[textureIndex]->image[0]);
		//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
		//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		// Set texture
		//Shader *shader = shaderMan->GetShader(SHADER_NORMAL);
		//glProgramUniform1i(shader->program, renderState->handleTexture, textureIndex);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, graphics->textures[textureIndex]->id);
		glUniform1i(renderState->handleTexture, 0);
	}
	if(vao >= 0){
		//glBindVertexArray(renderState->vertexArrayObjects[vao]);
		// Vertices
		if(vbo >= 0){
			glBindBuffer(GL_ARRAY_BUFFER, renderState->vertexBufferObjects[vbo]);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		}

		// Texture / Color
		if(tbo >= 0 && textureIndex != -1){
			glUniform1i(renderState->handleVisualMode, GLuint(2));
			// Set texture
			/*
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, graphics->textures[textureIndex]->id);
			glUniform1i(graphics->textures[textureIndex]->id, 0);*/
			// Enter texture coordinates
			glBindBuffer(GL_ARRAY_BUFFER, renderState->textureBufferObjects[tbo]);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
		}
		else if(hasColor){
			glUniform1i(renderState->handleVisualMode, GLuint(1));
			glUniform4fv(renderState->handleColor, 1, color.getContent());
		}
		else{
			glUniform1i(renderState->handleVisualMode, GLuint(0));
		}

		// Normals
		if(nbo >= 0){
			glBindBuffer(GL_ARRAY_BUFFER, renderState->normalBufferObjects[nbo]);
			glEnableVertexAttribArray(2);
			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
		}

		//glBindVertexArray(renderState->vertexArrayObjects[vao]);
		glDrawArrays(GL_TRIANGLES, 0, vboVertexCount);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, NULL);
	}
}