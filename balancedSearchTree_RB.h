
#ifndef _RED_BLACK_TREE_HPP_
#define _RED_BLACK_TREE_HPP_

#include <iomanip>
#include <iostream>
#include <windows.h>
using namespace std;

enum RBTColor {RED, BLACK};

template <class T>
class searchTreeNode
{
	public:
		RBTColor color;    // ��ɫ
		T key;            // �ؼ���(��ֵ)
		searchTreeNode *left;    // ����
		searchTreeNode *right;    // �Һ���
		searchTreeNode *parent; // �����

		searchTreeNode(T value, RBTColor c, searchTreeNode *p, searchTreeNode *l, searchTreeNode *r):
			key(value),color(c),parent(),left(l),right(r) {}
};

template <class T>
class searchTree
{
	private:
		searchTreeNode<T> *mRoot;
	public:
		searchTree();
		searchTreeNode<T>* search(T key);
		T minimum();
		T maximum();
		searchTreeNode<T>* successor(searchTreeNode<T> *x);
		searchTreeNode<T>* predecessor(searchTreeNode<T> *x);
		void insert(T key);
		void erase(T key);
        void RBoutput();
	private:
		searchTreeNode<T>* search(searchTreeNode<T>* x, T key) const;
		searchTreeNode<T>* iterativeSearch(searchTreeNode<T>* x, T key) const;
		searchTreeNode<T>* minimum(searchTreeNode<T>* tree);
		searchTreeNode<T>* maximum(searchTreeNode<T>* tree);
		void leftRotate(searchTreeNode<T>* &root, searchTreeNode<T>* x);
		void rightRotate(searchTreeNode<T>* &root, searchTreeNode<T>* y);
		void insert(searchTreeNode<T>* &root, searchTreeNode<T>* node);
		void insertFixUp(searchTreeNode<T>* &root, searchTreeNode<T>* node);
		void erase(searchTreeNode<T>* &root, searchTreeNode<T> *node);
		void eraseFixUp(searchTreeNode<T>* &root, searchTreeNode<T> *node, searchTreeNode<T> *parent);
        void RBoutput(searchTreeNode<T>* tree, T key, int direction, FILE*fp);

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};

