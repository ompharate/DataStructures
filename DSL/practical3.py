def linearSearch(arr,n,key):
    for i in arr:
        if i==key:
            print("found")
            return
    print("not found")

def sentinalSearch(arr,n,key):
    last = arr[n-1]
    arr[n-1] = last

    i=0
    while(arr[i]!=key):
        i+=1

    arr[n-1] = last

    if((i<n-1 or (arr[n-1]==key))):
        print("found At",i)
    else:
        print("not found")  

def main():
    arr = []
    n = int(input("How many roll numbers you want to"))
    for i in range(n):
        num = int(input("Enter roll number"))
        arr.append(num)

    print("1]Linear Search")
    print("2]Sentinal Search")
    ch = int(input(""))

    
    key = int(input("Enter the key to search"))
    if ch==1:
        linearSearch(arr,n,key)
    elif ch==2:
        sentinalSearch(arr,n,key)
    else:
        print("Wrong  input")
main()