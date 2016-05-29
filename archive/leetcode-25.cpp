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


bool shorterThanK(ListNode* u, int k) {
    for(int i = 0; i < k; i ++) {
        if(!u) return true;     //if # of remaining nodes is less than k.
        u = u->next;
    }
    return false;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || !head->next || k <= 1 || shorterThanK(head, k)) return head;

    ListNode *p, *h, *u, *v;
    h = u = head;
    v = u->next;
    for(int i = 0; i < k-1; i ++) {
        head = v;
        u->next = v->next;
        v->next = h;
        h = v;
        v = u->next;
    }
    p = u;
    u = u->next;

    while(1) {
        if(shorterThanK(u, k)) return head;
        h = u;
        v = u->next;
        for(int i = 0; i < k-1; i ++) {
            p->next = v;
            u->next = v->next;
            v->next = h;
            h = v;
            v = u->next;
        }
        p = u;
        u = u->next;
    }

    return head;
}

int main() {
	srand(time(NULL));

    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* h = head;
    int n = 1;
    for(int i = 0; i < n; i ++) {
        h->val = i;
        if(i!=n-1)h->next = (ListNode*)malloc(sizeof(ListNode));
        else h->next = 0;
        h = h->next;
    }

    h = head;
    while(h) {
        printf("%d -> ", h->val);
        h = h->next;
    }
    printf("\n");

    int k = 1;
    h = reverseKGroup(head, k);
    while(h) {
        printf("%d -> ", h->val);
        h = h->next;
    }
    printf("\n");



    return 0;
}
