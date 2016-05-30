// 63.84% med
// segment tree/interval tree
// Be clear about what to do in each step. 
// Make a list of comments to remind if necessary

#include"mytest.h"

struct Node {
    int l, r, m;
    long long val;
    Node* lchild, *rchild;
    Node(){
        l = r = m = val = -1;
        lchild = rchild = 0;
    }
    Node(int l, int r):l(l),r(r){
        m = (l+r)/2;
        val = -1;
        lchild = rchild = 0;
    }
};


class NumArray {
private:
    vector<int> nums;
    Node* root;
public:
    Node* buildTree(vector<int>& v, int l, int r) {
        Node* root = new Node(l, r);
        if(l == r) {
            root->val = (long long)v[l];
        }
        else {
            root->lchild = buildTree(v, l, root->m);
            root->rchild = buildTree(v, root->m+1, r);
            root->val = root->lchild->val + root->rchild->val;
        }
        return root;
    }

    NumArray(vector<int> &v) {
        if(v.size() == 0) return;
        root = buildTree(v, 0, v.size()-1);
        nums = v;
    }

    void updateTree(Node* u, int pos, long long diff) {
        if(!u || pos < u->l || pos > u->r) return;
        u->val += diff;
        updateTree(u->lchild, pos, diff);
        updateTree(u->rchild, pos, diff);
    }

    void update(int i, int val) {
        if(i < 0 || i >= nums.size()) return;
        long long diff = (long long)val - (long long)nums[i];
        nums[i] = val;
        updateTree(root, i, diff);
    }

    int sumRange(Node* u, int l, int r) {
        if(l < 0 || r >= nums.size()) return 0;
        if(l == u->l && r == u->r) return (int)u->val;
        if(l > u->m) {
            return sumRange(u->rchild, l, r);
        }
        else if(r < u->m+1) {
            return sumRange(u->lchild, l, r);
        }
        else {
            int a = sumRange(u->lchild, l, u->m);
            int b = sumRange(u->rchild, u->m+1, r);
            return a+b;
        }
    }
    int sumRange(int i, int j) {
//        printf("%d - %d: %d\n", i, j, sumRange(root, i, j));
        return sumRange(root, i, j);
    }
};




int main() {
	srand(time(NULL));

    vector<int> v;
    readVector(v);
    printVector(v);

    NumArray n = NumArray(v);
    n.update(4,6);
    v[4] = 6;
    printVector(v);
    n.update(0,2);
    v[0] = 2;
    printVector(v);
    n.update(0,9);
    v[0] = 9;
    printVector(v);
    n.sumRange(4,4);
    n.update(3,8);
    v[3] = 8;
    printVector(v);
    n.sumRange(0,4);
    n.update(4,1);
    v[4] = 1;
    printVector(v);
    n.sumRange(0,3);
    n.sumRange(0,4);
    n.update(0,4);
    v[0] = 4;
    printVector(v);


    return 0;
}
