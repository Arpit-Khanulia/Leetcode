class Solution {
public:
    
    unordered_map<string, int> memo;

    int solvethis(string& s, int i, set<string>& ss, string& ds) {
        string memoKey = to_string(i) + "-" + ds;
        if (memo.find(memoKey) != memo.end()) {
            return memo[memoKey];
        }

        int ans1 = INT_MAX;
        int ans2 = INT_MAX;
        int ans3 = INT_MAX;

        string dss = "";

        if (i == s.size()) return ds.size();

        ds.push_back(s[i]);

        if (ss.find(ds) != ss.end()) ans1 = solvethis(s, i + 1, ss, dss);

        ans2 = ds.size() + solvethis(s, i + 1, ss, dss);
        ans3 = solvethis(s, i + 1, ss, ds);

        ans1 = min(ans1, ans2);
        ans1 = min(ans1, ans3);

        memo[memoKey] = ans1;
        return ans1;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int i = 0;

        set<string> ss;
        for (auto word : dictionary) ss.insert(word);

        int ans = 0;
        string ds = "";

        ans = solvethis(s, i, ss, ds);

        return ans;
    }
};