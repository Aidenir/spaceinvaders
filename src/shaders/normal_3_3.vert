//--------------------------------------------------------------------------------------------------
// File:	normal.vert
// Author:	Blankycan
// Date:	2013-05-08
//--------------------------------------------------------------------------------------------------
#version 330

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform vec3 ratio;

layout(location = 0) in vec3 in_Position;
layout(location = 1) in vec2 in_uvCoord;
layout(location = 2) in vec3 in_Normal;

out vec4 gl_Position;
out vec3 pass_position;
out vec2 pass_TexCoord;
out vec3 pass_Normal;
out vec3 pass_WorldPos;

void main(){
	mat4 MVP = projectionMatrix * viewMatrix * modelMatrix;
    vec4 position = vec4(in_Position, 1.0);
	gl_Position = MVP * position;
	pass_position = vec3(gl_Position);
    pass_WorldPos = vec3(modelMatrix * position);

    mat4 normalMatrix = transpose(inverse(modelMatrix));
    pass_Normal = normalize(mat3(normalMatrix) * in_Normal);

	pass_TexCoord = in_uvCoord;
}