#### _WorldSpaceLightPos0

表示：世界坐标中光源的位置或方向向量。

如果 _WorldSpaceLightPos0.w为0，表示该光源为平行光。

​		 _WorldSpaceLightPos0.w为1。则表示光源为点光源或聚光灯。



#### float

**float** : 常见的写法有 **float4** 和 float3
**float3** : 一般情况下我们指的是向量，例如 ：**float3** normal ：NORMAL
**float4** : 对那些需要操作的顶点用 **float4** 来表示 ，例如 ： **float4** vertex : POSITION
那么我们为什么用 **float4** 来表示我们想要的顶点呢？
在unity内部，通过矩阵的方式来描述这些点，一般情况下我们觉得 3*3的矩阵就能够描述一个点了，但是这样的点是没有办法进行变换的 ： 旋转、缩放还有平移。因此我们需要扩散到一个齐次坐标空间，用 float4 来表示。