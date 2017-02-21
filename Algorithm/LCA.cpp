//http://www.voidcn.com/blog/gogokongyin/article/p-6071444.html

#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct BinTree
{
	int data;
	BinTree *pLeft;
	BinTree *pRight;
};

list<BinTree *> path1;
list<BinTree *> path2;

BinTree *pRoot1 = NULL;

bool IsExistData1 = true;
bool IsExistData2 = true;


//递归先序创建二叉树；
void CreateTree(BinTree *&root)
{
	int data;
	cin >> data;
	if (0 == data)
		root = NULL;
	else
	{
		root = new BinTree;
		root->data = data;
		CreateTree(root->pLeft);
		CreateTree(root->pRight);
	}
}


//1.将从根结点pRoot到输入的结点值data1,data2的路径保存在链表list1和list2中；
bool GetNodePath(BinTree *root, int target, list<BinTree*> &path)
{
	if (NULL == root)
		return false;
	
	path.push_back(root);

	if (root->data == target)
		return true;
	else
	{
		bool found = false;
		found = GetNodePath(root->pLeft, target, path);

		if (!found)
			found = GetNodePath(root->pRight, target, path);

		if (!found)
			path.pop_back();
		return found;
	}
}


//2.得到list1和list2公共结点；
BinTree *GetLastComNode(const list<BinTree *> &list1, const list<BinTree*> &list2)
{
	list<BinTree *>::const_iterator it1 = list1.begin();
	list<BinTree *>::const_iterator it2 = list2.begin();

	BinTree *pLast = NULL;

	while (it1 != list1.end() && it2 != list2.end())
	{
		if (*it1 == *it2)
			pLast = *it1;
		it1++;
		it2++;
	}
	return  pLast;
}


//3.组合1,2，返回公共结点；
BinTree *GetLastCommParent(BinTree *root, int data1, int data2)
{
	if (NULL == root)
		return NULL;
	//得到路径
	if (!GetNodePath(root, data1, path1))
	{
		IsExistData1 = false;
		return NULL;
	}
	if (!GetNodePath(root, data2, path2))
	{
		IsExistData2 = false;
		return NULL;
	}
	//得到最低公共祖先；
	return GetLastComNode(path1, path2);
}


void PreOrder(BinTree *root)
{
	if (root)
	{
		cout << root->data << " ";
		PreOrder(root->pLeft);
		PreOrder(root->pRight);
	}
}


void InOrder(BinTree *root)
{
	if (root)
	{
		InOrder(root->pLeft);
		cout << root->data << " ";
		InOrder(root->pRight);
	}
}


void DestoryBinTree(BinTree *root)
{
	if (root)
	{
		DestoryBinTree(root->pLeft);
		DestoryBinTree(root->pRight);
		delete root;
		root = NULL;
	}
}


int main()
{
	int da1, da2;
	BinTree *result = NULL;
	CreateTree(pRoot1);
	
	cout << "前序遍历：";
	PreOrder(pRoot1);
	cout << endl;
	cout << "中序遍历：";
	InOrder(pRoot1);
	cout << endl;

	while (1)
	{
		cin >> da1 >> da2;
		if (0 == da1 || 0 == da2)
			break;

		result = GetLastCommParent(pRoot1, da1, da2);
		path1.clear();
		path2.clear();
		if (IsExistData1&& IsExistData2)
			cout << da1 << "和" << da2 << "的最低公共祖先是：" << result->data << endl;
		else
		{
			if (!IsExistData1)
				cout << da1 << "数据不存在！" << endl;
			else
				cout << da2 << "数据不存在！" << endl;
		}
	}
	DestoryBinTree(pRoot1);
	system("pause");
	return 0;
}