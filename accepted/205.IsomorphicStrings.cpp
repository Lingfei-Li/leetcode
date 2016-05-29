// 55% med
// hashmap

#include"mytest.h"

bool isIsomorphic(string s, string t) {
    if(s.length() != t.length()) return false;
    int n = s.length();
    unordered_map<char, char> dict;
    unordered_set<char> st;
    for(int i = 0; i < n; i ++) {
        if(dict.count(s[i])) {
            if(t[i] != dict[s[i]]) return false;
        }
        else {
            if(st.count(t[i])) return false;
            dict[s[i]] = t[i];
            st.insert(t[i]);
        }
    }
    return true;
}



int main() {
	srand(time(NULL));

    string s, t;
    while(cin>>s>>t) {
        cout<<isIsomorphic(s, t)<<endl;
    }



    return 0;
}
