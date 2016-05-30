#include"mytest.h"


using namespace std;

//Feature: 
//      the use of two walking pointers. 
//      Check appearing "twice" by p2-2
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2) return n;
    int p1 = 0, p2 = 0;
    for(p2 = 0; p2 < n; p2 ++) {
        if(p1<2 || nums[p1-2] != nums[p2]) {
            nums[p1++] = nums[p2];
        }
    }

    return p1;
}


int main() {
	srand(time(NULL));

    vector<int> nums;
    genVector(nums, 5);
    sort(nums.begin(), nums.end());

    printVector(nums);
    cout<<removeDuplicates(nums)<<endl;
    printVector(nums);



    return 0;
}
