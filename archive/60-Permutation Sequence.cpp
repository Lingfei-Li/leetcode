#include"mytest.cpp"


using namespace std;

string getPermutation(int n, int k) {
    string ans = "";
    if(n == 0 || k == 0) return ans;
    int fact[10];
    fact[0] = 1;
    for(int i = 1; i <= n; i ++)
        fact[i] = fact[i-1]*i;

    int digit[10];
    memset(digit, 0, sizeof(digit));

    int cnt = n;
    int c = 0;
    while(k > 1) {
        int a = (k-1)/fact[cnt-1]+1;
        digit[c++] = a;
        k -= (a-1)*fact[--cnt];
    }
    while((cnt--)>0)
        digit[c++] = 1;

    int vis[10];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < c; i ++) { //high digit -> low
        int d = digit[i];

        for(int j = 1; j <= d; j ++) {
            if(vis[j]) {
                d++;
            }
        }
        ans += d+'0';
        vis[d] = 1;
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
