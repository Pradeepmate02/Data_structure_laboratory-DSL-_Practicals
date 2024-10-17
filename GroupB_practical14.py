def sel_sort(nums):
    for i in range(len(nums) - 1):
        min_idx = i
        for j in range(i + 1, len(nums)):
            if nums[j] < nums[min_idx]:
                min_idx = j
        nums[i], nums[min_idx] = nums[min_idx], nums[i]
    return nums

def bub_sort(nums):
    for i in range(len(nums)):
        for j in range(1, len(nums) - i):
            if nums[j - 1] > nums[j]:
                nums[j - 1], nums[j] = nums[j], nums[j - 1]
    return nums

def show_top_five(nums):
    sorted_sel = sel_sort(nums.copy())
    print("Top five scores using Selection Sort:")
    for score in sorted_sel[-5:][::-1]:
        print(score)

    sorted_bub = bub_sort(nums.copy())
    print("\nTop five scores using Bubble Sort:")
    for score in sorted_bub[-5:][::-1]:
        print(score)

def main():
    n = int(input("Enter the number of students: "))
    scores = []

    for i in range(n):
        while True:
            score = float(input(f"Enter the percentage of student {i + 1} (0-100): "))
            if 0 <= score <= 100:
                scores.append(score)
                break
            else:
                print("Invalid input. Please enter a percentage between 0 and 100.")

    show_top_five(scores)

if __name__ == "__main__":
    main()
