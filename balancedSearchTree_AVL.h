#ifndef _AVL_TREE_HPP_
#define _AVL_TREE_HPP_

#include <iomanip>
#include <iostream>
#include <windows.h>
using namespace std;

template <class T>
class searchTreeNode
{
	public:
		T key;                	// 关键字(键值)
		int height;         	// 高度
		searchTreeNode *left;    	// 左孩子
		searchTreeNode *right;    	// 右孩子

		searchTreeNode(T value, searchTreeNode *l, searchTreeNode *r):
			key(value), height(0),left(l),right(r) {}
};

template <class T>
class searchTree
{
	private:
		searchTreeNode<T> *mRoot;    // 根结点

	public:
		searchTree();
// 获取树的高度
		int height();
// 获取树的高度
		int max(int a, int b);
// 前序遍历"AVL树"
		void preOrder();
// (递归实现)查找"AVL树"中键值为key的节点
		searchTreeNode<T>* search(T key);
// 查找最小结点：返回最小结点的键值。
		T minimum();
// 查找最大结点：返回最大结点的键值。
		T maximum();
// 将结点(key为节点键值)插入到AVL树中
		void insert(T key);
// 删除结点(key为节点键值)
		void erase(T key);
// 打印AVL树
        void output();
	private:
// 获取树的高度
		int height(searchTreeNode<T>* tree) ;
// 前序遍历"AVL树"
		void preOrder(searchTreeNode<T>* tree) const;
// (递归实现)查找"AVL树x"中键值为key的节点
		searchTreeNode<T>* search(searchTreeNode<T>* x, T key) const;
// 查找最小结点：返回tree为根结点的AVL树的最小结点。
		searchTreeNode<T>* minimum(searchTreeNode<T>* tree);
// 查找最大结点：返回tree为根结点的AVL树的最大结点。
		searchTreeNode<T>* maximum(searchTreeNode<T>* tree);
// LL：左左对应的情况(左单旋转)。
		searchTreeNode<T>* leftLeftRotation(searchTreeNode<T>* k2);
// RR：右右对应的情况(右单旋转)。
		searchTreeNode<T>* rightRightRotation(searchTreeNode<T>* k1);
// LR：左右对应的情况(左双旋转)。
		searchTreeNode<T>* leftRightRotation(searchTreeNode<T>* k3);
// RL：右左对应的情况(右双旋转)。
		searchTreeNode<T>* rightLeftRotation(searchTreeNode<T>* k1);
// 将结点(z)插入到AVL树(tree)中
		searchTreeNode<T>* insert(searchTreeNode<T>* &tree, T key);
// 删除AVL树(tree)中的结点(z)，并返回被删除的结点
		searchTreeNode<T>* erase(searchTreeNode<T>* &tree, searchTreeNode<T>* z);
// 打印AVL树
        void output(searchTreeNode<T>* tree, T key, int direction, FILE*fp);
};

template <class T>
searchTree<T>::searchTree():mRoot(NULL)
{
}

template <class T>
int searchTree<T>::height(searchTreeNode<T>* tree)
{
	if (tree != NULL)
		return tree->height;

	return 0;
}

template <class T>
int searchTree<T>::height()
{
	return height(mRoot);
}

template <class T>
int searchTree<T>::max(int a, int b)
{
	return a>b ? a : b;
}

