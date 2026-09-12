$input v_normal, v_texcoord0, v_worldPos

#include <bgfx_shader.sh>
#include "texture_stage.sh"

SAMPLER2D(s_texColor, 0);

uniform vec4 u_lightPos[8];
uniform vec4 u_lightColor[8];
uniform vec4 u_lightParams[8];
uniform vec4 u_globalAmbient;
uniform vec4 u_diffuseColor;
uniform vec4 u_ambientColor;
uniform vec4 u_emissiveColor;
uniform vec4 u_alphaTest;

void main()
{
	vec4 texColor = texture2D(s_texColor, v_texcoord0);

	if (u_alphaTest.y > 0.5)
	{
		float ref = u_alphaTest.x;
		float func = u_alphaTest.z;
		float result = 1.0;

		if (func < 0.5)
		{
			result = 1.0;
		}
		else if (func < 1.5)
		{
			result = texColor.a > ref ? 1.0 : 0.0;
		}
		else if (func < 2.5)
		{
			result = texColor.a >= ref ? 1.0 : 0.0;
		}
		else if (func < 3.5)
		{
			result = texColor.a < ref ? 1.0 : 0.0;
		}
		else if (func < 4.5)
		{
			result = texColor.a <= ref ? 1.0 : 0.0;
		}
		else if (func < 5.5)
		{
			result = abs(texColor.a - ref) < 1.0 / 255.0 ? 1.0 : 0.0;
		}
		else if (func < 6.5)
		{
			result = abs(texColor.a - ref) >= 1.0 / 255.0 ? 1.0 : 0.0;
		}
		else
		{
			result = 0.0;
		}

		if (result < 0.5)
		{
			discard;
		}
	}

	vec3 normal = normalize(v_normal);
	vec3 lighting = u_ambientColor.rgb + u_globalAmbient.rgb;

	for (int i = 0; i < 8; ++i)
	{
		if (u_lightColor[i].a <= 0.0)
			continue;

		vec3 lightDir;
		float attenuation = 1.0;

		if (u_lightPos[i].w < 0.5)
		{
			lightDir = normalize(u_lightPos[i].xyz);
		}
		else
		{
			vec3 toLight = u_lightPos[i].xyz - v_worldPos;
			float dist = length(toLight);
			if (dist > 0.0001)
				lightDir = toLight / dist;
			else
				lightDir = vec3(0.0, 0.0, 1.0);

			float denom = u_lightParams[i].x + u_lightParams[i].y * dist + u_lightParams[i].z * dist * dist;
			if (denom > 0.0)
				attenuation = 1.0 / denom;
		}

		float ndotl = max(dot(normal, normalize(lightDir)), 0.0);
		lighting += u_lightColor[i].rgb * ndotl * attenuation;
	}

	vec3 litColor = lighting * u_diffuseColor.rgb + u_emissiveColor.rgb;
	vec4 vertexColor = vec4(clamp(litColor, vec3(0.0), vec3(1.0)), clamp(u_diffuseColor.a, 0.0, 1.0));
	gl_FragColor = applyTextureStage(texColor, vertexColor);
}
