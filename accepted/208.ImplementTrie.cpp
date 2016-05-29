// 44.56% 3rd group

#include"mytest.h"


struct TrieNode {
    TrieNode* n[30];
    TrieNode() {
        for(int i = 0; i < 30; i ++) {
            n[i] = 0;
        }
    }
};

TrieNode* root;
unordered_set<string> st;

void Trie() {
    root = new TrieNode();
}

void insert(string s) {
    TrieNode* u = root;
    for(int i = 0; i < s.length(); i ++) {
        char c = s[i];
        TrieNode* v = u->n[c-'a'];
        if(!v) {
            v = new TrieNode();
            u->n[c-'a'] = v;
        }
        u = v;
    }
    st.insert(s);
}

bool search(string s) {
    if(st.count(s)) return true;
    return false;
}

bool startsWith(string s) {
    if(s.length() == 0) {
        for(int i = 0; i < 30; i ++) {
            if(root->n[i]) return true;
        }
        return false;
    }
    TrieNode* u = root;
    for(int i = 0; i < s.length(); i ++) {
        char c = s[i];
        if(u->n[c-'a']) {
            u = u->n[c-'a'];
        }
        else {
            return false;
        }
    }
    return true;

}


int main() {
	srand(time(NULL));


    string s, t;
    vector<string> v;
    Trie();

    while(cin>>s>>t) {
        if(s=="i") {
            insert(t);
            v.push_back(t);
            printVector(v);
        }
        else if(s=="s") {
            cout<<search(t)<<endl;
        }
        else if(s=="p") {
            cout<<startsWith(t)<<endl;
        }
    }





    return 0;
}
