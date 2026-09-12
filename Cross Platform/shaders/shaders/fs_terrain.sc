$input v_color0, v_texcoord0, v_texcoord1

#include <bgfx_shader.sh>

SAMPLER2D(s_texColor, 0);   // Stage 0: Splat color texture
SAMPLER2D(s_texture1, 1);   // Stage 1: Splat alpha mask

void main()
{
	// Sample both texture stages
	vec4 colorTex = texture2D(s_texColor, v_texcoord0);
	vec4 alphaTex = texture2D(s_texture1, v_texcoord1);

	// Terrain splat blending: color texture modulated by alpha mask
	// Stage 0: Base color texture
	// Stage 1: Alpha mask that controls blending between different terrain textures
	vec4 finalColor = colorTex;
	finalColor.a *= alphaTex.a;

	// Apply vertex color (usually white for terrain)
	gl_FragColor = finalColor * v_color0;
}
