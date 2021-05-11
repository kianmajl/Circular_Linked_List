/*
 * Kian Majlesi(993613051)
 * Zahra Ebrahimi(993623002)
 * Alireza Karimi(993623035)
*/
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
        while (this->size > 0)
        {
            pop();
        }
    }
    int getSize()
    {
        return this->size;
    }
    Node *getCurrentNode()
    {
        return this->current;
    }
    void push(int data)
    {
        Node *node = new Node;
        node->setData(data);
        if (this->size == 0)
        {
            node->setNextNode(node);
            node->setPrevNode(node);
        }
        else
        {
            node->setNextNode(this->current);
            node->setPrevNode(this->current->getPrevNode());
            Node *tmp = this->current;
            while (tmp->getNextNode() != this->current)
                tmp = tmp->getNextNode();
            tmp->setNextNode(node);
        }
        this->current = node;
        this->size++;
    }
    bool pop()
    {
        if (!size)
        {
            cout << "The Linked-List is Empty!!!!" << endl;
            return false;
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
        return true;
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
    bool pop(int data)
    {
        Node *data_node = search(data);

        if (!data_node)
            return false;

        data_node->getNextNode()->setPrevNode(data_node->getPrevNode());
        data_node->getPrevNode()->setNextNode(data_node->getNextNode());
        delete data_node;
        size--;
        return true;
    }
    bool push_after(int new_data, int pa_data)
    {
        Node *pad = search(pa_data);

        if (!pad)
            return false;
        else
        {
            Node *tmp = new Node;

            tmp->setData(new_data);
            tmp->setNextNode(pad->getNextNode());
            tmp->setPrevNode(pad);
            pad->getNextNode()->setPrevNode(tmp);
            pad->setNextNode(tmp);
            this->size++;
            return true;
        }
    }
    void push_before(int data)
    {
        if (this->size == 0)
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
        if (this->current == nullptr)
        {
            cout << "This linklist is empy! For God's sake leave me alone user!" << endl;
            return;
        }

        do
        {
            cout << node->getData() << endl;
            node = node->getNextNode();
        } while (node != this->current);
    }
};

string action_menu()
{
    cout << "Hi buddy! What do u wanna do?" << endl;

    cout << "1.Make a linkl list(Your very first step)\n"
         << "2.Get the size of your current link list\n"
         << "3.Push data in current place\n"
         << "4.Pop current place\n"
         << "5.Find a special data\n"
         << "6.Pop a special data\n"
         << "7.Push after current\n"
         << "8.Push before current\n"
         << "9.Print your link list\n"
         << "To exit the program enter \"Let me out of this shit\"" << endl;

    string action;
    getline(cin, action);
    return action;
}

Circular_linked_list aka;

int main()
{
    string action = action_menu();
    if (action == "1")
    {
        cout << "Your link list is ready dude!" << endl
             << endl;
        cout << "Press Enter to go back to main menu.";
        cin.ignore();
        system("cls");
        main();
    }
    else if (action == "2")
    {
        cout << aka.getSize() << endl
             << endl;
        cout << "Press Enter to go back to main menu.";
        cin.ignore();
        system("cls");
        main();
    }
    else if (action == "3")
    {
        cout << "\n               --------------------------------------\n"
             << "Enter the data you wanna push: ";
        int d;
        cin >> d;
        aka.push(d);
        cout << endl
             << "Your data successfullu pushed :)" << endl
             << endl;
        cout << "Press Enter to go back to main menu.";
        cin.ignore();
        system("cls");
        main();
    }
    else if (action == "4")
    {
        cout << "\n               --------------------------------------\n";
        if (aka.pop() == true)
            cout << endl
                 << "Your current data successfully poped :)" << endl;
        else
            cout << "Unreachable request! Ye chi bkha ke beshe :/" << endl
                 << endl;
        cout << "Press Enter to go back to main menu.";
        cin.ignore();
        system("cls");
        main();
    }
    else if (action == "5")
    {
        cout << "\n               --------------------------------------\n"
             << "Enter the data you wanna seek for: ";
        int d;
        cin >> d;
        if (aka.search(d) != nullptr)
            cout << endl
                 << "Your current data successfully found :)" << endl;
        else
            cout << "Unreachable request! Bebin karato :/" << endl
                 << endl;
        cout << "Press Enter to go back to main menu.";
        cin.ignore();
        system("cls");
        main();
    }
    else if (action == "6")
    {
        cout << "\n               --------------------------------------\n"
             << "Enter the data you wanna pop: ";
        int d;
        cin >> d;
        if (aka.pop() == true)
            cout << endl
                 << "Your data successfully poped :)" << endl;
        else
            cout << "Unreachable request! Ish Ish :/" << endl
                 << endl;
        cout << "Press Enter to go back to main menu.";
        cin.ignore();
        system("cls");
        main();
    }
    else if (action == "7")
    {
        cout << "\n               --------------------------------------\n"
             << "Enter the data you wanna push after current data: ";
        int d;
        cin >> d;
        aka.push_after(d);
        cout << endl
             << "Your data successfullu pushed :)" << endl
             << endl;
        cout << "Press Enter to go back to main menu.";
        cin.ignore();
        system("cls");
        main();
    }
    else if (action == "8")
    {
        cout << "\n               --------------------------------------\n"
             << "Enter the data you wanna push before current data: ";
        int d;
        cin >> d;
        aka.push_before(d);
        cout << endl
             << "Your data successfullu pushed :)" << endl
             << endl;
        cout << "Press Enter to go back to main menu.";
        cin.ignore();
        system("cls");
        main();
    }
    else if (action == "9")
    {
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|||||||||||||||||||Here is your link list!|||||||||||||||||" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        aka.print();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;
        cout << "Press Enter to go back to main menu.";
        cin.ignore();
        system("cls");
        main();
    }
    else if (action == "Let me out of this shit")
    {
        cout << "Goodbye! Beri ke barnagardi :)" << endl;
        return 0;
    }
}
