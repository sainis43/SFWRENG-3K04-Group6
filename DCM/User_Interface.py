from tkinter import *
from tkinter import messagebox
from tkinter import ttk
import os
    
def session():
#    global dashboard_screen
#    dashboard_screen = Toplevel(root)
#    dashboard_screen.title("Pacemaker Dashboard")
#    dashboard_screen.geometry("925x600")

    root.geometry('925x600')
    root.configure(bg='white')
    root.resizable(False,False)
    root.title('Pacemaker Dashboard')

    frame = Frame(root,width=350, height= 350, bg='white')
    frame.place(x=480,y=70)

    frame2 = Frame(root,width=400, height= 400, bg='white')
    frame2.place(x=50,y=80)

    options = ["AOO",
               "VOO",
               "AAI",
               "VVI"]
    def optionselected(event):
        if(menu.get() == "AOO"):
            AOO()
        elif(menu.get() == "VOO"):
            VOO()
        elif(menu.get() == "AAI"):
            AAI()
        elif(menu.get() == "VVI"):
            VVI()
            
    menu = ttk.Combobox(root, value=options, state = "readonly")
    menu.current(0)
    menu.bind("<<ComboboxSelected>>", optionselected)
    menu.pack()

def AOO():
    Label(root, text = "Lower Rate Limit",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=20)
    Label(root, text = "Upper Rate Limit",bg = "white",fg = "black", font = ("calibri", 14)).place(x=200,y=70)
    Label(root, text = "Maximum Sensor Rate",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=120)
    Label(root, text = "Fixed AV Delay",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=170)
    Label(root, text = "Dynamic AV Delay",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=220)
    Label(root, text = "Sensed AV Delay Offset",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=270)
    Label(root, text = "Atrial Amplitude",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=320)
    Label(root, text = "Ventricular Amplitude",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=370)
    Label(root, text = "Atrial Pulse Width",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=420)
    Label(root, text = "Ventricular Pulse Width",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=470)
    Label(root, text = "Atrial Sensitivity",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=520)
    Label(root, text = "Ventricular Sensitivity",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=570)
    Label(root, text = "VRP",bg = "white", fg = "black", font = ("calibri", 14)).place(x=500,y=20)
    Label(root, text = "ARP",bg = "white", fg = "black", font = ("calibri", 14)).place(x=500,y=70)
    Label(root, text = "PVARP",bg = "white", fg = "black", font = ("calibri", 14)).place(x=500,y=120)
    Label(root, text = "PVARP Extension",bg = "white", fg = "black", font = ("calibri", 14)).place(x=500,y=170)
    Label(root, text = "Hysteresis",bg = "white", fg = "black", font = ("calibri", 14)).place(x=500,y=220)
    Label(root, text = "Rate Smoothing",bg = "white", fg = "black", font = ("calibri", 14)).place(x=500,y=270)
    Label(root, text = "ATR Duration",bg = "white", fg = "black", font = ("calibri", 14)).place(x=500,y=320)
    Label(root, text = "ATR Fallback Mode",bg = "white", fg = "black", font = ("calibri", 14)).place(x=500,y=370)
    Label(root, text = "ATR Fallback Time",bg = "white", fg = "black", font = ("calibri", 14)).place(x=500,y=420)
    Label(root, text = "Activity Threshold",bg = "white", fg = "black", font = ("calibri", 14)).place(x=500,y=470)
    Label(root, text = "Reaction Time",bg = "white", fg = "black", font = ("calibri", 14)).place(x=500,y=520)
    Label(root, text = "Response Factor",bg = "white", fg = "black", font = ("calibri", 14)).place(x=500,y=570)
    Label(root, text = "Recovery Time",bg = "white", fg = "black", font = ("calibri", 14)).place(x=700,y=20)

def VOO():
    frame = Frame(root,width=925, height= 600, bg='white')
    frame.place(x=0,y=20)
    
    #Insert VOO frame in here
    Label(root, text = "VOO Mode",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=20)
    
def AAI():
    frame = Frame(root,width=925, height= 600, bg='white')
    frame.place(x=0,y=20)
    #Insert AAI frame in here
    Label(root, text = "AAI Mode",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=20)
    
def VVI():
    frame = Frame(root,width=925, height= 600, bg='white')
    frame.place(x=0,y=20)
    #Insert VVI frame in here
    Label(root, text = "VVI Mode",bg = "white", fg = "black", font = ("calibri", 14)).place(x=200,y=20)

def incorrect_password():
    Label(root, text = "Incorrect Password",bg='white', fg = "red", font = ("calibri", 11)).place(x=595, y=335)
    
def unknown_user():
    Label(root, text = "Unknown User            ", fg = "red", bg='white', font = ("calibri", 11)).place(x=605, y=335)

def register_user():
    global numUsers

    inp1 = username_entry.get()
    inp2 = password_entry.get()

    if(inp1 == "Username"):
        Label(root, text = "Username Field Empty", fg = "red", bg='white',font = ("calibri", 11)).place(x=585, y=335)
    elif(inp2 == "Password"):
        Label(root, text = "Password Field Empty", fg = "red", bg='white',font = ("calibri", 11)).place(x=585, y=335)
    else:
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
    Button(frame, width=39, pady=7, text='Sign in', bg='#983cc8', fg='white', border=0, command = lambda:[login_verify()]).place(x=35, y=224)
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
