Shader"Custom/TutorialShader"

Properties{

}

SubShader{
    Pass{
        //Tags{""}

        CGPROGRAM

        #progam vertex vertexfunction
        #progam fragment fragmentfunction
        #include "UnityCG.cginc"

        struct a2v{
            float4 vertex : POSITION;
            float2 uv : TEXCOORD0;
        };

        struct v2f{
            float4 position : SV_POSITION;
            float2 uv : TEXCOORD0;
        };

        v2f vertexfunction(a2v v){
            v2f o;
            return o;
        }

        fixed4 fragmentfunction(v2f i): SV_TARGET{

        }

        ENDCG
    }
}