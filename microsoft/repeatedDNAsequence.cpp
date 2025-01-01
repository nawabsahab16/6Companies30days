class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string str = "";
        vector<string> result;

        if(s.length() < 10) return result;

        map<string, int> mp;

         for(int i = 0; i < 10 && i < s.length(); i++) {
            str += s[i];
         }
         mp[str]++;

          for(int i = 10; i < s.length(); i++) {
            str.erase(0,1);
            str += s[i];
            mp[str]++;
          }

          for(auto &it : mp) {
            if(it.second > 1) {
                result.push_back(it.first);
            }
          }
          return result;
    }
};