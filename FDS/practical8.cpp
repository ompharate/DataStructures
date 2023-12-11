#include <iostream>
using namespace std;

#define MAX_SIZE 10

class Deque {
private:
    int front;
    int rear;
    int arr[MAX_SIZE];

public:
    Deque(){
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        if(front == -1 && rear == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)){
            return true;
        }
        return false;
    }

    void insertFront(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the front." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }

        arr[front] = element;
        cout << "Inserted element " << element << " at the front." << endl;
    }

    void insertRear(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the rear." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = element;
        cout << "Inserted element " << element << " at the rear." << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front." << endl;
            return;
        }

        cout << "Deleted element " << arr[front] << " from the front." << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the rear." << endl;
            return;
        }

        cout << "Deleted element " << arr[rear] << " from the rear." << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);

        cout << endl;
    }
};

int main() {
    Deque deque;

    deque.insertFront(1);
    deque.insertRear(2);
    deque.insertFront(3);
    deque.display();

    deque.deleteFront();
    deque.display();

    deque.deleteRear();
    deque.display();

    deque.insertRear(4);
    deque.insertFront(5);
    deque.display();

    return 0;
}
