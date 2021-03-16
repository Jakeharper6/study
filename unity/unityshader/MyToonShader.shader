Shader "Unlit/MyToonShader"
{
    Properties
    {
        _LightColor("Light Color", Color) = (1,1,1,1)
        _MiddleColor("Middle Color", Color) = (1,1,1,1)
        _SecMidColor("SecMid Color", Color) = (1,1,1,1)
        _DarkColor("Dark Color", Color) = (1,1,1,1) 
        _Threshold1("Threshold 1", Range(0, 1)) = 0.25
        _Threshold2("Threshold 2", Range(0, 1)) = 0.5
        _Threshold3("Threshold 3", Range(0, 1)) = 0.75
		_AmbientColor("Ambient Color", Color) = (0.4,0.4,0.4,1)
    }
    SubShader
    {
        Tags 
        { 
            "RenderType"="Opaque" 
        }
        LOD 100
 
        Pass
        {
			Tags
			{
				//处理投影要在接收投影的物体shader里
				"LightMode" = "ForwardBase"
			}
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #pragma multi_compile_fwdbase
             
            #include "UnityCG.cginc"
            #include "AutoLight.cginc"
 
            struct appdata
            {
                float4 vertex : POSITION;
                float3 normal : NORMAL;
            };
 
            struct v2f
            {
                float4 pos : SV_POSITION;
                float lightDot : TEXCOORD0;
				float3 worldNormal : NORMAL;
                SHADOW_COORDS(2)
            };
             
 
            float4 _LightColor;
            float4 _MiddleColor;
            float4 _SecMidColor;
            float4 _DarkColor;
			float4 _AmbientColor;
 
            v2f vert (appdata v)
            {
                v2f o;
                o.pos = UnityObjectToClipPos(v.vertex);
                float3 normal = normalize(mul(unity_ObjectToWorld, float4(v.normal, 0))).xyz;
                float lightDot = clamp(dot(normal, normalize(_WorldSpaceLightPos0)), -1.0, 1.0);
                o.lightDot = (lightDot + 1) / 2; 
				o.worldNormal = UnityObjectToWorldNormal(v.normal);		
                TRANSFER_SHADOW(o)
                return o;
            }
             
            float _Threshold1;
            float _Threshold2;
            float _Threshold3;
 
            float4 frag (v2f i) : SV_Target
            {
                float4 col;
				float3 normal = normalize(i.worldNormal);

                //if (i.lightDot > 0 && i.lightDot < _Threshold1) col = _LightColor;
                //else if (i.lightDot > _Threshold1 && i.lightDot < _Threshold2) col = _MiddleColor;
                //else col = _DarkColor;

                // if (i.lightDot > 0 && i.lightDot < _Threshold1) col = _DarkColor;
                // else if (i.lightDot > _Threshold1 && i.lightDot < _Threshold2) col = _MiddleColor;
                // else col = _LightColor;

                //后期记住用step等方法优化
                if (i.lightDot > 0 && i.lightDot < _Threshold1) col = _DarkColor;
                else if (i.lightDot > _Threshold1 && i.lightDot < _Threshold2) col = _SecMidColor;
                else if (i.lightDot > _Threshold2 && i.lightDot < _Threshold3) col = _MiddleColor;
                else col = _LightColor;

				// 从平行光计算照明度。WorldSpaceLightPos0是指向主平行光相反方向的向量。
				float NdotL = dot(_WorldSpaceLightPos0, normal);

                float shadow = SHADOW_ATTENUATION(i);

				float lightIntensity = smoothstep(0, 0.01, NdotL * shadow);

				float4 shadowColor = lightIntensity * _LightColor;

                return col * (shadowColor + _AmbientColor);
            }
            ENDCG
        }

        UsePass "Legacy Shaders/VertexLit/SHADOWCASTER"
    }
}