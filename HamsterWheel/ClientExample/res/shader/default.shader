#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 inTexCoord;
out vec2 texCoord;

uniform vec2 res;

uniform vec3 pos;
uniform float rotY;

uniform vec3 worldPos;
uniform float worldRotY;

void main()
{
	// model matrix
	mat4 modelMatrix;
	mat4 positionTransformation = mat4
	(
		1, 0, 0, pos.x,
		0, 1, 0, pos.y,
		0, 0, 1, pos.z,
		0, 0, 0, 1
	);

	gl_Position = vec4(position, 1.0);//position;
	texCoord = inTexCoord;

};

#shader fragment
#version 330 core
precision mediump float;
in vec2 texCoord;

uniform sampler2D tex;

void main()
{

	vec4 texColor = texture(tex, texCoord);
	gl_FragColor = texColor;
	//gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);

};