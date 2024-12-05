class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        set<char> charSet;
        int beg = 0;
        
        for (int i = 0; i < n; i++) {
            if (charSet.count(s[i]) == 0) {
                charSet.insert(s[i]);
                maxLength = max(maxLength, (int)charSet.size());
            } else {
                while (charSet.count(s[i])) {
                    charSet.erase(s[beg]);
                    beg++;
                }
                charSet.insert(s[i]);
            }
        }
        
        return maxLength;
    }
};
