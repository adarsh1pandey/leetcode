class Solution {
public:
    int concatenatedBinary(int n) {
        long long val = 0;
        int mod = 1e9 + 7;
        int i = 1;
        while (i <= n)
        {
            val = ((val << (1 + int(log2(i)))) % mod + i) % mod;
            i++;
        }
        return val;
    }
};