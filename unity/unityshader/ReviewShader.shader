//牢记unityshader基础结构
Shader "Unlit/ReviewShader"
{
   Properties
   {
       _MainColor("MainColor", Color) = (1,1,1,1)
   }

   SubShader
   {
       Tags
       {
           "RenderType" = "Opaque"
       }

       Pass 
       {
           CGPROGRAM
           #pragma vertex vert 
           #pragma fragment frag 
           #include "UnityCG.cginc"

           struct a2v
           {
               float4 vertex : POSITION;
            //    float3 normal : NORMAL;
           };

           struct v2f
           {
               float4 pos : SV_POSITION;
            //    float3 worldNormal : NORMAL;
           };

           float4 _MainColor;

           v2f vert (a2v v)
           {
               v2f o;
               o.pos = UnityObjectToClipPos(v.vertex);
            //    o.worldNormal = UnityObjectToWorldNormal(v.normal);
               return o;
           }

           float4 frag (v2f i) : SV_TARGET
           {
               return _MainColor;
           }          

           ENDCG
       }

       UsePass "Legacy Shaders/VertexLit/SHADOWCASTER"
   }
}