// Note: slow implementation (6.75%)
// Feature:
// greedy
// operator overload

#include"mytest.h"


using namespace std;


struct Rat{
    int rat, idx;
    Rat(){}
    bool operator < (const Rat& rhs)  const{
        return rat < rhs.rat;
    }
};

int candy(vector<int>& ratings) {
    vector<Rat> rat;
    int n = ratings.size();
    if(!n) return 0;
    rat.resize(n);

    for(int i = 0; i < n; i ++) {
        rat[i].rat = ratings[i];
        rat[i].idx = i;
    }
    sort(rat.begin(), rat.end());

//    for(int i = 0; i < n; i ++) {
//        printf("%d %d\n", rat[i].rat, rat[i].idx);
//    }


    vector<int> candy;
    candy.resize(n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int idx = rat[i].idx;
        candy[idx] = 1;
        if(idx == 0) {
            if(ratings[idx] > ratings[idx+1]) {
                candy[idx] = candy[idx+1]+1;
            }
        }
        else if(idx == n-1) {
            if(ratings[idx] > ratings[idx-1]) {
                candy[idx] = candy[idx-1]+1;
            }
        }
        else {
            if(ratings[idx] > ratings[idx-1]) {
                candy[idx] = candy[idx-1]+1;
            }
            if(ratings[idx] > ratings[idx+1]) {
                candy[idx] = max(candy[idx], candy[idx+1]+1);
            }
        }
        ans += candy[idx];
    }


//    printVector(candy);


    return ans;
}



int main() {
	srand(time(NULL));

    vector<int> ratings;
    while(readVectorInt(ratings)){
    //    genVector(ratings, 5);

        printVector(ratings);
        cout<<candy(ratings)<<endl;
        ratings.clear();

    }




    return 0;
}
