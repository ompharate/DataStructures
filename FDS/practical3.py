def selectionSort(marks,n):
    for i in range(n-1):
        minIndex = i
        for j in range(i,n):
            if marks[j] < marks[minIndex]:
                temp = marks[minIndex]
                marks[minIndex] = marks[j]
                marks[j] = temp
    print(marks)

def bubbleSort(marks,n):
    for i in range(n-1):
        for j in range(n-i-1):
            if marks[j] > marks[j+1]:
                temp = marks[j]
                marks[j] = marks[j+1]
                marks[j+1] = temp
    
    print("Top five students marks is")
    for i in range(5):
        print(marks[i],end=',')

def main():
    marks = []
    n = int(input("How many marks do you wanna enter?"))
    for i in range(n):
        num = int(input("Enter The marks"))
        marks.append(num)

    print("1] Selection Sort ")
    print("2] Bubble Sort ")
    ch = int(input("Enter Choice"))
    if ch == 1:
        selectionSort(marks,n)
    elif ch == 2:
        bubbleSort(marks,n)
    else:
        print("Wrong input")
main()