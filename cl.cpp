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
        Circular_linked_list()
        {
            this->size =0;
            current = nullptr;
        }
	~Circular_linked_list();
	//add getter and setter functions here
	/*
		
			here

		*/
	void push();
	void pop();
	void pop(int data);
	void push_after(int data);
	void push_befor(int data);
        Node * search(int data)
        {
            Node * new_node = current;
            while(new_node->getNextNode() != current)
            {
                if(new_node->getData() == data)
                    return new_node;
                new_node = new_node->getNextNode();
            }
            cout << "Hey you! There is no such element." << endl;
            return nullptr;
        }
        void print()
        {
            cout << "what the hell it is? chikarsh bknim?" << endl;
        }
};

int main()
{
}
