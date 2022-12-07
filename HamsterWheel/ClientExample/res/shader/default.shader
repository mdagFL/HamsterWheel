#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
out vec4 color;
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
	)

	gl_Position = position;
	color = vec4(1.0, 0.0, 0.0, 1.0);
	texCoord = vec2(0, 0);

};

#shader fragment
#version 330 core

in vec4 color;
in vec2 texCoord;

uniform sampler2D tex;

void main()
{
	gl_FragColor = texture(tex, texCoord);

};