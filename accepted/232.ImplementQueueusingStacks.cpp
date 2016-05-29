#include"mytest.h"

class Queue {
private:
    stack<int> stk;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> tmp;
        while(!stk.empty()) {
            tmp.push(stk.top());
            stk.pop();
        }
        stk.push(x);
        while(!tmp.empty()) {
            stk.push(tmp.top());
            tmp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stk.pop();
    }

    // Get the front element.
    int peek(void) {
        return stk.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk.empty();
        
    }
};

int main() {
	srand(time(NULL));

    Queue q;
    string s;
    int t;
    while(cin>>s) {
        cout<<s<<endl;
        if(s == "push") {
            cin>>t;
            cout<<t<<endl;
            q.push(t);
        }
        else if(s == "pop") {
            q.pop();
        }
        else if(s == "top") {
            cout<<q.peek()<<endl;
        }
        else {
            cout<<q.empty()<<endl;
        }
    }


    return 0;
}
