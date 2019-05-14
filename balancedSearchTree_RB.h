
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
		RBTColor color;    // 颜色
		T key;            // 关键字(键值)
		searchTreeNode *left;    // 左孩子
		searchTreeNode *right;    // 右孩子
		searchTreeNode *parent; // 父结点

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
	// 如果x存在右孩子，则"x的后继结点"为 "以其右孩子为根的子树的最小结点"。
	if (x->right != NULL)
		return minimum(x->right);

	// 如果x没有右孩子。则x有以下两种可能：
	// (01) x是"一个左孩子"，则"x的后继结点"为 "它的父结点"。
	// (02) x是"一个右孩子"，则查找"x的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"x的后继结点"。
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
	// 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
	if (x->left != NULL)
		return maximum(x->left);

	// 如果x没有左孩子。则x有以下两种可能：
	// (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
	// (01) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
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
	// 设置x的右孩子为y
	searchTreeNode<T> *y = x->right;

	// 将 “y的左孩子” 设为 “x的右孩子”；
	// 如果y的左孩子非空，将 “x” 设为 “y的左孩子的父亲”
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;

	// 将 “x的父亲” 设为 “y的父亲”
	y->parent = x->parent;

	if (x->parent == NULL)
	{
		root = y;            // 如果 “x的父亲” 是空节点，则将y设为根节点
	}
	else
	{
		if (x->parent->left == x)
			x->parent->left = y;    // 如果 x是它父节点的左孩子，则将y设为“x的父节点的左孩子”
		else
			x->parent->right = y;    // 如果 x是它父节点的左孩子，则将y设为“x的父节点的左孩子”
	}

	// 将 “x” 设为 “y的左孩子”
	y->left = x;
	// 将 “x的父节点” 设为 “y”
	x->parent = y;
}

template <class T>
void searchTree<T>::rightRotate(searchTreeNode<T>* &root, searchTreeNode<T>* y)
{
	// 设置x是当前节点的左孩子。
	searchTreeNode<T> *x = y->left;

	// 将 “x的右孩子” 设为 “y的左孩子”；
	// 如果"x的右孩子"不为空的话，将 “y” 设为 “x的右孩子的父亲”
	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;

	// 将 “y的父亲” 设为 “x的父亲”
	x->parent = y->parent;

	if (y->parent == NULL)
	{
		root = x;            // 如果 “y的父亲” 是空节点，则将x设为根节点
	}
	else
	{
		if (y == y->parent->right)
			y->parent->right = x;    // 如果 y是它父节点的右孩子，则将x设为“y的父节点的右孩子”
		else
			y->parent->left = x;    // (y是它父节点的左孩子) 将x设为“x的父节点的左孩子”
	}

	// 将 “y” 设为 “x的右孩子”
	x->right = y;

	// 将 “y的父节点” 设为 “x”
	y->parent = x;
}

template <class T>
void searchTree<T>::insertFixUp(searchTreeNode<T>* &root, searchTreeNode<T>* node)
{
	searchTreeNode<T> *parent, *gparent;

	// 若“父节点存在，并且父节点的颜色是红色”
	while ((parent = rb_parent(node)) && rb_is_red(parent))
	{
		gparent = rb_parent(parent);

		//若“父节点”是“祖父节点的左孩子”
		if (parent == gparent->left)
		{
			// Case 1条件：叔叔节点是红色
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

			// Case 2条件：叔叔是黑色，且当前节点是右孩子
			if (parent->right == node)
			{
				searchTreeNode<T> *tmp;
				leftRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			// Case 3条件：叔叔是黑色，且当前节点是左孩子。
			rb_set_black(parent);
			rb_set_red(gparent);
			rightRotate(root, gparent);
		}
		else//若“z的父节点”是“z的祖父节点的右孩子”
		{
			// Case 1条件：叔叔节点是红色
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

			// Case 2条件：叔叔是黑色，且当前节点是左孩子
			if (parent->left == node)
			{
				searchTreeNode<T> *tmp;
				rightRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			// Case 3条件：叔叔是黑色，且当前节点是右孩子。
			rb_set_black(parent);
			rb_set_red(gparent);
			leftRotate(root, gparent);
		}
	}

	// 将根节点设为黑色
	rb_set_black(root);
}

template <class T>
void searchTree<T>::insert(searchTreeNode<T>* &root, searchTreeNode<T>* node)
{
	searchTreeNode<T> *y = NULL;
	searchTreeNode<T> *x = root;

	// 1. 将红黑树当作一颗二叉查找树，将节点添加到二叉查找树中。
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

	// 2. 设置节点的颜色为红色
	node->color = RED;

	// 3. 将它重新修正为一颗二叉查找树
	insertFixUp(root, node);
}

template <class T>
void searchTree<T>::insert(T key)
{
	searchTreeNode<T> *z=NULL;

	// 如果新建结点失败，则返回。
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
				// Case 1: x的兄弟w是红色的
				rb_set_black(other);
				rb_set_red(parent);
				leftRotate(root, parent);
				other = parent->right;
			}
			if ((!other->left || rb_is_black(other->left)) &&
			        (!other->right || rb_is_black(other->right)))
			{
				// Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->right || rb_is_black(other->right))
				{
					// Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色。
					rb_set_black(other->left);
					rb_set_red(other);
					rightRotate(root, other);
					other = parent->right;
				}
				// Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
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
				// Case 1: x的兄弟w是红色的
				rb_set_black(other);
				rb_set_red(parent);
				rightRotate(root, parent);
				other = parent->left;
			}
			if ((!other->left || rb_is_black(other->left)) &&
			        (!other->right || rb_is_black(other->right)))
			{
				// Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->left || rb_is_black(other->left))
				{
					// Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色。
					rb_set_black(other->right);
					rb_set_red(other);
					leftRotate(root, other);
					other = parent->left;
				}
				// Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
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

	// 被删除节点的"左右孩子都不为空"的情况。
	if ( (node->left!=NULL) && (node->right!=NULL) )
	{
		// 被删节点的后继节点。(称为"取代节点")
		// 用它来取代"被删节点"的位置，然后再将"被删节点"去掉。
		searchTreeNode<T> *replace = node;

		// 获取后继节点
		replace = replace->right;
		while (replace->left != NULL)
			replace = replace->left;

		// "node节点"不是根节点(只有根节点不存在父节点)
		if (rb_parent(node))
		{
			if (rb_parent(node)->left == node)
				rb_parent(node)->left = replace;
			else
				rb_parent(node)->right = replace;
		}
		else
			// "node节点"是根节点，更新根节点。
			root = replace;

		// child是"取代节点"的右孩子，也是需要"调整的节点"。
		// "取代节点"肯定不存在左孩子！因为它是一个后继节点。
		child = replace->right;
		parent = rb_parent(replace);
		// 保存"取代节点"的颜色
		color = rb_color(replace);

		// "被删除节点"是"它的后继节点的父节点"
		if (parent == node)
		{
			parent = replace;
		}
		else
		{
			// child不为空
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
	// 保存"取代节点"的颜色
	color = node->color;

	if (child)
		child->parent = parent;

	// "node节点"不是根节点
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

	// 查找key对应的节点(node)，找到的话就删除该节点
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
