//vertex shader code 

#version 330 core 
 
in vec3 positionIn; 
in vec3 colorIn;
in vec3 normalIn;
in vec2 textureIn;
in vec3 tangentIn;
in vec3 bitangentIn;

out vec3 positionOut;
out vec3 colorOut;
out vec3 normalOut;
out vec2 textureOut;

out mat3 TBN;

uniform mat4 modelIn;
uniform mat4 viewIn;
uniform mat4 worldIn;

void main(void) 
{
	positionOut = positionIn;
	colorOut	= colorIn;
	normalOut	= normalIn;
	textureOut	= textureIn;

	vec3 T = normalize(vec3(modelIn * vec4(tangentIn,   0.0)));
    vec3 B = normalize(vec3(modelIn * vec4(bitangentIn, 0.0)));
    vec3 N = normalize(vec3(modelIn * vec4(normalIn,    0.0)));

    TBN = transpose(mat3(T, B, N));

	gl_Position = worldIn * viewIn * modelIn * vec4(positionIn, 1.0);
}