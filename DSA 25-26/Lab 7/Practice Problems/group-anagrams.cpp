/*
  Given an array of strings strs, group the anagrams together. You can return the answer in any order.
  */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> soln;

        for(const string& s: strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            soln[key].push_back(s);
        }

        vector<vector<string>> result;

        for(auto &pair: soln)
            result.push_back(pair.second);
        
        return result;
    }
};
