#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int roll;
    Node *next;

    Node(int roll)
    {
        this->roll = roll;
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

    void push(int roll)
    {
        Node *temp = new Node(roll);
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
            cout << "roll number is:" << temp->roll << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

class operations
{

public:
    void intersection(SLL setA, SLL setB)
    {

        Node *temp1 = setA.head;
        Node *temp2 = setB.head;

        while (temp1 != nullptr)
        {
            while (temp2 != nullptr)
            {
                if (temp1->roll == temp2->roll)
                {
                    cout << temp1->roll<<",";
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
            temp2 = setB.head;
        }
    cout<<endl;
    }
    void unionLL(SLL setA, SLL setB)
    {
        bool flag = false;
        Node *temp1 = setA.head;
        Node *temp2 = setB.head;
        
        while (temp1 != nullptr)
        {
            while (temp2 != nullptr)
            {
                if (temp1->roll == temp2->roll)
                {
                    flag = true;
                    break;
                }
                
                
                temp2 = temp2->next;
            }
            if (flag == false)
            {
                cout << temp1->roll<<",";
            }
            flag = false;
            temp1 = temp1->next;
            temp2 = setB.head;
        }
     
        temp1 = setA.head;
        temp2 = setB.head;

        while (temp2 != nullptr)
        {
            while (temp1 != nullptr)
            {
                if (temp2->roll == temp1->roll)
                {
                    flag = true;
                    break;
                }
                temp1 = temp1->next;
            }
            if (flag == false)
            {
                cout << temp2->roll<<",";
            }
            flag = false;
            temp2 = temp2->next;
            temp1 = setA.head;
        }
        
        cout<<endl;
  
    }
    
    void neitherVaNorButt(SLL setA, SLL setB,SLL stu) {
    
        Node *temp1 = setA.head;
        Node *temp2 = setB.head;
        Node *temp3 = stu.head;
        bool flag1 = false;
        bool flag2 = false;
        
        while(temp3!=nullptr) {
            
            while(temp1!=nullptr && temp2!=nullptr) {
                
                if(temp3->roll == temp1->roll ) {
                   
                    flag1 = true;
                }
                 if(temp3->roll == temp2->roll) {
                    flag2 = true;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
                if(flag1==false && flag2==false) {
                     cout<<temp3->roll<<" ";
                }
                flag1 = false;
                flag2 = false;
                temp1 = setA.head;
                temp2 = setB.head;
                 
                temp3 = temp3->next;
        }
    
    } 

};

int main()
{

    SLL list1, list2, stu;

    stu.push(10);
    stu.push(60);
    stu.push(80);
    stu.push(90);
    stu.push(20);
    stu.push(40);
    stu.push(50);
    stu.push(10);
    stu.push(25);
    stu.push(75);

    list1.push(10);
    list1.push(60);
    list1.push(80);
    list1.push(90);
    list1.push(20);

    list2.push(40);
    list2.push(50);
    list2.push(10);
    list2.push(20);
    list2.push(60);

    operations action;

    cout<<"Set of students who like both vanilla and butterscotch"<<endl;
    action.intersection(list1, list2);
    cout<<"Set of students who like either vanilla or butterscotch or not both"<<endl;
    action.unionLL(list1,list2);
    cout<<"Number of students who like neither vanilla nor butterscotch "<<endl;
    action.neitherVaNorButt(list1,list2,stu);
    return 0;
}