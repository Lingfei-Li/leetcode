// Feature:
// Palindrom
// Helper function

#include"mytest.h"


using namespace std;

char transform(char ch) {
    if(ch >= 'A' && ch <= 'Z') return ch-'A'+'a';
    if(!(ch >= 'a' && ch <= 'z') && !(ch >= '0' && ch <= '9')) return 0;
}

bool isPalindrome(string s) {
    int n = s.length();
    int p1 = 0, p2 = n-1;
    while(p1<p2) {
        char c1 = transform(s[p1]), c2 = transform(s[p2]);
        if(!c1) {
            p1++;
            continue;
        }
        if(!c2) {
            p2--;
            continue;
        }
        if(c1!=c2) return false;
        p1++;
        p2--;
    }
    return true; 
}


int main() {
	srand(time(NULL));


    string s = "A man, a plan, a canal: Panama";
    s = "A man, a plan, a canal: Panama";
    s = "a         a";
    cout<<isPalindrome(s)<<endl;


    return 0;
}
