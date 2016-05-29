// 44.46% med
// tree preorder traversal

#include"mytest.h"


bool ok(char c) {
    return c=='#'||(c>='0' && c<='9');
}

bool solve(string& s, int& pos) {
    if(pos >= s.length()) return false;
    if(s[pos] == '#') return true;
    else {
        while(ok(s[pos])) pos++;
        pos ++;
        if(!solve(s, pos)) return false;
        while(ok(s[pos])) pos++;
        pos ++;
        if(!solve(s, pos)) return false;
    }
    return true;
}


bool isValidSerialization(string s) {
    int pos = 0;
    if(!solve(s, pos) || pos != s.length()-1) return false;
    return true;
}

int main() {
	srand(time(NULL));

    string s;
    while(cin>>s) {
        cout<<s<<endl;
        cout<<isValidSerialization(s)<<endl;
    }




    return 0;
}
