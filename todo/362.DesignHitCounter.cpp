#include"mytest.h"

class HitCounter {
public:


    long long sum;

    int curtime;

    deque<pair<int,int> > q;

    HitCounter() {
        sum = 0;
        curtime = 0;
    }

    void hit(int timestamp) {
        if(timestamp == curtime){
            q.back().second ++;
        }
        else {
            while(!q.empty() && q.front().first <= timestamp-300){
                sum -= q.front().second;
                q.pop_front();
            }
            curtime = timestamp;
            q.push_back(pair<int,int>(timestamp, 1));
        }
        sum ++;
    }
    
    int getHits(int timestamp) {
        while(!q.empty() && q.front().first <= timestamp-300){
            sum -= q.front().second;
            q.pop_front();
        }
        return sum;
    }
};

int main() {
	srand(time(NULL));




    return 0;
}
