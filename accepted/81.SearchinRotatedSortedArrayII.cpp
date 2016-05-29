// Feature:
// binary search
// handling of duplication

#include"mytest.h"


using namespace std;



bool search(vector<int>& nums, int target) {
    int n = nums.size();
    if(!n) return false;

    int l = 0, r = n-1;

    //new code from lc33
    //eliminate duplicate of start and end.
    while(l < r && nums[l] == nums[l+1]) l++;
    while(l < r && nums[r] == nums[r-1]) r--;

    r ++;
    if(l < r-1 && nums[l] == nums[r-1]) r --;    //eliminate duplicate of two ends, when l != r-1


    //below: same as 33

    while(l<r) {
        int m = (l+r)/2;
        if(nums[l] > nums[r-1]) { //rotated
            if(target >= nums[l]) { //target: left side
                if(nums[m] >= nums[l]) { //m: same side, normal bisearch
                    if(nums[m] == target) return true;
                    else if(nums[m] > target) r = m;
                    else l = m+1;
                }
                else if(nums[m] < nums[l]) r = m;   //diff side, shrink r
            }
            else if(target <= nums[r-1]){ //target: right side
                if(nums[m] <= nums[r-1]) { //m: same side
                    if(nums[m] == target) return true;
                    else if(nums[m] > target) r = m;
                    else l = m+1;
                }
                else {
                    l = m+1;
                }

            }
            else return false;
        }
        else {
            if(nums[m] == target) return true;
            else if(nums[m] > target) {
                r = m; 
            }
            else {
                l = m+1;
            }
        }
    }
    return false;
}


int main() {
	srand(time(NULL));
    int a;
    vector<int> v;
    while(cin>>a && a >= 0) {
        v.push_back(a);
    }

    int target = 4;
    printVector(v);
    cout<<search(v, target)<<endl;



    return 0;
}
