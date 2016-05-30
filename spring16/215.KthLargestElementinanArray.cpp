// 73.69% but.....................
// wtf

#include"mytest.h"

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()-k];
}



int main() {
	srand(time(NULL));


    vector<int> v;
    genVector(v,50);
        printVector(v);
    int a;
    while(cin>>a) {
        cout<<findKthLargest(v, a)<<endl;
        printVector(v);
    }





    return 0;
}
