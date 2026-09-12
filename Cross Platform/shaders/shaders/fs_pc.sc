$input v_color0

#include <bgfx_shader.sh>
#include "texture_stage.sh"

void main()
{
	vec4 texColor = vec4(1.0, 1.0, 1.0, 1.0);
	gl_FragColor = applyTextureStage(texColor, v_color0);
}
