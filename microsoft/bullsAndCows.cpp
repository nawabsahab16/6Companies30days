class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> freq(10,0);

        string answer;
        int bull = 0, cow = 0;

        for(int i = 0; i < secret.size(); i++) {
            if(guess[i] == secret[i]) {
                bull++;
            }
            else {
                if(freq[secret[i] - '0']++ < 0) cow++;
                if(freq[guess[i] - '0']-- > 0) cow++;
            }
        }
        answer = to_string(bull)+ 'A' + to_string(cow) + 'B';
        return answer;
    }
};