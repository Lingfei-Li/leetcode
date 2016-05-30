//57.8% 2nd group
//math...................

#include"mytest.h"



//overflow!
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
                
    long long ans = (D-B)*(C-A) + (G-E)*(H-F);  //total
    int a = max(A, E), b = max(B,F);
    int c = min(C, G), d = min(D, H);
    if(a >= c || b >= d) return (int)ans;
    ans -= (c-a)*(d-b);
    return (int) ans;
}


int main() {
	srand(time(NULL));




    return 0;
}
