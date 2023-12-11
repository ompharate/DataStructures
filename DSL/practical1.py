
def bothCricketBadminton(groupA,groupB):
    for i in groupA:
        if i in groupB:
            print(i,end=" ") 

def eitherCriBad(groupA,groupB):
    for i in groupA:
        if i not in groupB:
            print(i,end=" ")
        
    for i in groupB:
        if i not in groupA:
            print(i,end=" ")

def neitherCriNorBad(groupA,groupB,stu):
    for i in stu:
        if i not in groupA and i not in groupB:
            print(i,end=" ")

def criFotNotBad(groupA,groupB,groupC):   
    for i in groupA:
        if i in groupC and i not in groupB:
            print(i,end=" ") 

def main():
    stu = [1,8,3,7,4,15,9,6,2,7,11]
    groupA = [1,8,3,7,4] #cricket
    groupB = [9,3,6,2,1] # badminton
    groupC = [7,4,9,1,6] # football

    
    print("1]List of students who play both cricket and badminton")
    print("2]List of students who play either cricket or badminton but not both")
    print("3]Number of students who play neither cricket nor badminton")
    print("4]Number of students who play cricket and football but not badminton.")
    ch = int(input(""))

    if ch==1:
        bothCricketBadminton(groupA,groupB)
    if ch==2:
        eitherCriBad(groupA,groupB)
    if ch==3:
        neitherCriNorBad(groupA,groupB,stu)
    if ch==4:
        criFotNotBad(groupA,groupB,groupC)
    else:
        print("Invalid input")


main()