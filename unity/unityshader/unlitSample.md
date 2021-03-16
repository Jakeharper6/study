```c#
//定义shader的找寻路径
Shader "Unlit/DefaultUnlitShader"        
{    
    //属性区，会显示在inspector界面供调节
    Properties                                
    {
        _MainTex ("Texture", 2D) = "white" {}                //接受一张2D主纹理，默认白色
    }//子着色器区，可以有很多个，程序执行时显卡会自动选择第一个能够执行的
	SubShader                        
	{
    	Tags { "RenderType"="Opaque" }                        //渲染类型：不透明； 注一
    	LOD 100                                                //细节层次100；注二

    	//通道，可以有很多个，每一个执行一次渲染流程，即调用一次drawcall
    	Pass
    	{
            CGPROGRAM                                        //cg语法开始标签
            #pragma vertex vert                                //指明定点着色器使用vert方法
            #pragma fragment frag                            //指明片元着色器使用frag方法
            // make fog work        
            #pragma multi_compile_fog                        //unity5.x新增，使得fog工作

            #include "UnityCG.cginc"                        //同C语言语法，这个文件里面有很多宏，可以直接用

            struct appdata                                    //顶点着色器输入结构体
        	{
            	float4 vertex : POSITION;                    //顶点坐标； 注三
            	float2 uv : TEXCOORD0;                        //纹理uv坐标
            };

            struct v2f                                        //定点着色器输出结构体，同时也是片元着色器输入结构体
            {
                float2 uv : TEXCOORD0;                        //纹理uv坐标
                UNITY_FOG_COORDS(1)                            //宏，雾数据； 注四
                float4 vertex : SV_POSITION;                //顶点坐标； 注三
            };

            sampler2D _MainTex;                                //必须在此声明才能顶点着色器函数和片元着色器函数中使																	用，名字和属性那个一样说明两者绑定
            float4 _MainTex_ST;                                //变量声明，也是一个宏； 注五

            v2f vert (appdata v)                            //顶点着色器函数，每个顶点均会执行
            {
                v2f o;
                o.vertex = UnityObjectToClipPos(v.vertex);    //坐标变换，注六
                o.uv = TRANSFORM_TEX(v.uv, _MainTex);        //纹理位置计算，也是一个宏；注六
                UNITY_TRANSFER_FOG(o,o.vertex);                //输出雾效果，注七
                return o;
            }

            fixed4 frag (v2f i) : SV_Target                    //片元着色器函数
            {
                // sample the texture
                fixed4 col = tex2D(_MainTex, i.uv);            //根据坐标进行纹理采样；注八
                // apply fog
                UNITY_APPLY_FOG(i.fogCoord, col);            //启用雾效果；注七
                return col;
            }
            ENDCG                                            //cg语法结束标签
    	}
    }
}
```



注一：着色器可以被若干的标签（tags）所修饰，而硬件将通过判定这些标签来决定什么时候调用该着色器。

```glsl
 Tags { "RenderType"="Opaque" } 告诉了系统应该在渲染非透明物体时调用我们,Unity定义了一些列这样的渲染过程，

 与RenderType是Opaque相对应的显而易见的是"RenderType" = "Transparent"，表示渲染含有透明效果的物体时调用。
 在这里Tags其实暗示了你的Shader输出的是什么，如果输出中都是非透明物体，那写在Opaque里；

 如果想渲染透明或者半透明的像素，那应该写在Transparent中。
 另外比较有用的标签还有"IgnoreProjector"="True"（不被Projectors影响），

 "ForceNoShadowCasting"="True"（从不产生阴影）以及"Queue"="xxx"（指定渲染顺序队列）。
 这里想要着重说一下的是Queue这个标签，如果你使用Unity做过一些透明和不透明物体的混合的话，

 很可能已经遇到过不透明物体无法呈现在透明物体之后的情况。
 这种情况很可能是由于Shader的渲染顺序不正确导致的。

 Queue指定了物体的渲染顺序，预定义的Queue有：
 Background - 最早被调用的渲染，用来渲染天空盒或者背景

 Geometry - 这是默认值，用来渲染非透明物体（普通情况下，场景中的绝大多数物体应该是非透明的）

 AlphaTest - 用来渲染经过Alpha Test的像素，单独为AlphaTest设定一个Queue是出于对效率的考虑
 Transparent - 以从后往前的顺序渲染透明物体

 Overlay - 用来渲染叠加的效果，是渲染的最后阶段（比如镜头光晕等特效）
 这些预定义的值本质上是一组定义整数，Background = 1000， Geometry = 2000, AlphaTest = 2450， Transparent = 3000，

 最后Overlay = 4000。

 在我们实际设置Queue值时，不仅能使用上面的几个预定义值，我们也可以指定自己的Queue值，写成类似这样："Queue"="Transparent+100"，

 表示一个在Transparent之后100的Queue上进行调用。通过调整Queue值，我们可以确保某些物体一定在另一些物体之前或者之后渲染，这个技巧有时候很有用处
```


注二：shaderLOD， 在Unity的Quality Settings中我们可以设定允许的最大LOD，当设定的LOD小于SubShader所指定的LOD时，这个			SubShader将不可用,（diffuse的LOD为200）这样在之后调整根据设备图形性能来调整画质时可以进行比较精确的控制

注三：网上说POSITION语义和SV_POSITION语义都表示顶点位置，唯一区别是 SV_POSTION一旦被作为vertex shader的输出语义，
     	   那么这个最终的顶点位置就被固定了，DX10之后SV_POSITON作为顶点shader输出和片元shader的输入，但顶点的输入仍是			POSITION


注四：UNITY_FOG_COORDS，可以在UnityCG.cginc找到

注五：注六里的宏需要用到，所以必须先声明，个人理解这里面存储了在inspector界面设置的四个值Tiling和Offset

注六：个人理解： o.vertex = UnityObjectToClipPos(v.vertex); 这句话和 o.vertex= mul(UNITY_MATRIX_MVP, v.vertex);

​			这句是等价的，都是坐标变换到最终的二维窗口

```glsl
 	TRANSFORM_TEX宏的定义为 

 	#define TRANSFORM_TEX(tex,name) (tex.xy *name##_ST.xy + name##_ST.zw) 根据uv坐标来计算真正的纹理上对应的位置，		在选择纹理的

 	inspector界面可以设置四个值，Tiling对应xy，Offset对应zw
```
注七：UNITY_TRANSFER_FOG宏，在UnityCG.cginc的第945行起
     	#if (SHADER_TARGET < 30) || defined(SHADER_API_MOBILE)
       	 // mobile or SM2.0: calculate fog factor per-vertex
        #define UNITY_TRANSFER_FOG(o,outpos) UNITY_CALC_FOG_FACTOR((outpos).z); o.fogCoord.x = unityFogFactor
   		  #else
        	// SM3.0 and PC/console: calculate fog distance per-vertex, and fog factor per-pixel
        #define UNITY_TRANSFER_FOG(o,outpos) o.fogCoord.x = (outpos).z
    	#endif
     UNITY_APPLY_FOG宏，也可以在UnityCG.cginc找到

注八：CG语法，CG纹理采样函数，tex2D(sampler2D tex, float2 s)    //第一个参数：纹理，第二个参数UV向量

