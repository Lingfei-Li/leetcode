// boring...

#include"mytest.h"

vector<int> countBits(int num) {
    num ++;
    vector<int> ans;
    int a[4] = {0,1,1,2};
    for(int i = 0; i < min(4,num);i ++) {
        ans.push_back(a[i]);
    }
    if(num <= 4){
        return ans;
    }

    long long len = 2;
    int p = 2;
    while(ans.size() < num){
        for(int j = 0; j < len; j ++) {
            int tmp = ans[p+j];
            ans.push_back(tmp);
            if(ans.size() == num) return ans;
        }
        for(int j = 0; j < len; j ++) {
            int tmp = ans[p+j];
            ans.push_back(tmp+1);
            if(ans.size() == num) return ans;
        }
        p += len;
        len*= 2;
    }
    return ans;
}



int main() {
	srand(time(NULL));


    int a;
    while(cin>>a) print(countBits(a));


    return 0;
}
