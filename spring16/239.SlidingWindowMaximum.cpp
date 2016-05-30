// 53.7% ok
// monotonic queue (sliding window)

#include"mytest.h"


void dqinsert(deque<pair<int,int> >& dq, int a, int b) {
    pair<int,int> p = pair<int,int>(a,b);
    while(!dq.empty() && dq.back().first <= a) {
        if(dq.back().first == a) {
            dq.back().second = b;
            return;
        }
        dq.pop_back();
    }
    dq.push_back(p);
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    if(!n) return ans;
    deque<pair<int,int> > dq;

    for(int i = 0; i < k; i ++) {
        dqinsert(dq, nums[i], i);
    }

    ans.push_back(dq.front().first);

    for(int i = k; i < n; i ++) {
        while(!dq.empty() && dq.front().second <= i-k) {
            dq.pop_front();
        }
        dqinsert(dq, nums[i], i);
        ans.push_back(dq.front().first);
    }
    return ans;
}







int main() {
	srand(time(NULL));


    vector<int> v;
    readVector(v);
    printVector(v);
    v = maxSlidingWindow(v, 3);
    printVector(v);


    return 0;
}
