#!/usr/bin/python
# A simple program to reverse the string.

# Use a simple algorithm.
def rev_algo_string(a):
    final = ""
    for ch in a:
        final = ch + final

    print(final)

# This is for a directly executed function.
if __name__ == '__main__':
    a = raw_input("Enter the String: ")
    rev_algo_string(a)
