// Simple vertex shader for Position + Diffuse + TexCoord
// Compatible with Direct3D 9

float4x4 u_viewProj : register(c0);
float4x4 u_model : register(c4);

struct VS_INPUT
{
    float3 a_position : POSITION;
    float4 a_color0 : COLOR0;
    float2 a_texcoord0 : TEXCOORD0;
};

struct VS_OUTPUT
{
    float4 gl_Position : POSITION;
    float4 v_color0 : COLOR0;
    float2 v_texcoord0 : TEXCOORD0;
};

VS_OUTPUT main(VS_INPUT input)
{
    VS_OUTPUT output;

    float4 pos = float4(input.a_position, 1.0);
    output.gl_Position = mul(u_viewProj, pos);
    output.v_color0 = input.a_color0;
    output.v_texcoord0 = input.a_texcoord0;

    return output;
}
