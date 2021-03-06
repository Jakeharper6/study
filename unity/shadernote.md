# Unity Shader学习笔记

固定函数着色器：需要依靠旧设备运行的游戏（极少）

表面着色器：光源多（移动平台性能表现差）

顶点/片元着色器：单一光源、多自定义渲染效果

*本质上来说unity中只存在顶点/片元着色器*



### 常用帮助函数、结构体和全局变量

**内置包含文件**

　　Unity中有类似于C++的包含文件.cginc，在编写Shader时我们可以使用#include指令把这些文件包含进来
这样我们就可以使用Unity为我们提供的一些非常好用的函数、宏和变量。

例如：#include"UnityCG.cginc"

包含文件的位置：根目录\Editor\Data\CGIncludes

**知识点1：以下是Unity中常用包含文件：**
　　文件名 描述
　　1、UnityCG.cginc 包含最常用的帮助函数、宏和结构体
　　2、UnityShaderVariables.cginc 在编译Shader时，会被自动包含进来，包含了许多内置的全局变量，如UNITY_MATRIX_MVP
　　3、Ligghting.cginc 包含了各种内置光照模型，如果编写SurfaceShader的话，会被自动包含进来
　　4、HLSLSurport.cginc 在编译Shader时，会被自动包含进来，声明了很多跨平台编译的宏和定义

　　Unity5.2引入了许多新的重要的包含文件，如UnityStandardBRDF.cginc等。*这些文件用于实现基于物理的渲染*

**知识点2：UnityShader中常用的结构体****

　　　　名称 　　　　　　　　 描述 　　　　　　　　　　　　　包含的变量
　　appdata_base 　　　　用于顶点着色器输入 　　　　 顶点位置、顶点法线、第一组纹理坐标
　　appdata_tan 　　　　 用于顶点着色器输入 　　　　 顶点位置、顶点切线、顶点法线、第一组纹理坐标
　　appdata_full 　　　　用于顶点着色器输入 　　　　 顶点位置、顶点切线、顶点法线、四组（或更多）纹理坐标
　　appdata_img 　　　　 用于顶点着色器输入 　　　　 顶点位置、第一组纹理坐标
　　v2f_img 　　　　　　 用于顶点着色器输出 　　　　 裁剪空间中的位置、纹理坐标

struct appdata_img
{
　　float4 vertex : POSITION;
　　half2 texcoord : TEXCOORD0;
};

struct appdata_base
{
　　float4 vertex : POSITION;
　　float3 normal : NORMAL;
　　float4 texcoord : TEXCOORD0;
};

struct appdata_tan
{
　　float4 vertex : POSITION;
　　float4 tangent : TANGENT;
　　float3 normal : NORMAL;
　　float4 texcoord : TEXCOORD0;
};

struct appdata_full
{
　　float4 vertex : POSITION;
　　float4 tangent : TANGENT;
　　float3 normal : NORMAL;
　　float4 texcoord : TEXCOORD0;
　　float4 texcoord1 : TEXCOORD1;
　　float4 texcoord2 : TEXCOORD2;
　　float4 texcoord3 : TEXCOORD3;
\#if defined(SHADER_API_XBOX360)
　　half4 texcoord4 : TEXCOORD4;
　　half4 texcoord5 : TEXCOORD5;
\#endif
　　fixed4 color : COLOR;
};

struct v2f_img
{
　　float4 pos : SV_POSITION;
　　half2 uv : TEXCOORD0;
};

**知识点3：UnityShader中常用的帮助函数**

　　　　　　函数名 　　　　　　　　　　　　　　　　　　　　 描   述
float3 WorldSpaceViewDir(float4 v) 　　　　 　　 输入一个模型顶点坐标，得到世界空间中从该点到摄像机的观察方向
float3 ObjSpaceViewDir(float4 v) 　　　　　　 　 输入一个模型顶点坐标，得到模型空间中从该点到摄像机的观察方向
float3 WorldSpaceLightDir(float4 v) 　　　　　　  输入一个模型顶点坐标，得到世界空间中从该点到光源的光照方向（方向没有归一化，且只可用于前向渲染）
float3 ObjSpaceLightDir(float4 v) 　　　　　　 　  输入一个模型顶点坐标，得到模型空间中从该点到光源的光照方向（方向没有归一化，且只可用于前向渲染）
float3 UnityObjectToWorldNormal(float3 norm)　　将法线从模型空间转换到世界空间
float3 UnityObjectToWorldDir(in float3 dir) 　　　  把方向矢量从模型空间转换到世界空间
float3 UnityWorldToObjectDir(float3 dir) 　　　　  把方向矢量从世界空间转换到模型空间