template <class T>
searchTree<T>::searchTree():mRoot(NULL)
{
	mRoot = NULL;
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
	search(mRoot, key);
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
searchTreeNode<T>* searchTree<T>::successor(searchTreeNode<T> *x)
{
	// ���x�����Һ��ӣ���"x�ĺ�̽��"Ϊ "�����Һ���Ϊ������������С���"��
	if (x->right != NULL)
		return minimum(x->right);

	// ���xû���Һ��ӡ���x���������ֿ��ܣ�
	// (01) x��"һ������"����"x�ĺ�̽��"Ϊ "���ĸ����"��
	// (02) x��"һ���Һ���"�������"x����͵ĸ���㣬���Ҹø����Ҫ��������"���ҵ������"��͵ĸ����"����"x�ĺ�̽��"��
	searchTreeNode<T>* y = x->parent;
	while ((y!=NULL) && (x==y->right))
	{
		x = y;
		y = y->parent;
	}

	return y;
}

template <class T>
searchTreeNode<T>* searchTree<T>::predecessor(searchTreeNode<T> *x)
{
	// ���x�������ӣ���"x��ǰ�����"Ϊ "��������Ϊ���������������"��
	if (x->left != NULL)
		return maximum(x->left);

	// ���xû�����ӡ���x���������ֿ��ܣ�
	// (01) x��"һ���Һ���"����"x��ǰ�����"Ϊ "���ĸ����"��
	// (01) x��"һ������"�������"x����͵ĸ���㣬���Ҹø����Ҫ�����Һ���"���ҵ������"��͵ĸ����"����"x��ǰ�����"��
	searchTreeNode<T>* y = x->parent;
	while ((y!=NULL) && (x==y->left))
	{
		x = y;
		y = y->parent;
	}

	return y;
}

template <class T>
void searchTree<T>::leftRotate(searchTreeNode<T>* &root, searchTreeNode<T>* x)
{
	// ����x���Һ���Ϊy
	searchTreeNode<T> *y = x->right;

	// �� ��y�����ӡ� ��Ϊ ��x���Һ��ӡ���
	// ���y�����ӷǿգ��� ��x�� ��Ϊ ��y�����ӵĸ��ס�
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;

	// �� ��x�ĸ��ס� ��Ϊ ��y�ĸ��ס�
	y->parent = x->parent;

	if (x->parent == NULL)
	{
		root = y;            // ��� ��x�ĸ��ס� �ǿսڵ㣬��y��Ϊ���ڵ�
	}
	else
	{
		if (x->parent->left == x)
			x->parent->left = y;    // ��� x�������ڵ�����ӣ���y��Ϊ��x�ĸ��ڵ�����ӡ�
		else
			x->parent->right = y;    // ��� x�������ڵ�����ӣ���y��Ϊ��x�ĸ��ڵ�����ӡ�
	}

	// �� ��x�� ��Ϊ ��y�����ӡ�
	y->left = x;
	// �� ��x�ĸ��ڵ㡱 ��Ϊ ��y��
	x->parent = y;
}

template <class T>
void searchTree<T>::rightRotate(searchTreeNode<T>* &root, searchTreeNode<T>* y)
{
	// ����x�ǵ�ǰ�ڵ�����ӡ�
	searchTreeNode<T> *x = y->left;

	// �� ��x���Һ��ӡ� ��Ϊ ��y�����ӡ���
	// ���"x���Һ���"��Ϊ�յĻ����� ��y�� ��Ϊ ��x���Һ��ӵĸ��ס�
	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;

	// �� ��y�ĸ��ס� ��Ϊ ��x�ĸ��ס�
	x->parent = y->parent;

	if (y->parent == NULL)
	{
		root = x;            // ��� ��y�ĸ��ס� �ǿսڵ㣬��x��Ϊ���ڵ�
	}
	else
	{
		if (y == y->parent->right)
			y->parent->right = x;    // ��� y�������ڵ���Һ��ӣ���x��Ϊ��y�ĸ��ڵ���Һ��ӡ�
		else
			y->parent->left = x;    // (y�������ڵ������) ��x��Ϊ��x�ĸ��ڵ�����ӡ�
	}

	// �� ��y�� ��Ϊ ��x���Һ��ӡ�
	x->right = y;

	// �� ��y�ĸ��ڵ㡱 ��Ϊ ��x��
	y->parent = x;
}

template <class T>
void searchTree<T>::insertFixUp(searchTreeNode<T>* &root, searchTreeNode<T>* node)
{
	searchTreeNode<T> *parent, *gparent;

	// �������ڵ���ڣ����Ҹ��ڵ����ɫ�Ǻ�ɫ��
	while ((parent = rb_parent(node)) && rb_is_red(parent))
	{
		gparent = rb_parent(parent);

		//�������ڵ㡱�ǡ��游�ڵ�����ӡ�
		if (parent == gparent->left)
		{
			// Case 1����������ڵ��Ǻ�ɫ
			{
				searchTreeNode<T> *uncle = gparent->right;
				if (uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node = gparent;
					continue;
				}
			}

			// Case 2�����������Ǻ�ɫ���ҵ�ǰ�ڵ����Һ���
			if (parent->right == node)
			{
				searchTreeNode<T> *tmp;
				leftRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			// Case 3�����������Ǻ�ɫ���ҵ�ǰ�ڵ������ӡ�
			rb_set_black(parent);
			rb_set_red(gparent);
			rightRotate(root, gparent);
		}
		else//����z�ĸ��ڵ㡱�ǡ�z���游�ڵ���Һ��ӡ�
		{
			// Case 1����������ڵ��Ǻ�ɫ
			{
				searchTreeNode<T> *uncle = gparent->left;
				if (uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node = gparent;
					continue;
				}
			}

			// Case 2�����������Ǻ�ɫ���ҵ�ǰ�ڵ�������
			if (parent->left == node)
			{
				searchTreeNode<T> *tmp;
				rightRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			// Case 3�����������Ǻ�ɫ���ҵ�ǰ�ڵ����Һ��ӡ�
			rb_set_black(parent);
			rb_set_red(gparent);
			leftRotate(root, gparent);
		}
	}

	// �����ڵ���Ϊ��ɫ
	rb_set_black(root);
}

template <class T>
void searchTree<T>::insert(searchTreeNode<T>* &root, searchTreeNode<T>* node)
{
	searchTreeNode<T> *y = NULL;
	searchTreeNode<T> *x = root;

	// 1. �����������һ�Ŷ�������������ڵ���ӵ�����������С�
	while (x != NULL)
	{
		y = x;
		if (node->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	node->parent = y;
	if (y!=NULL)
	{
		if (node->key < y->key)
			y->left = node;
		else
			y->right = node;
	}
	else
		root = node;

	// 2. ���ýڵ����ɫΪ��ɫ
	node->color = RED;

	// 3. ������������Ϊһ�Ŷ��������
	insertFixUp(root, node);
}

template <class T>
void searchTree<T>::insert(T key)
{
	searchTreeNode<T> *z=NULL;

	// ����½����ʧ�ܣ��򷵻ء�
	if ((z=new searchTreeNode<T>(key,BLACK,NULL,NULL,NULL)) == NULL)
		return ;

	insert(mRoot, z);
}

template <class T>
void searchTree<T>::eraseFixUp(searchTreeNode<T>* &root, searchTreeNode<T> *node, searchTreeNode<T> *parent)
{
	searchTreeNode<T> *other;

	while ((!node || rb_is_black(node)) && node != root)
	{
		if (parent->left == node)
		{
			other = parent->right;
			if (rb_is_red(other))
			{
				// Case 1: x���ֵ�w�Ǻ�ɫ��
				rb_set_black(other);
				rb_set_red(parent);
				leftRotate(root, parent);
				other = parent->right;
			}
			if ((!other->left || rb_is_black(other->left)) &&
			        (!other->right || rb_is_black(other->right)))
			{
				// Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->right || rb_is_black(other->right))
				{
					// Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ��
					rb_set_black(other->left);
					rb_set_red(other);
					rightRotate(root, other);
					other = parent->right;
				}
				// Case 4: x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ�ģ�����������ɫ��
				rb_set_color(other, rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->right);
				leftRotate(root, parent);
				node = root;
				break;
			}
		}
		else
		{
			other = parent->left;
			if (rb_is_red(other))
			{
				// Case 1: x���ֵ�w�Ǻ�ɫ��
				rb_set_black(other);
				rb_set_red(parent);
				rightRotate(root, parent);
				other = parent->left;
			}
			if ((!other->left || rb_is_black(other->left)) &&
			        (!other->right || rb_is_black(other->right)))
			{
				// Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->left || rb_is_black(other->left))
				{
					// Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ��
					rb_set_black(other->right);
					rb_set_red(other);
					leftRotate(root, other);
					other = parent->left;
				}
				// Case 4: x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ�ģ�����������ɫ��
				rb_set_color(other, rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->left);
				rightRotate(root, parent);
				node = root;
				break;
			}
		}
	}
	if (node)
		rb_set_black(node);
}

template <class T>
void searchTree<T>::erase(searchTreeNode<T>* &root, searchTreeNode<T> *node)
{
	searchTreeNode<T> *child, *parent;
	RBTColor color;

	// ��ɾ���ڵ��"���Һ��Ӷ���Ϊ��"�������
	if ( (node->left!=NULL) && (node->right!=NULL) )
	{
		// ��ɾ�ڵ�ĺ�̽ڵ㡣(��Ϊ"ȡ���ڵ�")
		// ������ȡ��"��ɾ�ڵ�"��λ�ã�Ȼ���ٽ�"��ɾ�ڵ�"ȥ����
		searchTreeNode<T> *replace = node;

		// ��ȡ��̽ڵ�
		replace = replace->right;
		while (replace->left != NULL)
			replace = replace->left;

		// "node�ڵ�"���Ǹ��ڵ�(ֻ�и��ڵ㲻���ڸ��ڵ�)
		if (rb_parent(node))
		{
			if (rb_parent(node)->left == node)
				rb_parent(node)->left = replace;
			else
				rb_parent(node)->right = replace;
		}
		else
			// "node�ڵ�"�Ǹ��ڵ㣬���¸��ڵ㡣
			root = replace;

		// child��"ȡ���ڵ�"���Һ��ӣ�Ҳ����Ҫ"�����Ľڵ�"��
		// "ȡ���ڵ�"�϶����������ӣ���Ϊ����һ����̽ڵ㡣
		child = replace->right;
		parent = rb_parent(replace);
		// ����"ȡ���ڵ�"����ɫ
		color = rb_color(replace);

		// "��ɾ���ڵ�"��"���ĺ�̽ڵ�ĸ��ڵ�"
		if (parent == node)
		{
			parent = replace;
		}
		else
		{
			// child��Ϊ��
			if (child)
				rb_set_parent(child, parent);
			parent->left = child;

			replace->right = node->right;
			rb_set_parent(node->right, replace);
		}

		replace->parent = node->parent;
		replace->color = node->color;
		replace->left = node->left;
		node->left->parent = replace;

		if (color == BLACK)
			eraseFixUp(root, child, parent);

		delete node;
		return ;
	}

	if (node->left !=NULL)
		child = node->left;
	else
		child = node->right;

	parent = node->parent;
	// ����"ȡ���ڵ�"����ɫ
	color = node->color;

	if (child)
		child->parent = parent;

	// "node�ڵ�"���Ǹ��ڵ�
	if (parent)
	{
		if (parent->left == node)
			parent->left = child;
		else
			parent->right = child;
	}
	else
		root = child;

	if (color == BLACK)
		eraseFixUp(root, child, parent);
	delete node;
}

template <class T>
void searchTree<T>::erase(T key)
{
	searchTreeNode<T> *node;

	// ����key��Ӧ�Ľڵ�(node)���ҵ��Ļ���ɾ���ýڵ�
	if ((node = search(mRoot, key)) != NULL)
		erase(mRoot, node);
}

template <class T>
void searchTree<T>::RBoutput(searchTreeNode<T>* tree, T key, int direction, FILE*fp)
{
	if(tree != NULL)
	{
		if(tree->left!=NULL)
			fprintf(fp,"%d->%d;\n",tree->key,tree->left->key);
		if(tree->right!=NULL)
			fprintf(fp,"%d->%d;\n",tree->key,tree->right->key);		
        RBoutput(tree->left, tree->key, -1, fp);
        RBoutput(tree->right,tree->key,  1, fp);
	}
}

template <class T>
void searchTree<T>::RBoutput()
{
    FILE*fp = fopen("D:/zhangjunshuo_qt/myFirstWidgetProject/image/RB_searchTree_output_tempFile.dot","w+");
	fprintf(fp,"digraph zjs{\n");
	if (mRoot != NULL)
        RBoutput(mRoot, mRoot->key, 0, fp);
	fprintf(fp,"}\n");
	fclose(fp);
    //system("dot D:/zhangjunshuo_qt/myFirstWidgetProject/image/RB_searchTree_output_tempFile.dot -T png -o zjs.png");
    WinExec("dot D:/zhangjunshuo_qt/myFirstWidgetProject/image/RB_searchTree_output_tempFile.dot -T png -o D:/zhangjunshuo_qt/myFirstWidgetProject/image/zjs.png", SW_HIDE);
}

#endif
