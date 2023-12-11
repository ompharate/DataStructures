

def partition(marks,low,high):
    pivot = marks[high]

    i = low - 1
    for j in range(low,high):
        if marks[j] <= pivot:
            i = i + 1
            temp = marks[i]
            marks[i] = marks[j]
            marks[j] = temp

    temp = marks[high]
    marks[high] = marks[i+1]
    marks[i+1] = temp

    return i + 1

def quickSort(marks,low,high):
    if low < high:
        pivot = partition(marks,low,high)
        quickSort(marks,low,pivot-1)
        quickSort(marks,pivot+1,high)


def main():
    marks = []
    n = int(input("How many marks do you wanna enter?"))
    for i in range(n):
        num = int(input("Enter The marks"))
        marks.append(num) 

    low = 0
    high = n-1
    quickSort(marks,low,high)
    print(marks,end=",")
main()