#shader vertex
#version 330 core

attribute vec4 position;
varying vec4 color;

void main()
{
	gl_Position = position;
	color = vec4(1.0, 0.0, 0.0, 1.0);

};

#shader fragment
#version 330 core

varying vec4 color;

void main()
{
	gl_FragColor = color;

};