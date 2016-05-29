// 11.97% good
// binary search
// with duplicates
// change of meaning of 'r'

#include"mytest.h"


using namespace std;


int findMin(vector<int>& nums) {

    int n = nums.size();
    if(!n) return 0;
    if(n==1) return nums[0];
    int l = 0, r = n-1;


    while(l<=r) {
        //handle duplicates
        while(l<r) {
            if(nums[l] == nums[l+1]) {
                l ++;
                continue;
            }
            if(nums[r] == nums[r-1]) {
                r--;
                continue;
            }
            if(nums[l] == nums[r]) {
                r--;
                continue;
            }
            break;
        }
        if(l == r) return nums[l];

        int m = (l+r+1)/2;

        while(nums[m] == nums[m-1]) {
            m --;
        }
        int a = nums[l], b = nums[m], c = nums[r];

        //binary search;
        if(a > c) { //rotated
            if(a < b) { //m is on left side.
                l = m;
            }
            else {
                if(b > nums[m-1]) { //rhs of pivot
                    r = m-1;
                }
                else {
                    l = m;
                }
            }
        }
        else {
            return a;
        }
    }
    return nums[0];

}



int main() {
	srand(time(NULL));


    vector<int> v;
    readVectorInt(v);
    cout<<findMin(v)<<endl;




    return 0;
}
