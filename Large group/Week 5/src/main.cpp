#include<iostream>
#include"binary_sort_tree.h"
#include"LinkStack.h"
using namespace std;

int main()
{
	BinarySortTree root;
	ElemType value;
	int choice, judge;
	void visit(NodePtr n);
	while (1)
	{
		cout << endl << "         *二叉排序树*" << endl << endl
			<< "      你可进行以下操作：" << endl
			<< "       1. 初始化二叉排序树" << endl
			<< "       2. 插入数字" << endl
			<< "       3. 查找数字" << endl
			<< "       4. 删除数字" << endl
			<< "       5. 递归前序遍历" << endl
			<< "       6. 递归中序遍历" << endl
			<< "       7. 递归后序遍历" << endl
			<< "       8. 迭代前序遍历" << endl
			<< "       9. 迭代中序遍历" << endl
			<< "       10. 迭代后序遍历" << endl
			<< "       11. 层序遍历" << endl 
			<< "       12. 退出程序" << endl << endl
			<< "      请输入你想要的操作：" << endl
			<< "       ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case(1):
			judge = BST_init(&root);
			if (judge)
			{
				cout << "      初始化成功" << endl;
			}
			else
			{
				cout << "      初始化失败" << endl;
			}
			break;

		case(2):
			cout << "      请输入需插入的数字：" << endl << "       ";
			cin >> value;
			cout << endl;
			judge = BST_insert(&root, value);
			if (judge)
			{
				cout << "      插入成功" << endl;
			}
			else
			{
				cout << "      插入失败" << endl;
			}
			break;

		case(3):
			cout << "      请输入需查找的数字：" << endl << "       ";
			cin >> value;
			cout << endl;
			judge = BST_search(&root, value);
			if (judge)
			{
				cout << "      查找成功，该数字存在于二叉排序树中" << endl;
			}
			else
			{
				cout << "      查找失败，该数字不存在于二叉排序树中" << endl;
			}
			break;

		case(4):
			cout << "      请输入需删除的数字：" << endl << "       ";
			cin >> value;
			cout << endl;
			judge = BST_delete(&root, value);
			if (judge)
			{
				cout << "      删除成功" << endl;
			}
			else
			{
				cout << "      删除失败" << endl;
			}
			break;

		case(5):
			cout << "      递归前序遍历结果为：" << endl;
			cout << "       ";
			BST_preorderR(&root, visit);
			cout << endl;
			break;

		case(6):
			cout << "      递归中序遍历结果为：" << endl;
			cout << "       ";
			BST_inorderR(&root, visit);
			cout << endl;
			break;

		case(7):
			cout << "      递归后序遍历结果为：" << endl;
			cout << "       ";
			BST_postorderR(&root, visit);
			cout << endl;
			break;

		case(8):
			cout << "      迭代前序遍历结果为：" << endl;
			cout << "       ";
			BST_preorderI(&root, visit);
			cout << endl;
			break;

		case(9):
			cout << "      迭代中序遍历结果为：" << endl;
			cout << "       ";
			BST_inorderI(&root, visit);
			cout << endl;
			break;

		case(10):
			cout << "      迭代后序遍历结果为：" << endl;
			cout << "       ";
			BST_postorderI(&root, visit);
			cout << endl;
			break;

		case(11):
			cout << "      层序遍历结果为：" << endl;
			cout << "       ";
			BST_levelOrder(&root, visit);
			cout << endl;
			break;

		case(12):
			cout << "      程序即将退出" << endl;			
			break;
		
		}
		if (choice == 12)
		{
			break;
		}
		if (choice > 12)
		{
			cout << "      对不起，不知道你要进行什么操作" << endl;
		}
		cout << "      ";
		system("pause");
		system("cls");
	}
	return 0;
}