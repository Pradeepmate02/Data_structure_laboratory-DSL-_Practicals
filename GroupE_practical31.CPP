#include <iostream>
using namespace std;

class Deque {
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    Deque(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void addFront(int value) {
        if (isFull()) {
            cout << "Deque is full.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }
        arr[front] = value;
    }

    void addRear(int value) {
        if (isFull()) {
            cout << "Deque is full.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Elements in deque: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < capacity; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    ~Deque() {
        delete[] arr;
    }
};

int main() {
    Deque deque(5);
    int choice, value;

    do {
        cout << "\n--- Deque Menu ---\n";
        cout << "1. Add to Front\n";
        cout << "2. Add to Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Display Deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add to front: ";
                cin >> value;
                deque.addFront(value);
                break;
            case 2:
                cout << "Enter value to add to rear: ";
                cin >> value;
                deque.addRear(value);
                break;
            case 3:
                deque.deleteFront();
                break;
            case 4:
                deque.deleteRear();
                break;
            case 5:
                deque.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
