#!/usr/bin/python
# Head ends here

def findIndex(value, numList):
    i=0
    for num in numList:
        if(num == value):
            return i
        i += 1

    return -1

# Tail starts here
if __name__ == '__main__':
    value = input("Enter the Value: ")
    numList = map(int, raw_input("Enter the Number List: ").strip().split(" "))
    print findIndex(value, numList)
