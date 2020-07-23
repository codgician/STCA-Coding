class Solution {
public:
    int char2int(int n) {
        if (n == 'A') return 0;
        if (n == 'G') return 1;
        if (n == 'C') return 2;
        return 3;
    }
    string int2str(int n) {
        const int ch[4] = {'A', 'G', 'C', 'T'};
        string ret;
        for (int i = 0; i < 10; i++) {
            ret.push_back(ch[n & 3]);
            n >>= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> mp;
        int cur = 0, i = 0, len = s.size();
        int mask = ((1 << 19) - 1) & ((1 << 18) - 1);
        for (; i < 10; i++)
            cur = (cur << 2) + char2int(s[i]);
        mp[cur]++;
        for (; i < len; i++) {
            cur &= mask;
            cur = (cur << 2) + char2int(s[i]);
            mp[cur]++;
        }
        vector<string> vec;
        for (const auto & p : mp)
            if (p.second > 1)
                vec.push_back(int2str(p.first));
        return vec;
    }
};
