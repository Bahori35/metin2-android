#ifndef TEXTURE_STAGE_INCLUDED
#define TEXTURE_STAGE_INCLUDED

uniform vec4 u_textureFactor;
uniform vec4 u_stageColor;
uniform vec4 u_stageAlpha;
uniform vec4 u_stageColorFlags;
uniform vec4 u_stageAlphaFlags;

vec4 applyColorArgFlags(vec4 value, vec2 flags)
{
	vec4 result = value;
	if (flags.y > 0.5)
	{
		result.rgb = vec3(result.a);
	}
	if (flags.x > 0.5)
	{
		result = vec4(1.0) - result;
	}
	return result;
}

float applyAlphaFlags(float value, float complementFlag)
{
	return (complementFlag > 0.5) ? (1.0 - value) : value;
}

vec4 fetchColorArg(float selector, vec4 texColor, vec4 vertexColor, vec4 currentColor)
{
	if (selector < 0.5)
		return texColor;
	else if (selector < 1.5)
		return vertexColor;
	else if (selector < 2.5)
		return currentColor;
	else if (selector < 3.5)
		return u_textureFactor;
	else
		return vertexColor;
}

float fetchAlphaArg(float selector, float texAlpha, float vertexAlpha, float currentAlpha)
{
	if (selector < 0.5)
		return texAlpha;
	else if (selector < 1.5)
		return vertexAlpha;
	else if (selector < 2.5)
		return currentAlpha;
	else if (selector < 3.5)
		return u_textureFactor.a;
	else
		return vertexAlpha;
}

vec4 evaluateColorOp(float op, vec4 arg1, vec4 arg2, vec4 currentColor)
{
	if (op < 0.5)
		return currentColor;
	else if (op < 1.5)
		return arg1;
	else if (op < 2.5)
		return arg2;
	else if (op < 3.5)
		return arg1 * arg2;
	else if (op < 4.5)
		return min(arg1 * arg2 * 2.0, vec4(1.0));
	else if (op < 5.5)
		return min(arg1 * arg2 * 4.0, vec4(1.0));
	else if (op < 6.5)
		return min(arg1 + arg2, vec4(1.0));
	else if (op < 7.5)
		return clamp(arg1 + arg2 - 0.5, 0.0, 1.0);
	else if (op < 8.5)
		return clamp((arg1 + arg2 - 0.5) * 2.0, 0.0, 1.0);
	else if (op < 9.5)
		return clamp(arg1 - arg2, 0.0, 1.0);
	else
		return arg1 * arg2;
}

float evaluateAlphaOp(float op, float arg1, float arg2, float currentAlpha)
{
	if (op < 0.5)
		return currentAlpha;
	else if (op < 1.5)
		return arg1;
	else if (op < 2.5)
		return arg2;
	else if (op < 3.5)
		return arg1 * arg2;
	else if (op < 4.5)
		return min(arg1 * arg2 * 2.0, 1.0);
	else if (op < 5.5)
		return min(arg1 * arg2 * 4.0, 1.0);
	else if (op < 6.5)
		return min(arg1 + arg2, 1.0);
	else if (op < 7.5)
		return clamp(arg1 + arg2 - 0.5, 0.0, 1.0);
	else if (op < 8.5)
		return clamp((arg1 + arg2 - 0.5) * 2.0, 0.0, 1.0);
	else if (op < 9.5)
		return clamp(arg1 - arg2, 0.0, 1.0);
	else
		return arg1 * arg2;
}

vec4 applyTextureStage(vec4 texColor, vec4 vertexColor)
{
	vec4 currentColor = vertexColor;
	vec4 arg1 = fetchColorArg(u_stageColor.y, texColor, vertexColor, currentColor);
	arg1 = applyColorArgFlags(arg1, u_stageColorFlags.xy);
	vec4 arg2 = fetchColorArg(u_stageColor.z, texColor, vertexColor, currentColor);
	arg2 = applyColorArgFlags(arg2, u_stageColorFlags.zw);
	vec4 colorOut = evaluateColorOp(u_stageColor.x, arg1, arg2, currentColor);

	float alphaArg1 = fetchAlphaArg(u_stageAlpha.y, texColor.a, vertexColor.a, currentColor.a);
	alphaArg1 = applyAlphaFlags(alphaArg1, u_stageAlphaFlags.x);
	float alphaArg2 = fetchAlphaArg(u_stageAlpha.z, texColor.a, vertexColor.a, currentColor.a);
	alphaArg2 = applyAlphaFlags(alphaArg2, u_stageAlphaFlags.z);
	float alphaOut = evaluateAlphaOp(u_stageAlpha.x, alphaArg1, alphaArg2, currentColor.a);

	colorOut.a = alphaOut;
	return colorOut;
}

#endif // TEXTURE_STAGE_INCLUDED
