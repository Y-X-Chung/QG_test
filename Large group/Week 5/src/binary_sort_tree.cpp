#include<iostream>
#include <queue>
#include"binary_sort_tree.h"
#include"LinkStack.h"
using namespace std;

Status BST_init(BinarySortTreePtr r)
{
	r->root = NULL;
	return succeed;
}

int find_insert(NodePtr* r, ElemType v)
{
	if ((*r) == NULL)
	{
		(*r) = new Node;
		(*r)->left = NULL;
		(*r)->right = NULL;
		(*r)->value = v;
		return 1;
	}
	else if (v == (*r)->value)
	{
		return 0;
	}
	else if (v <= (*r)->value)
	{
		/*if ((*r)->left == NULL)
		{
			(*r)->left = new Node;
		}*/

		find_insert(&((*r)->left), v);
	}
	else if (v > (*r)->value)
	{
		/*if ((*r)->right == NULL)
		{
			(*r)->right = new Node;
		}*/

		find_insert(&((*r)->right), v);
	}
}

Status BST_insert(BinarySortTreePtr r, ElemType v)
{
	int i = find_insert(&r->root, v);
	if (i == 1)
	{
		return succeed;
	}
	else
	{
		return failed;
	}
	/*if (r->root->value == NULL)
	{
		r->root->value = v;
	}
	else if(v <= r->root->value)
	{
		if (r->root->left == NULL)
		{
			r->root->left = new Node;
		}
		
		insert(r->root->left, v);
	}
	else if (v > r->root->value)
	{
		if (r->root->right == NULL)
		{
			r->root->right = new Node;
		}

		insert(r->root->right, v);
	}*/
}

//int reconnect(NodePtr p, ElemType v)
//{
//	int judge = 1;
//	while (v != p->value)
//	{
//		if (v < p->value)
//		{
//			if (!p->left)
//			{
//				judge = 0;
//				break;
//			}
//			p = p->left;
//		}
//		else
//		{
//			if (!p->right)
//			{
//				judge = 0;
//				break;
//			}
//			p = p->right;
//		}
//	}
//	if (judge)
//	{
//		if (!p->left)
//		{
//			p = p->right;
//			delete(p->right);
//		}
//		else
//		{
//			NodePtr q = p->left;
//			while (q->right)
//			{
//				q = q->right;
//			}
//			int va = q->value;
//			q->value = p->value;
//			p->value = va;
//			if (!q->left)
//			{
//				delete(q);
//				return judge;
//			}
//			else
//			{
//				reconnect(q, va);
//			}
//		}
//	}
//	else
//	{
//		return judge;
//	}
//}

Status BST_delete(BinarySortTreePtr r, ElemType v)
{
	NodePtr p = r->root;
	bool judge = 1;
	if (p == NULL)
	{
		judge = 0;
	}
	else
	{
		while (v != p->value)
		{
			if (v < p->value)
			{
				if (p->left == NULL)
				{
					judge = 0;
					break;
				}
				p = p->left;
			}
			else
			{
				if (p->right == NULL)
				{
					judge = 0;
					break;
				}
				p = p->right;
			}
		}
	}
	if (judge == 1)
	{
		if (p->left == NULL && p->right == NULL)
		{
			p = NULL;
		}
		else if (p->left == NULL && p->right != NULL)
		{
			NodePtr q = p->right;
			p->right = NULL;
			p = q;
			delete(q);
			return succeed;
		}
		else if (p->right == NULL && p->left != NULL)
		{
			NodePtr q = p->left;
			p->left = NULL;
			p = q;
			delete(q);
			return succeed;
		}
		else
		{
			NodePtr q = p->left;
			while (q->right != NULL)
			{
				q = q->right;
			}
			int va = q->value;
			q->value = p->value;
			p->value = va;
			if (q->left == NULL)
			{
				q = NULL;
				return succeed;
			}
			else
			{
				NodePtr o = q->left;
				q->left = NULL;
				q = o;
				delete(o);
				return succeed;
			}
		}
	}
	else
	{
		return failed;
	}
}


Status BST_search(BinarySortTreePtr r, ElemType v)
{
	NodePtr p = r->root;
	bool judge = 1;
	if (p == NULL)
	{
		judge = 0;
	}
	else
	{
		while (v != p->value)
		{
			if (v < p->value)
			{
				if (p->left ==NULL)
				{
					judge = 0;
					break;
				}
				p = p->left;
			}
			else
			{
				if (p->right == NULL)
				{
					judge = 0;
					break;
				}
				p = p->right;
			}
		}
	}
	if (judge)
	{
		return succeed;
	}
	else
	{
		return failed;
	}
}

