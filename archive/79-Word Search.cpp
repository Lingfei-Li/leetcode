#include"mytest.cpp"
#define SPOJ "79-Word Search"


using namespace std;

bool valid(vector<vector<char> >& board, int r, int c) {
    if(r >= 0 && c >= 0 && r < board.size() && c < board[r].size()) return true;
    return false;
}

bool solve(vector<vector<char> >& board, vector<vector<int> >& vis, string word, int wordpos, int r, int c) {
    int step[4][2] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};





    return false;
}

bool exist(vector<vector<char> >& board, string word) {

    vector<vector<int> > vis;
    vis.resize(board.size());
    for(int i = 0; i < board.size(); i +) {
        vis[i].resize(board[i].size());
    }

    for(int r = 0; r < board.size(); r ++) {
        for(int c = 0; c < board[r].size(); c ++) {
            vis[r][c] = 1;
            if(solve(board, vis, word, 0, r, c)) return true;
            vis[r][c] = 0;
        }
    }




    return false;
}



int main() {
	srand(time(NULL));
    #define DEBUG 1
    #ifdef DEBUG
    char fileIn[30] = SPOJ, fileOut[30] = SPOJ;
    strcat(fileIn, ".in\0"); strcat(fileOut, ".out\0");
    freopen(fileIn,"r",stdin);
//    freopen(fileOut,"w",stdout);
    #endif



    vector<vector<char> > board;
    for(int i = 0; i < 3; i ++) {
        string s;
        cin>>s;
        vector<char> s2;
        for(int i = 0; i < s.size(); i ++) s2.push_back(s[i]);
        board.push_back(s2);
        cout<<s<<endl;
    }

    string word;
    while(cin>>word) {
        cout<<word<<endl;
        cout<<exist(board, word)<<endl;
    }




    return 0;
}
