#include <stdio.h>

// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1134


#define MAX_LEN 50001

int lis[MAX_LEN];           // 代表以nums[i]结尾的, 最大子序列长度
int max_value[MAX_LEN];     // 代表以长度为lis[i]的子序列中, 结尾数字最小的那个, 原因在于, 只要当前array[i] > max_value[lis[k]], 那么意味着, 最大长度就要+1
int max_len;                // 最长子序列长度
long nums[MAX_LEN];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%ld", &nums[i]);
        lis[i] = 1;
    }
    // 处理一下当只有一个元素时的状态
    lis[1] = 1;
    max_value[1] = nums[1];
    max_len = 1;
    // 依次处理所有元素
    for (int i = 1; i <= n; i++)
    {   
        for (int j = i - 1; j >= 1; j--)
        {
            // 此处可以进行优化, 我们思考下一下, 当第i个元素出现, 只有两种可能
            // 第一种,可以加入某个序列的结尾, 重点看下这种, 那么究竟这个nums[i], 放入那个序列呢? 
            // 我们考虑一个问题, 在`同长度`选最小结尾, 那么意味着, 这个下标含义为长度, 值为最小结尾，的数组是单调递增的
            // 所以，我们去这个数组种进行二分，nums[i]，返回的数组下标，就是len, 进而用lis[len] + 1 和 1 进行比较即可
            // 第二种,对所有序列无影响, 在这种case下, 也就是nums[i] < nums[k], 因此 lis[i] = 1
            if (nums[i] > nums[j])
            {
                int tmp = lis[j] + 1;
                if (tmp > lis[i])
                    lis[i] = tmp;
            }
        }
        if (lis[i] > max_len)
        {
            max_len = lis[i];
        }
    }

    printf("%d\n", max_len);
    return 0;
}
