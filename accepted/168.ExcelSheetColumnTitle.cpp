// 0ms
// modulos division (math)

#include"mytest.h"


string convertToTitle(int n) {
    string ans;
    if(n<=0) return ans;

    while(n){
        ans.push_back((n-1)%26+'A');
        n=(n-1)/26;
    }

    int len = ans.length();
    for(int i = 0; i < len/2; i ++) {
        swap(ans[i], ans[len-1-i]);
    }
    return ans;

}


int main() {
	srand(time(NULL));

    int a;
    while(cin>>a)
        cout<<convertToTitle(a)<<endl;




    return 0;
}
