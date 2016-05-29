#include"mytest.cpp"


using namespace std;



string addBinary(string a, string b) {
    string ans;
    string tmp1, tmp2;
    int n = max(a.length(), b.length());
    tmp1.resize(n);
    tmp2.resize(n);


    for(int i = 0; i < n; i ++) {
        tmp1[n-1-i] = (i<a.length())?a[a.length()-1-i]:'0';
        tmp2[n-1-i] = (i<b.length())?b[b.length()-1-i]:'0';
    }

    ans.resize(n+1);


    int c = 0;
    for(int i = 0; i < n; i ++) {
        int x = tmp1[n-1-i] - '0';
        int y = tmp2[n-1-i] - '0';
        ans[n-i] = (x+y+c)%2 + '0';
        if(x+y+c >= 2) c = 1;
        else c = 0;
    }
    if(c) ans[0] = '1';
    else ans = ans.substr(1, ans.length()-1);

    return ans;
}

int main() {
	srand(time(NULL));


    string s1, s2;
    while(cin>>s1>>s2) {
        cout<<addBinary(s1, s2)<<endl;
    }



    return 0;
}
