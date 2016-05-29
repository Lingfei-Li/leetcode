// 4.24% okay...not a performance-tensive problem
// comprehensive analysis of all possible cases
// ability of generalization (reason of a single fault -> a set of faults)

#include"mytest.h"


/*
    1. pow of 10: 2e8
        1.1 cannot appear after dot
        1.2 cannot appear before dot
            10.5e2 ok
            2e10.5 no
    2. fraction: 0.1 1.0
        2.1 only one dot per num
        2.2 neg sign cannot appear after dot
    3. integer
    4. comb
    5. neg
    6. space

   */

bool isnum(char c) {
    if(c >= '0' && c <= '9') return true;
    return false;
}

bool valid(char c) {
    if(isnum(c)) return true;
    char v[] = {'-', 'e', '+', '.'};
    for(int i = 0; i < 4; i ++) {
        if(c == v[i]) return true;
    }
    return false;
}

// -2: bad num. -1: not exp. positive: pos of exp
int exppos(string& s) {
    int n = s.length(), pos = -1;
    for(int i = 0; i < n; i ++ ){
        if(!valid(s[i])){
            return -2;
        }
        if(s[i] == 'e') {
            if(pos<0) pos = i;
            else return -2; //invalid number: 2e
        }
    }
    return pos;
}

bool issign(char c) {
    if(c == '+' || c == '-') return true;
    return false;
}

bool issign(string &s) {
    if(s.length() == 1 && issign(s[0])) return true;
    return false;

}

bool isint(string& s) {
    if(s.length() == 0) return true;
    if(!isnum(s[0]) && s[0] != '-' && s[0] != '+') return false;
    if(s.length() == 1 && (s[0] == '-' || s[0] == '+')) return false;
    for(int i = 1; i < s.length(); i ++) {
        if(!isnum(s[i])) return false;
    }
    return true;
}

bool isunsignedint(string& s) {
    if(s.length() == 0) return true;
    if(isnum(s[0]) && isint(s)) return true;
    return false;
}

void trim(string& s) {
    int n = s.length();
    for(int i = n-1; i >= 0; i --) {
        if(s[i] != ' ') {
            s.resize(i+1);
            break;
        }
    }
    for(int i = 0; i < n; i ++) {
        if(s[i] != ' ') {
            s.erase(0,i);
            break;
        }
    }
}


//no worry about exp - handled before
bool isfraction(string s) {
    int n = s.length(), pos = -1;
    if(!n) return 0;
    if(issign(s[0])) {
        s.erase(0,1);
        n = s.length();
    }
    for(int i = 0; i < n; i ++ ){
        if(!valid(s[i])){
            return false;
        }
        if(s[i] == '.') {
            if(pos<0) pos = i;
            else return false; //more than one dot
        }
    }

    string lhs = s.substr(0, pos);
    string rhs = s.substr(pos+1, n-pos-1);
    if(!lhs.length() && !rhs.length()) return false;
    if(isunsignedint(lhs) && isunsignedint(rhs)) return true;
    return false;
}

bool isNumber(string s) {
    int n = s.length();
    if(!n) return true;
//    s.insert(s.begin()+1, ' ');
//    s.insert(s.begin(), ' ');
//    s.insert(s.end(), ' ');
//    cout<<s<<endl;
    trim(s);
    n = s.length();
//    cout<<s<<endl;
    int exp = exppos(s); 
    if(exp == -2) {
        return false;
    }
    else if(exp == -1) {
        if(!isfraction(s) && !isint(s)) return false;
    }
    else {
        string lhs = s.substr(0, exp);
        string rhs = s.substr(exp+1, n-exp-1);
        if(!lhs.length() || !rhs.length()) return false;

        //lhs must be fraction or int (not exp)
        if(!isint(lhs) && !isfraction(lhs)) return false;
        //rhs of exp must be integer (not fraction or exp)
        if(!isint(rhs)) return false;

    }
    return true;
}


int main() {
	srand(time(NULL));

    string s;
    while(cin>>s) {
        cout<<s<<endl;
        cout<<isNumber(s)<<endl<<endl;
    }




    return 0;
}
