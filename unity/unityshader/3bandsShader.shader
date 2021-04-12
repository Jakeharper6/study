Shader "Unlit/3bandsShader"
{
    Properties
    {
        _LightColor("Light Color", Color) = (1,1,1,1)
        _SecMidColor("SecMid Color", Color) = (1,1,1,1)
        _Threshold("Threshold", Range(0, 1)) = 0.75
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
            float4 _SecMidColor;
			float4 _AmbientColor;
 
            v2f vert (appdata v)
            {
                v2f o;
                o.pos = UnityObjectToClipPos(v.vertex);
                float3 normal = normalize(mul(unity_ObjectToWorld, float4(v.normal, 0))).xyz;
                //clamp(x, a, b)
                //如果x<a返回a；如果x>b返回b；如果在a和b之间就返回x
                //dot(a, b)
                //dot()返回的是两个向量的点积(dot product)
                float lightDot = clamp(dot(normal, normalize(_WorldSpaceLightPos0)), -1.0, 1.0);
                o.lightDot = (lightDot + 1) / 2; 
				o.worldNormal = UnityObjectToWorldNormal(v.normal);		
                TRANSFER_SHADOW(o)
                return o;
            }
             
            float _Threshold;
 
            float4 frag (v2f i) : SV_Target
            {
                float4 col;
				float3 normal = normalize(i.worldNormal);

                //后期记住用step等方法优化
                if (i.lightDot > 0 && i.lightDot < _Threshold) col = _SecMidColor;
                else col = _LightColor;

				// 从平行光计算照明度。WorldSpaceLightPos0是指向主平行光相反方向的向量。
                // 所以此shader无法应用于spotlight和pointlight
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

