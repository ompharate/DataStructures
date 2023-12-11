
def longestStr(str):
    count = 0
    result = 0
    word = ""

    for i in str:
        if i!= ' ':
            count +=1
            word+=i
        else:
            if count>result:
                result = count
            count = 0
            word = ""      
    print("The string with longest length is",word,"with length",count)      

def frequencyStr(str,ch):
    count=0
    for i in str:
        if ch==i:
            count +=1
    print("the character",ch,"is occured",count,"times")

def palindrome(str):
    low = 0
    high = len(str) -1

    while low < high:
        if str[low]!=str[high]:
            print("not palindrome")        
            return
        low+=1
        high-=1
    print("palindrome")
    

def indexSubstring(str,subStr):
    words = str.split()
    for word in words:
        if word == subStr:
            print(str.find(word))
            return 
    print("-1")

def word_occurrences(string):
    words = string.split()
    cnt = 0
    for word in words:
        cnt = cnt + 1
    print(cnt)



def main():
    str =  input("Enter the input string:")

    print("1]To display word with the longest length")
    print("2]To determines the frequency of occurrence of particular character in the string")
    print("3] To check whether given string is palindrome or not")
    print("4] To display index of first appearance of thesubstring ")
    print("5] To count the occurrences of each word in a given string")
    ch = int(input("Enter the choice:"))

    if ch == 1:
        longestStr(str)
    elif ch == 2:
        ch = input("Enter the character")
        frequencyStr(str,ch)
    elif ch == 3:
        palindrome(str)
    elif ch == 4:
        ch = input("Enter the substring")
        indexSubstring(str,ch)
    elif ch == 5:
        word_occurrences(str)
    else:
        print("Wrong input")

main()