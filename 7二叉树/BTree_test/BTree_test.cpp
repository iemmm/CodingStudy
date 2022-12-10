#include <iostream>
#include <queue>
using namespace std;
//二叉树节点定义
struct BiTNode//二叉树的结点数据结构
{
	int data;
	BiTNode *lchild, *rchild;
};

//按层序输入，结点为空时，输入'#'
BiTNode *CreateBiTree(int *a, int n, int start)//*a为data，n为数组长度，start为根节点
{
    int temp = a[start];
    // std::cout<<temp<<std::endl;
	if (a[start] == '#')return NULL;//当根节点为空，即空树

	BiTNode* root = new BiTNode;//新建一个根结点
	root->data = a[start];//给根结点root的成员变量data,lchild,rchild赋初值
	root->lchild = NULL;
	root->rchild = NULL;

	int lnode = 2 * start + 1;//用根节点确定左节点的位置
	int rnode = 2 * start + 2;//用根节点确定右节点的位置

	if (lnode > n - 1) root->lchild = NULL;
	else root->lchild = CreateBiTree(a, n, lnode);//lnode替换start，为左子树的根节点

	if (rnode > n - 1) root->rchild = NULL;
	else root->rchild = CreateBiTree(a, n, rnode);//rnode替换start，为右子树的根节点

	return root;
}

//先序遍历函数（递归完成）
void PreOrderTraverse(BiTNode *T)
{
	if (T){
		cout << T->data << " ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

//层序遍历--队列
void LevelOrderTraverse(BiTNode *T)
{
	queue<BiTNode *> Q;//定义一个queue二叉树对象Q
	if (T == NULL) return;
	Q.push(T);//入队根指针  push：入队
	while (!Q.empty()){
		BiTNode *cur = Q.front();//当前指针指向队列的第一个元素
		Q.pop();// pop：出队
		cout << cur->data << " ";
		if (cur->lchild) Q.push(cur->lchild);
		if (cur->rchild) Q.push(cur->rchild);
	}
	cout << endl;
}


void test1(){
	BiTNode *t;
	int data[] = { 1, 2, 3, 4, 5, '#', 6, '#', '#', 7, 8 };
	//前序遍历：1 2 4 5 7 8 3 6
	t = CreateBiTree(data, sizeof(data) / sizeof(data[0]), 0);

	printf("The pre order is :   ");
	PreOrderTraverse(t);
	// cout << endl;

	// printf("The level order is : ");
	// LevelOrderTraverse(t);
}

void test2(){
	BiTNode *t;
	int data[] = { 1, 2, 3, 4, 5, '#', 6, 7 };
	//前序遍历：1 2 4 7 5 3 6
	t = CreateBiTree(data, sizeof(data) / sizeof(data[0]), 0);

	printf("The pre order is :   ");
	PreOrderTraverse(t);
	cout << endl;

	printf("The level order is : ");
	LevelOrderTraverse(t);
}
int main()
{
	test1();
	// test2();

	return 0;
}
