#include <stdio.h>
#include<iostream>
/*
 * Heap的几个基础概念
 *
 * Q1: Heap的存储: 本质是一颗完全二叉树
 *
 * Q2: Heap的调整: 调整是由某些动作触发的, 这些动作一般为`插入`、`删除(对堆顶元素的弹出也可以理解为删除的一种)`，而调整的目的在于维护堆的性质
 *
 * Q3: Heap的性质: 以最小堆为例, 1. 堆顶保存的元素全局最小 2. 给定任意元素heap[i]，其左右孩子分别为heap[i*2]与heap[i*2+1]，同时左右孩子的值小于等于父节点
 *
 * Q4: 堆的接口定义: 1. 
 */

using namespace std;

const int SIZE = 100;

struct Heap {
    int elements[SIZE + 1];
    int next_pos;
    int capacity;
};

Heap minHeap = {
    .next_pos = 1,
    .capacity = 100
};

// 当有新元素插入时, 执行Up操作
int up(Heap* h, int x) {
    int new_val = h->elements[x];
    int f = x;
    while (f/2 > 0 && h->elements[f/2] > new_val) {
        h->elements[f] = h->elements[f/2];
        f /= 2;
    }
    h->elements[f] = new_val;
    return 0;
}

int down(Heap* h, int x) {
    int new_val = h->elements[x];
    int f = x;
    for (f = x; f * 2 < h->next_pos;) {
        int child = f * 2;
        if (child + 1 < h->next_pos && h->elements[child] > h->elements[child+1]) {
            child = child + 1;
        }
        if (h->elements[child] > new_val) {
            break;
        }
        h->elements[f] = h->elements[child];
        f = child;
    }
    h->elements[f] = new_val;
    return 0;
}

int pop(Heap* h) {
    if (h->next_pos == 1)
        return -1;
    int res = h->elements[1];
    h->elements[1] = h->elements[h->next_pos-1];
    h->next_pos--;
    down(h, 1);
    return res;
}

int insert(Heap* h, int elem) {
    if (h->next_pos == h->capacity) return -1;
    h->elements[h->next_pos++] = elem;
    up(h, h->next_pos-1);
    return 0;
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++) {
        int val;
        scanf("%d", &val);
        insert(&minHeap, val);
    }
    for (int i = 1; i <= num; i++)
        printf("%10d", pop(&minHeap));
    return 0;
}
