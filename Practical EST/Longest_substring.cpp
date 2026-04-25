class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            string temp = "";
            for (int j = i; j < s.length(); j++) {
                if (temp.find(s[j]) != string::npos)
                    break;
                temp += s[j];
                maxLen = max(maxLen, (int)temp.length());
            }
        }
        return maxLen;
    }
};
