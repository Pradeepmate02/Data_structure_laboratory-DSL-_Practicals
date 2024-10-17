def lin_search(rolls, target):
    for i in range(len(rolls)):
        if rolls[i] == target:
            return True
    return False

def sent_search(rolls, target):
    n = len(rolls)
    last = rolls[n - 1]
    rolls[n - 1] = target
    
    i = 0
    while rolls[i] != target:
        i += 1
    
    rolls[n - 1] = last
    
    return i < n - 1

def main():
    n = int(input("Enter the number of students who attended the training program: "))
    rolls = []

    for i in range(n):
        roll = int(input(f"Enter roll number of student {i + 1}: "))
        rolls.append(roll)

    while True:
        print("\n--- Training Program Attendance ---")
        print("1. Search using Linear Search")
        print("2. Search using Sentinel Search")
        print("3. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            target = int(input("Enter the roll number to search: "))
            if lin_search(rolls, target):
                print(f"Student with roll number {target} attended the training program (Linear Search).")
            else:
                print(f"Student with roll number {target} did not attend the training program (Linear Search).")
        
        elif choice == 2:
            target = int(input("Enter the roll number to search: "))
            if sent_search(rolls, target):
                print(f"Student with roll number {target} attended the training program (Sentinel Search).")
            else:
                print(f"Student with roll number {target} did not attend the training program (Sentinel Search).")
        
        elif choice == 3:
            print("Exiting...")
            break
        
        else:
            print("Invalid choice, please try again.")

if __name__ == "__main__":
    main()
