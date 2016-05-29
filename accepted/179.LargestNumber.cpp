// 23.36% med (but I think mine is a succinct implementation)
// corner cases....
//  1.integer overflow
//  2.zeros
//  3.comparison function (what's the return value?)

#include"mytest.h"


static int cmp(const int& a1, const int& a2) {
    string s1 = to_string(a1), s2 = to_string(a2);
    long long c1 = stoll((s1+s2).c_str());
    long long c2 = stoll((s2+s1).c_str());  //mind overflow!
    return c1<c2;
}

string largestNumber(vector<int>& nums) {
    int n = nums.size();
    string ans;
    if(!n) return ans;

    sort(nums.begin(), nums.end(), cmp);
    printVector(nums);

    if(nums[n-1] == 0) return ans="0";    //all 0s
    
    for(int i = n-1; i >= 0; i --) 
        ans += to_string(nums[i]);

    
    return ans;
}


int main() {
	srand(time(NULL));

    vector<int> v;
//    genVector(v, 5, 1000);
    readVectorInt(v);
    printVector(v);
//    sort(v.begin(), v.end());
//    printVector(v);
//    return 0;
    cout<<endl;
    cout<<largestNumber(v)<<endl;




    return 0;
}
