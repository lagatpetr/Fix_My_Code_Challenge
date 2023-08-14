#!/usr/bin/python3

import sys

def fizzbuzz(n):
    # Initialize an empty list to store the results
    tmp_result = []

    # Loop through numbers from 1 to n
    for i in range(1, n + 1):
        if (i % 3) == 0 and (i % 5) == 0:
            # If divisible by both 3 and 5, append "FizzBuzz" to the results
            tmp_result.append("FizzBuzz")
        elif (i % 3) == 0:
            # If divisible by 3, append "Fizz" to the results
            tmp_result.append("Fizz")
        elif (i % 5) == 0:
            # If divisible by 5, append "Buzz" to the results
            tmp_result.append("Buzz")
        else:
            # Otherwise, append the number as a string to the results
            tmp_result.append(str(i))

    # Join the results with spaces to form the final output
    return " ".join(tmp_result)

if __name__ == '__main__':
    # Check if an argument is provided
    if len(sys.argv) <= 1:
        print("Missing number")
        print("Usage: ./0-fizzbuzz.py <number>")
        print("Example: ./0-fizzbuzz.py 89")
        sys.exit(1)

    # Convert the argument to an integer
    number = int(sys.argv[1])

    # Call the fizzbuzz function and get the result
    result = fizzbuzz(number)

    # Print the result
    print(result)

