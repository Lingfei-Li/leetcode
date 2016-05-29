#include"mytest.cpp"


using namespace std;

int mySqrt(int x) {
    int ans = 0;
    if(x <= 1) return x;
    int l = 0, r = x;
    while(l<r) {
        int m = (l+r)/2;
//        printf("%d %d %d - %d\n", l, m, r, (m*m)/m);
        int overflow_check = (int)(m*m)/m;
        if(m*m == x) return m;
        else if(overflow_check != m || m*m > x) {
            r = m;
        }
        else{
            l = m+1;
        }
    }
    int m = (l+r)/2;
//    printf("%d %d %d\n", l, m, r);

    return l-1;
}


int main() {
	srand(time(NULL));

    int n;
    while(cin>>n) {
        cout<<mySqrt(n)<<endl<<sqrt(n)<<endl<<endl;
    }
    return 0;
}