**知识点4：UnityShader中内置变量**
                                   Unity内置变换矩阵
      变量名                                       描     述
UNITY_MATRIX_MVP 　　　　   当前模型*观察*投影矩阵，用于将模型顶点/方向矢量从模型空间转换到裁剪空间
UNITY_MATRIX_MV 　　　　　  当前模型*观察矩阵，用于将模型顶点/方向矢量从模型空间转换到观察空间
UNITY_MATRIX_V 　　　　　　 当前观察矩阵，用于将顶点/方向矢量从世界空间变换到观察空间
UNITY_MATRIX_P 　　　　　　 当前投影矩阵，用于将顶点/方向矢量从观察空间变换到裁剪空间
UNITY_MATRIX_VP 　　　　　　当前观察*投影矩阵，用于将顶点/方向矢量从世界空间变换到裁剪空间
UNITY_MATRIX_T_MV 　　　　 UNITY_MATRIX_MV转置矩阵
UNITY_MATRIX_IT_MV 　　　　 UNITY_MATRIX_MV逆转置矩阵，可将法线矢量从模型空间转换到观察空间
_Object2World 　　　　　　　　 当前模型的矩阵，用于将模型顶点/方向矢量从模型空间转换到世界空间
_World2Object 　　　　　　     _Object2World逆矩阵，用于将模型顶点/方向矢量从世界空间转换到模型空间

另外：Unity还提供了能够访问时间、光照、雾效和环境光等目的的变量。这些内置变量大多UnityShaderVariables.cginc中，
跟光照有关的还定义在Lighting.cginc 和AutoLight.cginc中。

**知识点5：**

1、uint CreateShader(enum type) : 创建空的shader object; 
 type: VERTEX_SHADER, 
2、void ShaderSource(uint shader, sizeicount, const **string, const int *length)：加载shader源码进shader object；可能多个字符串 
3、void CompileShader(uint shader)：编译shader object； 
 shader object有状态 表示编译结果 
4、void DeleteShader( uint shader )：删除 shader object; 
5、void ShaderBinary( sizei count, const uint *shaders, 
enum binaryformat, const void *binary, sizei length ): 加载预编译过的shader 二进制串； 
6、uint CreateProgram( void )：创建空的program object， programe object组织多个shader object，成为executable; 
7、void AttachShader( uint program, uint shader )：关联shader object和program object； 
8、void DetachShader( uint program, uint shader )：解除关联； 
9、void LinkProgram( uint program )：program object准备执行，其关联的shader object必须编译正确且符合限制条件； 
10、void UseProgram( uint program )：执行program object； 
11、void ProgramParameteri( uint program, enum pname, 
int value )： 设置program object的参数； 
12、void DeleteProgram( uint program )：删除program object； 
13、shader 变量的qualifier: 
  默认：无修饰符，普通变量读写， 与外界无连接； 
  const：常量 const vec3 zAxis = vec3(0.0, 0.0, 1.0); 
  attribute: 申明传给vertex shader的变量；只读；不能为array或struct；attribute vec4 position; 
  uniform: 表明整个图元处理中值相同；只读； uniform vec4 lightPos; 
  varying: 被差值；读写； varying vec3 normal; 
  in, out, inout; 


shader变量的精度： 
  highp, mediump, lowp 

shader内置变量： 
  gl_Position: 用于vertex shader, 写顶点位置；被图元收集、裁剪等固定操作功能所使用； 
        其内部声明是：highp vec4 gl_Position; 
  gl_PointSize: 用于vertex shader, 写光栅化后的点大小，像素个数； 
        其内部声明是：mediump float gl_Position; 
  gl_FragColor: 用于Fragment shader，写fragment color；被后续的固定管线使用； 
         mediump vec4 gl_FragColor; 
  gl_FragData: 用于Fragment shader，是个数组，写gl_FragData[n] 为data n；被后续的固定管线使用； 
         mediump vec4 gl_FragData[gl_MaxDrawBuffers]; 
  gl_FragColor和gl_FragData是互斥的，不会同时写入； 
  gl_FragCoord: 用于Fragment shader,只读， Fragment相对于窗口的坐标位置 x,y,z,1/w; 这个是固定管线图元差值后产生的；z 是深度值; mediump vec4 gl_FragCoord; 
  gl_FrontFacing: 用于判断 fragment是否属于 front-facing primitive；只读； 
          bool gl_FrontFacing;  
  gl_PointCoord: 仅用于 point primitive; mediump vec2 gl_PointCoord; 


