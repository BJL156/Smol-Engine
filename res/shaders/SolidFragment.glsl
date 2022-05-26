#version 330 core

out vec4 Color;

uniform vec4 Tint;
uniform sampler2D image;

void main()
{
	Color = Tint;
}