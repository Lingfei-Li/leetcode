// 0ms
// scanning method
// min value, second min value

#include"mytest.h"

bool increasingTriplet(vector<int>& nums) {
    if(nums.size() < 3) return false;

    int min = (1<<31)-1, mid = (1<<31)-1;
    for(int i = 0; i < nums.size(); i ++) {
        int a = nums[i];
        if(a <= min) {
            min = a;
        }
        else if(a <= mid) {
            mid = a;
        }
        else
            return true;
    }
    return false;
                
}



int main() {
	srand(time(NULL));

    vector<int> v;
    read(v);
    print(v);
    cout<<increasingTriplet(v)<<endl;



    return 0;
}
