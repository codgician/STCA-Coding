class Solution {
public:
    int xorSum(int n) {
        int rem = n & 3;
        if (rem == 0) return n;
        if (rem == 1) return 1;
        if (rem == 2) return n + 1;
        return 0;
    }
    int missingNumber(vector<int>& nums) {
        int ret = xorSum(nums.size());
        for (auto & i : nums)
            ret ^= i;
        return ret;
    }
};

