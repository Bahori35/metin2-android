$input a_position, a_normal
$output v_color0, v_texcoord0, v_texcoord1

#include <bgfx_shader.sh>

uniform mat4 u_texTransform0;
uniform mat4 u_texTransform1;

void main()
{
	// Transform vertex position to world space
	vec4 worldPos = mul(u_model[0], vec4(a_position, 1.0));

	// Transform to clip space
	gl_Position = mul(u_viewProj, worldPos);

	// For terrain: apply texture transforms directly to world position
	// The texture transform matrices (from D3DTS_TEXTURE0/1) already include
	// ViewInverse in them, so they work with world-space positions, not camera-space
	vec4 texCoord0_4d = mul(u_texTransform0, worldPos);
	vec4 texCoord1_4d = mul(u_texTransform1, worldPos);

	v_texcoord0 = texCoord0_4d.xy;
	v_texcoord1 = texCoord1_4d.xy;

	// Pass through vertex color (white if not provided)
	v_color0 = vec4(1.0, 1.0, 1.0, 1.0);
}
