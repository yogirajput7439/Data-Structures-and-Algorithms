class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0)
            return 0;

        return (32 - __builtin_clz(num) - 1)
               + __builtin_popcount(num);
    }
};
