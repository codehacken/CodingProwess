#!/usr/bin/python
# Head ends here

def lonelyinteger(a):
    tempMap = {}
    for num in a:
        if (num not in tempMap):
            tempMap[num] = 1
        else:
            tempMap[num] += 1

    for num in tempMap:
        if (tempMap[num] == 1):
            return num

    return -1

# Tail starts here
if __name__ == '__main__':
    a = raw_input("Enter the Set of Numbers: ")
    b = map(int, a.strip().split(" "))
    print lonelyinteger(b)
