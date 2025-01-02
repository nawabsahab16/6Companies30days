class Solution {
public:

    int helper(vector<int>&price, vector<vector<int>>& special, vector<int>& needs, int index, int n) {
      
       if(index == special.size()) {
        int temp = 0;
        for(int i = 0; i < n; i++) {
            temp += (needs[i] * price[i]);
        }
        return temp;
       }
       int flag = 0;
       for(int i = 0; i < n; i++) {
        if(special[index][i] > needs[i]) flag = 1;
       }
       if(flag == 0) {
        for(int i = 0; i < n; i++) {
            needs[i] -= special[index][i];
        }
        int take = special[index][n] + helper(price, special, needs, index, n);
        for(int i = 0; i < n; i++) {
            needs[i] += special[index][i];
        }
        return min(take, helper(price, special, needs, index+1, n));
       }
       return helper(price, special, needs, index + 1, n);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        int answer = helper(price, special, needs, 0, n);

        return answer;
    }
};