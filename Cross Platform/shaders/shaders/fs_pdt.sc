$input v_color0, v_texcoord0

#include <bgfx_shader.sh>
#include "texture_stage.sh"

SAMPLER2D(s_texColor, 0);
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
			result = 1.0; // ALWAYS
		}
		else if (func < 1.5)
		{
			result = texColor.a > ref ? 1.0 : 0.0; // GREATER
		}
		else if (func < 2.5)
		{
			result = texColor.a >= ref ? 1.0 : 0.0; // GREATEREQUAL
		}
		else if (func < 3.5)
		{
			result = texColor.a < ref ? 1.0 : 0.0; // LESS
		}
		else if (func < 4.5)
		{
			result = texColor.a <= ref ? 1.0 : 0.0; // LESSEQUAL
		}
		else if (func < 5.5)
		{
			result = abs(texColor.a - ref) < 1.0/255.0 ? 1.0 : 0.0; // EQUAL
		}
		else if (func < 6.5)
		{
			result = abs(texColor.a - ref) >= 1.0/255.0 ? 1.0 : 0.0; // NOTEQUAL
		}
		else if (func < 7.5)
		{
			result = 0.0; // NEVER
		}

		if (result < 0.5)
		{
			discard;
		}
	}

	gl_FragColor = applyTextureStage(texColor, v_color0);
}
