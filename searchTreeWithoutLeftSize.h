#ifndef SVARCHTREEWITHOUTLEFTSIZE_H
#define SVARCHTREEWITHOUTLEFTSIZE_H
#include<windows.h>
#include<iostream>
using namespace std;

template<typename I, typename V>
class searchTreeNode
{
	public:
		pair<I,V> element;
		searchTreeNode* left;
		searchTreeNode* right;
		//leftup和rightup只能有一个非NULL，表示该节点是左、右子节点
		//同时能够指回自己的上级节点
		searchTreeNode* left_up;
		searchTreeNode* right_up;
		//构造函数
		searchTreeNode()
			:left(NULL),right(NULL),left_up(NULL),right_up(NULL) {}
};
template<typename I, typename V>
class searchTree
{
	private:
		searchTreeNode<I,V>* root = NULL;
		int num = 0;	//元素个数
	public:
        //insert
                void insert(pair<I,V> _element)
                //插入pair，允许有相同的value，遇到相同的index就更新value
                {
                    if(root==NULL)
                    {
                        //插入时root为空
                        root = new searchTreeNode<I,V>;
                        root->element = _element;
                    }
                    else
                    {
                        //插入时root不空
                        searchTreeNode<I,V>* ptr = root;
                        //pre_ptr永远滞后于ptr一层
                        //用于插入时给新node指示它的上级node的地址
                        auto pre_ptr = root;
                        while(1)
                        {
                            if(_element.first < ptr->element.first)
                            {
                                if(ptr->left==NULL)
                                {
                                    ptr->left = new searchTreeNode<I,V>;
                                    ptr->left->element = _element;
                                    ptr->left->left_up = ptr;
                                    num++;
                                    break;
                                }
                                else
                                {
                                    pre_ptr = ptr;
                                    ptr = ptr->left;
                                }
                            }
                            else if(_element.first > ptr->element.first)
                            {
                                if(ptr->right==NULL)
                                {
                                    ptr->right = new searchTreeNode<I,V>;
                                    ptr->right->element = _element;
                                    ptr->right->right_up = ptr;
                                    num++;
                                    break;
                                }
                                else
                                {
                                    pre_ptr = ptr;
                                    ptr = ptr->right;
                                }
                            }
                            else
                            {
                                ptr->element = _element;
                                break;
                            }
                        }
                    }
                }
        //erase
                void erase(I index)
                //根据index删除pair
                {
                    if(num==-1)
                        throw "Erase an empty tree!\n";
                    searchTreeNode<I,V>* ptr = root;
                    while(1)
                    {
                        if(index < ptr->element.first)
                        {
                            if(ptr->left==NULL)
                                //该node实际不存在
                                throw "Node doesnt exist!\n";
                            else
                                ptr = ptr->left;
                        }
                        else if(index > ptr->element.first)
                        {
                            if(ptr->right==NULL)
                                throw "Node doesnt exist!\n";
                            else
                                ptr = ptr->right;
                        }
                        else
                        {
                            //找到了该node
                            //分三种情况删除
                            if(ptr->left==NULL && ptr->right==NULL)
                                //最简单的叶子节点
                            {
                                //printf("2331\n");
                                if(ptr==root)
                                {
                                    root = NULL;
                                    num -- ;
                                    //delete ptr;
                                    break;
                                }
                                else
                                {
                                    if(ptr->left_up!=NULL)
                                    {
                                        //printf("32\n");
                                        //只有这样才能方便地知道ptr到底是一个左节点
                                        //还是一个右节点
                                        //cout << ptr->element.first << endl;

                                        auto up_ptr = ptr->left_up;
                                        //cout << up_ptr->element.first << endl;
                                        up_ptr->left = NULL;
                                        //delete ptr;
                                        num--;
                                        break;
                                    }
                                    else
                                    {
                                        auto up_ptr = ptr->right_up;
                                        up_ptr->right = NULL;
                                        //delete ptr;
                                        num--;
                                        break;
                                    }
                                }
                            }
                            else if(ptr->left!=NULL && ptr->right==NULL)
                                //有一个子节点，且为左子节点
                            {
                                //printf("2332\n");
                                //printf("删的是5\n");
                                if(ptr->left_up!=NULL)
                                {
                                    //printf("zheli\n");
                                    auto up_ptr = ptr->left_up;
                                    up_ptr->left = ptr->left;
                                    //delete ptr;
                                    num--;
                                    break;
                                }
                                else if(ptr->right_up!=NULL)
                                {
                                    //printf("nali\n");
                                    auto up_ptr = ptr->right_up;
                                    up_ptr->right = ptr->left;
                                    //delete ptr;
                                    num--;
                                    break;
                                }
                                else
                                {
                                    root = ptr->left;
                                    num--;
                                    break;
                                }
                            }
                            else if(ptr->left==NULL && ptr->right!=NULL)
                                //有一个子节点，且为右子节点
                            {
                                //printf("2333\n");
                                if(ptr->left_up!=NULL)
                                {
                                    auto up_ptr = ptr->left_up;
                                    up_ptr->left = ptr->right;
                                    //delete ptr;
                                    num--;
                                    break;
                                }
                                else if(ptr->right_up!=NULL)
                                {
                                    auto up_ptr = ptr->right_up;
                                    up_ptr->right = ptr->right;
                                    //delete ptr;
                                    num--;
                                    break;
                                }
                                else
                                {
                                    root = ptr->right;
                                    num--;
                                    break;
                                }
                            }
                            else
                                //有两个子节点
                                //之所以用else，是因为能到这一层已经确定要删的就是ptr了
                            {
                                //printf("2334\n");
                                auto replace_ptr = ptr->right;
                                if(replace_ptr->left==NULL)
                                {
                                    ptr->element = replace_ptr->element;
                                    replace_ptr->right_up->right = NULL;
                                    num--;
                                    break;
                                }
                                while(1)
                                {
                                    if(replace_ptr->left==NULL)
                                    {
                                        //printf("删的是3\n");
                                        //先用replace_ptr的值替换掉ptr的
                                        ptr->element = replace_ptr->element;
                                        //再删掉replace_ptr
                                        //replace_ptr一定是左子节点！
                                        replace_ptr->left_up->left = NULL;
                                        //这一步其实完全不用auto申请新指针
                                        //之前一直没这么写是因为比较难懂，怕自己review看不明白
                                        //就是先断指向re_ptr的线，然后delete该ptr
                                        //delete replace_ptr;
                                        num--;
                                        break;
                                    }
                                    replace_ptr = replace_ptr->left;
                                }
                            }
                        }
                    }
                    //break之后到达的位置
                    //可见break就相当于函数结束return
                }
//elementOf
		pair<I,V> elementOf(I index)
		//根据index返回pair
		{
			if(num==0)
				throw "Search an empty tree!\n";
			auto ptr = root;
			while(1)
			{
				if(ptr->element.first == index)
					return ptr->element;
				if(index < ptr->element.first)
					//则index的node应该在左边
				{
					if(ptr->left!=NULL)
						ptr = ptr->left;
					else
						throw "No such index!\n";
				}
				else
					//在右边
				{
					if(ptr->right!=NULL)
						ptr = ptr->right;
					else
						throw "No such index!\n";
				}
			}
		}
		private:
//preOrder
		void preOrder(searchTreeNode<I,V>* ptr, FILE*fp)
		{
			if(ptr!=NULL)
			{
				if(ptr->left!=NULL)
					fprintf(fp,"%d->%d;\n",ptr->element.first,ptr->left->element.first);
				if(ptr->right!=NULL)
					fprintf(fp,"%d->%d;\n",ptr->element.first,ptr->right->element.first);
				preOrder(ptr->left,fp);
				preOrder(ptr->right,fp);
			}
		}
		public:
//output
		void output()
		//按照索引升序输出，调试用函数，随意写写，搞不好我也不安升序输出呵呵
		{
            FILE*fp = fopen("D:/zhangjunshuo_qt/myFirstWidgetProject/image/searchTree_output_tempFile.dot","w+");
			fprintf(fp,"digraph zjs{\n");
			auto ptr = root;
			preOrder(ptr,fp);
			fprintf(fp,"}\n");
			fclose(fp);
            //system("dot D:/zhangjunshuo_qt/myFirstWidgetProject/image/searchTree_output_tempFile.dot -T png -o D:/zhangjunshuo_qt/myFirstWidgetProject/image/zjs.png");
            WinExec("dot D:/zhangjunshuo_qt/myFirstWidgetProject/image/searchTree_output_tempFile.dot -T png -o D:/zhangjunshuo_qt/myFirstWidgetProject/image/zjs.png", SW_HIDE);
		}
};
#endif // SVARCHTREEWITHOUTLEFTSIZE_H





































