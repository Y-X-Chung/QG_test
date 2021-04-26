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
		cout << endl << "         *����������*" << endl << endl
			<< "      ��ɽ������²�����" << endl
			<< "       1. ��ʼ������������" << endl
			<< "       2. ��������" << endl
			<< "       3. ��������" << endl
			<< "       4. ɾ������" << endl
			<< "       5. �ݹ�ǰ�����" << endl
			<< "       6. �ݹ��������" << endl
			<< "       7. �ݹ�������" << endl
			<< "       8. ����ǰ�����" << endl
			<< "       9. �����������" << endl
			<< "       10. �����������" << endl
			<< "       11. �������" << endl 
			<< "       12. �˳�����" << endl << endl
			<< "      ����������Ҫ�Ĳ�����" << endl
			<< "       ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case(1):
			judge = BST_init(&root);
			if (judge)
			{
				cout << "      ��ʼ���ɹ�" << endl;
			}
			else
			{
				cout << "      ��ʼ��ʧ��" << endl;
			}
			break;

		case(2):
			cout << "      ���������������֣�" << endl << "       ";
			cin >> value;
			cout << endl;
			judge = BST_insert(&root, value);
			if (judge)
			{
				cout << "      ����ɹ�" << endl;
			}
			else
			{
				cout << "      ����ʧ��" << endl;
			}
			break;

		case(3):
			cout << "      ����������ҵ����֣�" << endl << "       ";
			cin >> value;
			cout << endl;
			judge = BST_search(&root, value);
			if (judge)
			{
				cout << "      ���ҳɹ��������ִ����ڶ�����������" << endl;
			}
			else
			{
				cout << "      ����ʧ�ܣ������ֲ������ڶ�����������" << endl;
			}
			break;

		case(4):
			cout << "      ��������ɾ�������֣�" << endl << "       ";
			cin >> value;
			cout << endl;
			judge = BST_delete(&root, value);
			if (judge)
			{
				cout << "      ɾ���ɹ�" << endl;
			}
			else
			{
				cout << "      ɾ��ʧ��" << endl;
			}
			break;

		case(5):
			cout << "      �ݹ�ǰ��������Ϊ��" << endl;
			cout << "       ";
			BST_preorderR(&root, visit);
			cout << endl;
			break;

		case(6):
			cout << "      �ݹ�����������Ϊ��" << endl;
			cout << "       ";
			BST_inorderR(&root, visit);
			cout << endl;
			break;

		case(7):
			cout << "      �ݹ����������Ϊ��" << endl;
			cout << "       ";
			BST_postorderR(&root, visit);
			cout << endl;
			break;

		case(8):
			cout << "      ����ǰ��������Ϊ��" << endl;
			cout << "       ";
			BST_preorderI(&root, visit);
			cout << endl;
			break;

		case(9):
			cout << "      ��������������Ϊ��" << endl;
			cout << "       ";
			BST_inorderI(&root, visit);
			cout << endl;
			break;

		case(10):
			cout << "      ��������������Ϊ��" << endl;
			cout << "       ";
			BST_postorderI(&root, visit);
			cout << endl;
			break;

		case(11):
			cout << "      ����������Ϊ��" << endl;
			cout << "       ";
			BST_levelOrder(&root, visit);
			cout << endl;
			break;

		case(12):
			cout << "      ���򼴽��˳�" << endl;			
			break;
		
		}
		if (choice == 12)
		{
			break;
		}
		if (choice > 12)
		{
			cout << "      �Բ��𣬲�֪����Ҫ����ʲô����" << endl;
		}
		cout << "      ";
		system("pause");
		system("cls");
	}
	return 0;
}