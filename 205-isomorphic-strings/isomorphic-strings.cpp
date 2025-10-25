class Solution {
public:
    bool isIsomorphic(string s, string t) {
         if (s.size() != t.size()) return false;

        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // Check mapping from s → t
            if (mapST.count(c1) && mapST[c1] != c2) return false;

            // Check mapping from t → s
            if (mapTS.count(c2) && mapTS[c2] != c1) return false;

            // Add new mapping
            mapST[c1] = c2;
            mapTS[c2] = c1;
        }

        return true;
    }
};