#include"mytest.h"
#include <limits.h>


class Solution {

public:

    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return true;
        stack<int> st;
        int low = INT_MIN;
        st.push(preorder[0]);
        for(unsigned int i = 1; i < preorder.size(); i ++) {
            int p = preorder[i];
            if(st.empty() || p < low) return false;
            while(!st.empty() && p > st.top()) {
                low = st.top();
                st.pop();
            }
            st.push(p);
        }
        return true;
    }

};


int main() {
	srand(time(NULL));

    Solution sol;
    vector<int> v;
    read(v);
    print(v);
    cout<<sol.verifyPreorder(v)<<endl;




    return 0;
}
