### 二叉堆

> `二叉堆`可将其视为是一种`完全二叉树`，树中元素又左向右填充，并满足如下性质

定义i为树中结点下标，则

* 父结点 = i / 2
* 左结点 = 2i
* 右结点 = 2i + 1


#### 堆的常见类型

1. 最大堆: A[PARENT(i)] >= A[i] 
2. 最小堆: A[PARENT(i)] <= A[i]

#### 堆的常见性质

1. 堆的高度: 