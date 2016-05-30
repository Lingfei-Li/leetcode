// 24%
// .....

#include"mytest.h"


class TicTacToe {
private:
    vector<vector<int> > board;
    int sz;
    vector<int> rowSum, colSum, diagSum;
    int win;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n);
        for(int i = 0; i < n; i ++) {
            board[i].resize(n);
        }
        rowSum.resize(n);
        colSum.resize(n);
        diagSum.resize(2);
        win = 0;
        sz = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(win != 0) return win;
        if(player == 2) player = -1;
        board[row][col] = player;
        rowSum[row] += player;
        if(rowSum[row] == sz*player) goto over;
        colSum[col] += player;
        if(colSum[col] == sz*player) goto over;
        if(row == col) {
            diagSum[0] += player;
            if(diagSum[0] == sz*player) goto over;
        }
        if(row == sz-1-col) {
            diagSum[1] += player;
            if(diagSum[1] == sz*player) goto over;
        }


        /*
        for(int i = 0; i < sz; i ++) {
            for(int j = 0; j < sz; j ++) {
                printf("%d ", board[i][j]);
            }
            puts("");
        }
        */


        return 0;
over:
        if(player < 0) return win = 2;
        return win = 1;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */



int main() {
	srand(time(NULL));


    int n;
    cin>>n;
    TicTacToe obj = TicTacToe(n);
    int row, col, player;
    while(cin>>row>>col>>player)
        cout<<obj.move(row,col,player)<<endl;


    return 0;
}
