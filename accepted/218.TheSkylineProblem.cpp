// 13.81% 1ac
// scanning
// critical point
// using map as priority queue

#include"mytest.h"


vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {

    map<int, vector<int> > cpts;
    map<int, int> heights;

    for(int i = 0; i < buildings.size(); i ++) {
        //start and end of a building
        cpts[buildings[i][0]].push_back(buildings[i][2]);
        cpts[buildings[i][1]].push_back(-buildings[i][2]);
    }

    vector<pair<int,int> > ans;

    int prev = -1, cur = -1, end = -1;
    for(map<int, vector<int> >::iterator it = cpts.begin(); it != cpts.end(); it ++) {

        vector<int>& hts = it->second;
        for(int i = 0; i < hts.size(); i ++) {
            int ht = abs(hts[i]);
            if(hts[i] > 0) {    //new building
                heights[ht] ++;
            }
            else {                  //end of a building
                if((--heights[ht]) == 0) {
                    heights.erase(ht);
                }
            }
        }

        // test and add turning point into ans
        if(heights.size()) {
            cur = heights.rbegin()->first;
        }
        else {
            cur = 0;
        }

        // add to ans. avoiding duplicates
        if(cur != prev) ans.push_back(pair<int,int>(it->first, cur));

        prev = cur;
     
//        end = it->first;
    
    }
//    ans.push_back(pair<int,int>(end, 0));


    return ans;
                
}



int main() {
	srand(time(NULL));


    int a, b, c;
    vector<vector<int> > buildings;
    while(cin>>a>>b>>c) {
        printf("%d %d %d\n", a, b, c);
        vector<int> tmp;
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        buildings.push_back(tmp);
    }

    vector<pair<int,int> > ans = getSkyline(buildings);

    cout<<endl;
    for(int i = 0; i < ans.size(); i ++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }




    return 0;
}
