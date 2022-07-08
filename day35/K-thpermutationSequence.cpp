class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> nums;
        int fact = 1;
        for(int i = 1; i < n; i++){
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k--;
        while(true){
            
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            k %= fact;
            if(nums.size() == 0) break;
            fact /= nums.size();
        }
        return ans;
    }
};
