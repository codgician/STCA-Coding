class Solution {
public:
    int maximum(int a, int b) {
        long long d = (long long)b - a;
        return a + d * ((d >> 63) & 1 ^ 1);
    }
};
