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


void solveSudoku(vector<vector<char> >& board) {
    int vis[9][9][3];
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 3; j ++) {
            if(board[i][j] != '.') {
                int u = board[i][j]-'0';
                int r = i/3, c = j/3;
                int k = r*3+c;
                vis[i][u][0] = vis[j][u][1] = vis[k][u][2] = 1;
            }
        }
    }









}

void genBoard(vector<vector<char> >& board) {
    int vis[9][9][3];
    memset(vis, 0, sizeof(vis));
    
     
    board.resize(9);
    for(int i = 0; i < 9; i ++) board[i].resize(9);
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            board[i][j] = '.';
        }
    }
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
           if(rand()%2) {
                int u = rand()%9;
                int r = i/3, c = j/3;
                int k = r*3+c;
                if(!vis[i][u][0] && !vis[j][u][1] && !vis[k][u][2]) {       //row ok, column ok, block ok.
                    board[i][j] = u + '1';
                    vis[i][u][0] = vis[j][u][1] = vis[k][u][2] = 1;
                }
            }
        }
    }

}


void printBoard(vector<vector<char> >& board) {
    for(int i = 0; i < 9; i ++) {
        if(!(i%3)) printf("\n");
        for(int j = 0;j < 9; j ++) {
            if(!(j%3)) printf("|");
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}



int main() {
    srand(time(NULL));
    vector<vector<char> > board;
   
    genBoard(board);
    printBoard(board);
   
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
