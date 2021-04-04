#include<iostream>
#include<vector>


using namespace std;
class MyCircularQueue {
public:
    vector<int> elements;
    int head = 0;
    int last = 0;
    int tail = 0;
    int cap = 0;
    int cur_cap = 0;
    MyCircularQueue(int k) {
        elements = vector<int>(k);
        cap = k;
    }
    
    bool enQueue(int value) {
        if (cur_cap >= cap) return false;
        cur_cap += 1;
        elements[tail] = value;
        last = tail;
        tail += 1;
        tail %= cap;
        return true;
    }
    
    bool deQueue() {
        if (cur_cap == 0) return false;
        cur_cap -= 1;
        head += 1;
        head %= cap;
        return true;
    }
    
    int Front() {
        if (cur_cap == 0) return -1;
        return elements[head];
    }
    
    int Rear() {
        if (cur_cap == 0) return -1;
        return elements[last];
    }
    
    bool isEmpty() {
        return cur_cap == 0;
    }
    
    bool isFull() {
        return cur_cap == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


int main() {
    return 0;
}
