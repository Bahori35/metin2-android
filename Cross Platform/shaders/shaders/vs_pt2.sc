$input a_position, a_texcoord0
$output v_texcoord0, v_texcoord1

#include <bgfx_shader.sh>

uniform mat4 u_texTransform1;

void main()
{
	gl_Position = mul(u_viewProj, vec4(a_position, 1.0));

	// Stage 0: Pass through original texture coordinates
	v_texcoord0 = a_texcoord0;

	// Stage 1: Generate texture coordinates using transform matrix
	// For minimap, this applies the filter overlay transform
	vec4 worldPos = mul(u_model[0], vec4(a_position, 1.0));
	vec4 texCoord1_4d = mul(u_texTransform1, worldPos);
	v_texcoord1 = texCoord1_4d.xy;
}
