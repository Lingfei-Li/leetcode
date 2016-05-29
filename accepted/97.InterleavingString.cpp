// Feature:
// Dynamic programming
// **this implementation is very inefficient (1.09%)

#include"mytest.h"


using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    
    int n = s1.length(), m = s2.length(), l = s3.length();
    if(n+m!=l) return false;
//    bool dp[150][150][300];
    bool dp[105][105];

    dp[n][m] = 1;
    for(int i = n; i >= 0; i --) {
        for(int j = m; j >= 0; j --) {
            int k = i+j;
            bool& u = dp[i][j];
            if(!(i == n && j == m))u = 0;
            if(i < n && s3[k] == s1[i]) {
                u |= dp[i+1][j];
            }
            if(j < m && s3[k] == s2[j]) {
                u |= dp[i][j+1];
            }
        }
    }

    return dp[0][0];    
}


int main() {
	srand(time(NULL));

    string s1, s2, s3;
    while(cin>>s1>>s2>>s3){
        cout<<s1<<endl<<s2<<endl<<s3<<endl;
        cout<<isInterleave(s1,s2,s3)<<endl;
    }



    return 0;
}
