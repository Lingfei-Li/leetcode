// 0ms
// ...............to_string()?

#include"mytest.h"


void push_ans(vector<string>& ans, int l, int r) {
    string* tmp = new string;
    if(l == r) {
        *tmp += to_string(l);
    }
    else {
        *tmp += to_string(l);
        *tmp += "->";
        *tmp += to_string(r);
    }

    ans.push_back(*tmp);
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    int n = nums.size();
    if(!n) return ans;
    int l = -1, r = -1;
    for(int i = 0; i < n; i ++) {
        if(l == -1) {
            l = r = nums[i];
        }
        else {
            if(nums[i] == r + 1) {
                r = r + 1;
            }
            else {
                push_ans(ans, l, r);
                l = r = nums[i];
            }
        }
    }
    push_ans(ans, l, r);
    return ans;
            
}



int main() {
	srand(time(NULL));

    vector<int> v;
    genVector(v,2);
    sort(v.begin(), v.end());
    printVector(v);
    vector<string> ans = summaryRanges(v);
    printVector(ans);
    




    return 0;
}
