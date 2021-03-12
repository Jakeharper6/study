
Shader "Unlit/ToonTryShader" {
    Properties {

        [Enum(OFF,0,FRONT,1,BACK,2)] _CullMode("Cull Mode", int) = 2  //OFF/FRONT/BACK
        _MainTex ("BaseMap", 2D) = "white" {}

        _BaseColor ("BaseColor", Color) = (1,1,1,1)


        [Toggle(_)] _Is_LightColor_Base ("Is_LightColor_Base", Float ) = 1
        _1st_ShadeMap ("1st_ShadeMap", 2D) = "white" {}

        [Toggle(_)] _Use_BaseAs1st ("Use BaseMap as 1st_ShadeMap", Float ) = 0
        _1st_ShadeColor ("1st_ShadeColor", Color) = (1,1,1,1)

        [Toggle(_)] _Is_LightColor_1st_Shade ("Is_LightColor_1st_Shade", Float ) = 1
        _2nd_ShadeMap ("2nd_ShadeMap", 2D) = "white" {}
        //v.2.0.5
        [Toggle(_)] _Use_1stAs2nd ("Use 1st_ShadeMap as 2nd_ShadeMap", Float ) = 0
        _2nd_ShadeColor ("2nd_ShadeColor", Color) = (1,1,1,1)

        [Toggle(_)] _Is_LightColor_2nd_Shade ("Is_LightColor_2nd_Shade", Float ) = 1
        _NormalMap ("NormalMap", 2D) = "bump" {}
        _BumpScale ("Normal Scale", Range(0, 1)) = 1
        [Toggle(_)] _Is_NormalMapToBase ("Is_NormalMapToBase", Float ) = 0
        //v.2.0.4.4
        [Toggle(_)] _Set_SystemShadowsToBase ("Set_SystemShadowsToBase", Float ) = 1
        _Tweak_SystemShadowsLevel ("Tweak_SystemShadowsLevel", Range(-0.5, 0.5)) = 0
        //v.2.0.6
        _BaseColor_Step ("BaseColor_Step", Range(0, 1)) = 0.5
        _BaseShade_Feather ("Base/Shade_Feather", Range(0.0001, 1)) = 0.0001
        _ShadeColor_Step ("ShadeColor_Step", Range(0, 1)) = 0
        _1st2nd_Shades_Feather ("1st/2nd_Shades_Feather", Range(0.0001, 1)) = 0.0001
        [HideInInspector] _1st_ShadeColor_Step ("1st_ShadeColor_Step", Range(0, 1)) = 0.5
        [HideInInspector] _1st_ShadeColor_Feather ("1st_ShadeColor_Feather", Range(0.0001, 1)) = 0.0001
        [HideInInspector] _2nd_ShadeColor_Step ("2nd_ShadeColor_Step", Range(0, 1)) = 0
        [HideInInspector] _2nd_ShadeColor_Feather ("2nd_ShadeColor_Feather", Range(0.0001, 1)) = 0.0001

    }
    SubShader {
        Tags {
            "RenderType"="Opaque"
        }
        
        Pass {
            Name "FORWARD"
            Tags {
                "LightMode"="ForwardBase"
            }

            Cull[_CullMode]
            
            
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            //#define UNITY_PASS_FORWARDBASE
            #include "UnityCG.cginc"
            #include "AutoLight.cginc"
            #include "Lighting.cginc"
            #pragma multi_compile_fwdbase_fullshadows
            #pragma multi_compile_fog
            #pragma target 3.0

            //v.2.0.4
            #pragma multi_compile _IS_CLIPPING_OFF
            #pragma multi_compile _IS_PASS_FWDBASE
            //v.2.0.7
            #pragma multi_compile _EMISSIVE_SIMPLE _EMISSIVE_ANIMATION
            //
            #include "UCTS_DoubleShadeWithFeather.cginc"

            ENDCG
        }
        Pass {
            Name "FORWARD_DELTA"
            Tags {
                "LightMode"="ForwardAdd"
            }

            Blend One One
            Cull[_CullMode]
            
            
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            //#define UNITY_PASS_FORWARDADD
            #include "UnityCG.cginc"
            #include "AutoLight.cginc"
            #include "Lighting.cginc"

            #pragma multi_compile _IS_CLIPPING_OFF
            #pragma multi_compile _IS_PASS_FWDDELTA
            #include "UCTS_DoubleShadeWithFeather.cginc"

            ENDCG
        }
        Pass {
            Name "ShadowCaster"
            Tags {
                "LightMode"="ShadowCaster"
            }
            Offset 1, 1
            Cull Off
            
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            //#define UNITY_PASS_SHADOWCASTER
            #include "UnityCG.cginc"
            #include "Lighting.cginc"
            #pragma fragmentoption ARB_precision_hint_fastest
            #pragma multi_compile_shadowcaster
            #pragma multi_compile_fog
            #pragma target 3.0

            #pragma multi_compile _IS_CLIPPING_OFF
            #include "UCTS_ShadowCaster.cginc"
            ENDCG
        }
//ToonCoreEnd
    }
    FallBack "Legacy Shaders/VertexLit"
    CustomEditor "UnityChan.UTS2GUI"
}
