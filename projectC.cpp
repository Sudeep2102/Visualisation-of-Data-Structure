#include<iostream>
#include<fstream>
using namespace std;

class Node 
{
  public:
    int key;
  int data;
  Node * next;

  Node() //Default Constructor
  {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d) //Parameterized Constructor
  {
    key = k;
    data = d;
    next = NULL;
  }
};

class Stack 
{
  public:
    Node * top;
    fstream fio;
  	Stack()  //Constructor
	{
    	top = NULL;
  	}
	bool isFull(int *count,int ele);
	bool isEmpty(int *count);
	bool checkIfNodeExist(Node * n);
	void push(Node * n);
	Node * pop()
	{
		Node * temp = NULL;
    	temp = top;
    	top = top -> next;
    	return temp;	
	}
	inline Node * peek() //inline function
	{
		return top;	
	}
	int count();
	void display();
	void Search(int choice,int KOD);
	void FileWrite();
		
};
  
bool Stack::isFull(int *count,int ele)
{
  	if(*count<ele)
  		return false;
  	else if(*count==ele)
  		return true;
}

bool Stack::isEmpty(int *count) 
{
    if (*count==0) 
	{
      return true;
    } else 
	{
      return false;
    }
}
bool Stack::checkIfNodeExist(Node * n) 
{
    Node * temp = top;
    bool exist = false;
    while (temp != NULL) 
	{
      if (temp -> key == n -> key)
	   {
        exist = true;
        break;
      }
      temp = temp -> next;
    }
    return exist;
}

void Stack:: push(Node * n) 
{
    if (top == NULL) 
	{
      top = n;
      cout << "Node  PUSHED successfully" << endl;
    } 
	else if (checkIfNodeExist(n)) 
	{
      cout << "Node already exist with this Key value." <<"Enter different Key value" << endl;
    } 
	else
	{
      Node * temp = top;
      top = n;
      n -> next = temp;
      cout << "Node  PUSHED successfully" << endl;
    }

}
int Stack::count() 
{
    int count = 0;
    Node * temp = top;
    while (temp != NULL) 
	{
      count++;
      temp = temp -> next;
    }
    return count;
}
void Stack::Search(int choice,int KOD)
  {
  	Node *temp=top;
  	while(temp!=NULL)
  	{
  		if(choice==0)
  		{
  			if(temp->key==KOD)
  			{
  				cout<<"Element Found of Key:"<<KOD<<endl;
  				cout<<"Data:"<<temp->data<<endl;
  				break;
			}
			else
			{
				cout<<"Element Not Found.."<<endl;
				break;
			}
		}
		else if(choice==1)
		{
			if(temp->data==KOD)
			{
				cout<<"Element Found of Data:"<<KOD<<endl;
				cout<<"Key:"<<temp->key<<endl;
				break;
			}
			else
			{
				cout<<"Element Not Found.."<<endl;
				break;
			}
		}
		temp = temp->next;
		}
	}
  	

void Stack::display()
 {
    cout << "All values in the Stack are :" << endl;
    Node * temp = top;
    while (temp != NULL)
	 {
      cout << "(" << temp -> key << "," << temp -> data << ")" << " -> " <<endl;
      temp = temp -> next;
    }
    cout << endl;
}
void Stack::FileWrite()
{
	fio.open("Stack.txt",ios::out);
	fio<<"Elements in Stack are:"<<endl;
	Node * temp = top;
    while (temp != NULL) 
	{
      
      fio << "(" << temp -> key << "," << temp -> data << ")" <<endl;
      temp = temp -> next;
    }
	cout<<"Saved Successfully..."<<endl;
}


class Queue : public Stack //Inheritance
{
  public:
  	Node *front;
  	Node *rear;
    bool checkIfNodeExist(Node *n);
    void Enqueue(Node *n);
    int Count();
    bool IsEmpty();
    void Display();
    void Search(int KOD,bool choice ); //Polymorphism
    void Filewrite();
    Queue() 
	{
      top = NULL;
      rear = NULL;
    }
    Node* Dequeue() 
    {
        Node *temp=NULL;
      if (IsEmpty()) 
      {
          cout << "Queue UnderFlow..." << endl;
          return NULL;
      } 
      else 
      {
        if(top==rear)
        {
          temp=front;
          front = NULL;
          rear = NULL;  
          return temp;
        }
        else
        {
          temp=front;
          front = front->next;  
          return temp;
        }
          
       }
    }  
};
bool Queue::checkIfNodeExist(Node *n)
{
	 	Node *temp = front;
	 	bool exist=false;
	 	while(temp!=NULL)
	 	{
	 		if(temp->key==n->key)
        	{
          		exist=true;
         		 break;
      		}
      		temp=temp->next;
		}
		return exist;
}
	 
