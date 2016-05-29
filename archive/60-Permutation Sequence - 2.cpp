#include"mytest.cpp"


using namespace std;


int rec(int pos, int n, int k, int& cnt, int* vis) {
    for(int i = 1; i <= n; i ++) {
        if(vis[i] == -1) {
            vis[i] = pos;
            if(pos == n-1) {
                cnt ++;
                if(cnt == k) {
                    return 1;
                }
                else {
                    vis[i] = -1;
                    return 0;
                }
            }
            else {
                if(rec(pos+1, n, k, cnt, vis)) return 1;
            }
            vis[i] = -1;
        }
    }
    return 0;
}


string getPermutation(int n, int k) {
    string ans;
    ans.resize(n);
//    int cnt = 0;
//    int vis[10];
//    memset(vis, -1, sizeof(vis));
//    rec(0, n, k, cnt, vis);
//    for(int i = 1; i <= n; i ++) {
//        ans[vis[i]] = i+'0';
//    }
//    return ans;

    for(int i = 0; i < n; i ++) ans[i] = i+'1';
    for(int i = 0; i < k-1; i ++) {
        next_permutation(ans.begin(), ans.end());
    }
    return ans;
}


int main() {
	srand(time(NULL));

    int n, k;
    while(cin>>n>>k) {
        cout<<getPermutation(n, k)<<endl;
    }
    return 0;
}
