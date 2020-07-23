class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> mp;
        bool cnt[26]; int len = s.size();
        for (int i = 0; i + minSize <= len; i++) {
            fill(cnt + 0, cnt + 26, false);
            string cur; int uniqueChars = 0;     
            for (int j = 0; j < maxSize && i + j < len; j++) {
                if (!cnt[s[i + j] - 'a'])
                    uniqueChars++;
                if (uniqueChars > maxLetters)
                    break;
                cnt[s[i + j] - 'a'] = true;
                cur.push_back(s[i + j]);
                if (j >= minSize - 1)
                    mp[cur]++;
            }
        }
        int ret = 0;
        for (const auto & p : mp)
            ret = max(ret, p.second);
        return ret;
    }
};
