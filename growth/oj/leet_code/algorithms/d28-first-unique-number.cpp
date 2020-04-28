#include<iostream>
#include<unordered_map>
#include<list>


using namespace std;

class FirstUnique {
public:
    list<int> uniqe_list;
    unordered_map<int, int> num_counter;
    unordered_map<int, list<int>::iterator> num_2_position;

    FirstUnique(vector<int>& nums) {
        for(auto num : nums) {
            add(num);
        }
    }

    int showFirstUnique() {
        return uniqe_list.begin() == uniqe_list.end() ? -1 : *uniqe_list.begin();
    }

    void add(int value) {
        if (num_counter.find(value) == num_counter.end()) {
            num_counter[value] += 1;
            auto pos = uniqe_list.insert(uniqe_list.end(), value);
            num_2_position[value] = pos;
        } else {
            auto a = num_counter[value];
            if (num_counter[value] == 1) {
                uniqe_list.erase(num_2_position[value]);
                num_2_position.erase(value);
            }
            num_counter[value] += 1;

        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

int main() {
    Solution s;
    
    return 0;
}
