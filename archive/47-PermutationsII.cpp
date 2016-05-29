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



vector<vector<int> > gen_permute(vector<int> &nums, vector<int> &vis) {
    vector<vector<int> > ans;
    int n = nums.size();
    vector<vector<int> > tmp;
    map<int,int> dic;
    for(int i = 0; i < n; i ++) {
        if(!vis[i] && !dic[nums[i]]) {
//        if(!vis[i]) {
            vis[i] = 1;
            dic[nums[i]] = 1;
            tmp = gen_permute(nums, vis);
            for(int j = 0; j < tmp.size(); j ++) {
                tmp[j].push_back(nums[i]);
                ans.push_back(tmp[j]);
            }
            if(tmp.size() == 0) {
                vector<int> a;
                a.push_back(nums[i]);
                ans.push_back(a);
            }
            vis[i] = 0;
        }
    }
    return ans;
}

vector<vector<int> > permuteUnique(vector<int>& nums) {
    int n = nums.size();
    vector<int> vis;
    vis.resize(n);

    vector<vector<int> > ans = gen_permute(nums, vis);

    return gen_permute(nums, vis);
}





int main() {
	srand(time(NULL));

    vector<int> nums;
    genVector(nums, 4);
    printVector(nums);
    vector<vector<int> > ans = permute(nums);
    cout<<ans.size()<<endl;

    for(int i = 0; i < ans.size(); i ++) {
        for(int j = 0; j < ans[i].size(); j ++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
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
    for(int i = 0; i < n; i ++) v.push_back(rand()%5);
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