shader内置常量： 
  const mediump int gl_MaxVertexAttribs = 8; 
  const mediump int gl_MaxVertexUniformVectors = 128; 
  const mediump int gl_MaxVaryingVectors = 8; 
  const mediump int gl_MaxVertexTextureImageUnits = 0; 
  const mediump int gl_MaxCombinedTextureImageUnits = 8; 
  const mediump int gl_MaxTextureImageUnits = 8; 
  const mediump int gl_MaxFragmentUnitformVectors = 16; 
  const mediump int gl_MaxDrawBuffers = 1; 


shader内置数学函数： 
  一般默认都用弧度； 
  radians(degree) : 角度变弧度； 
  degrees(radian) : 弧度变角度； 
  sin(angle), cos(angle), tan(angle) 
  asin(x): arc sine, 返回弧度 [-PI/2, PI/2]; 
  acos(x): arc cosine,返回弧度 [0, PI]; 
  atan(y, x): arc tangent, 返回弧度 [-PI, PI]; 
  atan(y/x): arc tangent, 返回弧度 [-PI/2, PI/2]; 
 
  pow(x, y): x的y次方； 
  exp(x): 指数, log(x)： 
  exp2(x): 2的x次方， log2(x): 
  sqrt(x): x的根号； inversesqrt(x): x根号的倒数 
 
  abs(x): 绝对值 
  sign(x): 符号, 1, 0 或 -1 

  {sign(x)或者Sign(x)叫做符号函数，在数学和计算机运算中，其功能是取某个数的符号(正或负): 
  当x>0，sign(x)=1; 
  当x=0，sign(x)=0; 
  当x<0， sign(x)=-1;}  floor(x): 底部取整 
  ceil(x): 顶部取整 
  fract(x): 取小数部分 
  mod(x, y): 取模， x - y*floor(x/y) 
  min(x, y): 取最小值 
  max(x, y): 取最大值 
  clamp(x, min, max):  min(max(x, min), max); 
  mix(x, y, a): x, y的线性混叠， x(1-a) + y*a; 
  step(edge, x): 如 x 
  smoothstep(edge0, edge1, x): threshod  smooth transition时使用。 edge0<=edge0时为0.0， x>=edge1时为1.0 

  length(x): 向量长度 
  distance(p0, p1): 两点距离， length(p0-p1); 
  dot(x, y): 点积，各分量分别相乘 后 相加 
  cross(x, y): 差积，x[1]*y[2]-y[1]*x[2], x[2]*y[0] - y[2]*x[0], x[0]*y[1] - y[0]*x[1] 
  normalize(x): 归一化， length(x)=1; 
  faceforward(N, I, Nref): 如 dot(Nref, I)< 0则N, 否则 -N 
  reflect(I, N): I的反射方向， I -2*dot(N, I)*N, N必须先归一化 
  refract(I, N, eta): 折射，k=1.0-eta*eta*(1.0 - dot(N, I) * dot(N, I)); 如k<0.0 则0.0，否则 eta*I - (eta*dot(N, I)+sqrt(k))*N 

  matrixCompMult(matX, matY): 矩阵相乘, 每个分量 自行相乘， 即 r*[j] = x[j]\*y[j];* *
               矩阵线性相乘，直接用 \* 

  lessThan(vecX, vecY): 向量 每个分量比较 x < y 
  lessThanEqual(vecX, vecY): 向量 每个分量比较 x<=y 
  greaterThan(vecX, vecY): 向量 每个分量比较 x>y 
  greaterThanEqual(vecX, vecY): 向量 每个分量比较 x>=y 
  equal(vecX, vecY): 向量 每个分量比较 x==y 
  notEqual(vecX, vexY): 向量 每个分量比较 x!=y 
  any(bvecX): 只要有一个分量是true， 则true 
  all(bvecX): 所有分量是true， 则true 
  not(bvecX): 所有分量取反 

  texture2D(sampler2D, coord): texture lookup 
  texture2D(sampler2D, coord, bias): LOD bias, mip-mapped texture 
  texture2DProj(sampler2D, coord): 
  texture2DProj(sampler2D, coord, bias): 
  texture2DLod(sampler2D, coord, lod): 
  texture2DProjLod(sampler2D, coord, lod): 
  textureCube(samplerCube, coord): 
  textureCube(samplerCube, coord, bias): 
  textureCubeLod(samplerCube, coord, lod):* 



