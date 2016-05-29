//13.18%
//greatest common divisor
//corner cases...

#include"mytest.h"


using namespace std;


struct Point {
    int x;
    int y;
    Point(): x(0),y(0) {}
    Point(int a, int b): x(a), y(b) {}
};

int gcd(int a, int b) {
    if(a == b) return a;
    if(a > b) swap(a,b);
    return gcd(a, b-a); //assumption: a < b
}

int maxPoints(vector<Point>& points) {

    int n = points.size();
    if(!n) return 0;
    int ans = 0;
    for(int i = 0; i < n; i ++) {   //n points
//        printf("i: %d\n", i);
        int ptans = 0;
        Point& p1 = points[i];
        map<pair<int,int>,int> cnt;
        int samepos = 0;
        for(int j = 0; j < n; j ++) {   //n-1 pairs
            if(i!=j){
//                printf("j: %d\n", j);
                Point& p2 = points[j];
                int diffx = (p2.x-p1.x), diffy = (p2.y-p1.y);
                if(diffx && diffy) {
                    int g = gcd(abs(diffx), abs(diffy));
                    diffx /= g;
                    diffy /= g;
                }
                else if(diffx) {
                    diffx = 1;
                }
                else if(diffy){
                    diffy = 1;
                }
                else {
                    samepos ++;
                    continue;
                }
                if(diffx < 0 && diffy < 0) {
                    diffx = -diffx;
                    diffy = -diffy;
                }
                else if(diffx < 0 && diffy > 0) {
                    diffy = -diffy;
                }
                pair<int,int> p = pair<int,int>(diffx, diffy);
                cnt[p] ++;
                ptans = max(ptans, cnt[p]);
            }
        }
        ans = max(ans, ptans + samepos);
    }
    return ans+1;
                
}



int main() {
	srand(time(NULL));


    int n = 50;
    vector<Point> p;
    printf("[");
    for(int i = 0; i < n; i ++) {
        int a = rand()%10, b = rand()%10;
        if(i) printf(",");
        printf("[%d,%d]", a, b);
        Point pt = Point(a, b);
        p.push_back(pt);
    }
    printf("]\n");

    cout<<maxPoints(p)<<endl;




    return 0;
}
