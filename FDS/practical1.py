
def averageScore(marks,n):
    avg = 0
    sum = 0
    for i in marks:
        sum = sum + i
    avg = sum / n
    print("Average Score is ",avg)

def highestScoreAndLowestScore(marks,n):
    min = marks[0]
    max = marks[0]

    for i in marks:
        if i < min:
            min = i
        if i  > max:
            max = i

    print("Highest Score is ",max)
    print("Lowest Score is ",min)

def absentStudents(marks,n):
    count = 0
    for i in marks:
        if i == 0:
            count = count + 1
    print("No of absent students is ",count)

def displayMarksWithHighestFrequency(marks,n):
    frequencies = 0
    count = 0
    ele = 0

    for i in marks:
        for j in marks:
            if i==j:
                count = count + 1
        if count > frequencies:
            frequencies = count
            ele = i
        count = 0
    print("The highest frequency is " , frequencies , "of the number ",ele)


def main():
    arr = []
    n = int(input("How many marks do you want to enter?"))
    for i in range(n):
        num = int(input("Enter the marks"))
        arr.append(num)
    

    print("1]Average Score")
    print("2]Highest Scores and lowest Score")
    print("3]Count of students who were  absent for the test")
    print("4]Display marks with hight frequencies")
    ch = int(input("Enter the choise"))

    if(ch==1):
        averageScore(arr,n)
    elif(ch==2):
        highestScoreAndLowestScore(arr,n)
    elif(ch==3):
        absentStudents(arr,n)
    elif(ch==4):
        displayMarksWithHighestFrequency(arr,n)
    else:
        print("Wrong input")

main()