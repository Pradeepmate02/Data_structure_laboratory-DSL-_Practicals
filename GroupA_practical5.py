def menu():
    txt = input("\nEnter the line:")
    flag = 0
    while flag == 0:
        print("\n---------------------MENU---------------------\n")
        print("\n1. To display word with the longest length")
        print("2. To determine the frequency of occurrence of a particular character in the string")
        print("3. To check whether the given string is palindrome or not")
        print("4. To display the index of the first appearance of the substring")
        print("5. To count the occurrences of each word in a given string")
        print("6. Quit")

        option = int(input("\nEnter the option number:"))
        while option > 6 or option < 1:
            option = int(input("\nEnter a valid option number:"))

        if option == 1:
            print("\nLongest word in the given string: " + longest_word(txt))
        elif option == 2:
            char_freq(txt)
        elif option == 3:
            if is_palindrome(txt):
                print("\nGiven string is palindrome")
            else:
                print("\nGiven string is not palindrome")
        elif option == 4:
            print("\nFirst occurrence of substring: " + str(substring_idx(txt)))
        elif option == 5:
            word_count(txt)
        else:
            break


def longest_word(txt):
    max_w = ""
    curr_w = ""
    for ch in txt + " ":
        if ch != " ":
            curr_w += ch
        else:
            if len(max_w) < len(curr_w):
                max_w = curr_w
            curr_w = ""
    return max_w


def char_freq(txt):
    char = input("\nEnter the character to get its frequency: ").lower()
    count = 0
    for ch in txt:
        if ch.lower() == char:
            count += 1
    print("\nFrequency of " + char + ": " + str(count))


def is_palindrome(txt):
    left = 0
    right = len(txt) - 1
    while left < right:
        if txt[left].lower() != txt[right].lower():
            return False
        left += 1
        right -= 1
    return True


def substring_idx(txt):
    sub = input("\nEnter the substring to be found inside the line: ").lower()
    idx = -1
    for i in range(len(txt)):
        if i + len(sub) <= len(txt):
            if txt[i:i + len(sub)].lower() == sub:
                idx = i
                break
    return idx


def word_count(txt):
    txt += " "
    words = []
    temp_w = ""
    for ch in txt:
        if ch != " ":
            temp_w += ch.lower()
        else:
            if temp_w == " ":
                continue
            words.append(temp_w)
            temp_w = ""
    word_dict = {}
    for word in words:
        if in_dict(word_dict, word):
            word_dict[word] += 1
        else:
            word_dict[word] = 1
    print(word_dict)


def in_dict(word_dict, key):
    return key in word_dict


menu()
