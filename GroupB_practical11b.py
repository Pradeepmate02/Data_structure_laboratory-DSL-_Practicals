def binary_search(student_roll_numbers, search_roll_number):
    start, end = 0, len(student_roll_numbers) - 1
    while start <= end:
        mid = start + (end - start) // 2
        if student_roll_numbers[mid] == search_roll_number:
            return True
        elif student_roll_numbers[mid] < search_roll_number:
            start = mid + 1
        else:
            end = mid - 1
    return False

def fibonacci_search(student_roll_numbers, search_roll_number):
    fib_minus_2 = 0
    fib_minus_1 = 1
    fib_number = fib_minus_1 + fib_minus_2
    while fib_number < len(student_roll_numbers):
        fib_minus_2 = fib_minus_1
        fib_minus_1 = fib_number
        fib_number = fib_minus_1 + fib_minus_2

    offset = -1

    while fib_number > 1:
        index = min(offset + fib_minus_2, len(student_roll_numbers) - 1)

        if student_roll_numbers[index] < search_roll_number:
            fib_number = fib_minus_1
            fib_minus_1 = fib_minus_2
            fib_minus_2 = fib_number - fib_minus_1
            offset = index
        elif student_roll_numbers[index] > search_roll_number:
            fib_number = fib_minus_2
            fib_minus_1 -= fib_minus_2
            fib_minus_2 = fib_number - fib_minus_1
        else:
            return True

    if fib_minus_1 and offset + 1 < len(student_roll_numbers) and student_roll_numbers[offset + 1] == search_roll_number:
        return True

    return False

def main():
    number_of_students = int(input("Enter the number of students who attended the training program: "))
    student_roll_numbers = []

    for i in range(number_of_students):
        roll_number = int(input(f"Enter roll number of student {i + 1}: "))
        student_roll_numbers.append(roll_number)

    student_roll_numbers.sort()

    while True:
        print("\n--- Training Program Attendance ---")
        print("1. Search using Binary Search")
        print("2. Search using Fibonacci Search")
        print("3. Exit")
        user_choice = int(input("Enter your choice: "))

        if user_choice == 1:
            search_roll_number = int(input("Enter the roll number to search: "))
            if binary_search(student_roll_numbers, search_roll_number):
                print(f"Student with roll number {search_roll_number} attended the training program (Binary Search).")
            else:
                print(f"Student with roll number {search_roll_number} did not attend the training program (Binary Search).")
        
        elif user_choice == 2:
            search_roll_number = int(input("Enter the roll number to search: "))
            if fibonacci_search(student_roll_numbers, search_roll_number):
                print(f"Student with roll number {search_roll_number} attended the training program (Fibonacci Search).")
            else:
                print(f"Student with roll number {search_roll_number} did not attend the training program (Fibonacci Search).")
        
        elif user_choice == 3:
            print("Exiting...")
            break
        
        else:
            print("Invalid choice, please try again.")

if __name__ == "__main__":
    main()
