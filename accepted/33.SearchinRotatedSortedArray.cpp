// Feature:
// binary search
// conditions in the problem

#include"mytest.h"


using namespace std;



int search(vector<int>& nums, int target) {
    int n = nums.size();
    if(!n) return -1;

    int l = 0, r = n;
    while(l<r) {
        int m = (l+r)/2;
        if(nums[l] > nums[r-1]) { //rotated
            if(target >= nums[l]) { //target: left side
                if(nums[m] >= nums[l]) { //m: same side, normal bisearch
                    if(nums[m] == target) return m;
                    else if(nums[m] > target) r = m;
                    else l = m+1;
                }
                else if(nums[m] < nums[l]) r = m;   //diff side, shrink r
            }
            else if(target <= nums[r-1]){ //target: right side
                if(nums[m] <= nums[r-1]) { //m: same side
                    if(nums[m] == target) return m;
                    else if(nums[m] > target) r = m;
                    else l = m+1;
                }
                else {
                    l = m+1;
                }

            }
            else return -1;
        }
        else {
            if(nums[m] == target) return m;
            else if(nums[m] > target) {
                r = m; 
            }
            else {
                l = m+1;
            }
        }
    }
    return -1;
}


int main() {
	srand(time(NULL));
    int a;
    vector<int> v;
    while(cin>>a && a >= 0) {
        v.push_back(a);
    }

    int target = 2;
    printVector(v);
    cout<<search(v, target)<<endl;



    return 0;
}
