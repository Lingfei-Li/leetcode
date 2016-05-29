// Feature:
// Think about complexity...which way is better? all words vs. all positions
// Bidirectional BFS
// Note: 97.77%. good job.

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


int bfs(string& beginWord, string& endWord, unordered_set<string>& wordList) {
    //double BFS
    queue<string> q[2];
    int t = 0;
    q[0].push(beginWord);
    q[1].push(endWord);
    unordered_map<string, int> d[2];
    d[0][beginWord] = 1;
    d[1][endWord] = 1;
    while(!q[0].empty() && !q[1].empty()) {
        string u = q[t].front();
        q[t].pop();
        int du = d[t][u];


        if(d[t^1].count(u)) return d[t^1][u]+d[t][u]-1;

        for(int i = 0; i < beginWord.length(); i ++) {
            for(char c = 'a'; c <= 'z'; c ++) {
                char tmp = u[i];
                u[i] = c; 
                if(wordList.count(u)) {
                    if(!d[t].count(u)) {
                        q[t].push(u); 
                        d[t][u] = du + 1;
                    }
                }
                u[i] = tmp;
            }
        }
        t^=1;   //change BFS direction
    }

    //unreachable
    return 0;
}


int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
                
    if(!beginWord.length()) return 0;
    if(adj(beginWord, endWord) == 1) return 2;

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

    cout<<ladderLength(begin, end, wordList)<<endl;



    return 0;
}
