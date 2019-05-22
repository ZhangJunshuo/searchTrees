#ifndef SVARCHTREEWITHLEFTSIZE_H
#define SVARCHTREEWITHLEFTSIZE_H
#include<iostream>
#include<vector>
#include<windows.h>
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
		//leftSize
		int leftSize = 0;
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
//size
		int size()
		{
			return num;
		}
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
						//既然已经比ptr小了，那就必然要左走，而插入又不可能失败，所以ptrleftSize可以放心++
						ptr->leftSize++;
						//考虑完所有情况，发现这需要这一行就可以在insert里完美维护leftSize了
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
                    if(num==0)
                        printf( "Erase an empty tree!\n");
                    searchTreeNode<I,V>* ptr = root;
                    while(1)
                    {
                        if(index < ptr->element.first)
                        {
                            if(ptr->left==NULL)
                                //该node实际不存在
                                printf( "Node doesnt exist!\n");
                            else
                                ptr = ptr->left;
                        }
                        else if(index > ptr->element.first)
                        {
                            if(ptr->right==NULL)
                                printf( "Node doesnt exist!\n");
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
//下面是索引二叉搜索树的特色操作
//elementOfRank
		pair<I,V> elementOfRank(int rank)
		//输出升序排名第rank的元素
		{
			rank--;
			if(rank<0)
				throw "Wrong rank!\n";
			//因为leftSize都是从0开始的，所以rank要减一
			//rank=2实际上是想找排第二的元素，但是如果他是根，那他的leftSize应该是1
			auto ptr = root;
			while(1)
			{
				if(rank==ptr->leftSize)
					return ptr->element;
				else if(rank<ptr->leftSize)
				{
					if(ptr->left!=NULL)
						ptr = ptr->left;
					else
						throw "Wrong rank!\n";
				}
				else if(rank>ptr->leftSize)
				{
					rank = rank - (ptr->leftSize + 1);
					if(ptr->right!=NULL)
						ptr = ptr->right;
					else
						throw "Wrong rank!\n";
				}
			}
		}
//rankOf
//		int rankOf(I index)
//		//查询关键字index的元素的排名
//		//这里返回的rank不是树中索引，而是树中索引+1
//		//也就是这里返回的rank是从1开始数的
//		{
//思路错了，全部爆炸 
//			auto ptr = root;
//			int rank = 0;
//			while(1)
//			{
//				if(ptr->element.first == index)
//					//找到该index对应的node
//					//输出它的rank
//				{
//					return rank+1;
//				}
//				else if(index < ptr->element.first)
//				{
//					if(ptr->left!=NULL)
//						ptr = ptr->left;
//					else
//						throw "Wrong index!\n";
//				}
//				else if(index > ptr->element.first)
//				{
//					if(ptr->right!=NULL)
//					{
//						//我发现了个规律
//						//就是先假设肯定能找到这个index的node
//						//然后只要往右走了，那就把rank加上这个需要进右子树的node的leftSize+1,
//						//最后就能得到索引，再把索引+1输出就是rank！
//						//向左走不用管！
//						rank = rank + ptr->leftSize + 1;
//						ptr = ptr->right;
//					}
//					else
//						throw "Wrong index!\n";
//				}
//			}
//		
//		}
	private:
//innerRankOf
		int innerRankOf(I index, searchTreeNode<I,V>* _ptr)
		//被迫改成递归形态 
		//这个_ptr不能让用户乱传，严格来说就是不能让用户自己传
		//_ptr必须得从root开始递归 
		{
			if(index==_ptr->element.first)
				return _ptr->leftSize+1;
			else if(index < _ptr->element.first)
			{
				return innerRankOf(index, _ptr->left);
			}
			else if(index > _ptr->element.first)
			{
				return innerRankOf(index, _ptr->right) + _ptr->leftSize + 1;
			}
		}
	public:
//rankOf
		int rankOf(I index)
		{
			auto ptr = root;
			return innerRankOf(index, ptr);
			//不得已写成这样，否则就会编译报错，
			//没时间深究了
			//不求甚解！ 
		}
//elementBefore
		pair<I,V> elementBefore(I index)
		//输出排名在关键字index的元素之前的元素
		{
			return elementOfRank( rankOf(index)-1 );
			//复杂度比较高
		}
//elementBehind
		pair<I,V> elementBehind(I index)
		//输出排名在关键字index的元素之后的元素
		{
			return elementOfRank( rankOf(index)+1 );
		}
//outputByOrder
		void outputByOrder()
		//升序输出所有元素
		{
			for(int i=1; i<=num; i++)
				cout << elementOfRank(i).first << "," << elementOfRank(i).second << endl;
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
        void preOrderForFind(searchTreeNode<I,V>* ptr, FILE*fp, pair<int,char> _element)
        {
            if(ptr!=NULL)
            {
                if(ptr->left!=NULL)
                {
                    if(ptr->left->element.first == _element.first)
                    {
                        fprintf(fp,"%d->%d [color=\"red\"];\n",ptr->element.first,ptr->left->element.first);
                    }
                    else
                    {
                        fprintf(fp,"%d->%d;\n",ptr->element.first,ptr->left->element.first);
                    }
                }
                if(ptr->right!=NULL)
                {
                    if(ptr->right->element.first == _element.first)
                    {
                        fprintf(fp,"%d->%d [color=\"red\"];\n",ptr->element.first,ptr->right->element.first);
                    }
                    else
                    {
                        fprintf(fp,"%d->%d;\n",ptr->element.first,ptr->right->element.first);
                    }
                }
                preOrderForFind(ptr->left,fp, _element);
                preOrderForFind(ptr->right,fp, _element);
            }
        }
	public:
//output
		void output()
		//按照索引升序输出，调试用函数，随意写写，搞不好我也不安升序输出呵呵
		{
            FILE*fp = fopen("D:/zhangjunshuo_qt/myFirstWidgetProject/image/indexSearchTree_output_tempFile.dot","w+");
			fprintf(fp,"digraph zjs{\n");
			auto ptr = root;
			preOrder(ptr,fp);
			fprintf(fp,"}\n");
			fclose(fp);
            WinExec("dot D:/zhangjunshuo_qt/myFirstWidgetProject/image/indexSearchTree_output_tempFile.dot -T png -o D:/zhangjunshuo_qt/myFirstWidgetProject/image/indexSearchTreezjs.png", SW_HIDE);
        }
        void outputForFind(pair<int,char> _element)
        {
            FILE*fp = fopen("D:/zhangjunshuo_qt/myFirstWidgetProject/image/indexSearchTree_output_tempFile.dot","w+");
            fprintf(fp,"digraph zjs{\n");
            auto ptr = root;
            preOrderForFind(ptr,fp, _element);
            fprintf(fp,"}\n");
            fclose(fp);
            WinExec("dot D:/zhangjunshuo_qt/myFirstWidgetProject/image/indexSearchTree_output_tempFile.dot -T png -o D:/zhangjunshuo_qt/myFirstWidgetProject/image/indexSearchTreezjs.png", SW_HIDE);
        }
};
#endif // SVARCHTREEWITHLEFTSIZE_H





































