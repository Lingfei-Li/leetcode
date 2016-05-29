// 33.21% good
// math

#include"mytest.h"


int titleToNumber(string s) {
    if(!s.length()) return 0;
    int ans = 0, times = 1;
    for(int i = s.length()-1; i >= 0; i --) {
        ans += times*(s[i]-'A'+1);
        times *= 26;
    }
    return ans;
}


int main() {
	srand(time(NULL));

    string s;
    while(cin>>s) cout<<titleToNumber(s)<<endl;



    return 0;
}
