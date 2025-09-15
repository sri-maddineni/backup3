from bdb import Breakpoint
import sqlite3
con=sqlite3.connect("abc.db")
cur=con.cursor()

print("***Student database***")
print("------------------------")

print("columns of student table in student databse are : reg,name,marks for 3 subjects(m1,m2,m3)")
print("\n1.Create data\n2.Update date\n3.Search data\n4.Delete data\n5.Display\n6.Exit")
ch=int(input("Enter your choice: "))
print(ch)
while ch<=6:
    if(ch==1):
        #create data
        reg=int(input("Enter reg no: "))
        name=input("Enter your name: ")
        m=[]
        for i in range(3):
            ma=float(input("Enter marks subjects: "))
            m.append(ma)
        
        query='''insert into student(reg,name,m1,m2,m3)values(?,?,?,?,?)'''
        data=(reg,name,m[0],m[1],m[2])
        cur.execute(query,data)
        print("Data created successfully!")
        
    elif ch==2:
        #update data
        regn=int(input("Enter regno: "))
        print("What do you want to update\n1.name\n2.marks")
        c=int(input("Enter your choice: "))
        if c==1:
            n=input("Enter new name: ")
            query=('''update student set name=? where reg=?''')
            data=(n,regn)
            cur.execute(query,data)
            a=cur.execute('''select * from student where reg=? ''',(regn,))
            for i in a:
                print(i)
                print()
            r=cur.execute('select *from student')
            for i in r:
                print(i)
            con.commit()
        elif c==2:
            m=int(input("which subject marks you want to update? "))
            if m==1:
                nm=float(input("Enter new marks of sub 1: "))
                cur.execute('''update student set m1=? where reg=?''',(nm,regn,))
                a=cur.execute('''select * from student where reg=? ''',(regn,))
                for i in a:
                    print(i)
            elif m==2:
                nm=float(input("Enter new marks of sub 2: "))
                cur.execute('''update student set m2=? where reg=?''',(nm,regn,))
                a=cur.execute('''select * from student where reg=? ''',(regn,))
                for i in a:
                    print(i)
            elif m==3:
                nm=float(input("Enter new marks of sub 3: "))
                cur.execute('''update student set m3=? where reg=?''',(nm,regn,))
                a=cur.execute('''select * from student where reg=? ''',(regn,))
                for i in a:
                    print(i)
                
    elif ch==3:
        #search data
        print("What do you want to get?\n1.name\n2.marks of subjects\n3.percentage")
        c=int(input("Enter your choice : "))
        regn=int(input("Enter regno: "))
        if c==1:
            res=cur.execute('''select *from student''')
            for i in res:
                if i[0]==regn:
                    print(i[1])
                    break
                else:
                    print("Invalid reg no ")
                    break
        elif c==2:
            res=cur.execute('''select m1,m2,m3 from student where reg=?''',(regn,))
            for i in res:
                print(i)
            
        break
            
    elif ch==4:
        #delete data
        print("code not written")
        continue
    elif ch==5:
        #display data
        query='''select *from student'''
        res=cur.execute(query)
        for i in res:
            print(i)
        break
        

con.commit()
con.close()


'''
select *from sri;
create table sri(name,marks)
insert into sri(name,marks)values('sri',36)
create table student (reg,name,m1,m2,m3) 


res='select reg,name from student where reg= ? '
            r=cur.execute(res,regn)

'''



