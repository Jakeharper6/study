## 注意点

#### 1.SubShader的Tags和其内部Pass的Tags

**SubShader的Tags**：硬件将通过判断定义的这些标签来决定什么时候调用该着色器，其实暗示了Shader的输出，例：
								  "RenderType" = "Opaque" ：在渲染非透明物体时调用
								  "RenderType" = "Transparent" ：在渲染透明物体时调用

**Pass的Tags**：Pass的标签不同于SubShader标签，这些标签用于告诉渲染引擎我们希望如何来渲染物体，例：

​						LightModel定义该Pass在渲染管线中的角色 ，如Tags{"LightModel"="ForwardBase"}



#### 2.阴影注意事项

```glsl
Shader "Example/ShadowShader"
{
    Properties
    {
        ...
    }
    
    SubShader
    {
        Tags{...}
        
        Pass
        {
            Tags
            {
                //必要，处理投影要在接收投影的物体shader里
                "LightMode" = "ForwardBase"
            }
            
            CGPROGRAM
			...
                
            //根据照明设置编译此着色器的多个版本。
            //并且这是必要的，要想有正确的衰减内置变量等，必须要有这句
            #pragma multi_compile_fwdbase
            
            ...
                
            //必要，下面计算阴影时用到的宏都在此内置文件中声明
            #include "AutoLight.cginc"
                
            struct a2v
            {
                //必须用vertex
                float4 vertex : POSITION;
                ...
            }
            
            struct v2f
            {
                //必须用pos
                float4 pos : SV_POSITION;
                
                ...
                
                //这个宏的作用是声明一个用于对阴影纹理采样的坐标
                //SHADOW_COORDS这个宏后面的参数是指第几个通道，不要和其他的出现冲突。
                //也就是要改变投影的颜色话必须要占用一个通道。
                SHADOW_COORDS(2)
            }
            
            v2f vert (a2v v)
            {
                v2f o;
                ...
                
                //这个宏用于在顶点着色器中计算上一步声明的阴影纹理坐标
                TRANSFER_SHADOW(o)
                return o;
            }
            
            float4 frag (v2f i) : SV_Target
            {
                ...
                    
                //计算阴影值的宏    
                float shadow = SHADOW_ATTENUATION(i);
            }
            ENDCG
        }
        
    }
}
```

其中，结构体a2v和结构体v2f中顶点坐标变量名必须为**vertex**和**pos**，因为光影宏：TRANSFER_VERTEX_TO_FRAGMENT中有些嵌套宏有固化这个变量名称来处理。



## 困难

1.个人shader设计的出发点是依据光源方向和效果的3-4层可变色带，投影落在物体自身上的颜色调节是难点，尝试与_DarkLight同色。

2.个人shader中点积方法中采用_WorldSpaceLightPos0即该光源为平行光，所以使用此shader的物体必须在平行光源即Directional。