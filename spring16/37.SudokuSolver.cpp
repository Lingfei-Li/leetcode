//Feature:
//  The use of "vis" array. Backtracking

#include"mytest.h"


using namespace std;

int blocknum(int r, int c) {
    return (r/3)*3+(c/3);
}


bool solve(vector<vector<char> >& board, int vis[3][9][9], int r, int c) {
    if(r > 8) return true;

    int vr = (c==8)?r+1:r, vc = (c==8)?0:c+1;

//    printf("enter: r: %d, c: %d, vr: %d, vc: %d\n", r, c, vr, vc);

//    printMatrix(board);

    if(board[r][c] != '.') return solve(board, vis, vr, vc);

    for(int i = 1; i <= 9; i ++) {
//        printf("r: %d, c: %d, vr: %d, vc: %d, i: %d\n", r, c, vr, vc, i);
        int blk = blocknum(r,c);
        if(vis[0][r][i] == 0 && vis[1][c][i] == 0 && vis[2][blk][i] == 0) {

            vis[0][r][i] = vis[1][c][i] = vis[2][blk][i] = 1;
            char tmp = board[r][c];
            board[r][c] = i+'0';
            if(solve(board, vis, vr, vc)) return true;
            board[r][c] = tmp;
            vis[0][r][i] = vis[1][c][i] = vis[2][blk][i] = 0;
        }
    }
    return false;
}

void solveSudoku(vector<vector<char> >& board) {
    int vis[3][9][9];   //vis for row, col, block.
    memset(vis, 0, sizeof(vis));
    
    for(int r = 0; r < board.size(); r ++ ) {
        for(int c = 0; c < board[0].size(); c ++) {
            int ch = board[r][c]-'0';
            if(board[r][c] != '.') {
                vis[0][r][ch] = 1;
                vis[1][c][ch] = 1;
                vis[2][blocknum(r,c)][ch] = 1;
            }
        }
    }

    solve(board, vis, 0, 0);
//    cout<<solve(board, vis, 0, 0)<<endl;
}





int main() {
	srand(time(NULL));



    char c;
    string s;
    vector<vector<char> > board;
    while(cin>>s) {
        vector<char> line;
        for(int i = 0; i < s.length(); i ++) line.push_back(s[i]);
        board.push_back(line);
    }
    

    printMatrix(board);


    solveSudoku(board);
    printMatrix(board);

    return 0;
}
