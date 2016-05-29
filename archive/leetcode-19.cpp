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


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL) return head;
    int len = 0;
    int cnt = 0;
    ListNode* hs[10000];
    ListNode* u = head;
    while(u!=NULL) {
        hs[cnt++] = u;
        u = u->next;
        len ++;
    }

    int m = len-n;
    if(m == 0) {
        delete(head);
        if(len > 1) return head = hs[1];
        else return NULL;

    }
    else {
        hs[m-1]->next = hs[m]->next;
        delete(hs[m]);
        return head;
    }

//    cnt = len-n;
//    if(cnt == 0) {
//        ListNode* tmp = head->next;
//        if(tmp == NULL) head = NULL;
//        else head = tmp;
//        return head;
//    }
//    u = head;
//    while(u!=NULL) {
//        if(cnt == 1) {
//            ListNode* tmp = u->next;
//            if(tmp == NULL) u->next = NULL;
//            else u->next = tmp->next;
//            delete(tmp);
//        }
//        u = u->next;
//        cnt--;
//    }
    return head;
}


int main() {
	srand(time(NULL));
    int rng = 100;
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = rand()%rng;
    head->next = NULL;
    ListNode* h = head;


    for(int i = 0; i < 0; i ++) {
        ListNode* u = (ListNode*)malloc(sizeof(ListNode));
        u->val = rand()%rng;
        h->next = u;
        u->next = NULL;
        h = h->next;
    }

//    ListNode* hs[10000];
//    int cnt = 0;
//    ListNode* u = head;
//    while(u!=NULL) {
//        hs[cnt++] = u;
//        u = u->next;
//    }
//
//    for(int i = 0; i < cnt; i ++) {
//        printf("%d -> ", hs[i]->val);
//    }
//    printf("\n");


    h = head;
    while(h!=NULL) {
        printf("%d -> ", h->val);
        h = h->next;
    }
    puts("");
    h = head;
    h = removeNthFromEnd(h, 1);
    while(h!=NULL) {
        printf("%d -> ", h->val);
        h = h->next;
    }





    return 0;
}
