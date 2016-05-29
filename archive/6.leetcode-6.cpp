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


string convert(string s, int nRows) {
    char ans[1000][1000];
    string ans[nRows];

    int T = nRows + nRows-2;

    for(int i = 0; i < s.length(); i ++) {
        int p = i % T;
        if(p < nRows) {
            ans[p].push_back(s[i]);
        }
        else {
            p = nRows -- (i-nRows+1);
        }

    }

    return ans;
}

int main()
{


    string s="PAYPALISHIRING";
    cout<<convert(s, 3)<<endl;




    return 0;
}
