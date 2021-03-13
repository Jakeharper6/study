#### **UnityObjectToClipPos()函数**

将世界空间的模型坐标转换到裁剪空间，函数内部封装了实现顶点坐标变换的具体细节，如矩阵变换等等。

这个函数将在局部空间中表示的顶点，变换到渲染相机的裁剪空间。注意是通过设置o.position的位置来传递转换的点，例：

```glsl
v2f vertexFunction(a2v v){
    v2f o;
    o.position = UnityObjectToClipPos(v.vertex);
    return o;
}
```



#### UnityObjectToWorldDir()函数和UnityObjectToWorldNormal()函数

**UnityObjectToWorldDir**用于把模型空间下的矢量转换到世界空间

**UnityObjectToWorldNormal**用于把模型空间下的法线向量转换到世界空间。因为必须保证法线垂直于模型的表面，所以缩放的时候与普通矢量不一样。例：

```glsl
v2f vert (appdata v){
    v2f o;
    o.pos = UnityObjectToClipPos(v.vertex);
    o.worldNormal = UnityObjectToWorldNormal(v.normal);		
    o.viewDir = WorldSpaceViewDir(v.vertex);
    o.uv = TRANSFORM_TEX(v.uv, _MainTex);
    TRANSFER_SHADOW(o)
    return o;
}
```



#### normalize()函数

使该向量进行标准化，其的长度为1.0，但方向保持不变。

注：此函数将该更改向量，如果要保持当前向量不变，应使用normalized。

单位矢量
在很多情况下，我们只关心矢量的方向而不是模。此时我们就需要计算单位矢量（unit vector）。
单位矢量指的是那些模为1的矢量。单位矢量也被称为被归一化的矢量（normalized vector）。对任何给定的非零矢量，把它转换成单位矢量的过程就被称为归一化（normalization）。
为了对矢量进行归一化，我们可以用矢量的模除以该矢量来得到。

#### abs()函数

取绝对值



#### 投射阴影

```glsl
UsePass "Legacy Shaders/VertexLit/SHADOWCASTER"
```

添加到pass代码块外



#### **lerp()函数**

例：`lerp(a, b, w)`

a与b为同类型，即都是float或者float2之类的，那lerp函数返回的结果也是与ab同类型的值。
w是比重，在0到1之间
当w=0时返回a，w=1时返回b，在0-1之间时，以比重w将ab进行线性插值计算即w*(b-a)。



#### step()函数

`step(a, x)`

如果x<a返回0；如果x>或=a返回1

通常用来取代if-else代码



#### clamp()函数

`clamp(x, a, b)`

如果x<a返回a；如果x>b返回b；如果在a和b之间就返回x



#### dot()函数

`dot(a, b)`

dot()返回的是两个向量的点积(dot product)



#### smoothstep函数

`smoothstep(a, b, x)`

当x<a时返回a，当x>b时返回b，否则在a-b间平滑过渡