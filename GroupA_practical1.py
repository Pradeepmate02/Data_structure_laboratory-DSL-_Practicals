def menu():
    cricket_players = []
    football_players = []
    badminton_players = []
    
    cricket_count = int(input("Enter the number of students who play cricket: "))
    football_count = int(input("Enter the number of students who play football: "))
    badminton_count = int(input("Enter the number of students who play badminton: "))
    
    for i in range(cricket_count):
        cricket_roll = int(input(f"Enter the roll number of student who plays cricket {i + 1}: "))
        while cricket_roll in cricket_players or cricket_roll <= 0:
            cricket_roll = int(input(f"Please enter a valid and unique roll number for student {i + 1} who plays cricket: "))
        cricket_players.append(cricket_roll)
    
    for i in range(football_count):
        football_roll = int(input(f"Enter the roll number of student who plays football {i + 1}: "))
        while football_roll in football_players or football_roll <= 0:
            football_roll = int(input(f"Please enter a valid and unique roll number for student {i + 1} who plays football: "))
        football_players.append(football_roll)
    
    for i in range(badminton_count):
        badminton_roll = int(input(f"Enter the roll number of student who plays badminton {i + 1}: "))
        while badminton_roll in badminton_players or badminton_roll < 1:
            badminton_roll = int(input(f"Please enter a valid and unique roll number for student {i + 1} who plays badminton: "))
        badminton_players.append(badminton_roll)

    continue_flag = 0
    while continue_flag == 0:
        print("\nStudents who play cricket are:", cricket_players)
        print("Students who play football are:", football_players)
        print("Students who play badminton are:", badminton_players)
        print("-----------MENU----------")
        print("\n1. List of students who play both cricket and badminton")
        print("2. List of students who play either cricket or badminton but not both")
        print("3. Number of students who play neither cricket nor badminton")
        print("4. Number of students who play cricket and football but not badminton")
        print("5. Quit")
        
        choice = int(input("Choose your option: "))
        while choice < 1 or choice > 5:
            choice = int(input("Invalid choice. Please choose again: "))
        
        if choice == 1:
            print("List of students who play cricket and badminton both :- ", intersection(cricket_players, badminton_players))
            proceed = input("Do you want to continue(yes or no)? = ")
            while proceed != "yes" and proceed != "no":
                proceed = input("Please enter answer in yes or no = ")
            if proceed == "no":
                continue_flag = 1
        elif choice == 2:
            print("List of students who play cricket or badminton but not both :- ", difference(union(cricket_players, badminton_players), intersection(cricket_players, badminton_players)))
            proceed = input("Do you want to continue(yes or no)? = ")
            while proceed != "yes" and proceed != "no":
                proceed = input("Please enter answer in yes or no = ")
            if proceed == "no":
                continue_flag = 1
        elif choice == 3:
            print("Number of students who play neither cricket nor badminton :- ", len(difference(difference(football_players, badminton_players), cricket_players)))
            proceed = input("Do you want to continue(yes or no)? = ")
            while proceed != "yes" and proceed != "no":
                proceed = input("Please enter answer in yes or no = ")
            if proceed == "no":
                continue_flag = 1
        elif choice == 4:
            print("Number of students who play cricket and football but not badminton :- ", len(difference(intersection(cricket_players, football_players), badminton_players)))
            proceed = input("Do you want to continue(yes or no)? = ")
            while proceed != "yes" and proceed != "no":
                proceed = input("Please enter answer in yes or no = ")
            if proceed == "no":
                continue_flag = 1
        else:
            continue_flag = 1

def union(list_a, list_b):
    union_list = []
    for element in list_a:
        if element not in union_list:
            union_list.append(element)
    for element in list_b:
        if element not in union_list:
            union_list.append(element)
    return union_list

def intersection(list_a, list_b):
    intersection_list = []
    for element in list_a:
        if element in list_b and element not in intersection_list:
            intersection_list.append(element)
    return intersection_list

def difference(list_a, list_b):
    difference_list = []
    for element in list_a:
        if element not in list_b and element not in difference_list:
            difference_list.append(element)
    return difference_list

menu()
