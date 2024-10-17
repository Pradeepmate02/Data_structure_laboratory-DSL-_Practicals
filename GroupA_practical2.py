def avg_score(scores):
    total = 0
    cnt = 0
    for s in scores:
        if s != -1:
            total += s
            cnt += 1
    if cnt == 0:
        return 0
    return total / cnt

def high_low_score(scores):
    high = None
    low = None
    for s in scores:
        if s != -1:
            if high is None or s > high:
                high = s
            if low is None or s < low:
                low = s
    return high, low

def count_absent(scores):
    abs_cnt = 0
    for s in scores:
        if s == -1:
            abs_cnt += 1
    return abs_cnt

def max_freq_mark(scores):
    freq = {}
    for s in scores:
        if s != -1:
            if s not in freq:
                freq[s] = 1
            else:
                freq[s] += 1

    max_freq_mark = None
    max_freq = 0

    for s, f in freq.items():
        if f > max_freq:
            max_freq = f
            max_freq_mark = s

    return max_freq_mark

def main():
    n = int(input("Enter the number of students: "))
    scores = []

    for i in range(n):
        while True:
            score = float(input(f"Enter the marks of student {i + 1} (-1 if absent): "))
            if score == -1 or (0 <= score <= 30):
                scores.append(score)
                break
            else:
                print("Invalid input! Please enter a value between 0 and 30 or -1 for absent.")

    while True:
        print("\n--- Menu ---")
        print("1. Calculate Average Score")
        print("2. Find Highest and Lowest Scores")
        print("3. Count Absent Students")
        print("4. Find Mark with Highest Frequency")
        print("5. Exit")
        
        choice = int(input("Enter your choice (1-5): "))

        if choice == 1:
            print(f"Average score of the class: {avg_score(scores):.2f}")
        elif choice == 2:
            high, low = high_low_score(scores)
            if high is not None and low is not None:
                print(f"Highest score: {high}, Lowest score: {low}")
            else:
                print("No valid scores available.")
        elif choice == 3:
            print(f"Number of absent students: {count_absent(scores)}")
        elif choice == 4:
            most_freq = max_freq_mark(scores)
            if most_freq is not None:
                print(f"Mark with highest frequency: {most_freq}")
            else:
                print("No valid scores to calculate frequency.")
        elif choice == 5:
            print("Exiting the program.")
            break
        else:
            print("Invalid choice! Please choose an option between 1 and 5.")

if __name__ == "__main__":
    main()
