class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int len = arr.size(), ret = 0;
        vector<int> pfx = arr;
        for (int i = 1; i < len; i++)
            pfx[i] ^= pfx[i - 1];
        unordered_map<int, pair<int, int> > mp;
        mp[0] = make_pair(1, 0);
        for (int i = 0; i < len; i++) {
            auto it = mp.find(pfx[i]);
            if (it != mp.end())
                ret += it -> second.first * i - it -> second.second;
            if (mp.find(pfx[i]) == mp.end())
                mp[pfx[i]] = make_pair(0, 0);
            mp[pfx[i]].first++;
            mp[pfx[i]].second += i + 1;
        }
        return ret;
    }
};
