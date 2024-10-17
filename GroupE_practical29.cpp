#include <iostream>
#include <string>
using namespace std;

struct Job {
    string jobName;
    Job* next;
};

class JobQueue {
    Job* front;
    Job* rear;

public:
    JobQueue() {
        front = nullptr;
        rear = nullptr;
    }

    void addJob(string jobName) {
        Job* newJob = new Job{jobName, nullptr};
        if (rear == nullptr) {
            front = rear = newJob;
            return;
        }
        rear->next = newJob;
        rear = newJob;
    }

    void deleteJob() {
        if (front == nullptr) {
            cout << "No jobs in the queue.\n";
            return;
        }
        Job* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        cout << "Job deleted: " << temp->jobName << endl;
        delete temp;
    }

    void displayJobs() {
        if (front == nullptr) {
            cout << "No jobs in the queue.\n";
            return;
        }
        Job* temp = front;
        cout << "Jobs in the queue:\n";
        while (temp != nullptr) {
            cout << temp->jobName << endl;
            temp = temp->next;
        }
    }
};

int main() {
    JobQueue queue;
    int choice;
    string jobName;

    do {
        cout << "\n--- Job Queue Menu ---\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                cin >> jobName;
                queue.addJob(jobName);
                break;
            case 2:
                queue.deleteJob();
                break;
            case 3:
                queue.displayJobs();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
