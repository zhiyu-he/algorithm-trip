class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        merge_sort(nums, 0, nums.size()-1);
        return nums;
        
    }
    
    void quick_sort(vector<int>& nums, int l, int r) {
        if (l > r) return;
        
        int c = nums[r];
        
        // 目标所有比c小的都在左边，大于等于c的都在右边
        
        int ptr_l = l, ptr_r = r;
        
        while(ptr_l < ptr_r) {
            while(nums[ptr_l] < c && ptr_l < ptr_r) ptr_l += 1;
            while(nums[ptr_r] >= c && ptr_r > ptr_l) ptr_r -= 1;
            if (ptr_l < ptr_r) {
                int tmp = nums[ptr_r];
                nums[ptr_r] = nums[ptr_l];
                nums[ptr_l] = tmp;
            }
        }
        int tmp = nums[ptr_l];
        nums[ptr_l] = c;
        nums[r] = tmp;
        quick_sort(nums, l, ptr_l-1);
        quick_sort(nums, ptr_r+1, r);
    }
    void merge_sort(vector<int>& nums, int l, int r) {
        
        if (l < r) {
            int mid = (r-l) / 2 + l;
            merge_sort(nums, l, mid);
            merge_sort(nums, mid + 1, r);
            merge(nums, l, mid, r);
        }
    }
    void merge(vector<int>& nums, int l, int mid, int r) {
        vector<int> l1;
        vector<int> l2;
        for (int i = l; i <= mid; i++)
            l1.push_back(nums[i]);
        for (int i = mid+1; i <= r; i++)
            l2.push_back(nums[i]);
        
        int i = 0, j = 0;
        int start = l;
        while(i < l1.size() && j < l2.size()) {
            if (l1[i] < l2[j]) {
                nums[start++] = l1[i++];
            } else {
                nums[start++] = l2[j++];
            }
        }
        while(i < l1.size()) {
            nums[start++] = l1[i++];
        }
        while(j < l2.size()) {
            nums[start++] = l2[j++];
        }
    }
};


int main() {
	return 0;
}
