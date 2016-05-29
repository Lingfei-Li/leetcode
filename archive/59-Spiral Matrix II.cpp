#include"mytest.cpp"


using namespace std;
/*
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    void printVector(vector<int>& v);
    void printArray(int* A, int n);
    void printListkedList(ListNode *u);
    void genVector(vector<int>& v, int n);
    void genArray(int* A, int n);
    ListNode* genLinkedList(int n);
*/



static int isvalid(int r, int c, int n, vector<vector<int> >& board) {
    if(r < 0 || c < 0 || r >= n || c >= n) return 0;
    if(board[r][c] != 0) return 0;
    return 1;
}

static void walk(int& r, int& c, int dir) {
    int step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    r += step[dir][0];
    c += step[dir][1];
}

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > ans;
    if(n <= 0) return ans;
    ans.resize(n);
    for(int i = 0; i < n; i ++) ans[i].resize(n);
    int r = 0, c = 0, cnt = 1, dir = 0;
    while(1) {
        ans[r][c] = cnt++;
        int k = 0;
        for(k = 0; k < 4; k ++) {
            dir = (dir+k)%4;
            int r2 = r, c2 = c;
            walk(r2,c2,dir);
            if(isvalid(r2, c2, n, ans)) {
                r = r2, c = c2;
                break;
            }
        }
        if(k == 4) break;
    }
    return ans;
}


int main() {
	srand(time(NULL));

    int n;
    while(cin>>n) {
        vector<vector<int> > ans = generateMatrix(n);
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
