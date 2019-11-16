"""
Challenge Description:
    Given an unordered list of numbers, find a pair that when summed matches a given number.
        Example 1:   List - [1,2,3,9];   Sum - 8  ->  No pair in the given list fits the conditions.
        Example 2:   List - [1,2,4,4];   Sum - 8  ->  1 pair in the given list fits the conditions.

Link to Challenge:
    https://www.youtube.com/watch?v=XKu_SEDAykw
"""

# My Solution
original_list = [-1, 1, 2, 4, 4, 1, 7, 1, 1, 1, 7, 9]
number = 8

print(min(original_list))
print(max(original_list))

# Find the first num that can be used to make a pair, the second number will be found
# based on the given number and the first number of the pair.
for num1 in range((number//2)+1):   # This solution does not take into account negative numbers!
    if num1 in original_list:
        # Find second number
        num2 = number - num1

        # Check second num exists in the list
        if num2 in original_list:
            print("Pair Found: ", num1, " & ", num2)
            num1_occurrences = original_list.count(num1)
            num2_occurrences = original_list.count(num2)

            # Slight exception to the algorithm
            if num1 == num2:
                num1_occurrences //= 2
                num2_occurrences //= 2

            print("Pair Occurrences: ", num1_occurrences*num2_occurrences)
