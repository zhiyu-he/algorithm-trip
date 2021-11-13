class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        /*
        Method1. TLE
        
        for (int i = 0; i < temperatures.size(); i++) {
            res[i] = 0;
            for (int j = i + 1; j < temperatures.size(); j++) {
                if (temperatures[j] > temperatures[i]) {
                    res[i] = j - i;
                    break;
                }
            }
        }
        */
        
        // method2. AC 
        for (int i = temperatures.size()-1; i >= 0; i--) {
            res[i] = 0;
            int min_max_i = i + 1;
            while(min_max_i < temperatures.size() && temperatures[i] >= temperatures[min_max_i] && res[min_max_i] > 0) {
                min_max_i = min_max_i + res[min_max_i];
            }
            if (min_max_i < temperatures.size() && temperatures[i] < temperatures[min_max_i])
                res[i] = min_max_i - i;
        }
        
        return res;
    }
};
