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

bool match(char a, char b) {
    if(a == '(' && b == ')') return true;
    if(a == '[' && b == ']') return true;
    if(a == '{' && b == '}') return true;
    return false;
}

bool isValid(string s) {
    if(s.length() == 0) return true;
    stack<char> stk;
    for(int i = 0; i < s.length(); i ++) {
        if(!stk.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}') && match(stk.top(), s[i])) {
            stk.pop();
        }
        else {
            stk.push(s[i]);
        }
    }
    if(!stk.empty()) return false;
    return true;
}

int main() {
	srand(time(NULL));

    string str;
    while(cin>>str) {
        cout<<isValid(str)<<endl;
    }



    return 0;
}
