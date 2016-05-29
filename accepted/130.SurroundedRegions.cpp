// Note: slow implementation (14.79%)
// Feature:
// DFS: connected component
// Be extra careful when coding. Slow down.

#include"mytest.h"


using namespace std;

bool inside(vector<vector<char> >& board, int r, int c) {
    if(r > board.size()-1 || c > board[0].size()-1 || r < 0 || c < 0) return false;
    return true;
}

bool vis(vector<vector<char> >& board, int r, int c) {
    char ch = board[r][c];
    if(ch == 'X' || ch == 'O') return false;
    return true;
}

int h(int r, int c, int m) {
   return r*m+c;
}

void dehash(int h, int& r, int& c, int m) {
    r = h/m;
    c = h%m;
}

void capture(vector<vector<char> >& board, int r, int c) {
    if(vis(board, r, c)) return;
    char NOCAP =  'n';
    int step[4][2] = {{-1, 0}, {1, 0}, {0,1}, {0,-1}};
    int n, m;
    n = board.size();
    m = board[0].size();


    stack<int> stk;
    stk.push(r*m+c);

    while(!stk.empty()) {
        int u = stk.top();
        stk.pop();
        int ur = u/m, uc = u%m;
        if(vis(board, ur, uc)) continue;
        char& ch = board[ur][uc];
        if(ch == 'O') {
            int flag = 0;
            for(int i = 0; i < 4; i ++) {
                int vr = ur+step[i][0], vc = uc+step[i][1];
                if(inside(board, vr, vc) && board[vr][vc] == NOCAP) flag = 1;
            }
        
            if(flag || ur == 0 || uc == 0 || ur == board.size()-1 || uc == board[ur].size()-1) {
                ch = NOCAP;
                for(int i = 0; i < 4; i ++) {
                    int vr = ur+step[i][0], vc = uc+step[i][1];
                    if(inside(board, vr, vc) && !vis(board, vr, vc))
                        stk.push(vr*m+vc);
                }
            }
            else {
//                ch == 'c';
            }
        }
        else {
            ch = 'x';
        }
    }
}


void solve(vector<vector<char> >& board) {
    int n, m;
    n = board.size();
    if(n<=2) return;
    m = board[0].size();
    if(m<=2) return;


    for(int i = 0; i < n; i += n-1) {
        for(int j = 0; j < m; j ++) {
            if(!vis(board, i, j))
                capture(board, i, j);
        }
    }

    for(int j = 0; j < m; j += m-1) {
        for(int i = 0; i < n; i ++) {
            if(!vis(board, i, j))
                capture(board, i, j);
        }
    }


    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            char& ch = board[i][j];
            if(ch == 'n') ch = 'O';
            else ch = 'X';
        }
    }


}


int main() {
	srand(time(NULL));

    int n, m;
    char ch;
    while(cin>>n>>m) {
        vector<vector<char> > board;
        for(int i = 0; i < n; i ++) {
            vector<char> tmp;
            for(int j = 0; j < m; j ++) {
                cin>>ch;
                tmp.push_back(ch);
            }
            board.push_back(tmp);
        }
        printMatrix(board);
        solve(board);
        printMatrix(board);
    }




    return 0;
}

/*
    if(!inside(board, r, c) || vis(board, r, c)) return;
    char& ch = board[r][c];
    if(ch == 'O') {
        int flag = 0;
        for(int i = 0; i < 4; i ++) {
            int vr = r+step[i][0], vc = c+step[i][1];
            if(inside(board, vr, vc) && board[vr][vc] == NOCAP) flag = 1;
        }
        //boarder || next to openers
        if(flag || r == 0 || c == 0 || r == board.size()-1 || c == board[r].size()-1) {
            ch = NOCAP;
            for(int i = 0; i < 4; i ++) {
                int vr = r+step[i][0], vc = c+step[i][1];
                if(inside(board, vr, vc) && !vis(board, vr, vc))
                    capture(board, vr, vc);
            }
        }
        else {
            ch = 'c';       //will this case happen?
        }
    }
    else {
        ch = 'x';
    }
*/
