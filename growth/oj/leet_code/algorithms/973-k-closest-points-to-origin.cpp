#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        vector<int> euclidean_dis;
        for (auto point : points) {
            euclidean_dis.push_back(point[0]*point[0] + point[1] * point[1]);
        }
        cout << euclidean_dis.size() << endl;
        cout << points.size() << endl;



        int range_l = 0;
        int range_r = points.size() - 1;

        while(true) {

            int left_ptr = range_l;
            int right_ptr = range_r;
            int base = range_l;
            int pivot_val = euclidean_dis[base];


            while(left_ptr != right_ptr) {
                while(euclidean_dis[right_ptr] > pivot_val && left_ptr < right_ptr)
                    right_ptr -= 1;
                while(euclidean_dis[left_ptr] <= pivot_val && left_ptr < right_ptr)
                    left_ptr += 1;

                if (left_ptr < right_ptr) {
                    int tmp = euclidean_dis[left_ptr];
                    vector<int> point = points[left_ptr];
                    euclidean_dis[left_ptr] = euclidean_dis[right_ptr];
                    points[left_ptr] = points[right_ptr];
                    euclidean_dis[right_ptr] = tmp;
                    points[right_ptr] = point;
                }
            }

            int tmp = euclidean_dis[range_l];
            vector<int> point = points[range_l];
            euclidean_dis[range_l] = euclidean_dis[left_ptr];
            points[range_l] = points[left_ptr];
            euclidean_dis[left_ptr] = tmp;
            points[left_ptr] = point;

            //cout << left_ptr+1 << endl;
            if (left_ptr-0+1 == K)
                break;
            else if (left_ptr-0+1 > K) {
                range_r = left_ptr -1;
            } else {
                range_l = left_ptr + 1;
            }
        }

        for (int i = 0; i < K; i++)
            res.push_back(points[i]);
        return res;
    }
};

int main() {
    Solution s;
    
    return 0;
}
