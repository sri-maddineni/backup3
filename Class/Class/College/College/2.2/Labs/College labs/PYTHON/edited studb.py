import sqlite3
conn=sqlite3.connect('abc.db')
cur = conn.cursor()
cur.execute(''' SELECT count(name) FROM sqlite_master WHERE type='table' AND name='STUDENTS2' ''')
if cur.fetchone()[0]==0:
    cur.execute(
        '''
        CREATE TABLE STUDENTS2 (
         REGD varchar(10) PRIMARY KEY ,
         NAME VARCHAR(18),
         MATH_MARKS NUMBER,
         OOPS_MARKS NUMBER,
         DS_MARKS NUMBER,
         PERCENTAGE NUMBER )
         ''' )

    print("table created")
    conn.commit()

students=[]
class student:
    percentage=0
    def create(self):
        self.regd=input("enter the regd number: ")
        self.name=input("enter the your name: ")
        self.maths_marks=int(input("enter your maths marks :"))
        self.oops_marks=int(input("enter your oops marks :"))
        self.ds_marks=int(input("enter your ds marks :"))       
        self.percentage=int((self.maths_marks+self.oops_marks+self.ds_marks)/3)
        cur.execute('insert into STUDENTS2 values(?,?,?,?,?,?)',(self.regd,self.name,self.maths_marks,self.oops_marks,self.ds_marks,self.percentage))
        conn.commit()
    
    def update(self):
        print("1.name\n2.math_marks\n3.oops_marks\n4.ds_marks")
        ch=int(input("enter ur choice :"))
        i=input("enter the regd number :")
        
        if ch==1:
            c=input("enter new name you want to change : ")
            cur.execute('update students2 set name = ? where  regd =?',(c,i))
            conn.commit()
        elif ch==2:
            c=int(input("enter new maths marks : "))
            cur.execute('update students2 set math_marks=? where regd=?',(c,i))  
            conn.commit()          
        elif ch==3:
            c=int(input("enter oops marks ypu want to alter : "))
            cur.execute('update students2 set oops_marks=? where regd=?',(c,i))
            conn.commit()
        elif ch==4:
            c=int(input("enter ds marks ypu want to alter : "))
            cur.execute('update students2 set ds_marks=? where regd=?',(c,i))
            conn.commit()
        else:
            print("wrong choice!")
        if ch>4 and ch<8:
            cur.execute('select * from students2 where regd=?',(i,))
            row = cur.fetchone()
            sum=row[4]+row[5]+row[6]
            
            percentage=sum/3
            cur.execute('update students2 set percentage=? where regd=?',(percentage,i))
        conn.commit()

    def search(self):
        c=input("enter the regd number you want to search : ")
        cur.execute('select * from students2 where regd=?',(c,))
        for records in cur:
            print(records)

    def delete(self):
        c=input("enter the regd number you want to delete")
        cur.execute('delete  from students2 where regd=?',(c,))
        conn.commit()

    def display(self):
        cur.execute('select * from students2')
        f=cur.fetchall()
        for e in f:
            print(e)

while True:
    o1=student()
    ch=int(input("1.create\t2.update\t3.search\t4.delete\t5.display\nEnter your choice : "))
    if ch==1:
        o1.create()
        students.append(o1)
    elif ch==2:
        o1.update()
    elif ch==3:
        o1.search()
    elif ch==4:
        o1.delete()
    elif ch==5:
        ad=input("enter admin login(1234) : ")
        if ad=="1234":
            o1.display()
    else:
        cur.close()
        break