void visit(NodePtr n)
{
	cout << n->value << "   ";
}

void Stack_Push_pre(NodePtr bn, void (*visit)(NodePtr))
{
	LinkStack s;
	initLStack(&s);
	pushLStack(&s, bn->value);
	while (isEmptyLStack(&s))
	{
		ElemType e;
		getTopLStack(&s, &e);
		NodePtr sn = new Node;
		sn->value = e;
		if (sn == NULL)
		{
			continue;
		}
		visit(sn);
		popLStack(&s);
		if (bn->left != NULL)
		{
			Stack_Push_pre(bn->left, visit);
		}
		if (bn->right != NULL)
		{
			Stack_Push_pre(bn->right, visit);
		}
	}
}

Status BST_preorderI(BinarySortTreePtr r, void (*visit)(NodePtr))
{
	Stack_Push_pre(r->root, visit);
	return succeed;
}

void NLRTraversal(NodePtr n, void (*visit)(NodePtr))
{
	if (n == NULL)
	{
		return;
	}
	else
	{
		visit(n);
		NLRTraversal(n->left, visit);
		NLRTraversal(n->right, visit);
	}
}

Status BST_preorderR(BinarySortTreePtr r, void (*visit)(NodePtr))
{
	if (!r)
	{
		return failed;
	}
	else
	{
		NLRTraversal(r->root, visit);
	}
	return succeed;
}

void Stack_Push_in(NodePtr bn, void (*visit)(NodePtr))
{
	LinkStack s;
	initLStack(&s);
	pushLStack(&s, bn->value);
	while (isEmptyLStack(&s))
	{
		if (bn->left != NULL)
		{
			Stack_Push_in(bn->left, visit);
		}
		ElemType e;
		getTopLStack(&s, &e);
		NodePtr sn;
		sn = new Node;
		sn->value = e;
		if (sn == NULL)
		{
			continue;
		}
		visit(sn);
		popLStack(&s);
		if (bn->right != NULL)
		{
			Stack_Push_in(bn->right, visit);
		}
	}
}

Status BST_inorderI(BinarySortTreePtr r, void (*visit)(NodePtr))
{
	Stack_Push_in(r->root, visit);
	return succeed;
}

void LNRTraversal(NodePtr n, void (*visit)(NodePtr))
{
	if (n == NULL)
	{
		return;
	}
	else
	{
		NLRTraversal(n->left, visit);
		visit(n);
		NLRTraversal(n->right, visit);
	}
}

Status BST_inorderR(BinarySortTreePtr r, void (*visit)(NodePtr))
{
	if (!r)
	{
		return failed;
	}
	else
	{
		LNRTraversal(r->root, visit);
	}
	return succeed;
}

void Stack_Push_post(NodePtr bn, void (*visit)(NodePtr))
{
	LinkStack s;
	initLStack(&s);
	pushLStack(&s, bn->value);
	while (isEmptyLStack(&s))
	{
		if (bn->left != NULL)
		{
			Stack_Push_post(bn->left, visit);
		}
		if (bn->right != NULL)
		{
			Stack_Push_post(bn->right, visit);
		}
		ElemType e;
		getTopLStack(&s, &e);
		NodePtr sn = new Node;
		sn->value = e;
		if (sn == NULL)
		{
			continue;
		}
		visit(sn);
		popLStack(&s);
	}
}


Status BST_postorderI(BinarySortTreePtr r, void (*visit)(NodePtr))
{
	Stack_Push_post(r->root, visit);
	return succeed;
}

void LRNTraversal(NodePtr n, void (*visit)(NodePtr))
{
	if (n == NULL)
	{
		return;
	}
	else
	{
		NLRTraversal(n->left, visit);
		NLRTraversal(n->right, visit);
		visit(n);
	}
}

Status BST_postorderR(BinarySortTreePtr r, void (*visit)(NodePtr))
{
	if (!r)
	{
		return failed;
	}
	else
	{
		LRNTraversal(r->root, visit);
	}
	return succeed;
}

Status BST_levelOrder(BinarySortTreePtr r, void (*visit)(NodePtr))
{
	NodePtr n = r->root;
	queue <NodePtr> s;
	s.push(n);
	while (!s.empty())
	{
		n = s.front();
		s.pop();
		if (n->left != NULL) s.push(n->left);
		if (n->right != NULL) s.push(n->right);
		visit(n);
	}
	return succeed;
}





