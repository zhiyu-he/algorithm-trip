#include <stdio.h>
#include <string.h>
/**
   首先 最长递增子串，可以通过dp来求解，并用dp＋二分加速

   最长公共子串，需要求解的sub_str同时出现在串1，与串2中，衍生至`n个串的公共子串`

   一些条件:
   1. 公共子串最长为，min (str1.len, str2.len)
   
   求解方法:
   1. 穷举str1, 与str2的子串数量，然后依次求得 长度为[1, min(str_1.len, str_2.len)]中的最大值
   2. 利用dp的方式求解话，则相当于请求长度为1的公共子串，长度为2的公共子串，balabala？

   参考 结构之道中的讲解 ref:http://blog.csdn.net/v_JULY_v/article/details/6110269
   
     假设 字符串X、Y的长度分别为m, n, 1 <= i <=m; 1 <= j <= n
     公共子序列为zk
     那么可以推导
     当 Xi == Yj 时 必有Zk = Xi = Yj 即 Zk = LCS(Xi - 1, Yj - 1) + (Xi || Yi)

     当 Xi != Yj 时 max { LCS(Xi - 1 , Yj), LCS(Xi, Yj - 1) }
         Xi与Xj的最大子序列，与 Xi - 1, Yj  用 '<' 标记 || Xi, Yj - 1 用 '>' 标记

  一些思考:
  1. 字符串的组织形式，数组、链表、树，其中的优势、劣势
*/

char s1[1000];
char s2[1000];

int c[1001][1001];
char b[1001][1001];

int max_len = 0;
int i1, j1; // 用于定位一组解

void common_str(int l1, int l2);
void print_lcs();

int main()
{
  
  gets(s1);
  gets(s2);
  
  int l1, l2;
  l1 = strlen (s1);
  l2 = strlen (s2);
  
  int i, j;
  //  int j;

  for (i = 0; i <= l1; i++)
    b[i][0] = '?';
  for (j = 0; j <= l2; j++)
    b[0][j] = '?';
  common_str (l1, l2);

  print_lcs (i1, j1);
  printf ("\n");
  return 0;
}

void print_lcs (int i, int j)
{
  if (i == 0 || j == 0)
    return;
  if (b[i][j] == '=')
    {
      //      printf ("(i, j) -> (%d, %d) \n", i, j);
      print_lcs (i - 1, j - 1);
      printf("%c", s1[i - 1]);
    }
  else if (b[i][j] == '<')
    print_lcs (i -  1, j);
  else
    print_lcs(i, j - 1);
}

void common_str(int l1, int l2)
{
  int i, j;
  for (i = 1; i <= l1; i++)
    for (j = 1; j <= l2; j++)
      {
        c[i][j] = 0;
        if (s1[i - 1] == s2[j - 1])
          {
            //    printf("i: %d, j: %d, c[i - 1][j - 1]: %d\n", i, j, c[i -1][j - 1]);
            c[i][j] = c[i - 1][j - 1] + 1;
            b[i][j] = '=';
            if (c[i][j] > max_len)
              {
                max_len = c[i][j];
                i1 = i;
                j1 = j;
              }
          }
        else if (c[i - 1][j] >= c[i][j - 1])
          {
            c[i][j] = c[i - 1][j];
            b[i][j] = '<'; // 与s1 - 1的公共子序列相同
          }
        else
          {
            c[i][j] = c[i][j - 1];
            b[i][j] = '>'; // 与s2 -1的公共子序列相同
          }
      }
}
