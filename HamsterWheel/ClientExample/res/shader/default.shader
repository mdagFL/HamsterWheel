#shader vertex
#version 330 core
precision mediump float;
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 inTexCoord;
out vec2 texCoord;

uniform vec3 worldPos;
uniform vec3 worldRot;
uniform mat4 projectionMatrix;

uniform vec3 viewTranslate;
uniform vec3 modelTranslate;

void main()
{
	// model matrix
	mat4 modelMatrix;
	mat4 positionTransformation = mat4
	(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		modelTranslate.x, modelTranslate.y, modelTranslate.z, 1
	);


	mat4 viewTranslateMatrix = mat4
	(
		1.0, 0, 0, 0,
		0, 1.0, 0, 0,
		0, 0, 1.0, 0,
		-worldPos.x, -worldPos.y, -worldPos.z, 1.0
	);

	mat4 testProjectionMatrix = mat4
	(
		2.0 / 720.0, 0, 0, 0,
		0, 2.0 / 480.0, 0, 0,
		0, 0,   0, 0,
		-1.0, 1.0,   1.0, 1.0
	);

	gl_Position = testProjectionMatrix * viewTranslateMatrix * positionTransformation * vec4(position, 1.0);
	//gl_Position = vec4(position, 1.0);
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