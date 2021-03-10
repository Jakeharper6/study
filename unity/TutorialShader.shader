Shader "Unlit/TutorialShader"
{
    Properties{
        _Color("Totally Rad Color", Color) = (1, 1, 1, 1)
        _MainTexture("Main Texture", 2D) = "white"{}
    }

    SubShader{
        Pass{
            //Tags{""}

            CGPROGRAM

            #pragma vertex vertexfunction
            #pragma fragment fragmentfunction
            #include "UnityCG.cginc"

            struct a2v{
                float4 vertex : POSITION;
                float2 uv : TEXCOORD0;
            };

            struct v2f{
                float4 position : SV_POSITION;
                float2 uv : TEXCOORD0;
            };

            //从CG中获取属性
	        float4 _Color;
            sampler2D _MainTexture;

            v2f vertexfunction(a2v v){
                v2f o;
                o.position = UnityObjectToClipPos(v.vertex);
                o.uv = v.uv;
                return o;
            }

            fixed4 fragmentfunction(v2f i): SV_TARGET{
                return _Color;
            }

            ENDCG
        }
    }
}
