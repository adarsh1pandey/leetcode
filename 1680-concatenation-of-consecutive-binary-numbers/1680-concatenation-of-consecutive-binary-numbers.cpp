class Solution {
public:
    int concatenatedBinary(int n) {
        long long val = 0;
        int i = 1;
        while (i <= n)
        {
            val = ((val << (1 + int(log2(i)))) % 1000000007 + i) % 10000000007;
            i++;
        }
        return val;
    }
};