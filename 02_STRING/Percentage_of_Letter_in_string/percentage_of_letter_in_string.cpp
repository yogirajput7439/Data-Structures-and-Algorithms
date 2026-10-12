class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        int ans = 0;

        for(char x : s){
            if( x == letter){
                count+=1;
            }
        }

        ans = (count * 100) / s.length();

        if(ans > 0){
            return ans;
        }
        else {
            return 0;
        }
    }
};
