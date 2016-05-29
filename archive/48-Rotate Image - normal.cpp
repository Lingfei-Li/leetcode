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





void rotate(vector<vector<int> >& matrix) {
    if(matrix.size() == 0) return;

    int n = matrix.size();
    vector<vector<int> > m2;
    m2.resize(n);
    for(int i = 0; i < n; i ++) {
        m2[i].resize(n);
    }
    cout<<endl<<endl;
    for(int i = 0; i < n; i ++) {     //iterating from 0 to middle row
        for(int j = 0; j < n; j ++) { //iterating from 0 to middle column
            m2[i][j] = matrix[n-j-1][i];
        }
    }
    matrix = m2;
}



int main() {
	srand(time(NULL));

    const int n = 5;
    vector<vector<int> > m;
    m.resize(n);
    for(int i = 0; i < n; i ++) m[i].resize(n);

    for(int i = 0; i < n; i ++)
    for(int j = 0; j < n; j ++) {
        m[i][j] = i+j;
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++) {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }

    rotate(m);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++) {
            cout<<m[i][j]<<"\t";
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
