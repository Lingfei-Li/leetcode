#include"mytest.h"


using namespace std;

bool isScramble(string s1, string s2) {
                
    int n = s1.length();
    if(!n) return true;
    
    const int maxl = 45;

    bool isScramble[maxl][maxl][maxl][maxl];
    memset(isScramble, 0, sizeof(isScramble));


    for(int i = 0; i < n; i ++) { //length of comparing partition -1
//        for(int j = 0; j < n; j ++) {
            for(int k = 0; k + i < n; k ++)  {
                for(int p = 0; p + i < n; p ++) {
                    //isScramble: s1[k,k+i], s2[p,p+j]
                    
                    bool& u = isScramble[k][k+i][p][p+i]; 

//                    printf("%d-%d %d-%d\n", k, k+i, p, p+i);
//
                    if(i == 0) {
                        u = (s1[k] == s2[p]);                        
                    }
                    else {
                        u = 0;
                        //isScramble: s1[k,k+m], s2[p,p+m]; s1[k+m+1,k+i],s2[p+m+1,p+i];
                        for(int m = 0; m <= i; m ++) {
//                            int m = (i+1)/2;
//                            printf("m: %d\n", m);

//                            printf("cmp: %d-%d, %d-%d\n", k, k+m-1, p, p+m-1);
//                            printf("    %d-%d, %d-%d\n", k+m, k+i, p+m, p+i);
                            u |= isScramble[k][k+m-1][p][p+m-1] 
                            && isScramble[k+m][k+i][p+m][p+i];

//                            printf("u: %d\n", u);
    
//                            printf("cmp: %d-%d, %d-%d\n", k, k+m-1, p+i-m+1, p+i);
//                            printf("     %d-%d, %d-%d\n", k+m, k+i, p, p+i-m);
                            u |= isScramble[k][k+m-1][p+i-m+1][p+i] 
                            && isScramble[k+m][k+i][p][p+i-m];
//                            printf("u: %d\n", u);
                        }
                    }
                }
            }
    }

    return isScramble[0][n-1][0][n-1];

}


int main() {
	srand(time(NULL));

    string s1, s2;
    while(cin>>s1>>s2){
        cout<<s1<<endl<<s2<<endl;
        cout<<isScramble(s1,s2)<<endl;
    }


    return 0;
}
