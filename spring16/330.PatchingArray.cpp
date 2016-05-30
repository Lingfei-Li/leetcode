// 33.52% fastest
// greedy: covering the whole range
// INTEGER OVERFLOW........................

#include"mytest.h"

int minPatches(vector<int>& nums, int n) {
    int p = 0;
    long long i = 0;
    int ans = 0;
    while(i < n) {
//        printf("i: %d\n", i);
        if(p < nums.size() && nums[p] <= i+1) {
            i += nums[p++];
        }
        else {
            ans ++;
//            printf("add %d\n", i+1);
            i += i+1;
        }
    }
    return ans;
}



int main() {
	srand(time(NULL));


    int n;
    cin>>n;
    cout<<n<<endl;
    vector<int> v;
    readVector(v);
    printVector(v);
    cout<<minPatches(v, n)<<endl;


    return 0;
}
