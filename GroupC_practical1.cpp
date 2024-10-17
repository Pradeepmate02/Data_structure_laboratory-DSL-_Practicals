#include <iostream>
#include <string>

using namespace std;

struct Member {
    string prn;
    string name;
    Member* next;
};

class Club {
private:
    Member* head;

public:
    Club() : head(nullptr) {}

    void addMember(const string& memberPRN, const string& memberName) {
        Member* newMember = new Member{memberPRN, memberName, nullptr};
        if (!head) {
            head = newMember;
        } else {
            Member* currentMember = head;
            while (currentMember->next) {
                currentMember = currentMember->next;
            }
            currentMember->next = newMember;
        }
    }

    void removeMember(const string& memberPRN) {
        if (!head) {
            cout << "Club is empty, no members to delete.\n";
            return;
        }

        if (head->prn == memberPRN) {
            Member* memberToDelete = head;
            head = head->next;
            delete memberToDelete;
            cout << "Member removed successfully.\n";
            return;
        }

        Member* currentMember = head;
        Member* previousMember = nullptr;

        while (currentMember && currentMember->prn != memberPRN) {
            previousMember = currentMember;
            currentMember = currentMember->next;
        }

        if (!currentMember) {
            cout << "Member not found.\n";
            return;
        }

        previousMember->next = currentMember->next;
        delete currentMember;
        cout << "Member removed successfully.\n";
    }

    int getTotalMembers() const {
        int memberCount = 0;
        Member* currentMember = head;
        while (currentMember) {
            memberCount++;
            currentMember = currentMember->next;
        }
        return memberCount;
    }

    void showMembers() const {
        if (!head) {
            cout << "No members in the club.\n";
            return;
        }

        cout << "Members of the Pinnacle Club:\n";
        Member* currentMember = head;
        while (currentMember) {
            cout << "PRN: " << currentMember->prn << ", Name: " << currentMember->name << endl;
            currentMember = currentMember->next;
        }
    }

    void mergeClubs(Club& otherClub) {
        if (!head) {
            head = otherClub.head;
        } else {
            Member* currentMember = head;
            while (currentMember->next) {
                currentMember = currentMember->next;
            }
            currentMember->next = otherClub.head;
        }
    }
};

int main() {
    Club divisionA, divisionB;
    int menuChoice;
    string memberPRN, memberName;

    do {
        cout << "\n--- Pinnacle Club Management ---\n";
        cout << "1. Add Member to Division A\n";
        cout << "2. Add Member to Division B\n";
        cout << "3. Delete Member from Division A\n";
        cout << "4. Delete Member from Division B\n";
        cout << "5. Display Members of Division A\n";
        cout << "6. Display Members of Division B\n";
        cout << "7. Compute Total Members in Division A\n";
        cout << "8. Compute Total Members in Division B\n";
        cout << "9. Merge Division B into Division A\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> menuChoice;

        switch (menuChoice) {
            case 1:
                cout << "Enter PRN: ";
                cin >> memberPRN;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, memberName);
                divisionA.addMember(memberPRN, memberName);
                break;
            case 2:
                cout << "Enter PRN: ";
                cin >> memberPRN;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, memberName);
                divisionB.addMember(memberPRN, memberName);
                break;
            case 3:
                cout << "Enter PRN of member to delete: ";
                cin >> memberPRN;
                divisionA.removeMember(memberPRN);
                break;
            case 4:
                cout << "Enter PRN of member to delete: ";
                cin >> memberPRN;
                divisionB.removeMember(memberPRN);
                break;
            case 5:
                divisionA.showMembers();
                break;
            case 6:
                divisionB.showMembers();
                break;
            case 7:
                cout << "Total members in Division A: " << divisionA.getTotalMembers() << endl;
                break;
            case 8:
                cout << "Total members in Division B: " << divisionB.getTotalMembers() << endl;
                break;
            case 9:
                divisionA.mergeClubs(divisionB);
                cout << "Division B members merged into Division A.\n";
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (menuChoice != 10);

    return 0;
}
