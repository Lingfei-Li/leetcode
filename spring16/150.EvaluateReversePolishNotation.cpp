// slow 5.0%
// reverse polish notation
// stack

#include"mytest.h"


using namespace std;


bool isop(string& s) {
    if(s == "+" || s == "-" || s == "*" || s == "/") return true;
    return false;
}


int eval(string& sl, string& sr, string& op) {
    int l = atoi(sl.c_str());
    int r = atoi(sr.c_str());
    if(op == "+") 
        return l+r; 
    else if(op == "-")
        return l-r; 
    else if (op == "*")
        return l*r;
    else
        return l/r;
}

int evalRPN(vector<string>& tokens) {
    int n = tokens.size();
    stack<string> stk;
    for(int i = n-1; i >= 0; i --) {
        string& s1 = tokens[i];
        if(stk.empty() || isop(s1) || isop(stk.top()))  {
            stk.push(s1);
        }
        else {
            //calc
            do {
                string s2 = stk.top();
                stk.pop();
                string op = stk.top();
                stk.pop();
                ostringstream sin;
                sin<<eval(s1, s2, op);
                s1 = sin.str();
            } while(!stk.empty() && !isop(stk.top()));
            stk.push(s1);
        }
    }

    if(!stk.empty()) return atoi(stk.top().c_str());

/*
    while(!stk.empty()) {
        string &s1 = stk.top();
        stk.pop();
        if(stk.empty()) return atoi(s1.c_str());
        string& s2 = stk.top();
        stk.pop();
        string op = stk.top();
        stk.pop();
        ostringstream sin;
        sin<<eval(s1, s2, op);
        stk.push(sin.str());
    }
    */
    return 0;

}


int main() {
	srand(time(NULL));


    while(1) {
        vector<string> v;
        string s;
        while(cin>>s && s != "end") {
            cout<<s<<" ";
            v.push_back(s);
        }
        cout<<endl;
        if(v.size() == 0) break;
        cout<<evalRPN(v)<<endl;
    }



    return 0;
}