### 【Unity Shader】---准确认识SubShader语义块结构、渲染状态设定、Tags标签

**一【SubShader】**
　　每个UnityShader文件可以包含多个SubShader语义块，但至少要有一个。当Unity需要加载这个UnityShader时，
Unity会扫描所有的SubShader语义块，然后选择一个能够在目标平台上运行的SubShader。如果都不支持的话，Unity
就会使用FallBack语义指定的UnityShader。
　　Unity提供这种语义的原因在于，不同的显卡具有不同的能力。例如，一些旧的显卡仅能支持一定数目的操作指令，
而一些高级的显卡可以支持更多的指令数，那么我希望在旧的显卡上使用计算复杂度较低的着色器，而在高级的显卡上
执行计算复杂度高的着色器，以便提供更出色的画面效果。

SubShader
{
　　//可选的
　　[Tags]
　　//可选的
　　[RenderSetup]


　　Pass
　　{

　　}
　　//或更多Pass
}
　　SubShader中定义了一系列的Pass以及可选的标签[Tags]、状态[RenderSetup]。每个Pass定义一次完整的渲染流程
但是如果Pass数目过多会造成渲染性能的下降。因此，我们尽量使用数量最小的Pass。
补充说明：Tags也可以在Pass中声明。不同的是，SubShader中的一些标签设置是特定的。也就是说，
这些标签和Pass中设置的标签是不一样的。而对于状态设置来说，其使用的语法是相同。不过在SubShader进行的设置
将会用于所用的Pass。


**二【渲染状态】**
　　ShaderLab提供了一系列渲染状态的设定，这些指令可以设置显卡的各种状态，例如是否开启混合/深度测试等。
状态名称 　　    设置指令 　　　　　　　　　　 　　　　　　　　　　 　　　　 解释
Cull 　　　　Cull Back|Front|Off 　　　　 　　　　　　　　　　　　　　　　设置剔除模式，剔除背面|正面|关闭剔除  默认CullBack
ZTest 　　　ZTest Less Greater|LEqual|GEqual|Equal|NotEqual|Always 　　 设置深度时使用的函数　　　　　　　　默认ZTest LEqual 小于或等于目标深度才能被渲染
ZWrite 　　  ZWrite On|Off 　　　　　　　　　　　　　　　　　　　　　　　开启和关闭深度写入　　　　　　　　  默认ZWrite On
Blend 　　　Blend SrcFactor DstFactor 　　　　　　　　　　　　　　　　　 开启并设置混合模式　　    　　　　　　　

　　**当在SubShader块中设置了上述状态，将会被应用于所有的Pass。如果不想这样（例如在双面渲染中，我们可以希望第一**
**个Pass剔除正面来对背面进行渲染，在第二个Pass中选择剔除背面来对正面进行渲染），可以在Pass内部来单独设置状态。**

**三【Tags标签】**
　　UnityShader的Tags是一个键值对（Key/Value Pair），他的键和值都是字符串类型。这些键值是对SubShader和渲染引擎
之前沟通的桥梁。他们用于告诉渲染引擎：怎么样和什么时候调用这个SubShader。
标签语法如下：Tags{"TagName1" = "Value1" "TagName2" = "Value2"}

