#include<iostream>
#include<queue>

using namespace std;

class RecentCounter {
public:
    queue<int> frame;

    RecentCounter() {

    }

    int ping(int t) {
        frame.push(t);
        int delta = t - 3000;
        while(frame.size() > 0 && frame.front() < delta) {
            //cout << "q.front() " << frame.front() << endl;
            frame.pop();
        }
        return frame.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */


int main() {
    RecentCounter* obj = new RecentCounter();
    int param_1 = obj->ping(1);
    cout << param_1 << endl;
    return 0;
}
