// 2nd group
// nothing

#include"mytest.h"

/*
1.Any live cell with fewer than two live neighbors dies, as if caused by under-population.

2.Any live cell with two or three live neighbors lives on to the next generation.

3.Any live cell with more than three live neighbors dies, as if by over-population..

4.Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
*/

int liveNeighbors(vector<vector<int> >& board, int r, int c) {
    int cnt = 0;
    for(int i = -1; i <= 1; i ++) 
        for(int j = -1; j <= 1; j ++) 
            if(r+i>=0 && r+i < board.size() && c+j>=0 && c+j<board[0].size()) 
                if(!(i==0&&j==0))
                    cnt += board[r+i][c+j];
    return cnt;
}

void gameOfLife(vector<vector<int> >& board) {
    int n = board.size();
    if(!n) return;
    int m = board[0].size();
    if(!m) return;
    vector<vector<int> > tmp = board;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            int neighbors = liveNeighbors(tmp, i, j);
            if(tmp[i][j]) {
                if(neighbors < 2 || neighbors > 3) board[i][j] = 0;
            }
            else {
                if(neighbors == 3) board[i][j] = 1;
            }
        }
    }
}



int main() {
	srand(time(NULL));




    return 0;
}
