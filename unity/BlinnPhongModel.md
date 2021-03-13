Blinn-Phong 光照模型，又称为 Blinn-phong 反射模型（Blinn–Phong reflection model）或者 phong 修正模型（modified Phong reflection model），是由 Jim Blinn于 1977 年在文章“Models of light reflection for computer synthesized pictures”中对传统 phong 光照模型基础上进行修改提出的。和传统 phong 光照模型相比，Blinn-phong 光照模型混合了 Lambert 的漫射部分和标准的高光，渲染效果有时比 Phong 高光更柔和、更平滑，此外它在速度上相当快，因此成为许多 CG 软件中的默认光照渲染方法。此外它也集成在了大多数图形芯片中，用以产生实时快速的渲染。在 OpenGL 和 Direct3D 渲染管线中， Blinn-Phong 就是默认的渲染模型。


```glsl
Shader "Unlit/Blinn-phong"
{
    Properties
    {
        _MainTex ("Texture", 2D) = "white" {}
        _SpecularColor("SpecularColor",Color )=(1,1,1,1)
        _SpecularGloss("Gloss",Range(8.0,256)) = 20
        _Diffuse ("Diffuse", Color) = (1, 1, 1, 1)
    }
    SubShader
    {
        Tags { "RenderType"="Opaque" }

        Pass
        {
            Tags { "LightMode"="ForwardBase" }

            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag


            #include "UnityCG.cginc"
            #include "Lighting.cginc" 
            struct a2v
            {
                float4 vertex : POSITION;
                float2 uv : TEXCOORD0;
                float3 normal:NORMAL;
            };

            struct v2f
            {
                float2 uv : TEXCOORD0;
                float4 vertex : SV_POSITION;
                float3 worldNormal :TEXCOORD1;
                float3 worldPos :TEXCOORD2;
            };

            sampler2D _MainTex;
            float4 _MainTex_ST;
            float4 _SpecularColor;
            float  _SpecularGloss;
            float4  _Diffuse;

            v2f vert (a2v v)
            {
                v2f o;
                o.uv = TRANSFORM_TEX(v.uv,_MainTex);
                o.vertex = UnityObjectToClipPos(v.vertex);
                o.worldNormal = UnityObjectToWorldNormal(v.normal);
                o.worldPos  = mul(unity_ObjectToWorld,v.vertex).xyz;
                return o;
            }

            fixed4 frag (v2f i) : SV_Target
            {
                // 1.ambientColor
                float3  ambient = UNITY_LIGHTMODEL_AMBIENT.xyz;

                // 2.diffuseColor
                float3 N =  normalize(i.worldNormal);
                float3 L = normalize(_WorldSpaceLightPos0.xyz);
                float3 diffuseColor = _LightColor0.rgb * _Diffuse.rgb * max(0.0,dot(N,L));

                // 3.specularColor
                float3  V = normalize(_WorldSpaceCameraPos.xyz - i.worldPos.xyz);
                // H替代了Phong中的reflectDic = normalize(reflect(-L,N));
                float3 H = normalize(L+V);
                // 这里需要注意的是计算高光反射的时候使用的是【半角向量 H】和法向量的点积
                float3specularColor=_LightColor0.rgb*_SpecularColor.rgb*pow(max(0,dot(H,N)),_SpecularGloss);

                fixed4 col =  tex2D(_MainTex,i.uv) * float4 ((ambient+diffuseColor+specularColor),1);
                return col;
            }
            ENDCG
        }
    }
    FallBack "Specular"
}

```

