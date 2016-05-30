// 0ms
// corner cases

#include"mytest.h"

bool isAdditiveNumber(string num) {

    int n = num.length();
    if(n<3) return 0;
    //i: end of 1st num
    for(int i = 0; i < n-1; i ++) {
        if(num[0] == '0' && i != 0) continue;
        //i+1: start of 2nd num
        //j: end of 2nd num
        for(int j = i+1; j < n-1; j ++) {
            if(num[i+1] == '0' && j != i+1) continue;
            long long a = atoi(num.substr(0, i+1).c_str());
            long long b = atoi(num.substr(i+1, j-i).c_str());
            int p = j+1;
            long long c;
            string s;
            while(p <= n) {
                if(p == n) return true;
//                if(num[p] == '0') goto mismatch;  //unnecessary
                c = a+b;
                s = to_string(c);
                int len = s.length();
                if(p+len > n) goto mismatch;
                for(int k = 0; k < s.length(); k ++) {
                    if(s[k] != num[p+k]) goto mismatch;
                }
                a = b;
                b = c;
                p += len;
            }
mismatch:
            continue;
        }
    }
    return false;
            
}



int main() {
	srand(time(NULL));

    string a;
    while(cin>>a) cout<<isAdditiveNumber(a)<<endl;




    return 0;
}
