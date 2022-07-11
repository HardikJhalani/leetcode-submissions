#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void combinationFinder(int ind, int target, vector<int> &c, vector<int> &ds, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
        
        for(int i = ind; i < c.size(); i++) {
            if(i > ind && c[i] == c[i - 1]) continue;
            if(target < c[i]) break;
            ds.push_back(c[i]);
            combinationFinder(i + 1, target - c[i], c, ds, ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        combinationFinder(0, target, candidates, ds, ans);
        return ans;
    }
};