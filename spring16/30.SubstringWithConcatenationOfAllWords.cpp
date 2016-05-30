#include"mytest.h"


using namespace std;
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    if(s.length() == 0 || words.size() == 0) return ans;

    //assign id for each word
    int id = 1, n = words.size(), m = words[0].length(), len = s.length();
    map<string,int> dict;
    for(int i = 0; i < n; i ++) {
        dict[words[i]] = id++;
//        printf("%s: %d\n", words[i].c_str(), id-1);
    }
    vector<int> quant;
    quant.resize(id+2);
    for(int i = 0; i < n; i ++) {
        quant[dict[words[i]]] ++;
    }

    vector<int> sq[m];  //one id array for each offset
    for(int offset = 0; offset < m; offset ++) {
        for(int i = 0; i + offset < len; i += m) {
            int tmp = dict[s.substr(i+offset, m)];
//            printf("%s %d\n", s.substr(i+offset, m).c_str(), tmp);
            sq[offset].push_back(tmp);
//            printf("i: %d, off: %d\n", i, offset);
//            cout<<s.substr(i+offset,3)<<" "<<tmp<<endl;
//            printf("%s %d\n", s.substr(i+offset, 3), tmp);
        }
    }
    
    for(int offset = 0; offset < m; offset ++) {
        int l = 0, r = 0, cnt = 0;
        vector<int>& sqpt = sq[offset];
        vector<int> vis;
        vis.resize(id+2);
        for(int r = 0; r < sqpt.size(); r ++) {
//            printf("l: %d, r: %d\n", l, r);
//            for(int i = l; i <= r; i ++) cout<<sqpt[i]<<" ";
//            cout<<endl;
            if(sqpt[r] == 0) {    //invariate: no outlier between [l,r]
                while(l < r+1) {
                    vis[sqpt[l++]] = 0;
                }
                cnt = 0;
//                l = r+1;
                continue;
            }

            if(vis[sqpt[r]] < quant[sqpt[r]]) {     //normal: add a word into sq.
                vis[sqpt[r]] ++;
                cnt ++;
            }
            else {                      //more than quant[id]
                while(vis[sqpt[r]] >= quant[sqpt[r]] && l < r) { //invariate: no duplicate in [l,r]
//                    printf("r: %d, vis[%d] = 1, l: %d\n", r, sqpt[r], l);
//                    printf("inc l: %d\n", l);
                    vis[sqpt[l++]] --;
                    cnt --;
                } 
                //include the new character
                vis[sqpt[r]] ++;
                cnt ++;
            }
            if(cnt == n) {      //goal test: given that no outlier & no dup, cnt = n.
                ans.push_back(offset + l*m);
            }
        }
    }


    return ans;
}


int main() {
	srand(time(NULL));


//"wordgoodgoodgoodbestword"
//["word","good","best","good"]


    string s = "barfoothefoobarman";
//"wordgoodgoodgoodbestword"
//    string s = "wordgoodgoodgoodbestword";
    vector<string> words;
//    words.push_back("word");
//    words.push_back("good");
//    words.push_back("best");
//    words.push_back("good");
//    words.push_back("the");
    words.push_back("foo");
    words.push_back("bar");
    cout<<s<<endl;
    vector<int> ans = findSubstring(s, words);
    cout<<"ans\n";

    printVector(ans);


    return 0;
}
