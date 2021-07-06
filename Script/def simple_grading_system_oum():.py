#erwanfadlys@oum.edu.my / matrix # 881221495119001 / CBCP 2101
#naming convention used in this program is camelCase 
numberOfStudentLst = [] #store number of student data as list
def numberOfStudent():
    numberOfStudent = int(input("Enter number of students: "))
    numberOfStudentLst.append(numberOfStudent)

numberOfCourseLst = [] #store number of course as list
def numberOfCourse():
    numberOfCourse = input("Enter number of course: ")
    numberOfCourseLst.append(numberOfCourse)

def studentID():
    studentID = input("\n\t>>Enter student ID: ")
    print(f"\t>>Enter marks for {studentID} :")

list = [] #storage for courseMark
def simpleGradingSystem():
    courseMark = int(input("\t\tEnter Mark for course: "))
    list.append(courseMark)

    if courseMark >= 80 and courseMark < 100:
        print("\t\tGrade: A\n")
    elif courseMark >= 70 and courseMark <= 79:
        print("\t\tGrade: B\n")
    elif courseMark >= 60 and courseMark <= 69:
        print("\t\tGrade: C\n")
    elif courseMark >= 50 and courseMark <= 59:
        print("\t\tGrade: D\n")
    elif courseMark >= 40 and courseMark <= 49:
        print("\t\tGrade: E\n")
    elif courseMark >= 0 and courseMark <= 39:
        print("\t\tGrade: F\n")
    else:
        print('\t\tGrade is not markable')

def main():
    numberOfStudent()
    numberOfCourse()
    studentID()
    question = [] #list to store iteration of question asked
    studentAssessed = 0 #required for conditional statement counter

    student = [ int(x) for x in numberOfStudentLst ] #converting the string type to int type in the list
    course = [ int(x) for x in numberOfCourseLst ] #converting the string type to int type in the list

    while student != studentAssessed:   #conditional statement for counting the student iteration.
        studentAssessed = studentAssessed +1 #once cycle complete, add 1 value into list
        
        while course != sum(question):        #condition to iterate the course mark question
            question.append(1)      
            simpleGradingSystem()   #grading system function

            if sum(course) == sum(question):  #upon completion of nos question asked, exit condition by printing the total result and mark
                totalMark = sum(list)
                averageMark = totalMark/sum(course)
                print(f"\t\tTotal marks = {totalMark}")
                print ("\t\tAverage mark = {:.2f}".format(round(averageMark, 2)))
            
                if averageMark > 40 and averageMark <= 100:
                    print ("\n\t>>>PROCEED TO THE NEXT SEMESTER...\n")
                elif averageMark < 40:
                    print("\n\t>>>FAIL, TRY AGAIN NEXT SEMESTER\n")
                
                list.clear()    #once the condition met, clear the mark list to avoid grade overflow
                question.clear()       #once the condition met, clear x list to avoid iteration overflow.
                    #repeat with following student id provided condition are met
                if studentAssessed != sum(student): #this condtion to make sure keep looping if the student count not enough
                    studentID() 
                    break
                break
        if studentAssessed == sum(student):

            print("Program ended, run the program again with new parameter")
            print("erwanfadlys@oum.edu.my")
            break

main()





