// Feature:
// Dynamic programming (light)
// O(n) method of largest rectangle area problem

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




int maximalRectangle(vector<vector<char> >& matrix) {
    int ans = 0;
    int n = matrix.size();
    if(!n) return 0;
    int m = matrix[0].size();
    if(!m) return 0;

    vector<vector<int> > heights;
    heights.resize(n);
    
    for(int i = 0; i < n; i ++) {
        heights[i].resize(m);
    }


//    cout<<endl;
    for(int j = 0; j < m; j ++) {
        heights[0][j] = matrix[0][j]-'0';
//        cout<<heights[0][j]<<" ";
    }

//    cout<<endl;
    for(int i = 1; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(matrix[i][j] == '0') heights[i][j] = 0;
            else heights[i][j] = heights[i-1][j]+1;
//            cout<<heights[i][j]<<" ";
        }
//        cout<<endl;
    }


    for(int i = 0; i < n; i ++) {
        ans = max(ans, largestRectangleArea(heights[i]));
    }


    return ans;

}

int main() {
	srand(time(NULL));

    int a, k;
    while(cin>>k){
        vector<vector<char> > m;
        m.resize(k);
        for(int i = 0; i < k; i ++) {
            m[i].clear();
            while(cin>>a && a != -1) {
                cout<<a<<" ";
                m[i].push_back(a+'0');
            }
            cout<<endl;
        }
        cout<<maximalRectangle(m)<<endl<<endl;
    // cout<<largestRectangleArea(m)<<endl;
    }

    return 0;
}

