#include<iostream>
#include<string>
using namespace std;


template <typename T>
class node
{
public:
	T data;
	node* next;



	node()
	{
		data = 0;
		next = NULL;
	}

	node(T d, node* n)
	{
		data = d;
		next = n->next;
	}

	node(T d)
	{
		data = d;
		next = NULL;
	}

	void setData(T d)
	{
		data = d;
	}

	void setNext(node* n)
	{
		next = n->next;
	}

	T getData()
	{
		return data;
	}

	node* getNext()
	{
		return this->next;
	}

};

template <typename T>
class Queue {
	//private:
public:
	node<T>* head;
	node<T>* rear;



	Queue()
	{
		head = NULL;
		rear = NULL;
	}
	node<T>* getHead()
	{
		return head;
	}

	bool isEmpty()
	{
		if (this->head == NULL && this->rear==NULL)
			return true;
		return false;
	}

	void enqueue(T v)
	{
		node<T>* temp = new node<T>(v);
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			rear = temp;
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
		temp = NULL;
		delete temp;
	}



	

	int search(T c)
	{
		node<T>* p = head;
		int i = 0;
		while (p != NULL)
		{
			i++;
			if (p->data == c)
				return c;
			p = p->next;
		}
		return 0;
	}

	node<T>* dequeue()
	{
		node<T>* temp = NULL;
		if (this->isEmpty())
			return NULL;
		else
		{
			if (head == rear)
			{
				temp = head;
				head = NULL;
				rear = NULL;
				return temp;
			}
			else
			{
				temp = head;
				head = head->next;
				return temp;
			}
		}

	}

	void print()
	{
		if (isEmpty() == true)
		{
			cout << endl << " IS Empty" << endl;
			return;
		}

		node<T>* p = head;
		cout << endl;
		while (p != NULL)
		{
			cout << p->data;
			p = p->next;
		}
		cout << endl;

	}

	T Front()
	{
		node<T>* temp = head;
		temp->data = head->data;
		return temp->data;
	}	

};

template<typename T>
void  RoundRobin(Queue<int> &q, T quantum)
{
	
	while (!q.isEmpty())
	{	
		T f = q.Front();
		int d = f - quantum;
		cout << "\nExecution time is : " << f << "\nRemaining Time : " << d << endl;
		if (d > 0)
		{
			q.dequeue();
			q.enqueue(d);
		}
		else
		{
			q.dequeue();
		}
	}
}

template <typename T>
int objEnqueue(Queue<T> &obj, string str, int i)
{
    do
	{
		obj.enqueue(str[i]);
		++i;
	}while ((str[i] != ' ') && ((i<str.length())));
    return i;
}


void split(string str)
{
	int i=0,j=0;

    // j is the counter queue objects
    // i is the counter used in object enqueuing

	Queue<char>* q1  = new Queue<char> [str.length()] ;
     
    int k=0,l=0;

    // l is the counter in the for loop as well as used in printing the enqueued objects

    j=0;
	for(;l<str.length();l++)
    {
        i = objEnqueue(q1[l],str,i);
        j++;
        if(i>=str.length())
            break;
    }
	
    for(l=0;l<j;l++)
    {
        q1[l].print();
    }

    node<char>** rear= new node<char>* [j];
    for(int i=0; i<j; i++)
        rear[i]= new node<char> [j];
    
    for(int i=0;i<j;i++)
    {
        rear[i]=q1[i].rear;
    }
    for(int i=1;i<j;i++)
    {
        rear[i-1]->next =q1[i].head;
    }

    q1[0].print();
	/* node<char>* r1 = q1.rear;
	node<char>* r2 = q2.rear;
	node<char>* r3 = q3.rear;

	r1->next = q2.head;
	r2->next = q3.head;
	r3->next = q4.head;

g
	q1.print(); */

}




int main()
{
	Queue<int> Obj1;
//	Obj1.enqueue(8);
	Obj1.enqueue(4);
	Obj1.enqueue(5);
	Obj1.enqueue(9);
	Obj1.enqueue(4);
	Obj1.enqueue(8);

	Obj1.print();

	Obj1.dequeue();
	Obj1.print();

	RoundRobin(Obj1, 3);
	//Obj1.print();


	string str = "My name is Ahmad Hassan. I love C++.";
   // cout<<endl<<str<<endl;
	split(str);

}