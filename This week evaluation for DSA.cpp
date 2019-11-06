#include <iostream>
#include <fstream>
using namespace std;
class node
{
public:
    char data;
    node* next;
};

class stack
{
	public:
	node*head;
	public:
		stack()
		{
			head=NULL;
		}
    void push(char d);
    char pop();
    void print();
};
void stack::push(char d)
{
        node* tptr;
        tptr=head;
        node* nptr=new node();
        nptr->data=d;
        nptr->next=NULL;
        if(head==NULL)
        {
            head=nptr;
        }
        else
        {
            while(tptr->next!=NULL)
            {
                tptr=tptr->next;
            }
            tptr->next=nptr;
        }
    }

char stack::pop()
{
	node*tptr=head;
	node*pptr=head;
	
	if(head==NULL)
		return 'n';
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
			char n=tptr->data;
			head=head->next;
			return n; 
			
		}
		else 
		{
			while(i>1)
			{
				pptr=pptr->next;
				i--;
			}
			char n=tptr->data;
			pptr->next=tptr->next;
	    	return n ;
	}
		
	}
}
void stack::print()
{
        node* tptr;
        tptr=head;
        while(tptr!=NULL)
        {
            cout <<tptr->data<<endl;
            tptr=tptr->next;
        }
    }
    bool check (stack s,string array);
    bool check(stack s,string array)
    {
    int counter=0;
    int flag=2;
    ifstream file;
	file.open("Sample.cpp");
    char ch, che=39;
    if(file.is_open())
    {
    while(getline(file,array))
    {
//    	int k=0;
//    	if(array[k]==che)
//    	{
//    		k++;
//    		while(array[k]!=che)
//    		{
//    			k++;
//			}
//		}                             
           counter++;
    for(int i=0;i<array.length();i++)
    {
     if(array[i]=='{' || array[i]=='['||array[i]=='(')
       {
       s.push(array[i]);
       }
     if(array[i]=='}')
      {
       ch=s.pop();
	if(ch=='n')
      {
      cout<<"Error In line no "<<counter<<" because of miss bracket error "<<endl;
     flag=1;
     return false;
     }
     else if(ch=='('||ch=='[')
                     {;
     cout<<"Error In line no "<<counter<<" because of miss match bracket error "<<endl;
      flag= 1;
     return false;
      }
      }
     else if(array[i]==')')
     {
     ch=s.pop();
     if(ch=='n')
    {
    cout<<"Error In line no "<<counter<<" because of miss bracket error "<<endl;
    flag= 1;
    return false;
    }
    else if(ch=='{'||ch=='[')
    {
    cout<<"Error In line no "<<counter<<" because of miss match bracket error "<<endl;
    flag= 1;
    return false;
    }
    }
    else if (array[i]==']')
	{
	ch=s.pop();
	if(ch=='n')
	{
	cout<<"Error In line no "<<counter<<" because of miss bracket error "<<endl;
	flag= 1;
	return false ;                                                                   //error
					   	
	}
	else if (ch=='{'||ch=='(')
	{
	cout<<"Error In line no "<<counter<<" because of miss match bracket error "<<endl;
	flag= 1;
	return false;
	}					   
	} 
    }
	}
    }
    if(s.pop()!='n'&&flag==2)
    {
    cout<<"Error in line number "<<counter<<" due to missing of bracket "<<endl;
    return false;
    }
    if(s.pop()=='n'&&flag==2)
    {
    cout<<"Your program has no bracket  error";
    return true;
	}	
	}	
int main()
{
	stack st;
	string bracket;
	bool result;
	result=check(st,bracket);
	//cout<<endl<<st.pop();
    return 0;
}
