class Solution {
    public:
        int firstUniqChar(string s) {
            vector<int> count(26, 0); // Frequency of each lowercase letter
    
            // Count the frequency of each character
            for (char c : s) {
                count[c - 'a']++;
            }
    
            // Find the first character with frequency 1
            for (int i = 0; i < s.length(); i++) {
                if (count[s[i] - 'a'] == 1) {
                    return i;
                }
            }
    
            return -1; // No unique character found
        }
    };
    