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

string gen() {
    string str;
    srand(time(NULL));
    for(int i = 0; i < 20; i ++) {
        str.push_back(rand()%26+'A');
    }
    cout<<str<<endl;
    return str;
}
int inside(int l, int r, int p) {
    return (l>=0 && r < p);
}

string longestPalindrome(string s) {
    int ansl = 0, ansr = 0, len = 1;
    for(int i = 0; i < s.length(); i ++) {
        int j;
        for(j = 1; ; j ++) {
            int l = i - j, r = i + j;
            if(!inside(l, r, s.length()) || s[l] != s[r]) {
                break;
            }
        }
        j--;
        if(2*j+1 > len) {
            len = 2*j+1;
            ansl = i - j;
            ansr = i + j;
        }
        for(j = 1;;j ++) {
            int l = i-j, r = i+j-1;
            if(!inside(l, r, s.length()) || s[l] != s[r]) {
                break;
            }
        }
        j--;
        if(2*j > len) {
            len = 2*j;
            ansl = i - j;
            ansr = i + j-1;
        }
    }
    string ans = s.substr(ansl, ansr-ansl+1);
    return ans;
}

int main()
{

    string s;
    while(cin>>s)
        cout<<longestPalindrome(s)<<endl;



    return 0;
}
