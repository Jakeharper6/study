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