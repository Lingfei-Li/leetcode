#include"mytest.cpp"


using namespace std;


string minWindow(string s, string t) {
    if(!s.size() || !t.size()) return string();

    map<char, int> req;
    int reqcnt = 0;
    for(int i = 0; i < t.size(); i ++) {
        req[t[i]] ++;
        reqcnt ++;
    }

    map<char, int> dict;
    int cnt = 0, l = 0;
    pair<int,int> ans(0, s.size()+1);     //start pos, len of ans

    for(int i = 0; i < s.size(); i ++) {
        //expand window
        char c = s[i];
        dict[c] ++;
        if(dict[c] <= req[c]) cnt ++;

        //shrink window
        while(l <= i && cnt == reqcnt) {
            if(ans.second > i-l+1) ans.first = l, ans.second = i-l+1;
            dict[s[l]] --;
            if(dict[s[l]] < req[s[l]])
                cnt --;
            l ++;
        }
    }
    if(ans.second == s.size()+1) return string();
    return s.substr(ans.first, ans.second);
}


int main() {
	srand(time(NULL));


    string s, t;
    while(cin>>s>>t) {

        cout<<minWindow(s, t)<<endl;
    }



    return 0;
}
