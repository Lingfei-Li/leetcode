// 88.9% but still can be much improved (64ms->12ms)
// Trie (my method)
// bitmanipulation? hashmap?

#include"mytest.h"

struct Node {
    int valid;
    Node* n[4];
    Node(){
        for(int i = 0; i < 4; i ++) n[i] = 0;
        valid = 0;
    }

};


int id(const char ch) {
    switch(ch) {
        case 'A':
            return 0;
        case 'T':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
    }
    return -1;
}


vector<string> findRepeatedDnaSequences(string s) {
    int n = s.length();
    vector<string> ans;
    if(!n) return ans;
    Node* h = new Node();
    for(int i = 0; i <= n-10; i ++) {
        Node* u = h;
        for(int j = 0; j < 10; j ++) {
            char ch = s[i+j];
            Node* v = u->n[id(ch)];
            if(j == 9){
                if(v) {
                    if(v->valid == -1) {
                        break;
                    }
                    if(v->valid == 1) {
                        ans.push_back(s.substr(i,10));
                        v->valid = -1;  //no duplicates
                    }
                    else {
                        v->valid = 1;   //first time seen this
                    }
                }
                else {
                    v = u->n[id(ch)] = new Node();
                    v->valid = 1;
                }
            }
            else {
                if(!v) v = u->n[id(ch)] = new Node();
                u = v;
            }
        }
    }
}


int main() {
	srand(time(NULL));
    string s;
    while(cin>>s){
        vector<string> ans = findRepeatedDnaSequences(s);
        printVector(ans);
    }




    return 0;
}
