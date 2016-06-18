#include"mytest.h"



class Solution {
public:
    int maxKilledEnemies(vector<vector<char> >& grid) {

        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        if(!m) return 0;

        int rowKill[n][m] = {0};
        int colKill[n][m] = {0};

        for(int i = 0; i < n; i ++) {
            int prev = 0;
            int cnt = 0;
            for(int j = 0; j < m; j ++) {
                if(grid[i][j] == 'W'){
                    for(int k = prev; k < j; k ++) rowKill[i][k] = cnt;
                    prev = j+1;
                    cnt = 0;
                }
                else if(grid[i][j] == 'E'){
                    cnt ++;
                }
            }
            for(int k = prev; k < m; k ++) rowKill[i][k] = cnt;
        }

        for(int j = 0; j < m; j ++) {
            int prev = 0;
            int cnt = 0;
            for(int i = 0; i < n; i ++) {
                if(grid[i][j] == 'W'){
                    for(int k = prev; k < i; k ++) colKill[k][j] = cnt;
                    prev = i+1;
                    cnt = 0;
                }
                else if(grid[i][j] == 'E'){
                    cnt ++;
                }
            }
            for(int k = prev; k < n; k ++) colKill[k][j] = cnt;
        }

        int ans = 0;
        for(int j = 0; j < m; j ++) {
            for(int i = 0; i < n; i ++) {
                if(grid[i][j] == '0') ans = max(ans, colKill[i][j]+rowKill[i][j]);
            }
        }
        return ans;
    }
};



int main() {
	srand(time(NULL));

    Solution sol;



    return 0;
}
