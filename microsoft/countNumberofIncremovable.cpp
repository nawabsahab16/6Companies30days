class Solution {
public:
    
    bool solve(vector<int>&nums, int left, int right) {
        int n = nums.size();
        int prev = INT_MIN;

        for(int i = 0; i < n; i++) {
            if((left <= i) && (i <= right)) continue;
            if(prev >= nums[i]) return false;
            prev = nums[i];
        }
        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
         for(int left = 0; left < n; left++) {
            for(int right = left; right < n; right++) {
                if(solve(nums, left, right)) answer++;
            }
         }
         return answer;
    }
};