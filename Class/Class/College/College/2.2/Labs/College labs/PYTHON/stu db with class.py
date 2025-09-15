
class student:
    sdet=[]#to store details of all students
    #student details
    def __init__(self):
        
        print("-"*30,"\nSTUDENT DATA MANAGEMENT SYSTEM:\n","-"*30)
        #self.det=[]
        #print(student.sdet)
        if len(student.sdet)==0:
            print("Create student First: ")
            student.create(self)
        else:
            student.choice(self)
            
    def choice(self):
        

        ch=int(input("\n1.CREATE DATA\n2.UPDATE\n3.SEARCH\n4.DELETE\n5.EXIT\nEnter your choice: "))
        while(ch!=5):
            if ch>5:
                print("invalid choice")
            elif ch==1:
                student.create(self)
            elif ch==2:
                student.update(self)
            elif ch==3:
                student.search(self)
            elif ch==4:
                student.delete(self)
            elif ch==5:
                break
            else:
                print("Invalid choice!")
            ch=int(input("\n1.CREATE DATA\n2.UPDATE\n3.SEARCH\n4.DELETE\n5.EXIT\nEnter your choice: "))
        
    def create(self):
        stu=[]
        details=""
        name=input("Enter name: ")
        details+=name
        reg=int(input("Enter reg no: "))
        print("Your reg number is: ",reg)
        details+=" "+str(reg)
        marks=[]
        for i in range(4):
            m=float(input("Enter marks of 4  subjects :"))
            if(0<=m<=100):
                marks.append(m)
        per=sum(marks)/4
        details+=" "+str(per)
        details=details.split(" ")
        details[1]=int(details[1])
        details[2]=float(details[2])
        print("Your details are updated!")
        print(details)
        print(marks)
        stu.append(details)
        stu.append(marks)        
        self.sdet.append(stu)
        
        #print(self.sdet)
        return self.sdet
    
    def update(self):
        creg=int(input("Enter reg no : "))#check reg credentials
        for stu in self.sdet:
            print(stu)
            if stu[0][1]==creg:
                c=int(input("what do you want to update?\n1.name\n2.marks \n :"))
                if c==1:
                    n=input("Enter new name: ")
                    stu[0][0]=n
                    print("your name is update to ",stu[0][0])
                    print(stu)
                    break
                elif c==2:
                    ch=int(input("Enter which subject marks you want to update(sub 1=1) : "))
                    if ch==1:
                        ma=float(input("Enter new marks : "))
                        stu[1][0]=ma
                        per=sum(stu[1])/4
                        stu[0][2]=per
                        print("Your marks are updated",stu)
                    elif ch==2:
                        ma=float(input("Enter new marks : "))
                        stu[1][1]=ma
                        per=sum(stu[1])/4
                        stu[0][2]=per
                        print("Your marks are updated",stu)
                    elif ch==3:
                        ma=float(input("Enter new marks : "))
                        stu[1][2]=ma
                        per=sum(stu[1])/4
                        stu[0][2]=per
                        print("Your marks are updated",stu)
                    elif ch==4:
                        ma=float(input("Enter new marks : "))
                        stu[1][3]=ma
                        per=sum(stu[1])/4
                        stu[0][2]=per
                        print("Your marks are updated",stu[1])
                        
                    else:
                        break
            else:
                print("reg not found")
                        
        
    def search(self):
        creg=int(input("Enter reg no : "))#check reg credentials
        for stu in self.sdet:
            if stu[0][1]==creg:
                print(stu)
    
    def delete(self):
        creg=int(input("Enter reg no : "))#check reg credentials
        for stu in self.sdet:
            if stu[0][1]==creg:   
                self.sdet.remove(stu)
                #print(self.sdet)
                print("Record deleted!")
    
       
        
x=0
while x==0:
    obj=student()
    x=obj.choice()
     
print("Exiting...!")