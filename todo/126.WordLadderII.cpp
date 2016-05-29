#include"mytest.h"


using namespace std;

int adj(string s1, string s2) {
    int flag = 0;
    for(int i = 0; i < s1.length(); i ++){
        if(s1[i] != s2[i] && flag) return 0;
        if(s1[i] != s2[i] && !flag) flag = 1;
    }
    return flag;    //false if flag is still 0 -> same string
}


void addAns(vector<vector<string> >& ans, unordered_map<string, string>& p, string& u) {
    
}

vector<vector<string> > bfs(string& beginWord, string& endWord, unordered_set<string>& wordList) {
    queue<string> q;
    unordered_map<string, int> d;
    unordered_map<string, string> p;
    q.push(beginWord);
    d[beginWord] = 1;
    p[beginWord] = beginWord;
    vector<vector<string> > ans;
    
    int ansd = -1;
    while(!q.empty()){
        string u = q.front();
        cout<<u<<endl;
        q.pop();
        int du = d[u];

        if(ansd != -1 && du > ansd) return ans;
        if(u == endWord) {
            if(ansd == -1)
                ansd = du;
            addAns(ans, p, u);
        }

        for(int i = 0; i < beginWord.length(); i ++) {
            string v = u;
            for(char c = 'a'; c <= 'z'; c ++) {
                v[i] = c; 
                if(v == endWord || wordList.count(v)) {
                    if(!d.count(v)) {
                        q.push(v); 
                        d[v] = du + 1;
                        p[v] = u;
                    }
                }
            }
        }
    }

    //unreachable
    return ans;
}

vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
                
    vector<vector<string> > ans;

    if(!beginWord.length()) ans;
//    if(adj(beginWord, endWord) == 1) return 2;

    return bfs(beginWord, endWord, wordList);


}


int main() {
	srand(time(NULL));

    

    unordered_set<string> wordList;
    string s;
    string begin, end;
    cin>>begin;
    cin>>end;
    while(cin>>s && s != "end") {
        wordList.insert(s);
    }

    vector<vector<string> > ans = findLadders(begin, end, wordList);
    for(int i = 0; i < ans.size();i ++) {
        for(int j = 0; j < ans[i].size();j ++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
//    cout<<ladderLength(begin, end, wordList)<<endl;



    return 0;
}
