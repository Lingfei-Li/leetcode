// 77.08% 1st group
// dynamic programming (iterative)
// problem understanding and alanysis

#include"mytest.h"

int calculateMinimumHP(vector<vector<int> >& dungeon) {
    int n = dungeon.size();
    if(!n) return 0;
    int m = dungeon[0].size();
    if(!m) return 0;

    int intmax = (1<<31)-1;
    vector<vector<int> > dp;
    dp.resize(n+5);
    for(int i = 0; i < n+5; i ++) dp[i].resize(m+5);

    dp[n-1][m-1] = max(1,1-dungeon[n-1][m-1]);   //how many HP is needed before entering dun[i][j]

     for(int i = n-1; i >= 0; i --) {
        for(int j = m-1; j >= 0; j --) {
            if(i == n-1 && j == m-1) continue;
            int u = dungeon[i][j];
            if(i == n-1) {
                dp[i][j] = dp[i][j+1]-u;
            }
            else if(j == m-1) {
                dp[i][j] = dp[i+1][j]-u;
            }
            else {
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - u;
            }
            dp[i][j] = max(1,dp[i][j]);
        }
     }
     /*
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */

     return max(1, dp[0][0]);
}


int main() {
	srand(time(NULL));

    int n, m;
    cin>>n>>m;
    int a;
    vector<vector<int> > board;
    for(int i = 0; i < n; i ++) {
        vector<int> tmp;
        for(int j = 0; j < m; j ++) {
            cin>>a;
            tmp.push_back(a);
        }
        board.push_back(tmp);
    }

    printBoard(board);
    cout<<calculateMinimumHP(board)<<endl;





    return 0;
}
