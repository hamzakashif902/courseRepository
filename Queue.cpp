#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node*next;
};
class queue
{
	private:
		node*head;
		node*tail;
		public:
	queue()
	{
		head=NULL;
		tail=NULL;

	}		
	
    void enque(int n);
    int deque ();
    void print();	
};
void queue::enque(int n)
{
   	node* tptr;
	tptr = head;

	node* nptr = new node();
	nptr->data = n;
	tail=nptr;
	tail->next =NULL ;

	if (head == NULL)
	{
		head = nptr;
		tail = nptr;
		tail->next=NULL;
	}
	else {
		while(tptr->next!=NULL)
		{
			tptr=tptr->next;
		}
      tptr->next=nptr;
	}
}
int queue::deque()
{
//	node*tptr=head;
//	node*pptr=head;
	
	if(head==NULL)
		return -1;
	else
	{
		int n=head->data;
		head=head->next;
		return n;
	}
	}
void queue::print() {
	node* ptr;
	ptr = head;
	while (ptr != NULL) {
		cout << ptr->data << "  ";
		ptr = ptr->next;

	}
}

int main()
{
	queue ss;
	ss.enque(5);
	ss.enque(9);
	ss.enque(2);
	ss.enque(7);
	cout<<"printing after pushing"<<endl;
	ss.print();
	cout<<endl;
	cout<<"Poping result:"<<endl;
	cout<<ss.deque()<<endl;
	cout<<ss.deque()<<endl;
	cout<<ss.deque()<<endl;
	cout<<"Printing after poping"<<endl;
	ss.print();
	cout<<endl<<"After poping values"<<endl;
	cout<<ss.deque()<<endl;
	cout<<ss.deque()<<endl;
	ss.enque(11);
	cout<<ss.deque();
	ss.print();
	return 0;
	}	
	
		

