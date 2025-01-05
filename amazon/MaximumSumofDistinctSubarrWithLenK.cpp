class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long max_sum = 0;
        long long window_sum = 0;
        int start = 0;
        int n = nums.size();
        std::unordered_map<int, int> map;

        for (int i = 0; i < n; ++i) {
            window_sum += nums[i];
            map[nums[i]]++;

            if (i - start + 1 == k) {
                if (map.size() == k) {
                    max_sum = std::max(max_sum, window_sum);
                }

                window_sum -= nums[start];
                if (--map[nums[start]] == 0) {
                    map.erase(nums[start]);
                }
                ++start;
            }
        }

        return max_sum;
    }
};