// 16ms
// string
// corner case: upper case

#include"mytest.h"

int isvowel(char c) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for(int i = 0; i < 10; i ++) {
        if(c == vowels[i]) return 1;
    }
    return 0;
}

string reverseVowels(string s) {
    int n = s.length();
    if(n<=1) return s;
    int p1 = 0, p2 = n-1;
    while(p1<p2) {
        while(!isvowel(s[p1])) p1 ++;
        while(!isvowel(s[p2])) p2 --;
        while(p1 < p2 && isvowel(s[p1]) && isvowel(s[p2]))swap(s[p1++], s[p2--]);
    }
    return s;
}



int main() {
	srand(time(NULL));

    string s;
    while(cin>>s) cout<<reverseVowels(s)<<endl;




    return 0;
}
