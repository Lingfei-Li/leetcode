// 3.95% med
// stack


#include"mytest.h"


using namespace std;


struct MinStack {
    stack<int> stk;
    stack<int> minEle;
    void push(int x) {
        if(minEle.empty()) {
            minEle.push(x);    
        }
        else
            minEle.push(min(x, minEle.top()));
        stk.push(x);
    }

    void pop() {
        stk.pop();
        minEle.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minEle.top();
    }
};



int main() {
	srand(time(NULL));

    int a;
    MinStack minstack;
    while(cin>>a) {
        if(a < 0) minstack.pop();
        else minstack.push(a);
        printf("%d\n", minstack.getMin());
    }




    return 0;
}
