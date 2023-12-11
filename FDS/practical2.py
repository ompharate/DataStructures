def addition(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in  range(len(matrix1[0])):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)

    print(result)

def multiplication(matrix1, matrix2):
    if len(matrix1[0]) != len(matrix2):
        print("cannot multiplication")
        return
    
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            ele = 0
            for k in range(len(matrix2)):
                ele += matrix1[i][k] * matrix2[k][j]
            row.append(ele)
        result.append(row)

    print(result)

def transpose(matrix1):
    result = []
    for i in range(len(matrix1)):
        res = []
        for j in range(len(matrix1[0])):
            res.append(matrix1[j][i])
        result.append(res)
    print(result)



def main():

    matrix1 = [] 
    matrix2 = []

    print("For matrix1")
    row = int(input("Enter the number of rows "))
    col = int(input("Enter the number of columns "))

    for i in range(0,row):
        row = []
        for i in range(0,col):
            num = int(input("Enter the row "))
            row.append(num)
        matrix1.append(row)


    print("For matrix2")
    row = int(input("Enter the number of rows "))
    col = int(input("Enter the number of columns "))

    for i in range(0,row):
        row = []
        for i in range(0,col):
            num = int(input("Enter the row "))
            row.append(num)
        matrix2.append(row)

    print("1]Addition of matrix ")
    print("2]Multiplication of matrix ")
    print("3]Transpose of matrix ")

    ch = int(input("Enter the choice "))
    if ch==1:
        addition(matrix1,matrix2)
    elif ch==2:
        multiplication(matrix1,matrix2)
    elif ch==3:
        transpose(matrix1)
    else:
        print("Wrong choice")




main()