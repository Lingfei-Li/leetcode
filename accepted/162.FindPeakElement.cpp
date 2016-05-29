// 3.16% med
// binary search (variation)

#include"mytest.h"


bool asc(int i, vector<int>& nums) {
    if(i == nums.size()-1) return false;
    if(nums[i] < nums[i+1]) return true;
    return false;
}

bool ispeak(int i, vector<int>& nums) {
    int n = nums.size();
    if(i && i!=n-1) {
        if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return true;
    }
    else if(i) {    //last element
        if(nums[i] > nums[i-1]) return true;
    }
    else if(i != n-1) { //first element
        if(nums[i] > nums[i+1]) return true;
    }
    else return true;
}

int findPeakElement(vector<int>& nums) {

    int n = nums.size();
    if(n <= 1) return 0;
    if(n == 2) return (nums[0]>nums[1])?0:1;
    if(nums[0] > nums[1]) return 0;
    if(nums[n-1] > nums[n-2]) return n-1;

    int l = 0, r = n-1;
    while(l<=r) {
        int m = (l+r+1)/2;
        int a = nums[l], b = nums[m], c = nums[r];
//        printf("%d %d %d\n", l, r, m);
        if(l == r) return l;
        if(l == r-1) return (nums[l]>nums[r])?l:r;
        if(ispeak(m, nums)) return m;


        if(asc(l, nums)) {   //l is ascending
            if(asc(m, nums)) {
                l = m;
            }
            else {
                r = m;
            }
        }
        else {  //l is not ascending -> r is ascending (other direction)
            if(!asc(m, nums)) {
                r = m;
            }
            else {
//                cout<<"asd\n";
                l = m;
            }
        }
    }

    /*
    for(int i = 0; i < n; i ++) {
        if(i && i!=n-1) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        }
        else if(i) {    //last element
            if(nums[i] > nums[i-1]) return i;
        }
        else if(i != n-1) { //first element
            if(nums[i] > nums[i+1]) return i;
        }
    }
    */
    return 0;
}



int main() {
	srand(time(NULL));

    vector<int> v;
//    while(readVectorInt(v)) {
    for(int i = 0; i < 100; i ++) {
        genVector(v, 2);
//        printVector(v);
        int p = findPeakElement(v);
        if(ispeak(p,v) == false) {
            printVector(v);
            cout<<p<<endl;
        }
        v.clear();
    }



    return 0;
}
