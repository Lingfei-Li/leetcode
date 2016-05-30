// 0ms
// find patterns

#include"mytest.h"

int bulbSwitch(int n) {

    /*
    vector<int> v;
    v.resize(n);

    for(int i = 1; i <= n; i ++) {
        for(int j = i; j <= n; j += i) {
            v[j-1] = (v[j-1]+1)%2;;
        }
        printVector(v);
    }
    */

    long long sum = 0;
    int ans = 0;
    for(int i = 1; i <= n; i += 2) {
        sum += i;
        if(n < sum) {
            break;
        }
        ans ++;
    }

    return ans;

                
}



int main() {
	srand(time(NULL));

    int a;
    while(cin>>a) cout<<bulbSwitch(a)<<endl;



    return 0;
}
