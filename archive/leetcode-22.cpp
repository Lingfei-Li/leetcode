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


void dfs(vector<string>& ans, string str, int pos, int cnt, int pcnt, int n) {
    if(pos == 2*n && cnt == 0) ans.push_back(str);
    else if(pos == 2*n && cnt != 0) return;
    else{
        if(pcnt < n){
            str[pos] = '(';
            dfs(ans, str, pos+1, cnt+1, pcnt+1, n);
        }
        if(cnt){
            str[pos] = ')';
            dfs(ans, str, pos+1, cnt-1, pcnt, n);
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string str(2*n, 0);
    dfs(ans, str, 0, 0, 0, n);
    return ans;
}


int main() {
	srand(time(NULL));

	vector<string> ans;
	ans = generateParenthesis(5);
	for(int i = 0; i < ans.size(); i ++) {
        cout<<ans[i]<<endl;
	}

//    string s(5, '2');
////    s.resize(10);
//    cout<<s<<endl;
//    cout<<s.length()<<endl;



    return 0;
}
