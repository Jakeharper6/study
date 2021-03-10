# Unlit Shader 无光照着色器编写思路

```
Shader "Unlit/Tutorial_Shader"{
    ...
}
```

这行代码的作用是指定着色器代码存放在什么位置。双引号中的字符串告诉Unity在哪里查找Shader.



```
Shader "Unlit/Tutorial_Shader"{
    Properties{
        ...
    }
}
```

在属性块中，可以传递一些自定义数据。在这里声明的数据将被显示在Unity Editor面板中，在Editor中更改也会驱动脚本更改。



```
Shader "Unlit/Tutorial_Shader"{
    Properties{
        ...
    }
    SubShader{
        ...
    }
}
```

每一个shader有一个或者多个subshaders

如果你的应用将被部署到多种平台（移动、PC、主机）,添加多个Subshader是非常有用的。

例如：可能想要写为PC/Desktop写一个高质量的Subshader,为移动端写一个低质量,但速度更快的Subshader.



```
Shader "Unlit/Tutorial_Shader"{
    Properties{
        ...
    }
    Subshader{
        Pass{
            ...
        }
    }
}
```

每个Subshader至少有一个pass语句块，它实际上是对象渲染的位置。一些特效要求有多个pass语句块，目前，仅仅专注于一个。



```
Shader "Unlit/Tutorial_Shader"{
    Properties{
        
    }
    Subshader{
        Pass{
            CGPROGRAM
                ...
            ENDCG
        }
    }
}
```

在pass语句块中，是一些实际渲染的代码。

实际写的所有Shader代码都在CGPROGRAM和ENDCG中，对于Unity来说，shaderlab是HLSL和CG的变体。



```
CGPROGRAM
    #pragma vertex vertexFunction
    #pragma fragment fragmentFunction
ENDCG
```

这里，将vertex函数声明为vertexFunction，fragment函数声明为fragmentFunction。



```
CGPROGRAM 
    #pragma vertex vertexFunction
    #pragma fragment fragmentFunction
    
    void vertexFunction(){
        
    }
    
    void fragmentFunction(){
        
    }
ENDCG
```

定义这些函数



```
CGPROGRAM
    #pragma vertex vertexFunction
    #pragma fragment fragmentFunction
    
    #include "UnityCG.cginc"
    
    struct a2v{
        
    };
    
    void vertexFunction(a2v v){
        
    }
    void fragmentFunction(){
        
    }
ENDCG

```

在开始着色之前，需要设置一些数据结构和两个函数，这样，Unity给定的数据，并把数据返回到Unity中。

首先，添加UnityCG.cginc语句块，可以使用这个文件中包含的一些助手函数。

添加一个数据结构a2v（表示application to vertex shader，意思是数据从应用阶段传递到顶点着色器中）

并修改顶点函数，将a2v作为参数传递给顶点函数。




`[type] [name] :[semantic]`

```
struct a2v{
	flot4 vertex:POSITION;
};
```

当传递一个参数到vertexFunction中时，Unity将解析这个函数的结构，并基于正在绘制的对象模型传递值。可以传递一些自定义的数据。例如，可以要求Unity获取模型对象的顶点坐标。



```
struct a2v{
    float4 vertex:POSITION;
    float2 uv:TEXCOORD0;  //texture coordinate
}
```

也可以从Unity中获取顶点坐标和UV纹理坐标



```
CGPROGRAM
    #pragma vertex vertexFunction
    #pragma fragment fragmentFunction
    #include "UnityCG.cginc"
    
    struct a2v{
        float4 vertex:POSITION;
        float2 uv:TEXCOORD0;
    };
    
    struct v2f{
        
    };
    
    v2f vertexFunction(a2v v){
        v2f o;
        return o;
    }
    
    void fragmentFunction(){
        
    }

ENDCG
```

最后配置顶点函数，创建一个结构体v2f(代表从vertex shader to fragment shader，顶点着色器数据传递到片元着色器)

将vertex中包含的数据传递到片元函数，同时确保vertexFunction 返回 v2f的数据类型，在我们使用它时，创建并返回一个空白数据。



```
struct v2f{
    float4 position:SV_POSITION;
    float2 uv:TEXCOORD0;
}
```

像之前一样，可以在v2f结构体中定义一些数据，以便可能想要把这些数据从顶点函数传递到片元函数。

