#include"mytest.cpp"


using namespace std;


int uniquePaths(int m, int n) {
    int dp[105][105];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= m; i ++) dp[i][n] = 1;
    for(int j = 1; j <= n; j ++) dp[m][j] = 1;

    for(int i = m-1; i > 0; i --)
        for(int j = n-1; j > 0; j --)
            dp[i][j] = dp[i+1][j] + dp[i][j+1];

    return dp[1][1];
}


int main() {
	srand(time(NULL));

    int a, b;
    while(cin>>a>>b) {
        cout<<uniquePaths(a, b)<<endl;
    }



    return 0;
}
