int sizei(TreeNode *A)
{
    if(A==NULL)
       return 0;
    int l = sizei(A->left);
    int r = sizei(A->right);
    if(l>r)
    return l+1;
    else
     return  r+1;
}
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<struct TreeNode *> que;
    vector<vector<int> > vec;
    vec.clear();
    int size=0,i=0,s=0;
    s=sizei(A);
    vec.resize(s);
    que.push(A);
    while(!que.empty())
    {
        size=que.size();
        while(size--)
        {
              struct TreeNode * node= que.front();
              vec[i].push_back(node->val);
              que.pop();
              if(node->left)
                que.push(node->left);
              if(node->right)
                que.push(node->right);
        }
        i++;
    }
    return vec;
}