void Queue::Enqueue(Node *n) 
{
    if (IsEmpty())
      {
        front = n;
        rear = n;
        cout<<"Node  ENQUEUED successfully"<<endl;
      }
    else if(checkIfNodeExist(n))
    {
      cout<<"Node already exist with this Key value." 
      <<"Enter different Key value"<<endl;
    }
    else
    {
      rear->next=n;
      rear=n;
      //top = n;
      cout<<"Node  ENQUEUED successfully"<<endl;
    }
    
}
	
	
bool Queue::IsEmpty()
{
    	if(front==NULL && rear==NULL)
    	{
    		return true;
		}
		else
		{
			return false;
		}
}
	 
int Queue::Count() 
{
      int count=0;
      Node *temp=front;
      while(temp!=NULL)
      {
        	count++;
        	temp=temp->next;
      }
     return count;
}
	 
void Queue::Display() 
{
      if(IsEmpty())
      {
        cout << "Queue is Empty" << endl;
      }
    else
    {
      	cout << "All values in the Queue are :" << endl;
        Node *temp=front;
        while(temp!=NULL)
        {
          cout<<"("<<temp->key<<","<<temp->data<<")"<<" -> ";
          temp=temp->next;
      	}
      	cout<<endl;
    }  
}
void Queue::Search(int KOD,bool choice) //Linear Search
{
	Node *temp=front;
  	while(temp!=NULL)
  	{
  		if(choice==0)
  		{
  			if(temp->key==KOD)
  			{
  				cout<<"Element Found of Key:"<<KOD<<endl;
  				cout<<"Data:"<<temp->data<<endl;
  				break;
			}
			else
			{
				cout<<"Element Not Found.."<<endl;
				break;
			}
		}
		else if(choice==1)
		{
			if(temp->data==KOD)
			{
				cout<<"Element Found of Data:"<<KOD<<endl;
				cout<<"Key:"<<temp->key<<endl;
				break;
			}
			else
			{
				cout<<"Element Not Found.."<<endl;
				break;
			}
		}
		temp = temp->next;
	}	
}
void Queue::Filewrite()
{
	fio.open("Queue.txt",ios::out);
	fio<<"Elements in Queue are:"<<endl;
	Node *temp = front;
    while (temp != NULL) 
	{
	    fio<<"("<<temp->key<<","<<temp->data<<")"<<" -> ";
        temp=temp->next;
    }
    cout<<"Saved Successfully..."<<endl;
}

	 

