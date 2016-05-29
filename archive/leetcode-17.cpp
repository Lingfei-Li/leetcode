

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

int trans(int a) {
    if(a < 7) {
        return 3*a-3;
    }
    else {

    }
}

vector<string> letterCombinations(string digits) {
    string match[10];
    match[0] = " ", match[1] = "", match[2] = "abc", match[3] = "def", match[4] = "ghi", match[5] = "jkl", match[6] = "mno", match[7] = "pqrs", match[8] = "tuv", match[9] = "wxyz";

    vector<string> ans;
    if(digits.size() == 0) return ans;
    queue<string> q;
    q.push("");
    while(!q.empty()) {
        string u = q.front(); q.pop();
        int len = u.length();
        if(len == digits.length()) {
            ans.push_back(u);
            continue;
        }
        u.resize(len+1);
        int d = digits[len] - '0';
        for(int i = 0; i < match[d].size(); i ++) {
            u[len] = match[d][i];
            q.push(u);
        }
    }
//    for(int i = 0; i < ans.size(); i ++) {
//        cout<<ans[i]<<endl;
//    }

    return ans;
}


int main() {

    string s;
    while(cin>>s) letterCombinations(s);



    return 0;
}
