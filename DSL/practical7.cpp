#include <iostream>
using namespace std;

const int MAX_ORDERS = 5;  

class CircularQueue {
private:
    int front, rear, count;
    int orders[MAX_ORDERS];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_ORDERS;
    }

    void enqueue(int order) {
        if (isFull()) {
            cout << "Sorry, the pizza parlor is full. Cannot accept more orders." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_ORDERS;
        }

        orders[rear] = order;
        count++;

        cout << "Order " << order << " placed successfully." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No orders to serve." << endl;
            return;
        }

        int servedOrder = orders[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_ORDERS;
        }

        count--;

        cout << "Order " << servedOrder << " served." << endl;
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders currently." << endl;
            return;
        }

        cout << "Current orders: ";
        int i = front;
        do {
            cout << orders[i] << " ";
            i = (i + 1) % MAX_ORDERS;
        } while (i != (rear + 1) % MAX_ORDERS);
        cout << endl;
    }
};

int main() {
    CircularQueue pizzaParlor;

    int choice, order;

    do {
        cout << "\nPizza Parlor Simulation Menu:\n";
        cout << "1. Place an order\n";
        cout << "2. Serve an order\n";
        cout << "3. Display current orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter order number: ";
                cin >> order;
                pizzaParlor.enqueue(order);
                break;

            case 2:
                pizzaParlor.dequeue();
                break;

            case 3:
                pizzaParlor.displayOrders();
                break;

            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
