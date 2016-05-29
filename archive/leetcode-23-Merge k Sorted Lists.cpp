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


//Global Variables.

////

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printArray(int* A, int n);
void printListkedList(ListNode *u);
void genArray(int* A, int n);
ListNode* genLinkedList(int n);

void mergeSort(vector<ListNode*>& lists, int l, int r) {       //l,r included
    int n = r-l+1;
    if(lists.size() == 0 || n <= 0) return;
    else if(n == 1) return;

    if(n != 2) {        //divide
        mergeSort(lists, l, l+n/2-1);
        mergeSort(lists, l+n/2, r);
    }

    //there should only be two linked lists within range l and r, one at pos l and the other is at pos l+n/2+1
    ListNode *p1 = lists[l], *p2 = lists[l+n/2];
    ListNode *h = 0, *v = 0;
    while(p1||p2) {
        if(!p1 || (p2 && p1->val > p2->val)) {
            if(!h) {
                h = p2;
                v = h;
            }
            else {
                v->next = p2;
                v = v->next;
            }
//            v = v->next;              //WRONG PLACE. INFINITE LOOP BUG BECAUSE OF THIS MISTAKE.
            p2 = p2->next;
        }
        else {
            if(!h) {
                h = p1;
                v = h;
            }
            else {
                v->next = p1;
                v = v->next;
            }
            p1 = p1->next;
        }
    }
    lists[l] = h;
}

ListNode* mergeTwoList(ListNode* p1, ListNode *p2) {
//    return 0;
    ListNode *h = 0, *v = 0;
    while(p1||p2) {
        printf("%d %d\n", p1, p2);
        if(!p1 || (p2 && p1->val > p2->val)) {
            if(!h) {
                h = p2;
                v = h;
            }
            else {
                v->next = p2;
                v = v->next;
            }
            p2 = p2->next;
        }
        else {
            if(!h) {
                h = p1;
                v = h;
            }
            else {
                v->next = p1;
                v = v->next;
            }
            p1 = p1->next;
        }
    }
    return h;
}
ListNode* mergeSort_iterative(vector<ListNode*>& lists) {
    int n = lists.size();

    while(1) {
        int i = 0, j = 1, flag = 0;
        while(1) {
            while(!lists[i] && i < n) i++;
            if(i > n-2) break;
            while(j = i+1 && !lists[j] && j < n) j ++;
            if(j > n-1) break;
            printListkedList(lists[i]);
            printListkedList(lists[j]);
            ListNode* v = mergeTwoList(lists[i], lists[j]);
            printListkedList(v);
            printf("i:%d\n", i);
            lists[j] = 0;
            i = j+1;
            flag = 1;
        }
        if(flag == 0) return lists[0];
    }
}



ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) return 0;
//    mergeSort(lists, 0, lists.size()-1);
    return mergeSort_iterative(lists);
}




int main() {

//    #define DEBUG 1
//    #ifdef DEBUG
//    freopen("leetcode-23.out","w",stdout);
//    #endif
	srand(time(NULL));

    int n = 2;
    vector<ListNode*> v;
    ListNode *h = genLinkedList(10);
//    ListNode *h = 0;
    v.push_back(h);
    for(int i = 0; i < n; i ++) {
        h = genLinkedList(10);
//        h = 0;
        v.push_back(h);
    }


//    printListkedList(v[0]);
//    printListkedList(v[1]);
////    h = mergeKLists(v);
//    h = mergeTwoList(v[0], v[1]);
//    printListkedList(h);
    h = mergeSort_iterative(v);

//    h = mergeTwoList(v[0], v[1]);
//    printListkedList(v[0]);
//    printListkedList(v[1]);
//    printListkedList(h);
//    printListkedList(mergeKLists(v));


    return 0;
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
