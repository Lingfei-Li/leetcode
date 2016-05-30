// 26.13% 2nd level
// trick

#include"mytest.h"

string getHint(string secret, string guess) {
    unordered_map<char,int> m;
    int a = 0, b = 0;
    for(int i = 0; i < secret.size(); i ++) {
        if(secret[i] == guess[i]){
            a ++;
        }
        m[secret[i]] ++;
    }
    for(int i = 0; i < secret.size(); i ++) {
        if(m[guess[i]] > 0) {
            b++;
            m[guess[i]] --;
        }
    }
    return to_string(a)+"A"+to_string(b-a)+"B";
}



int main() {
	srand(time(NULL));

    string a, b;
    while(cin>>a>>b)
        cout<<getHint(a,b);
    



    return 0;
}
