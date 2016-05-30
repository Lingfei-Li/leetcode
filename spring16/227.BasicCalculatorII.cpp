// 33.28% after mainstream
// dequeue

#include"mytest.h"


int isop(char c) {
    switch(c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        deault:
            return 0;
    }
    return 0;
}

int isnum(char c) {
    if(c >= '0' && c <= '9') 
        return 1;
    return 0;
}

int calculate(string s) {


    int n = s.length();
    if(!n) return 0;
//    stack<int> stk;
    deque<int> stk;
    int opi[300];
    int add = -1, minus = -2, multiply = -3, devide = -4;
    opi['+'] = add;
    opi['-'] = minus;
    opi['*'] = multiply;
    opi['/'] = devide;
    for(int i = 0; i < n; i ++) {
        char c = s[i];
        if(isnum(c)) {
            int a = atoi(s.c_str() + i);

            if(!stk.empty() && (stk.front() == multiply || stk.front() == devide)) {
                int op = stk.front();
                stk.pop_front();
                int b = stk.front();
                stk.pop_front();
                switch(op) {
                    case -3:        //multiply
                        a = a*b;
                        break;
                    case -4:        //divide
                        a = b/a;
                        break;
                }
            }
            stk.push_front(a);

            for(; i < n && isnum(s[i]); i ++);
            i --;
        }
        else if(isop(c)){
            stk.push_front(opi[c]);
        }
        else {
        
        }
    
    }

    while(stk.size() > 1) {
        int a = stk.back();
        stk.pop_back();
        int op = stk.back();
        stk.pop_back();
        int b = stk.back();
        stk.pop_back();
        switch(op) {
            case -1:    //add
                a = a+b;
                break;
            case -2:        //minus
                a = a-b;
                break;
        }
        stk.push_back(a);
    }
    return stk.front();


}



int main() {
	srand(time(NULL));

    string s;
    while(getline(cin, s)){
        cout<<s<<endl;
        cout<<calculate(s)<<endl;
    }



    return 0;
}
