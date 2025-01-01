class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

         nth_element(nums.begin(), nums.begin() + (n/2), nums.end());
         int median = nums[n/2];

         for(int i = 0; i < n; i++) {
            count += abs(nums[i] - median);
         }
         return count;
    }
};