template <class T>
void searchTree<T>::preOrder(searchTreeNode<T>* tree) const
{
	if(tree != NULL)
	{
		cout<< tree->key << " " ;
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template <class T>
void searchTree<T>::preOrder()
{
	preOrder(mRoot);
}

template <class T>
searchTreeNode<T>* searchTree<T>::search(searchTreeNode<T>* x, T key) const
{
	if (x==NULL || x->key==key)
		return x;

	if (key < x->key)
		return search(x->left, key);
	else
		return search(x->right, key);
}

template <class T>
searchTreeNode<T>* searchTree<T>::search(T key)
{
	return search(mRoot, key);
}

template <class T>
searchTreeNode<T>* searchTree<T>::minimum(searchTreeNode<T>* tree)
{
	if (tree == NULL)
		return NULL;

	while(tree->left != NULL)
		tree = tree->left;
	return tree;
}

template <class T>
T searchTree<T>::minimum()
{
	searchTreeNode<T> *p = minimum(mRoot);
	if (p != NULL)
		return p->key;

	return (T)NULL;
}

template <class T>
searchTreeNode<T>* searchTree<T>::maximum(searchTreeNode<T>* tree)
{
	if (tree == NULL)
		return NULL;

	while(tree->right != NULL)
		tree = tree->right;
	return tree;
}

template <class T>
T searchTree<T>::maximum()
{
	searchTreeNode<T> *p = maximum(mRoot);
	if (p != NULL)
		return p->key;

	return (T)NULL;
}

template <class T>
searchTreeNode<T>* searchTree<T>::leftLeftRotation(searchTreeNode<T>* k2)
{
	searchTreeNode<T>* k1;

	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	k2->height = max( height(k2->left), height(k2->right)) + 1;
	k1->height = max( height(k1->left), k2->height) + 1;

	return k1;
}

template <class T>
searchTreeNode<T>* searchTree<T>::rightRightRotation(searchTreeNode<T>* k1)
{
	searchTreeNode<T>* k2;

	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;

	k1->height = max( height(k1->left), height(k1->right)) + 1;
	k2->height = max( height(k2->right), k1->height) + 1;

	return k2;
}

template <class T>
searchTreeNode<T>* searchTree<T>::leftRightRotation(searchTreeNode<T>* k3)
{
	k3->left = rightRightRotation(k3->left);

	return leftLeftRotation(k3);
}

template <class T>
searchTreeNode<T>* searchTree<T>::rightLeftRotation(searchTreeNode<T>* k1)
{
	k1->right = leftLeftRotation(k1->right);

	return rightRightRotation(k1);
}

template <class T>
searchTreeNode<T>* searchTree<T>::insert(searchTreeNode<T>* &tree, T key)
{
	if (tree == NULL)
	{
		// 新建节点
		tree = new searchTreeNode<T>(key, NULL, NULL);
		if (tree==NULL)
		{
			cout << "ERROR: create avltree node failed!" << endl;
			return NULL;
		}
	}
	else if (key < tree->key) // 应该将key插入到"tree的左子树"的情况
	{
		tree->left = insert(tree->left, key);
		// 插入节点后，若AVL树失去平衡，则进行相应的调节。
		if (height(tree->left) - height(tree->right) == 2)
		{
			if (key < tree->left->key)
				tree = leftLeftRotation(tree);
			else
				tree = leftRightRotation(tree);
		}
	}
	else if (key > tree->key) // 应该将key插入到"tree的右子树"的情况
	{
		tree->right = insert(tree->right, key);
		// 插入节点后，若AVL树失去平衡，则进行相应的调节。
		if (height(tree->right) - height(tree->left) == 2)
		{
			if (key > tree->right->key)
				tree = rightRightRotation(tree);
			else
				tree = rightLeftRotation(tree);
		}
	}
	else //key == tree->key)
	{
		cout << "添加失败：不允许添加相同的节点！" << endl;
	}

	tree->height = max( height(tree->left), height(tree->right)) + 1;

	return tree;
}

template <class T>
void searchTree<T>::insert(T key)
{
	insert(mRoot, key);
}

template <class T>
searchTreeNode<T>* searchTree<T>::erase(searchTreeNode<T>* &tree, searchTreeNode<T>* z)
{
	// 根为空 或者 没有要删除的节点，直接返回NULL。
	if (tree==NULL || z==NULL)
		return NULL;

	if (z->key < tree->key)        // 待删除的节点在"tree的左子树"中
	{
		tree->left = erase(tree->left, z);
		// 删除节点后，若AVL树失去平衡，则进行相应的调节。
		if (height(tree->right) - height(tree->left) == 2)
		{
			searchTreeNode<T> *r =  tree->right;
			if (height(r->left) > height(r->right))
				tree = rightLeftRotation(tree);
			else
				tree = rightRightRotation(tree);
		}
	}
	else if (z->key > tree->key)// 待删除的节点在"tree的右子树"中
	{
		tree->right = erase(tree->right, z);
		// 删除节点后，若AVL树失去平衡，则进行相应的调节。
		if (height(tree->left) - height(tree->right) == 2)
		{
			searchTreeNode<T> *l =  tree->left;
			if (height(l->right) > height(l->left))
				tree = leftRightRotation(tree);
			else
				tree = leftLeftRotation(tree);
		}
	}
	else    // tree是对应要删除的节点。
	{
		// tree的左右孩子都非空
		if ((tree->left!=NULL) && (tree->right!=NULL))
		{
			if (height(tree->left) > height(tree->right))
			{
				// 如果tree的左子树比右子树高；
				// 则(01)找出tree的左子树中的最大节点
				//   (02)将该最大节点的值赋值给tree。
				//   (03)删除该最大节点。
				// 这类似于用"tree的左子树中最大节点"做"tree"的替身；
				// 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的。
				searchTreeNode<T>* max = maximum(tree->left);
				tree->key = max->key;
				tree->left = erase(tree->left, max);
			}
			else
			{
				// 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
				// 则(01)找出tree的右子树中的最小节点
				//   (02)将该最小节点的值赋值给tree。
				//   (03)删除该最小节点。
				// 这类似于用"tree的右子树中最小节点"做"tree"的替身；
				// 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
				searchTreeNode<T>* min = maximum(tree->right);
				tree->key = min->key;
				tree->right = erase(tree->right, min);
			}
		}
		else
		{
			searchTreeNode<T>* tmp = tree;
			tree = (tree->left!=NULL) ? tree->left : tree->right;
			delete tmp;
		}
	}

	return tree;
}

template <class T>
void searchTree<T>::erase(T key)
{
	searchTreeNode<T>* z;

	if ((z = search(mRoot, key)) != NULL)
		mRoot = erase(mRoot, z);
}

template <class T>
void searchTree<T>::output(searchTreeNode<T>* tree, T key, int direction, FILE*fp)
{
	if(tree != NULL)
	{
		if(tree->left!=NULL)
			fprintf(fp,"%d->%d;\n",tree->key,tree->left->key);
		if(tree->right!=NULL)
			fprintf(fp,"%d->%d;\n",tree->key,tree->right->key);
        output(tree->left, tree->key, -1, fp);
        output(tree->right,tree->key,  1, fp);
	}
}

template <class T>
void searchTree<T>::output()
{
    FILE*fp = fopen("D:/zhangjunshuo_qt/myFirstWidgetProject/image/AVL_searchTree_output_tempFile.dot","w+");
	fprintf(fp,"digraph zjs{\n");
	if (mRoot != NULL)
        output(mRoot, mRoot->key, 0, fp);
	fprintf(fp,"}\n");
	fclose(fp);
    //system("dot D:/zhangjunshuo_qt/myFirstWidgetProject/image/AVL_searchTree_output_tempFile.dot -T png -o avlzjs.png");
    WinExec("dot D:/zhangjunshuo_qt/myFirstWidgetProject/image/AVL_searchTree_output_tempFile.dot -T png -o D:/zhangjunshuo_qt/myFirstWidgetProject/image/avlzjs.png", SW_HIDE);
}
#endif


































