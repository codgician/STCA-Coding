class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ret = 0;
        for (int t = 1 << 30; t > 0; t >>= 1) {
            if ((m & t) != (n & t))
                break;
            ret |= ((m & t) ? t : 0);
        }
        return ret;
    }
};
