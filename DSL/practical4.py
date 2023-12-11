import math

def binarySearch(arr,low,high,key):
    if low <= high:
        mid = math.floor((low + high )/ 2)
        if arr[mid] == key:
            print("we found at",mid)
            return
        elif key < arr[mid]:
            binarySearch(arr,0,mid-1,key)
        else:
            binarySearch(arr,mid+1,high,key)
    else:
        print("Eelement not present")


def main():
    arr = [1,3,6,8,9,10,34]
    n = len(arr)
    key = int(input("Enter the key to search:"))    
    binarySearch(arr,0,n,key)
main()