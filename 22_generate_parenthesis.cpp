class Solution {
public:
    std::vector<std::string> vec{};

    void recurse_gen_parenth(int n, std::string cur, int num_open, int num_close) {
        // NOTE: last closing brace encountered stop recursing
        if(num_close == n) {
            vec.push_back(cur);
            return;
        }

        if(num_close < num_open) {
            if(num_open < n) {
                recurse_gen_parenth(n, cur + "(", num_open + 1, num_close);
            }
            
            recurse_gen_parenth(n, cur + ")", num_open, num_close + 1);
        } else {
            recurse_gen_parenth(n, cur + "(", num_open + 1, num_close);
        }
    }   

    vector<string> generateParenthesis(int n) {
        recurse_gen_parenth(n, "(", 1, 0);
        return vec;
    }   
};
