#ifndef BALANCEDSEARCHTREE_TREAP_H
#define BALANCEDSEARCHTREE_TREAP_H

#include<windows.h>
#include<iostream>
using namespace std;

template<typename I, typename V>
class searchTreeNode
{
	public:
		pair<I,V> element;
		int random = 0;	//�����ֵ
		//int subTreeSize = 1;	//�Ըýڵ�Ϊ����������Ԫ�ظ���
		int size = 0;
		int numOfThis = 0;
		int*son = NULL;
		//��ȡ��AVL��ת���ѵĽ�ѵ��ȡ����left\right\left_up\right_up���ĸ�ָ��
		//ת��������һ�����������棬son[0]��ʾ���ӵ�λ�ã�son[1]��ʾ���ӵ�λ��
		//��һ����ȫ�������������ʵ�ʵ��������ָ��λ��û��Ԫ�أ���ôsonֵΪ-1;
		searchTreeNode()
		{
			son = new int[2];
			son[0] = son[1] = 0;
		}
};
template<typename I, typename V>
class searchTree
{
	private:
		searchTreeNode<I,V>* tree = NULL;
		int num = 0;	//Ԫ�ظ���
	public:
		int indexOfRoot = 0;
		searchTree()
		{
			tree = new searchTreeNode<I,V>[10000];
		}
	private:
		//
		void pushup(int p)
		{
			tree[p].size = tree[tree[p].son[0]].size + tree[tree[p].son[1]].size + 1;
		}
		void rotate(int &p,int d)
		{
			int k = tree[p].son[d^1];
			tree[p].son[d^1] = tree[k].son[d];
			tree[k].son[d] = p;
			pushup(p);
			pushup(k);
			p = k;
		}
	public:
//INSERT
		void insert(int &p, pair<I,V> _element)
		{
			if (!p)
			{
				p = ++num;
				tree[p].size = tree[p].numOfThis = 1;
				tree[p].element = _element;
				tree[p].random = rand();
				return;
			}
			if (tree[p].element.first == _element.first)
			{
				tree[p].numOfThis = 1;
				tree[p].size++;
				tree[p].element = _element;
				return;
			}
			int d = (_element.first > tree[p].element.first);
			insert(tree[p].son[d], _element);
			if (tree[p].random < tree[tree[p].son[d]].random) rotate(p, d^1);
			pushup(p);
		}
//ERASE
		void erase(int &p, I index)
		{
			if (!p) return;
			if (index < tree[p].element.first)
				erase(tree[p].son[0], index);
			else if (index > tree[p].element.first)
				erase(tree[p].son[1], index);
			else
			{
				if (!tree[p].son[0] && !tree[p].son[1])
				{
					tree[p].numOfThis--;
					tree[p].size--;
					if (tree[p].numOfThis==0) p=0;
				}
				else if (tree[p].son[0] && !tree[p].son[1])
				{
					rotate(p,1);
					erase(tree[p].son[1], index);
				}
				else if (!tree[p].son[0] && tree[p].son[1])
				{
					rotate(p,0);
					erase(tree[p].son[0], index);
				}
				else if (tree[p].son[0] && tree[p].son[1])
				{
					int d = (tree[tree[p].son[0]].random > tree[tree[p].son[1]].random);
					rotate(p,d);
					erase(tree[p].son[d], index);
				}
			}
			pushup(p);
		}
//OUTPUT
		void output()
		{
            FILE*fp = fopen("D:/zhangjunshuo_qt/myFirstWidgetProject/image/treap_searchTree_output_tempFile.dot","w+");
			fprintf(fp,"digraph zjs{\n");
			int numOfElement = num;
			for(int i=1; i<=num; i++)
			{
				if(tree[i].son[0]!=0)
					fprintf(fp,"%d->%d;\n",tree[i].element.first,tree[tree[i].son[0]].element.first);
				if(tree[i].son[1]!=0)
					fprintf(fp,"%d->%d;\n",tree[i].element.first,tree[tree[i].son[1]].element.first);
			}
			fprintf(fp,"}\n");
			fclose(fp);
            //system("dot D:/zhangjunshuo_qt/myFirstWidgetProject/image/treap_searchTree_output_tempFile.dot -T png -o D:/zhangjunshuo_qt/myFirstWidgetProject/image/zjs.png");
            WinExec("dot D:/zhangjunshuo_qt/myFirstWidgetProject/image/treap_searchTree_output_tempFile.dot -T png -o D:/zhangjunshuo_qt/myFirstWidgetProject/image/zjs.png", SW_HIDE);
		}

};
#endif
































