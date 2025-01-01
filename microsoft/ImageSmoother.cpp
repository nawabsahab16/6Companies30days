class Solution {
public:

   vector<vector<int>> directions {{-1, 0}, {-1, 1}, {0, 1}, {1, 1},
                              {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

     bool helper(int i, int j , int m, int n) { 
       return i >= 0 && i < m && j >= 0 && j < n;
     }                

     int solve(vector<vector<int>> &img, int i, int j) {
         
        int sum = img[i][j], count = 1;

        for(const auto &dir : directions) {
            int neighbourI = i + dir[0], neighbourJ = j + dir[1];

            if(helper(neighbourI, neighbourJ, img.size(), img[0].size())) {
                sum += img[neighbourI][neighbourJ];
                count++;
            }
        }
       return floor(sum/count);
     }
 
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> answer(m, vector<int>(n,0));

         for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                answer[i][j] = solve(img, i, j);
            }
         }
         return answer;
    }
};