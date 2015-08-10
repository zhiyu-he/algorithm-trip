/**
    树结构基本操作的实现
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
  char   data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int CreateBiTree(BiTree *T);

int main()
{
  int a = 1 == 1;
  printf("%d", a);
}



int CreateBiTree(BiTree *T)
{
  char ch;
  sacnf("%c", &ch);
  if (ch == '')
  {
    T = NULL;
  }
  else
  {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) exit();

    T->data = ch;
    CreateBiTree(T->lchild);
    CreateBiTree(T->rchild);
  }
  return 1;
}
