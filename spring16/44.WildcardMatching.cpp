//Feature:
//  Dynamic programming
//  O(n) memory space rolling array
//  Base case, proper initialization and clearance
//  Corner case: need to be VERY comprehensive and patient

#include"mytest.h"


using namespace std;


bool isMatch(string s, string p) {
    int n = s.length(), m = p.length();
    if(m == 0) return n==0;
    else if(n == 0) {
        for(int i = 0; i < m; i ++) if(p[i] != '*') return false;
        return true;
    }

    const int maxl = 5000;  //input size as large as 4000+
    int dp[2][maxl];

    int t = 0;
    dp[t][m] = 1;
    for(int i = m-1; i >= 0; i --) {
        if(p[i] == '*') dp[t][i] = dp[t][i+1];
        else dp[t][i] = 0;
    }

    for(int i = n-1; i >= 0; i --) {
        t ^= 1;
        //properly initialize the rolling array. 
        dp[t][m] = 0;
        for(int j = m-1; j >= 0; j --) {
            int& u = dp[t][j];
            if(s[i] == p[j] || p[j] == '?') {
                u = dp[t^1][j+1];
            }
            else if(p[j] == '*') {
                u = dp[t^1][j+1] || dp[t^1][j] || dp[t][j+1];   //last item: may cause undefined behavior if dp is not properly initialized.
            }
            else {
                u = 0; 
            }
        }
    }
    return dp[t][0];

}

int main() {
	srand(time(NULL));

    string s, p;
    while(cin>>s>>p) {
        cout<<isMatch(s, p)<<endl;
    }



    return 0;
}
