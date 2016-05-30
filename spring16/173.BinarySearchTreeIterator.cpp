// 2.1% slow
// iterative DFS
// space and time complexity of DFS

#include"mytest.h"


stack<TreeNode*> stk;
unordered_set<TreeNode*> st;

void BSTIterator(TreeNode *root) {
    if(root)
        stk.push(root);
}

/** @return whether we have a next smallest number */
bool hasNext() {
    return !stk.empty();
}

/** @return the next smallest number */
int next() {
    while(!stk.empty()) {
        TreeNode* u = stk.top();
        stk.pop();
        if(st.count(u)) {   //in-order traversal
            st.erase(u);
            return u->val;
        }
        else {
            st.insert(u);
            if(u->right)
                stk.push(u->right);
            stk.push(u);
            if(u->left)
                stk.push(u->left);
        }
    }
}

/**
 *  * Your BSTIterator will be called like this:
 *   * BSTIterator i = BSTIterator(root);
 *    * while (i.hasNext()) cout << i.next();
 *     */



int main() {
	srand(time(NULL));

    TreeNode* u = readTree();
    printTree(u);
    BSTIterator(u);
    while(hasNext()) cout<<next()<<endl;



    return 0;
}
