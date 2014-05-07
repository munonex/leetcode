#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class comp
{
public:
	bool operator() (const ListNode* a, const ListNode* b) const
	{
		return (a->val > b->val);
	}
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

ListNode *sortList(ListNode *head) 
{
	if(!head)
		return head;

	priority_queue<ListNode*, vector<ListNode*>, comp> myQ;
	ListNode* curNode = head;
	ListNode* nextNode;
	while(curNode)
	{
		myQ.push(curNode);
		nextNode = curNode->next;
		// delete curNode;
		curNode = nextNode;
	}
	ListNode* newHead = myQ.top();
	curNode = newHead;
	myQ.pop();
	while(!myQ.empty())
	{
		nextNode = myQ.top();
		myQ.pop();
		curNode->next = nextNode;
		curNode = nextNode;
	}
	curNode->next = NULL;
	return newHead;
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
			int x;
			cin >> x;
			if(cin.fail())
				break;
			nextNode = new ListNode(x);
			curNode->next = nextNode;
			curNode = nextNode;
		}
	}
	cout << "input array: ";
	coutList(head);
	ListNode* newhead = sortList(head);
	cout << "sorted array: ";
	coutList(newhead);
	while(head)
	{
		ListNode* temp = head->next;
		delete head;
		head = temp;
	}
	return 0;
}