#version 330 core
layout(location = 0) in vec2 vertex;

out vec2 TextureCoordinates;

uniform mat4 projection;
uniform mat4 model;

void main()
{
	TextureCoordinates = vertex.xy;
	gl_Position = projection * model * vec4(vertex.xy, 0.0f, 1.0f);
}