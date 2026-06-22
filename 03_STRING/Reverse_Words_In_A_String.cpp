// 1. Optimal Solution with 0(n) time Complexity

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string str = "";

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ' && str != "") {
                ans = str + ' ' + ans;
                str = "";
            }
            else if(s[i] != ' ') {
                str += s[i];
            }
        }

        if(str != "") {
            ans = str + ' ' + ans;
        }

        if(!ans.empty()) {
            ans.pop_back(); // remove last extra space
        }

        return ans;
    }
};
