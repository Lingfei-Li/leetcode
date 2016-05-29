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
void printArray(vector<int>& v);
void printArray(int* A, int n);
void printListkedList(ListNode *u);
void genArray(int* A, int n);
ListNode* genLinkedList(int n);





void nextPermutation(vector<int>& nums) {
    int n = nums.size(), p;
    if(n <= 1) return;
    for(int i = n-2; i >= 0; i --) {
        for(int j = n-1; j > i; j --) {
            if(nums[j] > nums[i]) {
                swap(nums[j], nums[i]);
                p = i;
                goto NEXT;
            }
        }
    }
    sort(nums.begin(), nums.end());
    return;
    NEXT:
        sort(&nums[p+1], &nums[n]);
}



int main() {
	srand(time(NULL));

    vector<int> v;
    for(int i = 0; i < 20; i ++) {
        v.push_back(rand()%100);
    }
    vector<int> v2(v);
    printArray(v);
    nextPermutation(v);
    printArray(v);
    next_permutation(v2.begin(), v2.end());
    printArray(v2);




    return 0;
}

void printArray(int* A, int n) {
	for(int i = 0; i < n; i ++) printf("%d ", A[i]);
    printf("\n");
}
void printArray(vector<int>& v) {
	for(int i = 0; i < v.size(); i ++) printf("%d ", v[i]);
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
