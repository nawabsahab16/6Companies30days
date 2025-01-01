class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> num1(nums);

        sort(num1.begin(), num1.end());

         int i = n - 1;
         int j = 0;
         int k = (n/2) + (n % 2);

          while(i >= 0) {
            if(i % 2 == 1) {
                nums[i] = num1[k];
                k++;
            }
            else {
                nums[i] = num1[j];
                j++;
            }
           i--;
          }
    }
};