SV代表“system value”，在v2f结构中表示最终渲染的顶点的位置。



```
fixed4 fragmentFunction(v2f i){
    
}
```

现在需要编辑片元函数，使它接受一个v2f结构并返回一个fixed4的值。

输出的片元函数将是一个有（R,G,B,A)代表的颜色值。

float4:float类型的四维向量 (x,y,z,w)或(r,g,b,a),  精度更高，计算时消耗更大
fixed4:fixed类型的四维向量 (x,y,z,w)或(r,g,b,a)，精度不高，但用于颜色足够了



```
fixed4 fragmentFunction(v2f i):SV_TARGET{
    
}
```

最后，将为片元函数添加一个SV_TARGET的输出语义



```
Shader "Unlit/Tutorial_Shader"{
    Properties{
        
    }
    Subshader{
        Pass{
            CGPROGRAM
            #pragma vertex vertexFunction
            #pragma fragment fragmentFunction
            #include "UnityCG.cginc"
            
            struct a2v{
                float4 vertex:POSITION;
                float2 uv:TEXCOORD0;
            };
            struct v2f{
              float4 position : SV_POSITION;
              float2 uv : TEXCOORD0;
            };
            v2f vertexFunction(a2v v){
                v2f o;
                return o;
            }
            fixed4 fragmentFunction(v2f i) : SV_TARGET{
                
            }
            ENDCG
        }
    }
}

```

这里大致的骨架已经出来了



```
v2f vertexFunction(a2v v){
    v2f o;
    o.position = UnityObjectToClipPos(v.vertex);
    return o;
}
```

接着要做的是获取顶点的正确位置，使用Unity中提供的UnityObjectToClipPos()函数（这个函数的作用是将世界空间的模型坐标转换到裁剪空间，函数内部封装了实现顶点坐标变换的具体细节，如矩阵变换等等）。这个函数将在局部空间中表示的顶点，变换到渲染相机的裁剪空间。注意是通过设置o.position的位置来传递转换的点。



```
fixed4 fragmentFunction(v2f i) : SV_TARGET{
    return fixed4(0, 1, 0, 1);
}
```

接下来，给片元函数一个输出。

想要编辑shader使得其能返回一个想要的颜色，需要回到开始的自定义属性。



```
Properties{
    //_name ("display name", type) = default value
    _Color("Totally Rad Color", Color) = (1, 1, 1, 1)
}
```

在这里定义了一个颜色供使用，将其称之为_Color并且它将显示为 “Totally Rad Color”



```
//结构体

float4 _Color;	//从CG中获取属性
	
//函数方法
```

在我们使用这个color之前，我们需要把它传递到CG代码中



```
fixed4 fragmentFunction(v2f i):SV_TARGET{
    return _Color;
}   
```

现在，可以在片元函数中使用_Color值了



```
Shader "Unlit/TutorialShader"
{
    Properties{
        _Color("Totally Rad Color", Color) = (1, 1, 1, 1)
    }

    SubShader{
        Pass{

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

            v2f vertexfunction(a2v v){
                v2f o;
                o.position = UnityObjectToClipPos(v.vertex);
                return o;
            }

            fixed4 fragmentfunction(v2f i): SV_TARGET{
                return _Color;
            }

            ENDCG
        }
    }
}
```

当前只显示颜色的着色器完整代码



```
Properties{
    _Color("_Color",Color)=(1,1,1,1)
    _MainTexture("Main Texture",2D)="white"{}
}
```

现在添加一张标准的纹理贴图，这里需要添加一个新的属性给我们的纹理



```
float4 _Color;
sampler2D _MainTexture;
```

注意它的类型是2D，默认给它一张白色的纹理，此时同样还需要获取这个属性在CG片段中使用它



```
v2f vertexFunction(a2v v){
    v2f o;
    o.position=UnityObjectToClipPos(v.vertex);
    o.uv=v.uv;
    return o;
}
```

然后，需要从模型传递UV纹理坐标到片元函数，可以通过返回顶点函数并将其传递v2f中



```
fixed4 fragmentFunction(v2f i):SV_TARGET{
    return tex2D(_MainTexture,i.uv);
}
```

为了能在片元函数中使用纹理的颜色，我们需要对纹理进行采样

CG中已经有一个tex2D()函数做了一切