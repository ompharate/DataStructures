#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int prn;
    string name;
    Node *next;

    Node(int prn, string name)
    {
        this->prn = prn;
        this->name = name;
    }
};

class SLL
{
public:
    Node *head;
    Node *curr;

    SLL()
    {
        head = nullptr;
        curr = nullptr;
    }

    void push(int prn, string name)
    {
        Node *temp = new Node(prn, name);
        temp->next = NULL;

        if (head == nullptr)
        {
            head = temp;
            curr = head;
            return;
        }
        else
        {
            curr->next = temp;
            curr = temp;
        }
    }

    void remove()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == nullptr)
        {
            cout << "Removed";
            delete head;
            head = nullptr;
            curr = nullptr;
            return;
        }

        Node *temp = head;

        while (temp->next != curr)
        {
            temp = temp->next;
        }

        cout << "Deleted" << curr->name << endl;
        delete curr;
        curr = temp;
        curr->next = nullptr;
    }

    void length()
    {
        int count = 0;
        Node *temp = head;

        while (temp != nullptr)
        {

            count++;
            temp = temp->next;
        }
        cout << "Total length is: " << count << endl;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty";
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "PRN number is:" << temp->prn << endl;
            cout << "name  is:" << temp->name << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    SLL list1;

    list1.push(1, "om");
    list1.push(2, "suraj");
    list1.push(3, "karan");
    list1.display();
    list1.length();

    return 0;
}