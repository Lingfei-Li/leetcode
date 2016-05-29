//Feature:
//The use of stack to achieve O(n) complexity - time and space
//The calculation of rect area in during and after scanning
//Need to be very careful when coding. Can make mistakes easily

#include"mytest.h"


using namespace std;

int largestRectangleArea(vector<int>& heights) {

    stack<int> stk;

    int ans = 0;
    int n = heights.size();

    for(int r = 0; r < n; r ++) {
        while(!stk.empty() && heights[r] < heights[stk.top()]) {
            int l = stk.top(); 
            stk.pop();
            if(stk.empty()) {
                ans = max(ans, r*(heights[l]));
            }
            else {
                ans = max(ans, (r-stk.top()-1)*(heights[l]));   
            }
        }
        while(!stk.empty() && heights[r] == heights[stk.top()]) 
            stk.pop();
        stk.push(r);
        ans = max(ans, heights[r]);
    }
    int h = -1;
    while(!stk.empty()){
        int l = stk.top();
        stk.pop();
        ans = max(ans, (n-l-1)*h);
        h = heights[l];
    }
    ans = max(ans, (n*h));

    return ans;

}

int main() {
	srand(time(NULL));

    vector<int> heights;
    int a, k;
    cin>>k;
    while(k--){
        heights.clear();
        while(cin>>a && a != -1) {
            cout<<a<<" ";
            heights.push_back(a);
        }
        cout<<endl;
        cout<<largestRectangleArea(heights)<<endl;
    }


    return 0;
}
