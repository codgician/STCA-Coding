class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size(), cnt = 1, i = 0, j;
        for (j = 1; j < len; j++) {
            if (nums[i] == nums[j]) {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    i = ++j, cnt = 1;
                }
            }
        }
        return i < len ? nums[i] : nums[j];
    }
};
