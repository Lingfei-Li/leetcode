#include"mytest.cpp"
#define SPOJ "79-Word Search"


using namespace std;

static void pickCombination(int n, int k, int remaining, int p, vector<int>& comb, vector<vector<int> >& ans) {
    if(!remaining) {
        ans.push_back(comb);
        return;
    }
    int initsize = comb.size();
    for(int i = p; i <= n-remaining+1; i ++) {
        comb.push_back(i);
        pickCombination(n, k, remaining-1, i+1, comb, ans);
        comb.resize(initsize);
    }
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > ans;
    if(!n || !k) return ans;
    vector<int> dummy;
    pickCombination(n, k, k, 1, dummy, ans);
    return ans;
}

int main() {
	srand(time(NULL));
    #define DEBUG 1


    int n, k;
    while(cin>>n>>k) {
        vector<vector<int> > ans = combine(n, k);
        for(int i = 0; i < ans.size(); i ++) {
            for(int j = 0; j < ans[i].size(); j ++) {
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }



    return 0;
}
