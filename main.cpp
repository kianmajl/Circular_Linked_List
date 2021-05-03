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
        this->size = 0;
        current = nullptr;
    }
    ~Circular_linked_list()
    {
        //hhhhh
    }

    int getSize()
    {
        return this->size;
    }
    Node * getCurrentNode()
    {
        return this->current;
    }
    void push(int data)
    {
        Node * node = new Node;
        node->setData(data);
        if(this->size == 0)
        {
            node->setNextNode(node);
            node->setPrevNode(node);
        }
        else
        {
            node->setNextNode(this->current);
            node->setPrevNode(this->current->getPrevNode());
        }
        this->current = node;
        this->size++;
    }
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
    Node *search(int data)
    {
        Node *new_node = current;
        while (new_node->getNextNode() != current)
        {
            if (new_node->getData() == data)
                return new_node;
            new_node = new_node->getNextNode();
        }
        cout << "Hey you! There is no such element. Koshti mno!!" << endl;
        return nullptr;
    }
    void pop(int data)
    {
        Node *data_node = search(data);

        if (!data_node)
            return;

        data_node->getNextNode()->setPrevNode(data_node->getPrevNode());
        data_node->getPrevNode()->setNextNode(data_node->getNextNode());
        delete data_node;
        size--;
    }
    void push_after(int data)
    {
        if(this->size == 0)
            push(data);
        else
        {
            Node *tmp = new Node;

            tmp->setData(data);
            tmp->setNextNode(this->current->getNextNode());
            tmp->setPrevNode(this->current);
            this->current->setNextNode(tmp);
        }
    }
    void push_before(int data)
    {
        if(this->size == 0)
            push(data);
        else
        {
            Node *tmp = new Node;

            tmp->setData(data);
            tmp->setNextNode(this->current);
            tmp->setPrevNode(this->current->getPrevNode());
            this->current->setPrevNode(tmp);
        }
    }
    void print()
    {
        Node *node = this->current;
        while( node != this->current )
        {
            cout << node->getData() << endl;
            node = node->getNextNode();
        }
    }
};

int main()
{
    Circular_linked_list aka;
}
