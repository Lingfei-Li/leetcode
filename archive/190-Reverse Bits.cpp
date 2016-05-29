#include"mytest.cpp"


using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t p = 1, ans = 0, cnt = 0, sigpos = 0;
    p = 1<<31;
    while(p) {
        if(p&n) {
            ans += 1<<cnt;
        }
        cnt ++;
        p = p>>1;
    }

    return ans;
}

int main() {
	srand(time(NULL));

    uint32_t t;
    while(cin>>t) {
        cout<<reverseBits(t)<<endl;
    }






    return 0;
}
