// 25.91% 1st
// Tree.......

#include"mytest.h"




TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    stack<TreeNode*> stk;
    stk.push(p);
    while(!stk.empty()){
        TreeNode* u = stk.top();
        stk.pop();
        if(u == q) return p;
        if(u->left) stk.push(u->left);
        if(u->right) stk.push(u->right);
    }
                
    stk.push(q);
    while(!stk.empty()){
        TreeNode* u = stk.top();
        stk.pop();
        if(u == p) return q;
        if(u->left) stk.push(u->left);
        if(u->right) stk.push(u->right);
    }
    //assert: LCA is not p or q;
    printf("asd\n");
    


    unordered_map<TreeNode*, TreeNode*> parent;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()) {
        TreeNode* u = que.front();
        que.pop();
        if(u->left) {
            que.push(u->left);
            parent[u->left] = u;
        }
        if(u->right) {
            que.push(u->right);
            parent[u->right] = u;
        }

        if(parent.count(p) && parent.count(q)) break;
    }

    TreeNode* u, *v;
    u = p;
    v = q;
    unordered_set<TreeNode*> st;
    while( 1 ) {
        if(u) {
            if(st.count(u)) return u;
            st.insert(u);
            if(parent.count(u))
                u = parent[u];
            else
                u = 0;
        }
        if(v) {
            if(st.count(v)) return v;
            st.insert(v);
            if(parent.count(v))
                v = parent[v];
            else
                v = 0;
        }
        if(!u && !v) {
            cout<<"u.v == NULL\n";
            break;
        }
    }
    return 0;
}



int main() {
	srand(time(NULL));

    TreeNode* t;
    t = readTree();
    printTree(t);


    TreeNode* a = lowestCommonAncestor(t, t->left->left, t->left->right);
    cout<<a->val<<endl;



    return 0;
}
