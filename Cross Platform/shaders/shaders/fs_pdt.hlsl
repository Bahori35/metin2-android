// Simple pixel shader for Position + Diffuse + TexCoord
// Compatible with Direct3D 9

sampler2D s_texColor : register(s0);

struct PS_INPUT
{
    float4 v_color0 : COLOR0;
    float2 v_texcoord0 : TEXCOORD0;
};

float4 main(PS_INPUT input) : COLOR0
{
    float4 texColor = tex2D(s_texColor, input.v_texcoord0);
    return texColor * input.v_color0;
}
