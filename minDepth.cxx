int minDepth(TreeNode *root) {
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return 1;
	else
	{
		int left, right;
		if(root->left && root->right)
			return (1 + min(minDepth(root->left), minDepth(root->right)));
		else if(root->left)
			return (1 + minDepth(root->left));
		else if(root->right)
			return (1 + minDepth(root->right));
	}
}