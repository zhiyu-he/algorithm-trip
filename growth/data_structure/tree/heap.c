#include <stdio.h>

// 堆, 其实就是完全二叉树, 那么什么是堆小堆, 什么是最大堆?
// 最小堆: 根元素都小于子节点
// 最大堆: 根元素都大于子节点
// 删除操作: 当从堆顶移除一个元素后, 只需要对最后一个元素进行shiftup即可 // why not?
// 删除操作: 从当前堆顶删除一个元素后, h[1] = h[n], shiftdown(h[1])
// 插入操作: 放入到最后h[n+1] = val, siftup(h[n+1])
// 同时我们思考一下, 如何利用堆对一组数字进行排序, 假设由小->大

// 以小顶堆为例

int array[101], n;

// 什么情况下会siftup?
void siftup(int i)
{
    // 我们要比较当前节点和父节点的大小关系, 如果比父节点小, 则continue, 否则交换
    int flag = 0;
    if (i == 1)
        return;
    int t = i / 2;
    while (t != i && flag != 0)
    {
        t = i / 2;
        if (array[t] > array[i]) {
            int m = array[t];
            array[t] = array[i];
            array[i] = m;
            i = t;
        } else {
            flag = 1;
        }
    }
}

// 什么情况下会siftdown?
void siftdown(int i)
{
    int flag = 0;
    while (i * 2 <= n && flag == 0)
    {
        // Q: 为什么一定要在左右孩子中选择出最小的那个?
        int t = i;
        // 先处理左儿子
        if (i *2 <= n && array[i*2] < array[i])
            t = i * 2;
        // 处理右儿子 
        if (i*2+1 <= n && array[i*2+1] < array[t])
            t = i * 2 +1;
        if (t != i)
        {
            int m = array[t];
            array[t] = array[i];
            array[i] = m;
            i = t;
        } else {
            flag = 1;
        }
    }
}

void creat()
{
    int i;
    for (i = n /2; i >= 1; i--)
        siftdown(i);
    return;
}

int deletemin()
{
    int t;
    t = array[1];
    array[1] = array[n];
    n--;
    siftdown(1);
    return t;
}

int main()
{
    int num;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
        scanf("%d", &array[i]);
    n = num;
    creat();
    for (int i = 1; i <= num; i++)
        printf("%10d", deletemin());
    return 0;
}
