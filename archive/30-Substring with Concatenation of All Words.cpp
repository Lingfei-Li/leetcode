#include"mytest.cpp"


using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    int len = s.size(), n = words.size();
    vector<int> ans;

    //Construction of map
    map<string, int> dict;
    for(int i = 0; i < words.size(); i ++) {
        string& tmp = words[i];
        if(dict.count(tmp) == 0) dict[tmp] = i+1;
    }

    vector<int> vec[3];
    for(int offset = 0; offset < 3; offset ++) {
        for(int i = offset; i + 2 < len; i += 3) {
            string tmp = s.substr(i, 3);
            if(dict.count(tmp) == 0) dict[tmp] = -1;
            vec[offset].push_back(dict[tmp]);
        }
    }

    for(int offset = 0; offset < 3; offset ++) {
        int vis[10000];
        memset(vis, -1, sizeof(vis));
        int cnt = 0;
        for(int pos = 0; pos < vec[offset].size(); pos ++) {
            for(int i = pos; i < pos + n && i+n-1 < len; i ++) {
////                printf("%d ", vec[offset][pos]);
                int tmp = vec[offset][pos];
                if(tmp == -1) {     //this word is not existent in words.
                    pos = i+1;      //start from next of the word.
                    break;
                }
                if(vis[tmp] != -1) {    //duplicated word.
                    pos = vis[tmp]+1;   //start from the first appearance position + 1
                    break;
                }
                else {                  //first appearance of the word.
                    vis[tmp] = i;
                }
            }
        }
        printf("\n");
    }





    return ans;
}


int main() {
	srand(time(NULL));

    string s;
    int n;
    while(cin>>s) {
        cin>>n;
        string tmp;
        vector<string> words;
        while(n--) {
            cin>>tmp;
            words.push_back(tmp);
        }
        for(int i = 0; i < words.size(); i ++)
            cout<<words[i]<<" ";
        cout<<endl;
        vector<int> ans = findSubstring(s, words);
        for(int i = 0; i < ans.size(); i ++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }





    return 0;
}
