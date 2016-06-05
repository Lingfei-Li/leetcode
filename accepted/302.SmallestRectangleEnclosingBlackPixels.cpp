// slow
// graph dfs

#include"mytest.h"

class Solution {
public:

    int minx, miny, maxx, maxy;
    vector<vector<int> > vis;

    bool isvalid(int x, int y) {
        if(x < 0 || y < 0 || x >= vis.size() || y >= vis[0].size()) return false;
        return true;
    }

    void dfs(int x, int y, vector<vector<char> >& img){
        minx = min(x, minx);
        miny = min(y, miny);
        maxx = max(x, maxx);
        maxy = max(y, maxy);

        int step[4][2] = {{-1,0}, {0,-1}, {1, 0}, {0,1}};

        for(int i = 0; i < 4; i ++) {
            int x2 = x+step[i][0];
            int y2 = y+step[i][1];
            if(isvalid(x2, y2) && img[x2][y2] == '1' && vis[x2][y2] == 0){
                vis[x2][y2] = 1;
                dfs(x2, y2, img);
            }
        }
    }

    int minArea(vector<vector<char> >& image, int x, int y) {
        int n = image.size();
        if(!n) return 0;
        int m = image[0].size();
        if(!m) return 0;

        vis.resize(n);
        for(int i = 0; i < n; i ++) vis[i].resize(m);

        minx = miny = max(m,n);
        maxx = maxy = 0;

        dfs(x, y, image);

        return (1+maxy-miny)*(1+maxx-minx);

    }
};


int main() {
	srand(time(NULL));

    Solution sol;



    return 0;
}
