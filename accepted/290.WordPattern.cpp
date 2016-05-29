// 0ms
// stringstream
// bijection: how to enforce the relationship?

#include"mytest.h"

bool wordPattern(string pattern, string str) {
    if(!pattern.length() || !str.length()) return false;
    unordered_map<char, string> mp;
    unordered_set<string> st;
    stringstream ss;
    ss<<str;
    string a;
    for(int i = 0; i < pattern.length(); i ++) {
        if(ss>>a == false) return false;
        if(mp.count(pattern[i])) {
            if(mp[pattern[i]] != a) return false;
        }
        else {
            if(st.count(a)) return false;
            mp[pattern[i]] = a;
            st.insert(a);
        }
    }
    if(ss>>a) return false;
    return true;
}



int main() {
	srand(time(NULL));

    cout<<wordPattern("abba", "cat cat cat cat");



    return 0;
}
