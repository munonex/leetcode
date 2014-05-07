#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void coutList(ListNode* head)
{
	ListNode* curNode = head;
	while(curNode)
	{
		cout << curNode->val << " ";
		curNode = curNode->next;
	}
	cout << endl;
}

void getHalf(ListNode* &half, ListNode* &end)
{
	if(!end)
		return;
	bool count = false;
	while(end->next)
	{
		if(count)
		{
			half = half->next;
			count = false;
		}
		else
		{
			count = true;
		}
		end = end->next;
	}
	
}

ListNode* reverseList(ListNode *head)
{
	if(!head)
		return head;
	ListNode *cur = head;
	ListNode *next = head->next;
	ListNode *temp;
	while(next)
	{
		temp = next->next;
		next->next = cur;
		cur = next;
		next = temp;
	}
	head->next = NULL;
	return cur;
}

void mergeList(ListNode *a, ListNode *b)
{
	ListNode *cur1 = a;
	ListNode *cur2 = b;
	ListNode *next1;
	ListNode *next2;
	while(a && b)
	{
		next1 = a->next;
		next2 = b->next;
		a->next = b;
		b->next = next1;
		a = next1;
		b = next2;
	}
}

void reorderList(ListNode *head) 
{
	ListNode *half = head;
	ListNode *end = head;
	getHalf(half, end);
	if(half)
	{
		ListNode *newHalf = reverseList(half->next);
		half->next = NULL;
		mergeList(head, newHalf);
	}
}

int main(int argc, char const *argv[])
{
	ListNode* head = NULL;
	int a;
	if(cin >> a)
	{
		head = new ListNode(a);
		ListNode* curNode = head;
		ListNode* nextNode;
		while(true)
		{
			cin >> a;
			if(cin.fail())
				break;
			nextNode = new ListNode(a);
			curNode->next = nextNode;
			curNode = nextNode;
		}
	}
	cout << "input array: ";
	coutList(head);
	reorderList(head);
	cout << "reoredered array: ";
	coutList(head);
	while(head)
	{
		ListNode* temp = head->next;
		delete head;
		head = temp;
	}
	return 0;
}