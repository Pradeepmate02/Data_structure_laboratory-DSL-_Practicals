#include <iostream>

using namespace std;

struct Seat {
    int seatNumber;
    bool isBooked;
    Seat* next;
    Seat* prev;
};

class Row {
public:
    Seat* head;
    Row() : head(nullptr) {}

    void createSeats() {
        Seat* last = nullptr;
        for (int i = 1; i <= 7; i++) {
            Seat* newSeat = new Seat{i, false, nullptr, nullptr};
            if (!head) {
                head = newSeat;
                newSeat->next = newSeat->prev = newSeat;
            } else {
                last->next = newSeat;
                newSeat->prev = last;
                newSeat->next = head;
                head->prev = newSeat;
            }
            last = newSeat;
        }
    }

    void displayAvailableSeats() {
        Seat* temp = head;
        bool available = false;
        do {
            if (!temp->isBooked) {
                cout << temp->seatNumber << " ";
                available = true;
            }
            temp = temp->next;
        } while (temp != head);
        if (!available) {
            cout << "No available seats";
        }
        cout << endl;
    }

    void bookSeat(int seatNum) {
        Seat* temp = head;
        do {
            if (temp->seatNumber == seatNum) {
                if (!temp->isBooked) {
                    temp->isBooked = true;
                    cout << "Seat " << seatNum << " is booked successfully.\n";
                } else {
                    cout << "Seat " << seatNum << " is already booked.\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Invalid seat number.\n";
    }

    void cancelBooking(int seatNum) {
        Seat* temp = head;
        do {
            if (temp->seatNumber == seatNum) {
                if (temp->isBooked) {
                    temp->isBooked = false;
                    cout << "Booking of seat " << seatNum << " is cancelled.\n";
                } else {
                    cout << "Seat " << seatNum << " is not booked.\n";
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Invalid seat number.\n";
    }
};

int main() {
    Row rows[10];
    for (int i = 0; i < 10; i++) {
        rows[i].createSeats();
    }

    int choice, rowNum, seatNum;

    do {
        cout << "\nCinemax Theater Ticket Booking System\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter row number (1-10): ";
                cin >> rowNum;
                if (rowNum >= 1 && rowNum <= 10) {
                    cout << "Available seats in row " << rowNum << ": ";
                    rows[rowNum - 1].displayAvailableSeats();
                } else {
                    cout << "Invalid row number.\n";
                }
                break;

            case 2:
                cout << "Enter row number (1-10): ";
                cin >> rowNum;
                if (rowNum >= 1 && rowNum <= 10) {
                    cout << "Enter seat number (1-7): ";
                    cin >> seatNum;
                    rows[rowNum - 1].bookSeat(seatNum);
                } else {
                    cout << "Invalid row number.\n";
                }
                break;

            case 3:
                cout << "Enter row number (1-10): ";
                cin >> rowNum;
                if (rowNum >= 1 && rowNum <= 10) {
                    cout << "Enter seat number (1-7): ";
                    cin >> seatNum;
                    rows[rowNum - 1].cancelBooking(seatNum);
                } else {
                    cout << "Invalid row number.\n";
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
