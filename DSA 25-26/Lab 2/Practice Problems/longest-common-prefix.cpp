/*
  Write a function to find the longest common prefix string amongst an array of strings.
  If there is no common prefix, return an empty string "".
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        if (str.empty()) return "";
        sort(str.begin(), str.end());
        string first = str[0];
        string last = str[str.size() - 1];
        string ans = "";
        int minLength = min(first.size(), last.size());
        for (int i = 0; i < minLength; i++) {
            if (first[i] != last[i]) break;
            ans += first[i];
        }
        return ans;
    }
};
