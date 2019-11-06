#include<iostream>
using namespace std;
class node
	 {
	 public:
		int data;
		node*next;
};
class stack
{
	private:
		node*head;
		node*tail;
		public:
	stack()
{	
		head=NULL;
		tail=NULL;

}
    void push(int n);
    int pop (];
    void print();	
};
void stack::push(int n)
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
int stack::pop()
{
	node*tptr=head;
	node*pptr=head;
	
	if(head==NULL)
	{
		cout<<endl<<"There is nothing to pop in the stack"<<endl;	
		return -1;
	}
	else
	{
		int i=0;
		while(tptr->next!=NULL)
		{
			tptr=tptr->next;
			i++;
		}
		
		if(tptr==head)
		{
			int n=tptr->data;
			head=head->next;
			cout<<endl<<"Result of poping"<<endl;
			cout<<n;
			return n; 
			
		}
		else 
		{
			while(i>1)
			{
				pptr=pptr->next;
				i--;
			}
			int n=tptr->data;
			pptr->next=tptr->next;
			cout<<endl<<"Result of poping"<<endl;
			cout<<n;
	    	return n ;
	}
		
	}
}
void stack::print() {
	node* ptr;
	ptr = head;
	if(ptr==NULL)
	{
		cout<<endl<<"The stack is empty"<<endl;
	}
	else
	{
	while (ptr != NULL) {
		cout << ptr->data << "  ";
		ptr = ptr->next;

	}
}
}

int main()
{
	stack ss;
	ss.print();
	ss.pop();
	ss.push(5);
//	cout<<endl;
	ss.push(9);
	ss.push(2);
	cout<<"The value aftering inserting"<<"\n";
	ss.print();
	cout<<endl;
/*	ss.push(7);
	cout<<"printing after pushing"<<endl;
	ss.print();
	cout<<endl;
	cout<<"Poping result:"<<endl;
	cout<<ss.pop()<<endl;
	cout<<ss.pop()<<endl;
	cout<<ss.pop()<<endl;
	cout<<"Printing after poping"<<endl;
	ss.print();
	cout<<endl<<"After poping values"<<endl;
	cout<<ss.pop()<<endl;
	cout<<ss.pop()<<endl;
	ss.push(11);
	*/
	ss.pop();
	ss.pop();
	ss.pop();
	ss.pop();
	ss.print();
	return 0;
	}	
