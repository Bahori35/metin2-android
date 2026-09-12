$input v_texcoord0, v_texcoord1

#include <bgfx_shader.sh>
#include "texture_stage.sh"

SAMPLER2D(s_texColor, 0);   // Stage 0: Minimap terrain texture
SAMPLER2D(s_texture1, 1);   // Stage 1: Filter overlay texture

void main()
{
	// Sample both textures
	vec4 texColor0 = texture2D(s_texColor, v_texcoord0);
	vec4 texColor1 = texture2D(s_texture1, v_texcoord1);

	// Modulate the textures (stage 0 * stage 1)
	// This matches D3D9 behavior: D3DTOP_MODULATE on stage 1
	vec4 finalColor = texColor0 * texColor1;

	// Apply texture stage states (for alpha operations)
	vec4 vertexColor = vec4(1.0, 1.0, 1.0, 1.0);
	gl_FragColor = applyTextureStage(finalColor, vertexColor);
}
