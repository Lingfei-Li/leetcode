#include"mytest.h"

string reverseString(string s) {
    int l = 0, r = s.length()-1;
    while(l<r){
        swap(s[l++], s[r--]);
    }
    return s;
}



int main() {
	srand(time(NULL));

    string s;
    while(cin>>s) cout<<reverseString(s)<<endl;




    return 0;
}