int main() {
  Stack s1;
  Queue q;
  int option, key, data, ele,count=0,SOQ;
  cout<<"1.Stack\n2.Queue\nEnter Your Choice:";
  cin>>SOQ;
  if(SOQ==1 || SOQ==2)
  {
  	cout<<"Enter Number of Elements in Stack/Queue: ";
  	cin>>ele;
  }
  if(SOQ==1)
  {
	
	  do 
	  {
	    cout << "Choose Your Operation on Stack(0=EXIT):"<<endl;
	    cout << "1. Push()\t3. peek()\t5. display()\t7.Clear Screen" << endl;
	    cout << "2. Pop()\t4. count()\t6. Search()\t8.Save" << endl;
	    cout<<"Enter Your Choice:";
	    cin >> option;
	
	    Node * new_node = new Node(); //Dynamic Memory Allocation
	
	    switch (option) {
	    case 0:
	      break;
	    case 1:
	    if(!s1.isFull(&count,ele))
	    {
		
	      cout << "Enter KEY and VALUE of NODE to push in the stack" <<endl;
	      cout<<"Key:";
	      cin >> key;
	      cout<<"Data:";
	      cin >> data;
	      new_node -> key = key;
	      new_node -> data = data;
	      s1.push(new_node);
	      count++;
		}
		else
		{
			cout<<"Stack OverFlow..."<<endl;
		}
	      break;
	    case 2:
	      if(!s1.isEmpty(&count))
	      {
	      	cout << "Pop Function Called - Poped Value: " << endl;
	      	new_node = s1.pop();
	      	cout << "TOP of Stack is: (" << new_node -> key << "," << new_node -> data << ")";
	      	delete new_node;
	      	cout << endl;
		  	count--;
	      }
	      else
	      {
	      	cout<<"Stack UnderFlow..."<<endl;
		  }
	      break;
	    case 3:
	      if (s1.isEmpty(&count)) {
	        cout << "Stack is Empty" << endl;
	      } else {
	        cout << "PEEK Function Called : " << endl;
	        new_node = s1.peek();
	        cout << "TOP of Stack is: (" << new_node -> key << "," << new_node -> data << ")" <<
	          endl;
	      }
	      break;
	    case 4:
	      cout << "Count Function Called: " << endl;
	      cout << "No of nodes in the Stack: " << s1.count() << endl;
	      break;
	
	    case 5:
	      cout << "Display Function Called - " << endl;
	      s1.display();
	      cout << endl;
	      break;
	    
	    case 6:
	    	int c,kod;
	    	cout<<"How you want to find the element?(Key=0 or data=1)";
	    	cin>>c;
	    	if(c==0)
	    	{
	    		cout<<endl<<"Enter the Key:";
	    		cin>>kod;
	    		s1.Search(c,kod);
			}
			else if(c==1)
	    	{
	    		cout<<endl<<"Enter the data:";
	    		cin>>kod;
	    		s1.Search(c,kod);
			}
			else
			{
				cout<<"Invalid Choice..";
			}
			break;
	    case 7:
	      system("cls");
	      break;
	    case 8:
	    	{
	    		s1.FileWrite();
	    		break;
	    	}

	    default:
	      cout << "Invalid Choice... " << endl;
	    }
	
	  } while (option != 0);
	}
	else if(SOQ==2)
	{
		do 
		{
    		cout << "Choose Your Operation on Queue(0=EXIT):"<<endl;
	    	cout << "1. Enqueue()\t3. count()\t5. Search\t7.Save" << endl;
	    	cout << "2. Dequeue()\t4. display()\t6. Clear Screen"<< endl;
	    	cout<<"Enter Your Choice:";
	    	cin >> option;
 	
	 		Node * new_node = new Node();
	 
    
    		switch (option) 
			{
    		case 0:
      			break;
    		case 1:
      			if(!q.isFull(&count,ele))
				{
				  cout << "ENQUEUE Function Called -" <<endl;
			      cout << "Enter KEY and VALUE of NODE to ENQUEUE in the Queue"<<endl;
			      cout<<"Key:";
			      cin >> key;
			      cout<<"Value:";
			      cin >> data;
			      new_node->key = key;
			      new_node->data = data;
			      q.Enqueue(new_node);
			      count++;
				}
				else
				{
					cout<<"Queue OverFlow..."<<endl;
				}
      			break;
    		case 2:
      			cout << "DEQUEUE Function Called - " <<endl;
      			new_node = q.Dequeue();
      			if(!q.IsEmpty())
	  			{
      				cout<<"Dequeued Value is: ("<<new_node->key<<","<<new_node->data<<")";
      				delete new_node;
      				count--;
  	 	 		}				
	  			cout<<endl;
      			break;
    		case 3:
    			cout << "Count Function Called - " << endl;
      			cout << "No of nodes in the Queue: " <<q.Count()<<endl;
      			break;
    		case 4:
      			cout << "Display Function Called - " << endl;
      			q.Display();
      			cout << endl;
      			break;
    
    		case 5:
    			bool c;
				int kod;
	    		cout<<"How you want to find the element?(Key=0 or data=1)";
	    		cin>>c;
	    		if(c==0)
	    		{
	    			cout<<endl<<"Enter the Key:";
	    			cin>>kod;
	    			q.Search(kod,c);
				}
				else if(c==1)
	    		{
	    			cout<<endl<<"Enter the data:";
	    			cin>>kod;
	    			q.Search(kod,c);
				}
				else
				{
					cout<<"Invalid Choice..";
				}
				break;
    		case 6:
    			system("cls");
      			break;
    		case 7:
    		{
	    		q.Filewrite();
	    		break;
	    	}
    		default:
      			cout << "Enter Proper Option number " << endl;
			}
  		} while (option != 0);	
	}
	else
	{
		cout<<"Invalid Choice...";
	}
  return 0;
}
