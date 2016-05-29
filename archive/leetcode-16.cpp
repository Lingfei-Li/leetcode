#include<cstdio>
#include<cstring>
#include<algorithm>

#include<vector>

#include<queue>
#include<string>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<set>
#include<map>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;


//Global Variables.

////


void update_ans(int& ans, int target, int s1, int s2) {
    if(abs(s1-target) < abs(ans-target)) {
        ans = s1;
    }
    if(abs(s2-target) < abs(ans-target)) {
        ans = s2;
    }
}

int threeSumClosest(vector<int>& nums, int target) {
    int ans = 0, n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < min(3, n); i ++) ans += nums[i];
    if(nums.size() < 3) return ans;

    for(int i = 0; i < n; i ++) {
        if(i && nums[i] == nums[i-1]) continue;
        int a = i + 1, b = n - 1;

        int  u = nums[i] + nums[a] + nums[b] - target, v = u;
        while(a < b) {
            u = nums[i] + nums[a] + nums[b] - target;
            update_ans(ans, target, u+target, v+target);
            if(a != i + 1 && nums[a] == nums[a-1]) a ++;
            else if(b != n-1 && nums[b] == nums[b+1]) b --;
            else if(u == 0) return target;
            else if(u > 0) {
                b --;
            }
            else if(u < 0) {
                a ++;
            }
            v = u;
        }
    }
    return ans;
}



int main() {


    while(1){
        vector<int> v;
        int x;
        while(cin>>x && x!=88) v.push_back(x);
        cin>>x;
        cout<<threeSumClosest(v, x)<<endl;
    }





    return 0;
}
