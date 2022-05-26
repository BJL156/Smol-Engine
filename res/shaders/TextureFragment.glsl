#version 330 core

in vec2 TextureCoordinates;

out vec4 Color;

uniform vec4 Tint;
uniform sampler2D image;

void main()
{
	Color = Tint * texture(image, TextureCoordinates);
}