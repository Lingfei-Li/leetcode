// 7.1% slow........
// matrix...divide and conquer, bsearch

#include"mytest.h"

bool search(vector<vector<int> >& m, int r, int c, int vr, int vc, int targ) {

//    printf("%d %d %d %d\n", r, c, vr, vc);
    if(r == vr) {
        for(int i = c; i <= vc; i ++) if(m[r][i] == targ) return true;
        return false;
    }
    if(c == vc) {
        for(int i = r; i <= vr; i ++) if(m[i][c] == targ) return true;
        return false;
    }

    if(r==vr && c == vc) return m[r][c] == targ;
    for(int i = 0; ; i ++) {
//        cout<<"asd\n";
//        printf("%d %d\n", r+i, c+i);
        if(r+i>=m.size() && c+i>=m[0].size()){
            return false;
        }
        if(r+i >= m.size()) {
            return search(m, r, c+i, vr, vc, targ);
        }
        else if(c+i >= m[0].size()) {
            return search(m, r+i, c, vr, vc, targ);
        }
        if(m[r+i][c+i] == targ) {
            return true;
        }
        if(m[r+i][c+i] > targ) {
            return search(m, r+i, c, vr, c+i, targ) || search(m, r, c+i, r+i, vc, targ);
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int> >& m, int targ) {
    if(!m.size()) return false;
    if(!m[0].size()) return false;

    return search(m, 0, 0, m.size()-1, m[0].size()-1, targ);
}

int main() {
	srand(time(NULL));

    vector<vector<int> > board;

    readBoard(board);

    printBoard(board);

    int a;
    while(cin>>a){
        cout<<a<<endl;
        cout<<searchMatrix(board, a)<<endl;
    }



    return 0;
}
