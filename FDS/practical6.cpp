#include <iostream>
using namespace std;
#define MAX 10
class Queue
{
private:
    int front;
    int rear;
    int *arr;

public:
    Queue()
    {
        front = -1;
        rear = -1;
        arr = new int[MAX];
    }

    void push()
    {
        if (rear == MAX - 1)
        {
            cout << "Queue is full!" << endl;
            return;
        }
        int data = 0;
        cout << "Enter the data you want to enter: ";
        cin >> data;

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        arr[rear] = data;
    }

    void pop()
    {
        if (front == -1)
        {
            cout << " Queue is empty!" << endl;
            return;
        }

        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << " Queue is empty!" << endl;
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Queue queue;
    queue.push();
    queue.push();
    queue.push();
    queue.push();
    queue.display();
    queue.pop();
    queue.display();
    queue.pop();
    queue.display();
    return 0;
}