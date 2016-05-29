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
void printArray(int* A, int n);
void genArray(int* A, int n);
ListNode* genLinkedList();


int removeElement(int A[], int n, int elem) {
    int p1, p2;
    for(p1 = 0, p2 = 0; p2 < n; p2 ++) {
        if(A[p2] == elem) continue;
        A[p1++] = A[p2];
    }
    return p1;
}

int main() {
	srand(time(NULL));

    int n = 10;
    int A[n];
    genArray(A, n);
    printArray(A, n);
    int elem = 1;
    int p1 = removeElement(A, n, elem);
    cout<<p1<<endl;
    printArray(A, p1);


    return 0;
}

void printArray(int* A, int n) {
	for(int i = 0; i < n; i ++) printf("%d ", A[i]);
    printf("\n");
}

void genArray(int* A, int n) {
    for(int i = 0; i < n; i ++) A[i] = rand()%20-10;
    sort(A, A+n);
}

ListNode* genLinkedList() {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* h = head;
    int n = 1;
    for(int i = 0; i < n; i ++) {
        h->val = i;
        if(i!=n-1)h->next = (ListNode*)malloc(sizeof(ListNode));
        else h->next = 0;
        h = h->next;
    }
    return head;
}
