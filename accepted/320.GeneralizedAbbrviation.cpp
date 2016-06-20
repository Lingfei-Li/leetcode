#include"mytest.h"

class Solution {
public:

    void solve(string s, int pos, vector<string>& ans, string& prefix){

        if(pos >= s.length()) {
            ans.push_back(prefix);
            return;
        }

        int prev_len = prefix.length();
        prefix.push_back(s[pos]);
        solve(s, pos+1, ans, prefix);
        prefix.resize(prev_len);

        for(int i = pos; i < s.length(); i ++) {
            prefix += to_string((long)i-pos+1);
            if(i+1 < s.length())
                prefix.push_back(s[i+1]);
            solve(s, i+2, ans, prefix);
            prefix.resize(prev_len);
        }
    }


    vector<string> generateAbbreviations(string word) {
        vector<string> ans;

        string prefix = "";
        solve(word, 0, ans, prefix);

        return ans;
        
    }
};

int main() {
	srand(time(NULL));

    Solution sol;
    string word;
    while(cin>>word)
        print(sol.generateAbbreviations(word));



    return 0;
}
