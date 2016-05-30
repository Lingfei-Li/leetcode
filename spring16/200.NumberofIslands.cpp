// 25.66 2nd group
// dfs
// connected components

#include"mytest.h"

bool valid(int r, int c, vector<vector<char> >& grid) {
    if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return false;
    if(grid[r][c] == 0 || grid[r][c] == '0') return false;
    return true;
}


void dfs(int r, int c, vector<vector<char> >& grid) {
    int step[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

    if(valid(r, c, grid)) {
        grid[r][c] = 0;
        for(int i = 0; i < 4; i ++) {
            int vr = r+step[i][0], vc = c+step[i][1];
            dfs(vr, vc, grid);
        }
    }
}


int numIslands(vector<vector<char> >& grid) {
    int n = grid.size();
    if(!n) return 0;
    int m = grid[0].size();
    if(!m) return 0;
    int ans = 0;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m;j ++) {
            if(valid(i,j,grid)) {
                ans ++;
                dfs(i,j,grid);
            }
        }
    }

    return ans;
            
}



int main() {
	srand(time(NULL));

    vector<vector<char> > grid;

    int n, m;
    cin>>n>>m;
    int c;
    for(int i = 0; i < n; i ++) {
        vector<char> tmp;
        for(int j = 0; j < m; j ++) {
            cin>>c;
            tmp.push_back(c+'0');
        }
        grid.push_back(tmp);
    }
    printBoard(grid);
        
    cout<<numIslands(grid)<<endl;




    return 0;
}
