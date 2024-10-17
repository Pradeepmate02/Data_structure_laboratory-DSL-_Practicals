def quick_sort(data):
    if len(data) <= 1:
        return data
    pivot = data[len(data) // 2]
    left = [x for x in data if x < pivot]
    middle = [x for x in data if x == pivot]
    right = [x for x in data if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def display_top_five_scores(scores):
    sorted_scores = quick_sort(scores)
    print("Top five scores:")
    top_five = sorted_scores[-5:][::-1] if len(sorted_scores) >= 5 else sorted_scores[::-1]
    for score in top_five:
        print(score)

def main():
    num_students = int(input("Enter the number of students: "))
    scores = []

    for i in range(num_students):
        while True:
            score = float(input(f"Enter the percentage of student {i + 1} (0-100): "))
            if 0 <= score <= 100:
                scores.append(score)
                break
            else:
                print("Invalid input. Please enter a percentage between 0 and 100.")

    display_top_five_scores(scores)

if __name__ == "__main__":
    main()
