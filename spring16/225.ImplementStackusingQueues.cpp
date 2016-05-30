// 0ms
// queue & stack

#include"mytest.h"

class Stack {
private: 
    queue<int> q[2];
public:
    // Push element x onto stack.
    void push(int x) {
        int t = 0;
        if(q[0].empty()) t = 1;
        q[t^1].push(x);
        while(!q[t].empty()) {
            q[t^1].push(q[t].front());
            q[t].pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        int t = 0;
        if(q[0].empty()) t = 1;
        q[t].pop();
    }

    // Get the top element.
    int top() {
        int t = 0;
        if(q[0].empty()) t = 1;
        return q[t].front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[0].empty()&&q[1].empty();
    }
};

int main() {
	srand(time(NULL));

    Stack stk;
    string s;
    int t;
    while(cin>>s) {
        cout<<s<<endl;
        if(s == "push") {
            cin>>t;
            cout<<t<<endl;
            stk.push(t);
        }
        else if(s == "pop") {
            stk.pop();
        }
        else if(s == "top") {
            cout<<stk.top()<<endl;
        }
        else {
            cout<<stk.empty()<<endl;
        }
    }




    return 0;
}
