class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int lims[26] = {0}, ans = 0;
        for (const auto & ch : letters)
            lims[ch - 'a']++;
        int len = words.size();
        for (int st = 0; st < (1 << len); st++) {
            int cnt[26] = {0}, scr = 0;
            bool valid = true;
            for (int i = 0; i < len && valid; i++) {
                if (st & (1 << i)) {
                    for (const auto & ch : words[i]) {
                        cnt[ch - 'a']++, scr += score[ch - 'a'];
                        if (cnt[ch - 'a'] > lims[ch - 'a']) {
                            valid = false; break;
                        }
                    }
                }
            }
            if (valid)
                ans = max(ans, scr);
        }
        return ans;
    }
};
