#include<cstdio>
#include<cstring>
#include<algorithm>

#include<vector>

#include<queue>
#include<string>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<set>
#include<map>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

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


static const int maxn = 1000;
void solve(int vis[4][maxn], int row, int n, vector<string>& board, vector<vector<string> >& ans) {
    if(row == n) {
        ans.push_back(board);
        return;
    }
    for(int i = 0; i < n; i ++) {
        if(!vis[0][i] && !vis[1][i+row] && !vis[2][i-row+n]) {
            vis[0][i] = vis[1][i+row] = vis[2][i-row+n] = 1;
            board[row][i] = 'Q';
            solve(vis, row+1, n, board, ans);
            vis[0][i] = vis[1][i+row] = vis[2][i-row+n] = 0;
            board[row][i] = '.';
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > ans;
    vector<string> board;
    board.resize(n);
    for(int i = 0; i < n; i ++) board[i].resize(n);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            board[i][j] = '.';
        }
    }
    int vis[4][maxn];
    memset(vis, 0, sizeof(vis));
    solve(vis, 0, n, board, ans);
    return ans;
}




int main() {
	srand(time(NULL));

    vector<vector<string> > ans;
    ans = solveNQueens(4);
    for(int i = 0; i < ans.size(); i ++) {
        for(int j = 0; j < ans[i].size(); j ++) {
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }



    return 0;
}
void printVector(vector<int>& v) {
    for(int i = 0; i < v.size(); i ++) printf("%d ", v[i]);
    printf("\n");
}
void printArray(int* A, int n) {
	for(int i = 0; i < n; i ++) printf("%d ", A[i]);
    printf("\n");
}
void printListkedList(ListNode *u) {
    while(u) {
        printf("%d -> ", u->val);
        u = u->next;
    }
	printf("\n");
}
void genVector(vector<int>& v, int n) {
    for(int i = 0; i < n; i ++) v.push_back(rand()%20-10);
    sort(v.begin(), v.end());
}
void genArray(int* A, int n) {
    for(int i = 0; i < n; i ++) A[i] = rand()%20-10;
    sort(A, A+n);
}

ListNode* genLinkedList(int n) {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* h = head;
    for(int i = 0; i < n; i ++) {
        h->val = i;
        if(i!=n-1)h->next = (ListNode*)malloc(sizeof(ListNode));
        else h->next = 0;
        h = h->next;
    }
    return head;
}
