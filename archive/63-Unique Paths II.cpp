#include"mytest.cpp"


using namespace std;


int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    if(obstacleGrid.size() == 0) return 0;

    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    int dp[105][105];
    memset(dp, 0, sizeof(dp));
    dp[m-1][n-1] = !obstacleGrid[m-1][n-1];

    for(int i = m-1; i >= 0; i --) {
        for(int j = n-1; j >= 0; j --){
            if(obstacleGrid[i][j] == 0) {
                if(i+1 < m) dp[i][j] += dp[i+1][j];
                if(j+1 < n) dp[i][j] += dp[i][j+1];
            }
            else
                dp[i][j] = 0;
        }
    }

    return dp[0][0];
}


int main() {
	srand(time(NULL));

	vector<vector<int> > v;
	vector<int> tmp;
	tmp.push_back(0);
	tmp.push_back(1);
	v.push_back(tmp);
    cout<<uniquePathsWithObstacles(v)<<endl;

//    int a, b;
//    while(cin>>a>>b) {
//        cout<<uniquePathsWithObstacles(a, b)<<endl;
//    }



    return 0;
}
