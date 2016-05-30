// Feature:
// Dynamic programming
// O(n) space

#include"mytest.h"


using namespace std;

int numDistinct(string s1, string s2) {
    int n = s1.length(), m = s2.length();

    int dp[2][11000];
    memset(dp, 0, sizeof(dp));
    int t = 0;

    dp[t][m] = 1;

    for(int i = n-1; i >= 0; i --) {
        t^=1;
//        for(int k = 0; k < m+5; k ++) dp[t][k] = 0;
        dp[0][m] = dp[1][m] = 1;
        for(int j = m-1; j >= 0; j --) {
            if(s1[i] == s2[j]) {
                //if match: either pair or not
//                dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                dp[t][j] = dp[t^1][j+1] + dp[t^1][j];
            }
            else {
//                dp[i][j] = dp[i+1][j];
                dp[t][j] = dp[t^1][j];
            }
        }
    }

    return dp[t][0];
}


int main() {
	srand(time(NULL));


    string s1, s2;
    while(cin>>s1>>s2) {
        cout<<numDistinct(s1, s2)<<endl;
    }


    return 0;
}
