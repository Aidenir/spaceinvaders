//--------------------------------------------------------------------------------------------------
// File:	normal.frag
// Author:	Blankycan
// Date:	2013-05-08
//--------------------------------------------------------------------------------------------------
#version 330

// Uniform values
uniform int			in_visualMode;		// Determines if using color or texture etc.
uniform sampler2D	in_texture;
uniform vec4		in_color;

// Values passed from vertex shader
in		vec3		pass_position;
in      vec3        pass_Normal;
in		vec2		pass_TexCoord;
in      vec3        pass_WorldPos;

// Values going out from fragment shader
out		vec4		fragColor;

void main(){
    vec3 L = normalize(vec3(0, 10000, 0) - pass_WorldPos); // Light position
    //vec3 E = normalize(vec3(0, 1, 0)); // Eye position
    //vec3 R = normalize(-reflect(L, pass_Normal));
    float NdotL = dot(pass_Normal, L);



	int mode = in_visualMode;
    vec4 ambi = vec4(1.0, 1.0, 0.0, 1.0);
    vec4 diff = vec4(0.3, 0.3, 0.3, 1.0) * max(NdotL, 0.0);
    //vec4 spec = vec4(0.3, 0.3, 0.3, 1.0) * pow(max(dot(R, E), 0.0), 0.3);

	// No mode, radiant
	if(mode == 0)
	{
		ambi = vec4(normalize(pass_position), 1);
		ambi.z = ambi.y * 1.5 + ambi.x * 0.5;
		ambi.y = 0.8 - ambi.z;
		ambi.x = 1.2 - ambi.y - ambi.z;
		ambi.y = ambi.y / 10.0f;
		ambi = normalize(ambi)* 1.5;
	}
	
	// Color mode
	else if(mode == 1)
	{
		ambi = in_color;
	}

	// Texture mode
	else if(mode == 2)
	{
		ambi = texture(in_texture, pass_TexCoord);
		if(ambi.rgb == vec3(1.0, 0.0, 1.0))
			ambi = vec4(0, 0, 0, 0);
		else
			ambi.rgb *= vec3(1, 1, 1);
	}

	// Missing Texture
	else
	{
		ambi = vec4(1.f, 0.f, 1.f, 1.f);
	}

	// Set the final fragment color
	fragColor = ambi + diff;// + spec;
}