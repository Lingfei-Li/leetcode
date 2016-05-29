// 30.22% slow...
// stack

#include"mytest.h"


int isnum(char c) {
    if(c >= '0' && c <= '9') return 1;
    return 0;
}

int isop(char c) {
    if(c  == '+' || c == '-') return 1;
    return 0;
}

int isparenth(char c) {
    if(c == '(' || c == ')') return 1;
    return 0;
}


int calculate(string s) {
    if(s.length() == 0) return 0;
    int add = -1, minus = -2, leftp = -3, rightp = -4;
    stack<int> stk;
    int n = s.length();

    for(int i = 0; i < n; i ++) {
//        printf("i: %d\n", i);
        char ch = s[i];
        if(isop(ch)) {
//            cout<<"push op\n";
            if(ch == '+') stk.push(add);
            if(ch == '-') stk.push(minus);
        }
        else if(isnum(ch)) {
            int a = atoi(s.c_str()+i);
            int j = i;
            for(j; isnum(s[j]) && j < n; j ++);
            i = j-1;

//            printf("a: %d\n", a);
            while(stk.size() > 1 && stk.top() != leftp) { //an operator. compute and re-push
                int op = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
//                printf("a: %d, b: %d\n", a, b);
                if(op == add) {
                    a = b+a;
//                    printf("add:  %d\n", a);
                }
                else {
                    a = b-a;
//                    printf("minus:  %d\n", a);
                }
            }
            stk.push(a);
        }
        else if(ch == ')'){     //eliminate left p
            int a = stk.top();
            stk.pop();
            stk.pop();  //must be '('
            while(stk.size() > 1 && stk.top() != leftp) { //an operator. compute and re-push
                int op = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
//                printf("a: %d, b: %d\n", a, b);
                if(op == add) {
                    a = b+a;
//                    printf("add:  %d\n", a);
                }
                else {
                    a = b-a;
//                    printf("minus:  %d\n", a);
                }
            }
            stk.push(a);
        }
        else if(ch == '(') {
//            printf("push leftp\n");
            stk.push(leftp);
        }
        else {
//            if(ch != ' ')
//                printf("oops: %c\n", ch);
        
        }
    }
    return stk.top();
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
