// Feature:
// Palindrom
// Backtracking

#include"mytest.h"


using namespace std;

bool ispalindrom(string& s, int l, int r) {
    while(l<r) {
        if(s[l] != s[r]) return false;
        l++;r--;
    }
    return true;
}

void solve(vector<vector<string> >& ans, string& s, int l, vector<string>& tmp ) {
    int r = s.length()-1;

    //no need to partition:
    if(ispalindrom(s, l, r)) {
        int sz = tmp.size();
        tmp.push_back(s.substr(l,r-l+1));
        ans.push_back(tmp);
        tmp.resize(sz);
    }
    //partition:
    for(int i = l; i < r; i ++) {
        if(ispalindrom(s, l, i)) {
            int sz = tmp.size();
            tmp.push_back(s.substr(l, i-l+1));
            solve(ans, s, i+1, tmp);
            tmp.resize(sz);
        }
    }
} 

vector<vector<string> > partition(string s) {
    vector<vector<string> > ans;
    vector<string> tmp;

    solve(ans, s, 0, tmp);

    return ans;
                
}


int main() {
	srand(time(NULL));


    string s;
    while(cin>>s) {
    vector<vector<string> > ans =  partition(s);
    for(int i = 0; i < ans.size(); i ++) {
        for(int j = 0; j < ans[i].size(); j ++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    }




    return 0;
}
