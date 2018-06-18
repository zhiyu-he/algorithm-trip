#include <stdio.h>

/*
 * 关于冒泡排序
 * 1. 原地的
 * 2. 时间复杂度O(n^2)
 * 3. 需要思考的点为:
 *     3.1 最终的状态是什么?
 *     3.2 比较的是什么?
 * 4. e.g len(array) == 2 循环1次，比较1次
 *    e.g len(array) == 3 循环2次，比较2+1次
 *    e.g len(array) == 4 循环3次, 比较3+2+1次
 *    因此，我们可以归纳出 元素为N的时候，实际复杂度为一个等差数列 (n-1)*(n-2)*....*1-> 即O(n^2)
 *
 */
int main()
{
    int n;
    scanf("%d", &n);
    
    int num[100];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", num[i]);    
    }
    printf("\n");
	
	// control loop times = n - 1
	for(int i = 0; i < n - 1; i++)
	{	
		for(int j = 0; j < n-i-1; j++)
		{
			if(num[j] > num[j+1])
			{
				int tmp = num[j];
				num[j] = num[j+1];
				num[j+1] = tmp;
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
    return 0;
}
