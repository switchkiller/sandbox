__author__="bond007"

def binary_search(array, item, hi=None, lo=0):
    hi=hi or len(array)
    if hi<lo:
        return False
    mid=(hi+lo)//2
    if item == array[mid]:
        return mid
    elif item<array[mid]:
        return binary_search(array, item, hi=mid-1, lo=lo)
    else:
        return binary_search(array,item,hi=hi, lo=mid+1)

'''array=list()
num=int(input("Number of element you want to enter: "))
for i in range(int(num)):
    n=int(input())
    array.append(int(n))
k=int(input("Enter the search key: "))
print(binary_search(array,k)+1)'''

if __name__ == '__main__':
    import doctest
    doctest.testmod()