SubShader标签类型：注意这些标签只能在SubShader中声明，不能再Pass中
　　标签类型 　　　　　　　　　　　　　　　　 说明 　　　　　　　　 　　　　　　　　 列　　　　子
Queue 　　　　　　　　     控制渲染顺序，指定该物体属于哪一个渲染队列 　　　　 Tags{"Queue" = "Transparent"}
RenderType 　　　　　　    对着色器分类。例如：这是一个不透明着色器 　　　　　 Tags{"RenderType" = "Opaque"}
DisableBatching 　　　　    一些SubShader在使用Unity批处理时会出现问题。
　　　　　　　　　　　　    可以用该标签直接表明是否使用批处理 　　　　　　　　 Tags{"DisableBatching" = "True"}
ForecNoShadowCasting 　　  控制该SubShader的物体是否会投射阴影 　　　　　　   Tags{"ForceNoShadowCasting" = "True"}
IgnoreProjector 　　　　　　 设置该SubShader的物体是否受Projector影响　　　　　  Tags{"IgnoreProjector" = "True"}
　　　　　　　　　　　　　　True常用与半透明物体。
CanUseSpriteAtlas 　　　　　 当该SubShader用于“sprite”时，将该标签设为False 　　 Tags{"CanUseSpriteAtlas" = "False"}
PriviewType 　　　　　　　　 材质面板的预览类型，一般默认材质预览效果是球形　　 Tags{"PreviewType" = "Plane"}
　　　　　　　　　　　　　　还可以该为"Plane" "SkyBox"。

 

**四【Pass语义块】**
Pass
{
　　[Name]
　　[Tags]
　　[RenderSetup]
　　//other code
}
1、[Name]Pass名称
　　Pass的名称，可以使用ShaderLab的UsePass命令来使用其他Shader的Pass代码
例如：UsePass"MyShader/MYPASSNAME",这样提高代码复用性，
注意：UnityShader内部会自动把PassName转换成大写格式。
2、[RenderSetup]Pass渲染状态设置
　　SubShader的渲染状态也适用于Pass，而且Pass还可以适用固定管线着色器的命令
3、[Tags]Pass的标签
　　Pass的标签不同于SubShader标签，这些标签用于告诉渲染引擎我们希望如何来渲染物体
　　标签类型 　　　　　　 说明　　　　　　　　　　　　　　　　 例子
LightModel　　　　 定义该Pass在渲染管线中的角色 　　　　 Tags{"LightModel"="ForwardBase"}
RequireOption 　　 用于指定满足某些条件是才渲染该　　　　Pass Tags{"RequireOption" = "SoftVegetation"}

ColorMask　       可以让我们制定渲染结果的输出通道，而不是通常情况下的RGBA这4个通道全部写入。可选参数是 RGBA 的任意组合以及 0， 这将意味着不会写入到任何通道。



# Unity Shader Graph

#### 使用前准备

1. 安装Universal RP

   点击菜单`Window - Package Manager`，打开`Package Manager`窗口。

   点击`Packages`，选择`Unity Registry`

   然后搜索`Universal RP`，点击`Install`按钮，等等安装完毕。

2. 创建Pipeline Assets

   在`Project`窗口中`右键 - Create - Rendering - Universal Render Pipeline - Pipeline Asset (Forward Renderer)`，即可创建一个`Pipeline Assets`资源：`UniversalRenderPipelineAssets`。

3. 设置Pipeline Assets

   点击菜单 `Edit - Project Settings`，弹出`Project Settings`窗口，点击`Graphics`，

   将上面创建的`UniversalRenderPipelineAssets`拖到`Scriptable Render Pipeline Settings`中。

#### 材质分类

1. 现在游戏常用材质分为PBR(Standard)和不受光材质(Unlit)。
2. 次世代游戏用的是PBR材质,其中最基本的是4张贴图:颜色贴图,Normal贴图,AO贴图,高光贴图。
3. 不受光材质:像魔兽世界把特效关闭, 一个模型的只靠最基本的颜色贴图, 游戏中的灯光用的也是图片模拟的光晕, 材质根本不受光。 低模一个颜色贴图足够,特别适合现在的移动端游戏。
4. 由于不受光材质比PBR的性能高出太多,PBR的浮点计算量大概是PBR4个贴图都用上的10几倍。

#### PBR Graph的简单使用

1. 创建PBR Graph

   在`Project`窗口中`右键-Create-Shader-PBR Graph`，即可创建一个`PBR Graph`脚本。

   点击左上角的属性窗口中的`+号`可以创建变量。

2. 将变量拖动到操作区中,将节点连到`PBR Master`节点的插槽中,

   点击`Save Asset`即可保存`ShaderGraph`文件。

3. 创建一个`Material`材质球：`PBRTestMaterial`，然后直接将`ShaderGraph`文件拖动到材质球文件上即可。