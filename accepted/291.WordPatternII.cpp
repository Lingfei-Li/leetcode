#include"mytest.h"

class Solution {
public:

    unordered_map<char, string> dict;
    unordered_set<string> st;


    bool match(string& s1, string& s2, int p2) {
        if(s2.length()-p2 < s1.length()) return false;

        for(unsigned int i = 0; i < s1.length(); i ++) {
            if(s1[i] != s2[p2+i]) return false;
        }

        return true;
    }

    bool solve(string& pattern, int p1, string& str, int p2) {
        if(p1 == pattern.length() && p2 == str.length()) return true;
        if(dict.count(pattern[p1])){
            if(match(dict[pattern[p1]], str, p2)) {
                return solve(pattern, p1+1, str, p2+dict[pattern[p1]].length());
            }
            else {
                return false;
            }
        }
        else {
            for(unsigned int i = p2; i < str.length(); i ++) {   //prune?
                string subs = str.substr(p2, i-p2+1);
                if(!st.count(subs)){
                    st.insert(subs);
                    dict[pattern[p1]] = subs;
                    if(solve(pattern, p1+1, str, i+1)) return true;
                    st.erase(subs);
                    dict.erase(pattern[p1]);
                }
            }
        }
        return false;
    }


    bool wordPatternMatch(string pattern, string str) {
        return solve(pattern, 0, str, 0);
    }

};

int main() {
	srand(time(NULL));

    string s1, s2;
    while(cin>>s1>>s2){
        Solution sol;
        cout<<sol.wordPatternMatch(s1, s2)<<endl;
    }



    return 0;
}
