#include"mytest.h"


#define distinctNum 30
//const int distinctNum = 30;
//Trie node
struct Node {
    int valid;
    int idx;
    unordered_map<char, Node*> child;
    Node(){
        for(int i = 0; i < distinctNum; i ++) child[i] = 0;
        valid = 0;
    }
};

    vector<vector<int> > ans;

void build(Node* root, string& word, int idx) {
    Node* u = root;
    for(int i = 0; i < word.size(); i ++) {
        Node* v = u->child[word[i]];
        if(v == 0) { v = new Node(); }
        u->child[word[i]] = v;
        u = v;
    }
    u->valid = 1;
    u->idx = idx;
}

void buildReverse(Node* root, string& word, int idx) {
    Node* u = root;
    for(int i = word.size()-1; i >= 0; i --) {
        Node* v = u->child[word[i]];
        if(v == 0) { v = new Node(); }
        u->child[word[i]] = v;
        u = v;
    }
    u->valid = 1;
    u->idx = idx;
}


int ispalindrom(string& s, int l, int r) {
    while(l<r) if(s[l++] != s[r--]) return 0;
    return 1;
}

set<vector<int> > st;

void pushans(int i, int j){
    vector<int> tmp;
    tmp.push_back(i);
    tmp.push_back(j);
    st.insert(tmp);
//    ans.push_back(tmp);
}

void helper(Node* u, vector<int>& idx, string& s, Node* start){
    if(!u) return;
    if(u->valid && u != start) {
        if(ispalindrom(s, 0, s.length()-1)){
            idx.push_back(u->idx);
        }
    }

    int initsz = s.length();
    for(auto it = u->child.begin(); it != u->child.end(); it ++){
        s.push_back(it->first);
        helper(it->second, idx, s, start);
        s.resize(initsz);
    }
}

//take 'word' as the beginning. seek reversed matching part
//root should be reverse trie
void solve(Node* root, string& word, int idx) {
    Node* u = root;
    for(int i = 0; i < word.size(); i ++) {
        Node* v = u->child[word[i]];
        if(v == 0) return;
        if(v->valid) {
            if(ispalindrom(word, i+1, word.size()-1) && idx != v->idx){
//                printf("%d %d\n", idx, v->idx);
                pushans(idx, v->idx);
            }
        }
        u = v;
    }
    return;
//    for(int i = 0; i < distinctNum; i ++) {
//        Node* v = u->child[i];
        if(u) {
            vector<int> tmpidx;
            string s;
            helper(u, tmpidx, s, u);
            for(int j = 0; j < tmpidx.size(); j ++) if(tmpidx[j] != idx){
//                printf("%d %d\n", idx, tmpidx[j]);
                pushans(idx, tmpidx[j]);
            }
        }
//    }
}

//take 'word' as the right hand part. seek left handpart
//root should be normal trie
void solveReverse(Node* root, string& word, int idx) {
    Node* u = root;
    int lastpos = -1;
    for(int i = word.size()-1; i >= 0; i --) {
        Node* v = u->child[word[i]];
        if(v == 0) return;
        if(v->valid) {
            if(ispalindrom(word, 0, i-1) && idx != v->idx){
                pushans(v->idx, idx);
            }
        }
        u = v;
    }
}

void releaseMem(Node* u) {
    if(!u) return;
    for(int i = 0; i < distinctNum; i ++) {
        if(u->child[i])
            releaseMem(u->child[i]);
    }
    delete(u);
}

vector<vector<int> > palindromePairs(vector<string>& words) {
    int n = words.size();
    if(n <= 1) return ans;
    Node* trie, *rtrie;
    trie = new Node();
    rtrie = new Node();
    for(int i = 0; i < n; i ++) {
        build(trie, words[i], i);
        buildReverse(rtrie, words[i], i);
    }

    for(int i = 0; i < n; i ++) {
        cout<<words[i]<<endl;
        solve(rtrie, words[i], i);
        solveReverse(trie, words[i], i);
    }

    for(auto it = st.begin(); it != st.end(); it ++) {
        ans.push_back(*it);
    }

    releaseMem(trie);
    releaseMem(rtrie);

    return ans;
}



int main() {
	srand(time(NULL));



    vector<string> words;
    read(words);
    print(words);
    vector<vector<int> > res = palindromePairs(words);
    for(int i = 0; i < res.size(); i ++) {
        for(int j = 0; j < res[i].size(); j ++) {
            printf("%d ", res[i][j]);
        }
        for(int j = 0; j < res[i].size(); j ++) {
            printf("%s ", words[res[i][j]].c_str());
        }
        cout<<endl;
    }


    return 0;
}
