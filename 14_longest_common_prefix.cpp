class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) {
            return strs[0];
        }

        std::string cur{""};
        int i = 0;

        while(true) {
            char cur_char = 0;
            for(int j = 1; j < strs.size(); j++) {
                if(i >= strs[j].size() || strs[j][i] != strs[j - 1][i]) {
                    return cur;
                }
                
                cur_char = strs[j][i];
            }
            if(cur_char != 0) {
                cur += cur_char;
            }
            i++;
        }

        return cur;
    }
};
