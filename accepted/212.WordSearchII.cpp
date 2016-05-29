// 66.63% fine
// Trie tree
// backtracking
// analysis, find better backtracking direction
// pruning

#include"mytest.h"


struct Node {
    Node* n[30];
    int valid;
    Node(){
        for(int i = 0; i < 30; i ++) n[i] = 0;
        valid = 0;
    }
};

bool valid(vector<vector<char> >& board, pair<int,int> coordinate) {
    int r = coordinate.first, c = coordinate.second;
    if(r > board.size()-1 || c > board[0].size()-1 || r < 0 || c < 0) return false;

    if(board[r][c] == '\0') return false;

    return true;
}

void build_tree(Node* u, string& s, int p) {
    if(!u) return;
    if(p == s.length()) {
        u->valid = 1;   //is a word - not a intermidiate thing
        return;
    }
    int c = s[p]-'a';
    if(u->n[c]) build_tree(u->n[c], s, p+1);
    else {
        u->n[c] = new Node();
        build_tree(u->n[c], s, p+1);
    }
}

void recurse(vector<vector<char> >& board, string& word, pair<int,int> coordinate, vector<string>& ans, Node* u) {
    int r = coordinate.first, c = coordinate.second;

    //base case
    if(u->valid) {
        ans.push_back(word);
        u->valid = 0;       //already got this.
    }

    int step[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    for(int dir = 0; dir < 4; dir ++) {
        int vr = r + step[dir][0], vc = c + step[dir][1];
        pair<int,int> vp = pair<int,int>(vr, vc);
        if(valid(board, vp)) {
            char tmp = board[r][c];
            board[r][c] = '\0';
            char vch = board[vr][vc];
            if(u->n[vch-'a']) {
                int initsz = word.size();
                word.push_back(vch);
                recurse(board, word, vp, ans, u->n[vch-'a']);
                word.resize(initsz);
            }
            board[r][c] = tmp;
        }
    }
}




vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
    vector<string> ans;

    Node* h = new Node();
    for(int i = 0; i < words.size(); i ++) 
        build_tree(h, words[i], 0);
    
    if(board.size() == 0 || board[0].size() == 0 || words.size() == 0) 
        return ans;

    string word;
    for(int r = 0; r < board.size(); r ++) {
        for(int c = 0; c < board[0].size(); c ++) {
            if(ans.size() == words.size()) return ans;  //pruning..
            pair<int,int> vp = pair<int,int>(r, c);
            char tmp = board[r][c];
            board[r][c] = '\0';
            if(h->n[tmp-'a']) {
                int initsz = word.size();
                word.push_back(tmp);
                recurse(board, word, vp, ans, h->n[tmp-'a']);
                word.resize(initsz);
            }
            board[r][c] = tmp;

        }
    }


    return ans;    
}


int main() {
	srand(time(NULL));

    int tmp1, tmp2;
    while(cin>>tmp1>>tmp2) {
        char c;
        vector<char> line;
        vector<vector<char> > board;
        for(int i = 0; i < tmp1; i ++) {
            for(int j = 0; j < tmp2; j ++) {
                cin>>c;
                line.push_back(c);
            }
            board.push_back(line);
            line.clear();
        }

        printBoard(board);

        string word;
        vector<string> words;
        readVector(words);

        vector<string> ans = findWords(board, words);
        printVector(ans);
    }


    return 0;
}


/*
bool exist(Node* u, string& s, int pos) {
    if(pos == s.length()) return u->valid;
    Node* v = u->n[s[pos]-'a'];
    if(v) {
        return exist(v, s, pos+1);
    }
    return false;
}
*/
