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

void dfs(vector<vector<int> >& ans, vector<int>& u, vector<int>& candidates, int p, int target) {
    if(target == 0) {
        ans.push_back(u);
        return;
    }
    for(int i = p; i < candidates.size(); i ++) {
        if(candidates[i] > target) return;
        if(i > p && candidates[i] == candidates[i-1]) continue;
        vector<int> v(u);
        v.push_back(candidates[i]);
        dfs(ans, v, candidates, i+1, target-candidates[i]);
    }
}


vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > ans;
    vector<int> tmp;
    dfs(ans, tmp, candidates, 0, target);
    return ans;
}



int main() {
	srand(time(NULL));

    vector<int> tmp;
//    genVector(tmp, 10);
//    printVector(tmp);
    tmp.push_back(1);
    tmp.push_back(1);
    vector<vector<int> > ans = combinationSum2(tmp, 2);

    for(int i = 0; i < ans.size(); i ++) {
        for(int j = 0; j < ans[i].size(); j ++) {
            cout<<ans[i][j]<<" ";
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
    for(int i = 0; i < n; i ++) v.push_back(rand()%20+1);
    sort(v.begin(), v.end());
}
void genArray(int* A, int n) {
    for(int i = 0; i < n; i ++) A[i] = rand()%20+1;
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
