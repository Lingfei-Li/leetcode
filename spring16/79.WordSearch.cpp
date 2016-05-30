//Feature:
//  Brute Force search (backtracking). 
//  The use of "step" array
//  Avoid "vis" array by backtracking on the "board" array



#include"mytest.cpp"


using namespace std;

bool valid(vector<vector<char> >& board, pair<int,int> coordinate) {
    int r = coordinate.first, c = coordinate.second;
    if(r > board.size()-1 || c > board[0].size()-1 || r < 0 || c < 0) return false;

    if(board[r][c] == '\0') return false;

    return true;
}

bool recurse(vector<vector<char> >& board, string& word, int pos, pair<int,int> coordinate) {
    int r = coordinate.first, c = coordinate.second;

    if(board[r][c] != word[pos]) return false;
    if(pos == word.size()-1 && board[r][c] == word[pos]) return true;
    

    int step[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    for(int dir = 0; dir < 4; dir ++) {
        int vr = r + step[dir][0], vc = c + step[dir][1];
        if(valid(board, pair<int,int>(vr, vc))) {
            char tmp = board[r][c];
            board[r][c] = '\0';
            if(recurse(board, word, pos+1, pair<int,int>(vr, vc))) return true;
            board[r][c] = tmp;
        }
        
    }

    return false;
}

bool exist(vector<vector<char> >& board, string word) {
    if(board.size() == 0 || board[0].size() == 0 || word.size() == 0) return false;

    for(int r = 0; r < board.size(); r ++) {
        for(int c = 0; c < board[0].size(); c ++) {
            if(recurse(board, word, 0, pair<int,int>(r,c))) return true;
        }
    }
    return false;
}

int main() {
	srand(time(NULL));

    char c;
    vector<char> line;
    vector<vector<char> > board;
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 4; j ++) {
            cin>>c;
            line.push_back(c);
        }
        board.push_back(line);
        line.clear();
    }
    for(int i = 0; i < board.size(); i ++) {
        for(int j = 0; j < board[i].size(); j ++) {
            cout<<board[i][j];
        }
        cout<<endl;
    }


    string word;
    while(cin>>word) {
        cout<<exist(board, word)<<endl;

    }



    return 0;
}
