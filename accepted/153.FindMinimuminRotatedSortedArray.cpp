// 8.87% good
// binary search

#include"mytest.h"


using namespace std;


int findMin(vector<int>& nums) {

    int n = nums.size();
    if(!n) return 0;
    if(n==1) return nums[0];
    int l = 0, r = n;

    while(l<r) {
        int m = (l+r)/2;
        int a = nums[l], b = nums[m], c = nums[r-1];
        if(l == m) return a;
        if(a > c) { //rotated
            if(a < b) { //m is on left side.
                l = m;
            }
            else {
                if(b > nums[m-1]) { //rhs of pivot
                    r = m;
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
