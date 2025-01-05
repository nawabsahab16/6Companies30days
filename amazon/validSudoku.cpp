class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int checkrow [10][10] = {0}, checkcol[10][10]= {0}, checkbox[10][10] = {0};
        for(int row = 0; row <9; row++){
          for(int col = 0; col < 9; col++){
            if(board[row][col] == '.') continue;
            int number = board[row][col] - '0';
            int box = (row/3)*3 + (col/3);
            if(checkrow[row][number] || checkcol[number][col] || checkbox[box][number])
            return false;
            checkrow[row][number] = checkcol[number][col] = checkbox[box][number] = true;

          }
        }
        return true;
    }
};