// 17.38% 2nd group
// backtracking

#include"mytest.h"


void solve(int k, int n, int u, vector<vector<int> >& ans, vector<int>& tmp) {

    if(!k && !n) {
        ans.push_back(tmp);
        return;
    }
    if(k <= 0) return;

    int tmpsz = tmp.size();
    for(int i = u+1; i < 10 && i <= n; i ++) {
        tmp.push_back(i);
        solve(k-1, n-i, i, ans, tmp);
        tmp.resize(tmpsz);
    }
}


vector<vector<int> > combinationSum3(int k, int n) {

    vector<vector<int> > ans;
    vector<int> tmp;
    solve(k, n, 0, ans, tmp);

    for(int i = 0; i < ans.size(); i ++) {
        printVector(ans[i]);
    }

    return ans;
                
}



int main() {
	srand(time(NULL));


    int n, k;
    while(cin>>k>>n) {
        combinationSum3(k, n);
    }


    return 0;
}
