#include"mytest.cpp"


using namespace std;

static int D = 0, L = 1, D_L = -1, L_D = -2;

int get_cur_state(int code) {
    if(code >= 0) return code;
    else if(code == D_L) return D;
    else if(code == L_D) return L;
}

int valid(int i, int j, int m, int n) {
    return (i>=0 && i < m && j >= 0 && j < n);
}

//Any live cell with fewer than two live neighbors dies, as if caused by under-population.
//Any live cell with two or three live neighbors lives on to the next generation.
//Any live cell with more than three live neighbors dies, as if by over-population..
//Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
int get_next_state(int i, int j, int m, int n, vector<vector<int> >& board) {
    int step[8][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
    int cnt = 0, cur_state = get_cur_state(board[i][j]);
    for(int i = 0; i < 8; i ++) {
        int u = i+step[i][0], v = j+step[i][1];
        if(valid(u, v, m, n)) cnt += get_cur_state(board[u][v]);
    }
    if(cur_state == L) {
        if(cnt == 2 || cnt == 3)
            return L;
        return L_D;
    }
    else {
        if(cnt == 3) return D_L;
        return D;
    }
}


void gameOfLife(vector<vector<int> >& board) {
    int m = board.size();
    if(!m) return;
    int n = board[0].size();
    if(!n) return;

    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            board[i][j] = get_next_state(i, j, m, n, board);
        }
    }
    for(int i = 0; i < m; i ++) {
        printVector(board[i]);
    }
    cout<<endl;
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            if(board[i][j] < 0) board[i][j] = (board[i][j]==D_L)?L:D;
        }
    }
}


int main() {
	srand(time(NULL));


    string s;
    while(cin>>s) {
        int m = 4, n = 4;
        vector<vector<int> > matrix;
        for(int i = 0; i < m; i ++) {
            vector<int> vec;
            genVector(vec, n);
            matrix.push_back(vec);
            printVector(vec);
        }
        cout<<endl;


        gameOfLife(matrix);
        for(int i = 0; i < m; i ++) {
            printVector(matrix[i]);
        }
    }





    return 0;
}
