#include"mytest.h"


using namespace std;

void printBin(int a) {
    while(a) {
        cout<<(a%2);
        a/=2;
    }
    cout<<endl;
}

vector<int> grayCode(int n) {
    vector<int> ans;


    vector<int> vis;
    vis.resize(pow(2, n) + 5); 
//    cout<<pow(2,n)+5<<endl;

    int a = 0;
    ans.push_back(a);
    vis[a] = 1;
    
    if(!n) return ans;

    printBin(a);
    int p = 0;
    for(;;) {
        int tmp = a^(1<<p);
        for(p = 0; p <= n, vis[tmp] == 1; p ++) {
            tmp = a^(1<<p);
        }
        if(p > n) break;   //end of sequence
        ans.push_back(tmp);
        printBin(tmp);
        vis[tmp] = 1;
        a = tmp;
        p = 0;
    }



    return ans;
}

int main() {
	srand(time(NULL));

    int a;
    while(cin>>a){
//        printBin(a);
        vector<int> v = grayCode(a);
        printVector(v);
    }



    return 0;
}
