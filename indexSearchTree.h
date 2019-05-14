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
		//leftup��rightupֻ����һ����NULL����ʾ�ýڵ��������ӽڵ�
		//ͬʱ�ܹ�ָ���Լ����ϼ��ڵ�
		searchTreeNode* left_up;
		searchTreeNode* right_up;
		//leftSize
		int leftSize = 0;
		//���캯��
		searchTreeNode()
			:left(NULL),right(NULL),left_up(NULL),right_up(NULL) {}
};
template<typename I, typename V>
class searchTree
{
	private:
		searchTreeNode<I,V>* root = NULL;
		int num = 0;	//Ԫ�ظ���
	public:
//size
		int size()
		{
			return num;
		}
//insert
		void insert(pair<I,V> _element)
		//����pair����������ͬ��value��������ͬ��index�͸���value
		{
			if(root==NULL)
			{
				//����ʱrootΪ��
				root = new searchTreeNode<I,V>;
				root->element = _element;
			}
			else
			{
				//����ʱroot����
				searchTreeNode<I,V>* ptr = root;
				//pre_ptr��Զ�ͺ���ptrһ��
				//���ڲ���ʱ����nodeָʾ�����ϼ�node�ĵ�ַ
				auto pre_ptr = root;
				while(1)
				{
					if(_element.first < ptr->element.first)
					{
						//��Ȼ�Ѿ���ptrС�ˣ��Ǿͱ�ȻҪ���ߣ��������ֲ�����ʧ�ܣ�����ptrleftSize���Է���++
						ptr->leftSize++;
						//�����������������������Ҫ��һ�оͿ�����insert������ά��leftSize��
						if(ptr->left==NULL)
						{
							ptr->left = new searchTreeNode<I,V>;
							ptr->left->element = _element;
							ptr->left->left_up = pre_ptr;
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
							ptr->right->right_up = pre_ptr;
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
		//����indexɾ��pair
		{
			if(num==0)
				throw "Erase an empty tree!\n";
			searchTreeNode<I,V>* ptr = root;
			//��һ��searchTreeNode<I,V>*��vector�����ڱ���ɾ�����Ա�ά��leftSize
			vector< searchTreeNode<I,V>* > deleteNodePath;
			//��ʼɾ��
			while(1)
			{
				if(index < ptr->element.first)
				{
					if(ptr->left==NULL)
					{
						//��nodeʵ�ʲ�����
						throw "Node doesnt exist!\n";
						//ɾ��ʧ�ܣ����ø����κ�һ�����leftSize
						//throw��ʹ����������ֹ
					}
					else
					{
						//��ʱҪ����·�����Ա����ɾ����Ϻ�ά��leftSize
						deleteNodePath.push_back(ptr);
						//ֻƾ��һ���¼��ʵ����ȫ��
						//����ɾ���������ӽڵ�Ľڵ���������Ϊ���ô������������������ߵ��ף����������ﻹ�ü�¼
						ptr = ptr->left;
					}
				}
				else if(index > ptr->element.first)
				{
					if(ptr->right==NULL)
					{
						throw "Node doesnt exist!\n";
						//ɾ��ʧ�ܣ����ø����κ�һ�����leftSize
					}
					else
					{
						//���߲�����¼������
						//��Ϊ���ߵ�node��leftSZie��������Ӱ�죡
						ptr = ptr->right;
					}
				}
				else
				{
					//�ҵ��˸�node
					//���������ɾ��
					if(ptr->left==NULL && ptr->right==NULL)
						//��򵥵�Ҷ�ӽڵ�
					{
						if(ptr==root)
						{
							root = NULL;
							delete ptr;
						}
						else
						{
							if(ptr->left_up!=NULL)
							{
								//ֻ���������ܷ����֪��ptr������һ����ڵ�
								//����һ���ҽڵ�
								auto up_ptr = ptr->left_up;
								up_ptr->left = NULL;
								delete ptr;
								num--;
								break;
							}
							else
							{
								auto up_ptr = ptr->right_up;
								up_ptr->right = NULL;
								delete ptr;
								num--;
								break;
							}
						}
					}
					else if(ptr->left!=NULL && ptr->right==NULL)
						//��һ���ӽڵ㣬��Ϊ���ӽڵ�
					{
						if(ptr->left_up!=NULL)
						{
							auto up_ptr = ptr->left_up;
							up_ptr->left = ptr->left;
							delete ptr;
							num--;
							break;
						}
						else
						{
							auto up_ptr = ptr->right_up;
							up_ptr->right = ptr->left;
							delete ptr;
							num--;
							break;
						}
					}
					else if(ptr->left==NULL && ptr->right!=NULL)
						//��һ���ӽڵ㣬��Ϊ���ӽڵ�
					{
						if(ptr->left_up!=NULL)
						{
							auto up_ptr = ptr->left_up;
							up_ptr->left = ptr->right;
							delete ptr;
							num--;
							break;
						}
						else
						{
							auto up_ptr = ptr->right_up;
							up_ptr->right = ptr->right;
							delete ptr;
							num--;
							break;
						}
					}
					else
						//�������ӽڵ�
						//֮������else������Ϊ�ܵ���һ���Ѿ�ȷ��Ҫɾ�ľ���ptr��
					{
						auto replace_ptr = ptr->right;
						while(1)
						{
							if(replace_ptr->left==NULL)
							{
								//����replace_ptr��ֵ�滻��ptr��
								ptr->element = replace_ptr->element;
								//��ɾ��replace_ptr
								//replace_ptrһ�������ӽڵ㣡
								replace_ptr->left_up->left = NULL;
								//��һ����ʵ��ȫ����auto������ָ��
								//֮ǰһֱû��ôд����Ϊ�Ƚ��Ѷ������Լ�review��������
								//�����ȶ�ָ��re_ptr���ߣ�Ȼ��delete��ptr
								delete replace_ptr;
								num--;
								break;
							}
							//�ڴ˴����ü�¼·����
							deleteNodePath.push_back(replace_ptr);
							replace_ptr = replace_ptr->left;
						}
					}
					//��һ������������Ĺ�һ��ɾ�����֮��ά��·�������е��leftSize����Ҫ����һ������ˡ�
					auto iter = deleteNodePath.begin();
					while(iter!=deleteNodePath.end())
					{
						(*iter)->leftSize--;
					}
				}
			}
			//break֮�󵽴��λ��
			//�ɼ�break���൱�ں�������return
		}
//elementOf
		pair<I,V> elementOf(I index)
		//����index����pair
		{
			if(num==0)
				throw "Search an empty tree!\n";
			auto ptr = root;
			while(1)
			{
				if(ptr->element.first == index)
					return ptr->element;
				if(index < ptr->element.first)
					//��index��nodeӦ�������
				{
					if(ptr->left!=NULL)
						ptr = ptr->left;
					else
						throw "No such index!\n";
				}
				else
					//���ұ�
				{
					if(ptr->right!=NULL)
						ptr = ptr->right;
					else
						throw "No such index!\n";
				}
			}
		}
//������������������������ɫ����
//elementOfRank
		pair<I,V> elementOfRank(int rank)
		//�������������rank��Ԫ��
		{
			rank--;
			if(rank<0)
				throw "Wrong rank!\n";
			//��ΪleftSize���Ǵ�0��ʼ�ģ�����rankҪ��һ
			//rank=2ʵ�����������ŵڶ���Ԫ�أ�����������Ǹ���������leftSizeӦ����1
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
//		//��ѯ�ؼ���index��Ԫ�ص�����
//		//���ﷵ�ص�rank��������������������������+1
//		//Ҳ�������ﷵ�ص�rank�Ǵ�1��ʼ����
//		{
//˼·���ˣ�ȫ����ը 
//			auto ptr = root;
//			int rank = 0;
//			while(1)
//			{
//				if(ptr->element.first == index)
//					//�ҵ���index��Ӧ��node
//					//�������rank
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
//						//�ҷ����˸�����
//						//�����ȼ���϶����ҵ����index��node
//						//Ȼ��ֻҪ�������ˣ��ǾͰ�rank���������Ҫ����������node��leftSize+1,
//						//�����ܵõ��������ٰ�����+1�������rank��
//						//�����߲��ùܣ�
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
		//���ȸĳɵݹ���̬ 
		//���_ptr�������û��Ҵ����ϸ���˵���ǲ������û��Լ���
		//_ptr����ô�root��ʼ�ݹ� 
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
			//������д������������ͻ���뱨��
			//ûʱ�����
			//�������⣡ 
		}
//elementBefore
		pair<I,V> elementBefore(I index)
		//��������ڹؼ���index��Ԫ��֮ǰ��Ԫ��
		{
			return elementOfRank( rankOf(index)-1 );
			//���ӶȱȽϸ�
		}
//elementBehind
		pair<I,V> elementBehind(I index)
		//��������ڹؼ���index��Ԫ��֮���Ԫ��
		{
			return elementOfRank( rankOf(index)+1 );
		}
//outputByOrder
		void outputByOrder()
		//�����������Ԫ��
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
		//����������������������ú���������дд���㲻����Ҳ������������Ǻ�
		{
            FILE*fp = fopen("D:/zhangjunshuo_qt/myFirstWidgetProject/image/indexSearchTree_output_tempFile.dot","w+");
			fprintf(fp,"digraph zjs{\n");
			auto ptr = root;
			preOrder(ptr,fp);
			fprintf(fp,"}\n");
			fclose(fp);
            WinExec("dot D:/zhangjunshuo_qt/myFirstWidgetProject/image/indexSearchTree_output_tempFile.dot -T png -o D:/zhangjunshuo_qt/myFirstWidgetProject/image/zjs.png", SW_HIDE);
        }
        void outputForFind(pair<int,char> _element)
        {
            FILE*fp = fopen("D:/zhangjunshuo_qt/myFirstWidgetProject/image/indexSearchTree_output_tempFile.dot","w+");
            fprintf(fp,"digraph zjs{\n");
            auto ptr = root;
            preOrderForFind(ptr,fp, _element);
            fprintf(fp,"}\n");
            fclose(fp);
            WinExec("dot D:/zhangjunshuo_qt/myFirstWidgetProject/image/indexSearchTree_output_tempFile.dot -T png -o D:/zhangjunshuo_qt/myFirstWidgetProject/image/zjs.png", SW_HIDE);
        }
};
#endif // SVARCHTREEWITHLEFTSIZE_H





































