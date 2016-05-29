#include<cstdio>
#include<cstring>
#include<algorithm>

#include<vector>

#include<queue>
#include<string>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<set>
#include<map>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;


//Global Variables.

////

string longestCommonPrefix(vector<string>& strs) {
    int l;
    string s;
    if(!strs.size()) return s;
    for(l = 0; ; l ++) {
        char c = strs[0][l];
        for(int i = 0; i < strs.size(); i ++) {
            if(l >= strs[i].length() || strs[i][l] != c)
                goto END;
        }
    }

    END:
    s = strs[0].substr(0, l);
    return s;
}


int main() {

    vector<string> v;
    string s;
    while(cin>>s) {
        v.push_back(s);
        cout<<longestCommonPrefix(v)<<endl;;
    }




    return 0;
}
