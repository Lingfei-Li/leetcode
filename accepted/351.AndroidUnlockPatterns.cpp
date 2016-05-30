// 38.69% med
// backtracking

#include"mytest.h"

class Solution {
public:

    void solve(int m, int n, int vis[9], int check[9][9], int& ans, int u, int cnt) {
        if(cnt > n) return;
        if(cnt >= m) ans ++;

        for(int i = 0; i < 9; i ++) {
            if(vis[i] == 0) {
                int ck = check[u][i];
                if(ck == -1 || vis[ck] != 0){
                    vis[i] = 1;
                    solve(m, n, vis, check, ans, i, cnt+1);
                    vis[i] = 0;
                }
            }
        }
    }

    int numberOfPatterns(int m, int n) {
        if(m > n || n < 0) return 0;
        int vis[9];
        memset(vis, 0, sizeof(vis));

        int ans = 0;
        if(m <= 0) ans = 1;
        int check[9][9];
        memset(check, -1, sizeof(check));
        check[0][2] = check[2][0] = 1;
        check[0][6] = check[6][0] = 3;
        check[0][8] = check[8][0] = 
            check[1][7] = check[7][1] = 
            check[2][6] = check[6][2] = 
            check[3][5] = check[5][3] = 4;
        check[2][8] = check[8][2] = 5;
        check[6][8] = check[8][6] = 7;

        for(int i = 0; i < 9; i ++) {
            vis[i] = 1;
            solve(m, n, vis, check, ans, i, 1);
            vis[i] = 0;
        }

        return ans;
    }
};



int main() {
	srand(time(NULL));

    Solution sol;

    int m, n;
    while(cin>>m>>n){
        printf("%d %d\n", m, n);
        cout<<sol.numberOfPatterns(m, n)<<endl;
    }



    return 0;
}
