class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       
      sort(envelopes.begin(), envelopes.end(),[](vector<int>& a, vector<int>& b){
        
        if(a[0]==b[0]) return a[1]>b[1];

        return a[0]<b[0];
       });

       int n = envelopes.size();

       vector<int> ans;
       ans.push_back(envelopes[0][1]);
       
       int len=1;
       for(int i=1;i<n;i++){
            if(envelopes[i][1]>ans.back()){
                ans.push_back(envelopes[i][1]);
                len++;
            }
            else{
                int low = lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[low] = envelopes[i][1];
            }
        }
    return len;
        
    }
};