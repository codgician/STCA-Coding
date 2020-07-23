class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> mp;
        for (const auto & s : words) {
            int st = 0;
            for (const auto & ch : s)
                st |= (1 << (ch - 'a'));
            mp[st]++;
        }
        vector<int> ans; ans.reserve(puzzles.size());
        for (const auto & s : puzzles) {
            int st = 0, cur = 0;
            for (const auto & ch : s)
                st |= (1 << (ch - 'a'));
            st &= ~(1 << (s[0] - 'a'));
            for (int subst = st; ; subst = st & (subst - 1)) {
                cur += mp[subst | (1 << (s[0] - 'a'))];
                if (subst == 0)
                    break;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
