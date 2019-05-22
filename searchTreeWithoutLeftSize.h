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
		//leftup��rightupֻ����һ����NULL����ʾ�ýڵ��������ӽڵ�
		//ͬʱ�ܹ�ָ���Լ����ϼ��ڵ�
		searchTreeNode* left_up;
		searchTreeNode* right_up;
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
                //����indexɾ��pair
                {
                    if(num==-1)
                        throw "Erase an empty tree!\n";
                    searchTreeNode<I,V>* ptr = root;
                    while(1)
                    {
                        if(index < ptr->element.first)
                        {
                            if(ptr->left==NULL)
                                //��nodeʵ�ʲ�����
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
                            //�ҵ��˸�node
                            //���������ɾ��
                            if(ptr->left==NULL && ptr->right==NULL)
                                //��򵥵�Ҷ�ӽڵ�
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
                                        //ֻ���������ܷ����֪��ptr������һ����ڵ�
                                        //����һ���ҽڵ�
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
                                //��һ���ӽڵ㣬��Ϊ���ӽڵ�
                            {
                                //printf("2332\n");
                                //printf("ɾ����5\n");
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
                                //��һ���ӽڵ㣬��Ϊ���ӽڵ�
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
                                //�������ӽڵ�
                                //֮������else������Ϊ�ܵ���һ���Ѿ�ȷ��Ҫɾ�ľ���ptr��
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
                                        //printf("ɾ����3\n");
                                        //����replace_ptr��ֵ�滻��ptr��
                                        ptr->element = replace_ptr->element;
                                        //��ɾ��replace_ptr
                                        //replace_ptrһ�������ӽڵ㣡
                                        replace_ptr->left_up->left = NULL;
                                        //��һ����ʵ��ȫ����auto������ָ��
                                        //֮ǰһֱû��ôд����Ϊ�Ƚ��Ѷ������Լ�review��������
                                        //�����ȶ�ָ��re_ptr���ߣ�Ȼ��delete��ptr
                                        //delete replace_ptr;
                                        num--;
                                        break;
                                    }
                                    replace_ptr = replace_ptr->left;
                                }
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
		//����������������������ú���������дд���㲻����Ҳ������������Ǻ�
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





































