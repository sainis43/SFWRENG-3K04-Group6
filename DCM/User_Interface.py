from tkinter import *
from tkinter import messagebox
import os

def session():
    root.geometry('925x800')
    root.configure(bg='white')
    root.resizable(False,False)
    root.title('Pacemaker Dashboard')

    frame = Frame(root,width=350, height= 350, bg='white')
    frame.place(x=480,y=70)

    frame2 = Frame(root,width=400, height= 400, bg='white')
    frame2.place(x=50,y=80)

def incorrect_password():
    Label(root, text = "Incorrect Password",bg='white', fg = "red", font = ("calibri", 11)).place(x=595, y=335)

def username_empty():
    Label(root, text = "Username Field Empty",bg='white', fg = "red", font = ("calibri", 11)).place(x=595, y=335)

def password_empty():
    Label(root, text = "Password Field Empty",bg='white', fg = "red", font = ("calibri", 11)).place(x=595, y=335)
    
def unknown_user():
    Label(root, text = "Unknown User            ", fg = "red", bg='white', font = ("calibri", 11)).place(x=605, y=335)

def register_user():
    global numUsers

    f = open("users.txt","r")
    numUsers = int(f.readline())
    f.close()
    
    f = open("users.txt", "w")
    numUsers += 1
    f.write(str(numUsers))

    if (numUsers <= 10):
        username_info = user.get()
        password_info = password.get()

        file = open(username_info, "w")
        file.write(username_info + "\n")
        file.write(password_info)
        file.close()

        username_entry.delete(0, END)
        password_entry.delete(0, END)

        Label(root, text = "Registration Successful", fg = "green", bg='white',font = ("calibri", 11)).place(x=585, y=335)
    else:
        Label(root, text = "Maximum Amount of Users Reached", fg = "red", bg='white',font = ("calibri", 11)).place(x=540, y=335)

def login_verify():
    username1 = username_verify.get()
    password1 = password_verify.get()
    user.delete(0, END)
    password.delete(0, END)

    list_of_files = os.listdir()
    if username1 in list_of_files:
       file1 = open(username1, "r")
       verify = file1.read().splitlines()
       if password1 in verify:
           session()
       else:
           incorrect_password()
    else:
        unknown_user()

def register():

    global root
    global user
    global password
    global username_entry
    global password_entry
    
    root.title('Pacemaker Registration Screen')

    frame = Frame(root,width=350, height= 350, bg='white')
    frame.place(x=480,y=70)
    img = PhotoImage(file = 'login.png')
    Label(root, image = img, bg = 'white').place(x=50,y=80)

    heading = Label(frame,text = 'Register', fg = '#983cc8', bg='white', font=('Microsoft YaHei UI Light',23, 'bold'))
    heading.place(x=110,y=25)

    user = StringVar()
    password = StringVar()
     
    ###

    def onClick(x):
        username_entry.delete(0,'end')

    def onUnClick(x):
        name = username_entry.get()
        if name == '':
            username_entry.insert(0, 'Username')


    username_entry = Entry(frame, width=25, fg='black', border=0, bg="white", font=('Microsoft YaHei UI Light',11), textvariable = user)
    username_entry.pack()
    username_entry.place(x=30,y=100)
    username_entry.insert(0,'Username')
    username_entry.bind('<FocusIn>', onClick)
    username_entry.bind('<FocusOut>', onUnClick)

    Frame(frame,width=288,height=2,bg='black').place(x=30,y=127)

    ###

    def onClick(x):
        password_entry.delete(0,'end')

    def onUnClick(x):
        name = password_entry.get()
        if name == '':
            password_entry.insert(0, 'Password')
            
    password_entry = Entry(frame, width=25, fg='black', border=0, bg="white", font=('Microsoft YaHei UI Light',11), textvariable = password)
    password_entry.pack()
    password_entry.place(x=30,y=170)
    password_entry.insert(0,'Password')
    password_entry.bind('<FocusIn>', onClick)
    password_entry.bind('<FocusOut>', onUnClick)

    Frame(frame,width=288,height=2,bg='black').place(x=30,y=197)

    ###
    Button(frame, width=39, pady=7, text='Register', bg='#983cc8', fg='white', border=0, command = register_user).place(x=35, y=224)
    label=Label(frame, text="Already have an account?", fg='black', bg='white', font=('Microsoft YaHei UI Light',9))
    label.place(x=80, y=290)
    sign_up= Button(frame, width=6, text='Sign in', border=0, bg='white', cursor='hand2', fg='#983cc8', command = main_screen)
    sign_up.place(x=225, y=290)
    
    root.mainloop()
    

def main_screen():
    global root
    global username_verify
    global password_verify
    global user
    global password

    root.title('Pacemaker Login Screen')

    img = PhotoImage(file = 'login.png')
    Label(root, image = img, bg = 'white').place(x=50,y=80)

    frame = Frame(root,width=350, height= 350, bg='white')
    frame.place(x=480,y=70)

    heading = Label(frame,text = 'Sign in', fg = '#983cc8', bg='white', font=('Microsoft YaHei UI Light',23, 'bold'))
    heading.place(x=115,y=25)

    username_verify = StringVar()
    password_verify = StringVar()
     
    ###

    def onClick(x):
        user.delete(0,'end')

    def onUnClick(x):
        name = user.get()
        if name == '':
            user.insert(0, 'Username')


    user = Entry(frame, width=25, fg='black', border=0, bg="white", font=('Microsoft YaHei UI Light',11), textvariable = username_verify)
    user.pack()
    user.place(x=30,y=100)
    user.insert(0,'Username')
    user.bind('<FocusIn>', onClick)
    user.bind('<FocusOut>', onUnClick)

    Frame(frame,width=288,height=2,bg='black').place(x=30,y=127)

    ###

    def onClick(x):
        password.delete(0,'end')

    def onUnClick(x):
        name = password.get()
        if name == '':
            password.insert(0, 'Password')
            
    password = Entry(frame, show="*", width=25, fg='black', border=0, bg="white", font=('Microsoft YaHei UI Light',11), textvariable = password_verify)
    password.pack()
    password.place(x=30,y=170)
    password.insert(0,'Password')
    password.bind('<FocusIn>', onClick)
    password.bind('<FocusOut>', onUnClick)

    Frame(frame,width=288,height=2,bg='black').place(x=30,y=197)


    ###
    Button(frame, width=39, pady=7, text='Sign in', bg='#983cc8', fg='white', border=0, command = login_verify).place(x=35, y=224)
    label=Label(frame, text="Don't have an account?", fg='black', bg='white', font=('Microsoft YaHei UI Light',9))
    label.place(x=75, y=290)
    sign_up= Button(frame, width=6, text='Sign up', border=0, bg='white', cursor='hand2', fg='#983cc8', command = register)
    sign_up.place(x=215, y=290)

    root.mainloop()

root = Tk()
root.geometry('925x500+300+200')
root.configure(bg='white')
root.resizable(False,False)
main_screen()
