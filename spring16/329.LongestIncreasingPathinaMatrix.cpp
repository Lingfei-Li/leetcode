// 40.9% med
// dynamic programming (memoization)

#include"mytest.h"


vector<vector<int> > dp;
int m, n;

int isvalid(int r, int c) {
    return r >= 0 && c >= 0 && r < n && c < m;
}


int solve(vector<vector<int> >& mx, int r, int c) {
    int step[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    if(dp[r][c] != 0) return dp[r][c];
    dp[r][c] = 1;
    for(int i = 0; i < 4; i ++) {
        int vr = r + step[i][0], vc = c + step[i][1];
        if(isvalid(vr,vc) && mx[vr][vc] > mx[r][c]) {
            dp[r][c] = max(dp[r][c], solve(mx,vr,vc)+1);
        }
    }
    return dp[r][c];
}


int longestIncreasingPath(vector<vector<int> >& matrix) {
    n = matrix.size();
    if(!n) return 0;
    m = matrix[0].size();
    if(!m) return 0;

    dp.resize(n);
    for(int i = 0; i < n; i ++) dp[i].resize(m);

    int ans = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            ans = max(ans,solve(matrix, i, j));

    return ans;
                
}




int main() {


    vector<vector<int> >b;
    readBoard(b);
    print(b);
    cout<<longestIncreasingPath(b)<<endl;



    return 0;
}
