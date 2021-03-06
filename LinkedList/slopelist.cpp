#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
	int x, y;
	//int hd;
	node *next;

	node(int a, int b)
	{
		x = a, y = b;
		//hd = INT_MAX;
		next = NULL;
	}
};


int checkslope(node *head)
{
	int count = 0;
	node* curr = head;
	//slope = (y2-y1)/(x2-x1);

	double m = (curr->next->y - curr->y) / (curr->next->x - curr->x);
	//cout<<
	//curr = curr->next;
	while(curr && curr->next)
	{
		node* nxt = curr->next;
		
		double s = (nxt->y - curr->y)/(nxt->x - curr->x);		
		if(s != m)
		{
			count++;
			m = s;
		}
		curr = nxt;
	}
	return count;
}

void print(node* head)
{
	node* t = head;
	while(t)
	{
		cout<<"x: "<<t->x<<" y: "<<t->y<<endl;
		t = t->next;
	}
	cout<<endl;
}

int main()
{
	node* head = new node(1, 5);
	head->next = new node(2, 5);
	head->next->next = new node(3, 5);
	head->next->next->next = new node(5, 10);
	head->next->next->next->next = new node(7, 10);
	print(head);
	int res = checkslope(head);
	cout<<res<<endl;
	return 0;
}