#include"mytest.cpp"


using namespace std;

int hammingWeight(uint32_t n) {
    uint32_t p = 1;
    int ans = 0;
    while(p) {
        if(p&n) ans ++;
        p<<=1;
    }
    return ans;
}

int main() {
	srand(time(NULL));

    uint32_t t;
    while(cin>>t) {
        cout<<hammingWeight(t)<<endl;
    }






    return 0;
}
