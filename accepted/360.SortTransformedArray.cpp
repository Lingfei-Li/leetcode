#include"mytest.h"



class Solution {
public:
    int calc(int x, int a, int b, int c){
        return a*x*x+b*x+c;
    }

    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> ans;
        int n = nums.size();
        if(!n) return ans;
        ans.resize(n);
        int p1, p2, p;
        p1 = 0;
        p2 = n-1;
        if(a > 0) { p = n-1; }
        else { p = 0; }
        while(p1<=p2){
            int n1 = calc(nums[p1], a, b, c);
            int n2 = calc(nums[p2], a, b, c);
            int u;
            if(a > 0) {
                if(n1 > n2) {
                    u = n1;
                    p1 ++;
                }
                else {
                    u = n2;
                    p2 --;
                }
                ans[p--] = u;
            }
            else {
                if(n1 < n2) {
                    u = n1;
                    p1 ++;
                }
                else {
                    u = n2;
                    p2 --;
                }
                ans[p++] = u;
            }
        }
        return ans;
    }
};


int main() {
	srand(time(NULL));

    Solution sol;
    int a, b, c;
    cin>>a>>b>>c;
    vector<int> v;
    read(v);
    print(v);
    print(sol.sortTransformedArray(v, a, b, c));



    return 0;
}
