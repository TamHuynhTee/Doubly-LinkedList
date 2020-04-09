#include<stdio.h>
#include<conio.h>

int nodeCount = 0;

struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
};

typedef struct Node node;

struct List
{
	node* head;
	node* tail;
};

void Initualize(List &l)
{
	l.head = NULL;
	l.tail = NULL;
}

bool checkEmpty(List l)
{
	if (l.head == NULL)
		return true;
	return false;
}

void Display(List l)// Duyệt xuôi
{
	node* p = l.head;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\nNumber of nodes: %d", nodeCount);
}

void reverseDisplay(List l)// Duyệt ngược
{
	node* p = l.tail;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->prev;
	}
	printf("\nNumber of nodes: %d", nodeCount);
}

int searchNode(List l, int x)
{
	node* p = l.head;
	int run = 1;
	for (p; p != NULL; p = p->next)
	{
		if (p->data == x)
		{
			return run;
		}
		else
			run++;
	}
	return -1;
}

node* newNode(int x)
{
	node* p = new node;
	p->data = x;
	p->next = p->prev = NULL;
	return p;
}

void AddHead(List &l, int x)
{
	node* new_element = newNode(x);
	if (new_element == NULL)
	{
		return;
	}
	if (l.head == NULL)
	{
		l.head = l.tail = new_element;
		nodeCount++;
	}
	else 
		if (l.head!=NULL)
		{
			new_element->next = l.head;
			l.head->prev = new_element;
			l.head = new_element;
			nodeCount++;
		}
}

void AddTail(List &l, int x)
{
	node* new_element = newNode(x);
	if (new_element == NULL)
	{
		return;
	}
	if (l.head == NULL)
	{
		l.head = l.tail = new_element;
		nodeCount++;
	}
	else 
		if (l.head != NULL)
		{
			new_element->prev = l.tail;
			l.tail->next = new_element;
			l.tail = new_element;
			nodeCount++;
		}
}

void AddNode(List &l, int pos, int x)// Add bất kỳ vị trí
{
	node* new_element = newNode(x);
	if (l.head == NULL)// Khi List rỗng
	{
		l.head = l.tail = new_element;
		nodeCount++;
	}
	if (pos > nodeCount + 1 || pos < 1)
	{
		return;
	}
	if (new_element == NULL)
	{
		return;
	}
	else 
		if (pos == 1)// Nếu vị trí đầu
		{
			AddHead(l, x);
		}
		else
			if (pos == nodeCount + 1)// Nếu vị trí cuối
			{
				AddTail(l, x);
			}
			else
			{
				node* p = l.head;
				int run = 1;
				while (run < nodeCount - 1)
				{
					p = p->next;
					run++;
				}
				node* p1 = p->next;
				new_element->next = p1;
				p1->prev = new_element;
				p->next = new_element;
				new_element->prev = p;
				nodeCount++;
			}
}

void DelHead(List &l)// Xóa đầu
{
	node* p = l.head;
	if (l.head == NULL)
		return;
	else 
		if (nodeCount == 1)
		{
			l.head = NULL;
			l.tail = NULL;
			nodeCount--;
		}
		else
		{
			l.head = p->next;
			l.head->prev = NULL;
			delete(p);
			nodeCount--;
		}
	Display(l);
}

void DelTail(List &l)// Xóa cuối
{
	node* p = l.tail;
	if (l.head == NULL)
		return;
	else 
		if (nodeCount == 1)
		{
			l.head = NULL;
			l.tail = NULL;
			nodeCount--;
		}
		else
		{
			l.tail = p->prev;
			l.tail->next = NULL;
			delete(p);
			nodeCount--;
		}
	Display(l);
}

void DeleteNode(List &l, int pos)// Xóa theo chỉ số node
{
	if (pos > nodeCount || pos < 1)
	{
		printf("\nInvalid node index or node not found.");
		return;
	}
	else
		if (pos == 1)
		{
			DelHead(l);
		}
		else
			if (pos == nodeCount)
			{
				DelTail(l);
			}
			else
			{
				node* p = l.head;
				int run = 1;
				while (run < pos - 1)
				{
					p = p->next;
					run++;
				}
				node* p1 = p->next->next;
				delete(p->next);
				p->next = p1;
				p1->prev = p;
				nodeCount--;
				Display(l);
			}
}

void DeleteData(List &l, int x)
{
	int pos = searchNode(l, x);
	DeleteNode(l, pos);
}

void main()
{
	List l;
	Initualize(l);
	AddHead(l, 30);
	AddHead(l, 20);
	AddHead(l, 10);
	AddTail(l, 50);
	AddNode(l, 2, 40);
	reverseDisplay(l);
	_getch();
}