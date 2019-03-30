 // Morris.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "string"

class Node {
public:
	int value;
	Node* left;
	Node* right;
	Node(int val):value(val),left(NULL),right(NULL){ }
};

//中序遍历，左根右
static void morriesIn(Node* head) {
	if (head == nullptr)
		return;
	Node *cur1 = head;
	Node *cur2 = nullptr;
	while (cur1 != NULL) {
		cur2 = cur1->left;//2）如果有左孩子，找到左子树上最右的节点
		if (cur2 != NULL) {
			while (cur2->right != NULL && cur2->right != cur1) {
				cur2 = cur2->right;
			}
			if (cur2->right == NULL) {//第一次来到该节点
				cur2->right = cur1;
				cur1 = cur1->left;
				continue;
			}
			else {
				cur2->right = NULL;//第二次来到该节点
			}
		}
		std::cout << cur1->value << " ";
		cur1 = cur1->right;//1）如果没有左孩子，cur1向右移动
	}
}

//先序遍历,根左右
static void morriesPre(Node* head) {
	if (head == nullptr)
		return;
	Node *cur1 = head;
	Node *cur2 = nullptr;
	while (cur1 != NULL) {
		cur2 = cur1->left;//2）如果有左孩子，找到左子树上最右的节点
		if (cur2 != NULL) {
			while (cur2->right != NULL && cur2->right != cur1) {
				cur2 = cur2->right;
			}
			if (cur2->right == NULL) {//第一次来到该节点
				cur2->right = cur1;
				std::cout << cur1->value << " ";
				cur1 = cur1->left;
				continue;
			}
			else {
				cur2->right = NULL;//第二次来到该节点
			}
		}
		else {
			std::cout << cur1->value << " ";
		}
		cur1 = cur1->right;//1）如果没有左孩子，cur1向右移动
	}
}


int main()
{
	std::cout << "Hello World!\n";
	Node head = Node(4);
	head.left = new Node(2);
	head.right = new Node(6);
	head.left->left = new Node(1);
	head.left->right = new Node(3);
	head.right->left = new Node(5);
	head.right->right = new Node(7);
	std::cout << "中序遍历" << std::endl;
	morriesIn(&head);
	std::cout << std::endl;
	std::cout << "前序遍历" << std::endl;
	morriesPre(&head);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
