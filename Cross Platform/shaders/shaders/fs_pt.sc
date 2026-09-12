$input v_texcoord0

#include <bgfx_shader.sh>
#include "texture_stage.sh"

SAMPLER2D(s_texColor, 0);

void main()
{
	vec4 texColor = texture2D(s_texColor, v_texcoord0);
	vec4 vertexColor = vec4(1.0, 1.0, 1.0, 1.0);
	gl_FragColor = applyTextureStage(texColor, vertexColor);
}
