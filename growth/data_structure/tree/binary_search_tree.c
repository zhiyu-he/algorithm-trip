#include <stdio.h>
#include <stdlib.h>

// 二叉搜索树，会保证所有的左节点都小于根节点、右节点都大于根节点
struct node
{
  int val;
  struct node *l, *r;
};

struct node * insert (struct node *p, int value)
{
  if (p == NULL)
    {
      struct node *q = (struct node *) malloc (sizeof (struct node));
      q->val = value;
      q->l = NULL;
      q->r = NULL;
      //      printf ("value: %d\n", q->val));
      return q;
    }
  else
    {
      if (p->val > value) // root大于value，插入右节点
        {
          p->l = insert (p->r, value);
        }
      else
        {
          p->r = insert (p->l, value);
        }
      return p;
    }
}

struct node * delete (struct node *p, int value)
{
  if (p == NULL)
    return NULL;
  else if (p->val > value)
    p->l = delete (p->l, value);
  else if (p->val < value)
    p->r = delete (p->r, value);
  else if (p->l == NULL) // 排除上述的>、<之后，这个为==的判断?!
    {
      struct node *q = p->r;
      free (p);
      return q;
    }
  else if (p->l->r == NULL)
    {
      struct node *q = p->l;
      q->r = p->r;
      free (p);
      return q;
    }
  else
    {
      struct node *q;
      for (q = p->l; q->r->r != NULL; q = q->r);
      struct node *r = q->r;
      q->r = r->l;
      r->l = p->l;
      r->r = p->r;
      free (p);
      return r;
    }
  return p;
}

int search (struct node *p, int value)
{
  if (p == NULL) return 0;
  
  if (p->val == value)
    return 1;
  else if (p->val > value)
    return search (p->l, value);
  else
    return search (p->r, value);
}

int main ()
{
  struct node *root = NULL;
  
  root = insert (root, 10);
  insert (root, 1);
  insert (root, 20);
  printf ("insert done\n");

  printf ("find 10: %d\n", search (root, 10));
  printf ("find 3: %d\n", search (root, 3));
  printf ("find 1: %d\n", search (root, 1));
  printf ("find 20: %d\n", search (root, 20));

  // delete
  root = delete (root, 1);
  
  printf ("delete done\n");
  // query
  printf ("find 10: %d\n", search (root, 10));
  printf ("find 3: %d\n", search (root, 3));
  printf ("find 1: %d\n", search (root, 1));
  printf ("find 20: %d\n", search (root, 20));

  return 0;
}
