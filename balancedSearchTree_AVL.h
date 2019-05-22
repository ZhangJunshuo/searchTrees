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
		T key;                	// �ؼ���(��ֵ)
		int height;         	// �߶�
		searchTreeNode *left;    	// ����
		searchTreeNode *right;    	// �Һ���

		searchTreeNode(T value, searchTreeNode *l, searchTreeNode *r):
			key(value), height(0),left(l),right(r) {}
};

template <class T>
class searchTree
{
	private:
		searchTreeNode<T> *mRoot;    // �����

	public:
		searchTree();
// ��ȡ���ĸ߶�
		int height();
// ��ȡ���ĸ߶�
		int max(int a, int b);
// ǰ�����"AVL��"
		void preOrder();
// (�ݹ�ʵ��)����"AVL��"�м�ֵΪkey�Ľڵ�
		searchTreeNode<T>* search(T key);
// ������С��㣺������С���ļ�ֵ��
		T minimum();
// ��������㣺���������ļ�ֵ��
		T maximum();
// �����(keyΪ�ڵ��ֵ)���뵽AVL����
		void insert(T key);
// ɾ�����(keyΪ�ڵ��ֵ)
		void erase(T key);
// ��ӡAVL��
        void output();
	private:
// ��ȡ���ĸ߶�
		int height(searchTreeNode<T>* tree) ;
// ǰ�����"AVL��"
		void preOrder(searchTreeNode<T>* tree) const;
// (�ݹ�ʵ��)����"AVL��x"�м�ֵΪkey�Ľڵ�
		searchTreeNode<T>* search(searchTreeNode<T>* x, T key) const;
// ������С��㣺����treeΪ������AVL������С��㡣
		searchTreeNode<T>* minimum(searchTreeNode<T>* tree);
// ��������㣺����treeΪ������AVL��������㡣
		searchTreeNode<T>* maximum(searchTreeNode<T>* tree);
// LL�������Ӧ�����(����ת)��
		searchTreeNode<T>* leftLeftRotation(searchTreeNode<T>* k2);
// RR�����Ҷ�Ӧ�����(�ҵ���ת)��
		searchTreeNode<T>* rightRightRotation(searchTreeNode<T>* k1);
// LR�����Ҷ�Ӧ�����(��˫��ת)��
		searchTreeNode<T>* leftRightRotation(searchTreeNode<T>* k3);
// RL�������Ӧ�����(��˫��ת)��
		searchTreeNode<T>* rightLeftRotation(searchTreeNode<T>* k1);
// �����(z)���뵽AVL��(tree)��
		searchTreeNode<T>* insert(searchTreeNode<T>* &tree, T key);
// ɾ��AVL��(tree)�еĽ��(z)�������ر�ɾ���Ľ��
		searchTreeNode<T>* erase(searchTreeNode<T>* &tree, searchTreeNode<T>* z);
// ��ӡAVL��
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
		// �½��ڵ�
		tree = new searchTreeNode<T>(key, NULL, NULL);
		if (tree==NULL)
		{
			cout << "ERROR: create avltree node failed!" << endl;
			return NULL;
		}
	}
	else if (key < tree->key) // Ӧ�ý�key���뵽"tree��������"�����
	{
		tree->left = insert(tree->left, key);
		// ����ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
		if (height(tree->left) - height(tree->right) == 2)
		{
			if (key < tree->left->key)
				tree = leftLeftRotation(tree);
			else
				tree = leftRightRotation(tree);
		}
	}
	else if (key > tree->key) // Ӧ�ý�key���뵽"tree��������"�����
	{
		tree->right = insert(tree->right, key);
		// ����ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
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
		cout << "���ʧ�ܣ������������ͬ�Ľڵ㣡" << endl;
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
	// ��Ϊ�� ���� û��Ҫɾ���Ľڵ㣬ֱ�ӷ���NULL��
	if (tree==NULL || z==NULL)
		return NULL;

	if (z->key < tree->key)        // ��ɾ���Ľڵ���"tree��������"��
	{
		tree->left = erase(tree->left, z);
		// ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
		if (height(tree->right) - height(tree->left) == 2)
		{
			searchTreeNode<T> *r =  tree->right;
			if (height(r->left) > height(r->right))
				tree = rightLeftRotation(tree);
			else
				tree = rightRightRotation(tree);
		}
	}
	else if (z->key > tree->key)// ��ɾ���Ľڵ���"tree��������"��
	{
		tree->right = erase(tree->right, z);
		// ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
		if (height(tree->left) - height(tree->right) == 2)
		{
			searchTreeNode<T> *l =  tree->left;
			if (height(l->right) > height(l->left))
				tree = leftRightRotation(tree);
			else
				tree = leftLeftRotation(tree);
		}
	}
	else    // tree�Ƕ�ӦҪɾ���Ľڵ㡣
	{
		// tree�����Һ��Ӷ��ǿ�
		if ((tree->left!=NULL) && (tree->right!=NULL))
		{
			if (height(tree->left) > height(tree->right))
			{
				// ���tree�����������������ߣ�
				// ��(01)�ҳ�tree���������е����ڵ�
				//   (02)�������ڵ��ֵ��ֵ��tree��
				//   (03)ɾ�������ڵ㡣
				// ����������"tree�������������ڵ�"��"tree"������
				// �������ַ�ʽ�ĺô��ǣ�ɾ��"tree�������������ڵ�"֮��AVL����Ȼ��ƽ��ġ�
				searchTreeNode<T>* max = maximum(tree->left);
				tree->key = max->key;
				tree->left = erase(tree->left, max);
			}
			else
			{
				// ���tree��������������������(��������ȣ�������������������1)
				// ��(01)�ҳ�tree���������е���С�ڵ�
				//   (02)������С�ڵ��ֵ��ֵ��tree��
				//   (03)ɾ������С�ڵ㡣
				// ����������"tree������������С�ڵ�"��"tree"������
				// �������ַ�ʽ�ĺô��ǣ�ɾ��"tree������������С�ڵ�"֮��AVL����Ȼ��ƽ��ġ�
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


































