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



int search(vector<int>& nums, int target) {
    if(nums.empty()) return -1;
    int n = nums.size();
    int l = 0, r = n;
    int a = nums[0], b = nums[n-1], m;
    while(l < r) {
        m = (l+r)/2;
        if(m != n-1 && nums[m] > nums[m+1])
            break;
        else if(nums[m] <= b)           //left range.
            r = m;
        else if(nums[m] >= a)           //right range.
            l = m+1;
    }
    if(l<r) {           //found a pivot.
        if(target >= a)
            l = 0, r = m+1;
        else if(target <= b)
            l = m+1, r = n;
        else
            return -1;
    }
    else {          //not rotated.
        l = 0, r = n;
    }

    while(l < r) {
        m = (l+r)/2;
        if(target == nums[m])
            break;
        else if(target < nums[m])
            r = m;
        else if(target > nums[m])
            l = m+1;
    }
    if(l<r) return m;
    else return -1;
}



int main() {
	srand(time(NULL));

    vector<int> v;
    genVector(v, 2);
    printVector(v);
    cout<<search(v, 15)<<endl;



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
    for(int i = 0; i < n; i ++) v.push_back((i+14)%20);
//    sort(v.begin(), v.end());
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
