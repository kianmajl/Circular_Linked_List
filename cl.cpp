#include <iostream>
using namespace std;

class Node
{
private:
	int data;
	Node *next;
	Node *prev;

public:
	void setData(int data)
	{
		this->data = data;
	}
	void setNextNode(Node *next)
	{
		this->next = next;
	}
	void setPrevNode(Node *prev)
	{
		this->prev = prev;
	}
	int getData()
	{
		return this->data;
	}
	Node *getNextNode()
	{
		return this->next;
	}
	Node *getPrevNode()
	{
		return this->prev;
	}
};

class Circular_linked_list
{
private:
	int size;
	Node *current;

public:
	Circular_linked_list();
	~Circular_linked_list();
	//add getter and setter functions here
	/*
		
			here

		*/
	void push();
	void pop()
	{
		if (!size)
		{
			cout << "The Linked-List is Empty!!!!" << endl;
			return;
		}
		if (size == 1)
		{
			delete current;
			current = nullptr;
		}
		else
		{
			Node *temp = current;
			current->getPrevNode()->setNextNode(current->getNextNode());
			current = current->getNextNode();
			delete temp;
		}
		size--;
	}
	void pop(int data);
	void push_after(int data);
	void push_befor(int data);
	void print();
};

int main()
{
	Circular_linked_list aka;
}
