/*含有父节点指针的普通二叉树节点结构*/
typedef struct TreeNode {
	int val;
	TreeNode *left;
	vector<TreeNode *> m_vChildren;

	TreeNode(int val) :val(val), m_vChildren(vector<TreeNode*>()) {}
};

//获取node节点在树root中的路径
bool getNodePath(TreeNode *root, TreeNode *node, vector<TreeNode *> &path)
{
	if (root == node)
		return true;

	path.push_back(root);
	bool found = false;
	vector<TreeNode *>::iterator iter = root->m_vChildren.begin();
	while (!found && iter < root->m_vChildren.end())
	{
		found = getNodePath(*iter, node, path);
		++iter;
	}//while

	if (!found)
		path.pop_back();

	return found;
}

TreeNode *getLastCommonNode(vector<TreeNode *> pV, vector<TreeNode *> qV)
{
	if (pV.empty() && qV.empty())
		return NULL;
	vector<TreeNode *>::iterator pIter = pV.begin(), qIter = qV.begin();

	TreeNode *ret = NULL;
	while (pIter != pV.end() && qIter != qV.end())
	{
		if (*pIter == *qIter)
			ret = *pIter;
		++pIter;
		++qIter;
	}//while
	return ret;

}

TreeNode *getLastCommonParent4(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (root == NULL)
		return NULL;

	vector<TreeNode *> pV, qV;
	getNodePath(root, p, pV);
	getNodePath(root, q, qV);

	return getLastCommonNode(pV, qV);
}
