// Feature:
// Greedy
// Scanning

#include"mytest.h"


using namespace std;


void inc(int& a, int n) {
    a = (a+1)%n;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    int n = gas.size();
    if(!n) return -1;
    if(n == 1) {
        if(gas[0] >= cost[0]) return 0;
        return -1;
    }

    vector<int> diff;
    diff.resize(n);
    int sum = 0;
    for(int i = 0; i < n; i ++) {
        diff[i] = gas[i]-cost[i];
        sum += diff[i];
    }
    if(sum<0) return -1;      //impossible

    int i = 0, j;
    while(1) {
        j = (i+1)%n;
        if(diff[i] >= 0) {
            while(diff[i] + diff[j] >= 0) {
                if(i == j) return i;
                diff[i] = diff[i]+diff[j];
                diff[j] = 0;
                inc(j,n);
            }
            i = j;
        }
        else {
            inc(i,n);
        }
    }

    return -1;
}


int main() {
	srand(time(NULL));

    int t;
    cin>>t;
    while(t--) {
        vector<int> gas, cost;
        readVectorInt(gas);
        readVectorInt(cost);
        cout<<canCompleteCircuit(gas, cost)<<endl;
    }




    return 0;
}
