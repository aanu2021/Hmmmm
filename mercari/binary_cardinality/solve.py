# Question 2 : Cardinality Sorting

# The binary cardinality of a number is the total number of 1's it contains in its binary represerntation. For example, the decimal integer 2010 Corresponds to the binary number 10100↓2
# There are 2 1's in the binary representation so its binary cardinality is 2.
# Given an array of decimal integers, sort it ascending first by binary cardinality, then by decimal value. Return the resulting array.
# Example
# n=4 nums = [1 2, 3,4]



def solution(arr):
    arr.sort(key=lambda x: (bin(x).count("1"), x))
    return arr

nums = [1,2,3,4]
print(solution(nums))
