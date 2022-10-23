from tkinter import *
from tkinter import messagebox
from tkinter import ttk
import os
    
def session():

    global LRL, URL, AA, APW, VA, VPW, VRP, ARP
    root.geometry('925x600')
    root.configure(bg='white')
    root.resizable(False,False)
    root.title('Pacemaker Dashboard')

    frame = Frame(root,width=925, height= 600, bg='white')
    frame.place(x=0,y=0)
    OFF()
    
    options = ["OFF",
               "AOO",
               "VOO",
               "AAI",
               "VVI"]
    def optionselected(event):
        if(menu.get() == "OFF"):
            OFF()
        elif(menu.get() == "AOO"):
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

def OFF():
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()
    
    frame = Frame(root,width=550, height= 450, bg='white')
    frame.place(x=180,y=80)
    
    Label(frame, text = "Lower Rate Limit (ppm)", bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=20)
    LRL_entry = Entry(frame, width=25, fg='black', border=0, font=('Microsoft YaHei UI Light',11), state = "readonly", readonlybackground =  "white", textvariable = LRL)
    LRL_entry.pack()
    LRL_entry.place(x=320,y=20)

    Label(frame, text = "Upper Rate Limit (ppm)",bg = "white",fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=70)
    URL_entry = Entry(frame, width=25, fg='black', border=0, font=('Microsoft YaHei UI Light',11), state = "readonly", readonlybackground =  "white", textvariable = URL)
    URL_entry.pack()
    URL_entry.place(x=320,y=70)
    
    Label(frame, text = "Atrial Amplitude (V)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=120)
    AA_entry = Entry(frame, width=25, fg='black', border=0, font=('Microsoft YaHei UI Light',11), state = "readonly", readonlybackground =  "white", textvariable = AA)
    AA_entry.pack()
    AA_entry.place(x=320,y=120)
    
    Label(frame, text = "Atrial Pulse Width (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=170)
    APW_entry = Entry(frame, width=25, fg='black', border=0, font=('Microsoft YaHei UI Light',11), state = "readonly", readonlybackground =  "white", textvariable = APW)
    APW_entry.pack()
    APW_entry.place(x=320,y=170)
    
    Label(frame, text = "Ventricular Amplitude (V)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=220)
    VA_entry = Entry(frame, width=25, fg='black', border=0, font=('Microsoft YaHei UI Light',11), state = "readonly", readonlybackground =  "white", textvariable = VA)
    VA_entry.pack()
    VA_entry.place(x=320,y=220)
    
    Label(frame, text = "Ventricular Pulse Width (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=270)
    VPW_entry = Entry(frame, width=25, fg='black', border=0, font=('Microsoft YaHei UI Light',11), state = "readonly", readonlybackground =  "white", textvariable = VPW)
    VPW_entry.pack()
    VPW_entry.place(x=320,y=270)
    
    Label(frame, text = "VRP (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=320)
    VRP_entry = Entry(frame, width=25, fg='black', border=0, font=('Microsoft YaHei UI Light',11), state = "readonly", readonlybackground =  "white", textvariable = VRP)
    VRP_entry.pack()
    VRP_entry.place(x=320,y=320)
    
    Label(frame, text = "ARP (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=370)
    ARP_entry = Entry(frame, width=25, fg='black', border=0, font=('Microsoft YaHei UI Light',11), state = "readonly", readonlybackground =  "white", textvariable = ARP)
    ARP_entry.pack()
    ARP_entry.place(x=320,y=370)
    
    
    

def AOO():

    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()

    frame = Frame(root,width=550, height= 450, bg='white')
    frame.place(x=180,y=80)
    
    Label(frame, text = "Lower Rate Limit (ppm)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=20)
    LRL_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = LRL)
    LRL_entry.pack()
    LRL_entry.place(x=320,y=20)
    
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=47)
    Label(frame, text = "Upper Rate Limit (ppm)",bg = "white",fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=70)
    URL_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = URL)
    URL_entry.pack()
    URL_entry.place(x=320,y=70)
    
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=97)
    Label(frame, text = "Atrial Amplitude (V)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=120)
    AA_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = AA)
    AA_entry.pack()
    AA_entry.place(x=320,y=120)
    
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=147)
    Label(frame, text = "Atrial Pulse Width (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=170)
    APW_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = APW)
    APW_entry.pack()
    APW_entry.place(x=320,y=170)
    
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=197)
    Label(frame, text = "Ventricular Amplitude (V)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=220)
    VA_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white", fg='black', border=0, font=('Microsoft YaHei UI Light',11), textvariable = VA)
    VA_entry.pack()
    VA_entry.place(x=320,y=220)
    
    Label(frame, text = "Ventricular Pulse Width (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=270)
    VPW_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white",fg='black', border=0, font=('Microsoft YaHei UI Light',11), textvariable = VPW)
    VPW_entry.pack()
    VPW_entry.place(x=320,y=270)
    
    Label(frame, text = "VRP (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=320)
    VRP_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white",fg='black', border=0, font=('Microsoft YaHei UI Light',11), textvariable = VRP)
    VRP_entry.pack()
    VRP_entry.place(x=320,y=320)
    
    Label(frame, text = "ARP (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=370)
    ARP_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white",fg='black', border=0, font=('Microsoft YaHei UI Light',11), textvariable = ARP)
    ARP_entry.pack()
    ARP_entry.place(x=320,y=370)
    


def VOO():
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()

    frame = Frame(root,width=550, height= 450, bg='white')
    frame.place(x=180,y=80)
    
    Label(frame, text = "Lower Rate Limit (ppm)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=20)
    LRL_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = LRL)
    LRL_entry.pack()
    LRL_entry.place(x=320,y=20)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=47)
    Label(frame, text = "Upper Rate Limit (ppm)",bg = "white",fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=70)
    URL_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = URL)
    URL_entry.pack()
    URL_entry.place(x=320,y=70)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=97)
    Label(frame, text = "Atrial Amplitude (V)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=120)
    AA_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white",fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = AA)
    AA_entry.pack()
    AA_entry.place(x=320,y=120)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=147)
    Label(frame, text = "Atrial Pulse Width (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=170)
    APW_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white",fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = APW)
    APW_entry.pack()
    APW_entry.place(x=320,y=170)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=197)
    Label(frame, text = "Ventricular Amplitude (V)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=220)
    VA_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VA)
    VA_entry.pack()
    VA_entry.place(x=320,y=220)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=247)
    Label(frame, text = "Ventricular Pulse Width (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=270)
    VPW_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VPW)
    VPW_entry.pack()
    VPW_entry.place(x=320,y=270)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=297)
    Label(frame, text = "VRP (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=320)
    VRP_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white",fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VRP)
    VRP_entry.pack()
    VRP_entry.place(x=320,y=320)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=347)
    Label(frame, text = "ARP (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=370)
    ARP_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white",fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = ARP)
    ARP_entry.pack()
    ARP_entry.place(x=320,y=370)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=397)
    
def AAI():
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()

    frame = Frame(root,width=550, height= 450, bg='white')
    frame.place(x=180,y=80)
    
    Label(frame, text = "Lower Rate Limit (ppm)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=20)
    LRL_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = LRL)
    LRL_entry.pack()
    LRL_entry.place(x=320,y=20)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=47)
    Label(frame, text = "Upper Rate Limit (ppm)",bg = "white",fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=70)
    URL_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = URL)
    URL_entry.pack()
    URL_entry.place(x=320,y=70)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=97)
    Label(frame, text = "Atrial Amplitude (V)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=120)
    AA_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = AA)
    AA_entry.pack()
    AA_entry.place(x=320,y=120)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=147)
    Label(frame, text = "Atrial Pulse Width (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=170)
    APW_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = APW)
    APW_entry.pack()
    APW_entry.place(x=320,y=170)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=197)
    Label(frame, text = "Ventricular Amplitude (V)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=220)
    VA_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white",fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VA)
    VA_entry.pack()
    VA_entry.place(x=320,y=220)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=247)
    Label(frame, text = "Ventricular Pulse Width (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=270)
    VPW_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white",fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VPW)
    VPW_entry.pack()
    VPW_entry.place(x=320,y=270)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=297)
    Label(frame, text = "VRP (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=320)
    VRP_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white",fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VRP)
    VRP_entry.pack()
    VRP_entry.place(x=320,y=320)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=347)
    Label(frame, text = "ARP (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=370)
    ARP_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = ARP)
    ARP_entry.pack()
    ARP_entry.place(x=320,y=370)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=397)
    
def VVI():
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()

    frame = Frame(root,width=550, height= 450, bg='white')
    frame.place(x=180,y=80)
    
    Label(frame, text = "Lower Rate Limit (ppm)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=20)
    LRL_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = LRL)
    LRL_entry.pack()
    LRL_entry.place(x=320,y=20)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=47)
    Label(frame, text = "Upper Rate Limit (ppm)",bg = "white",fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=70)
    URL_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = URL)
    URL_entry.pack()
    URL_entry.place(x=320,y=70)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=97)
    Label(frame, text = "Atrial Amplitude (V)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=120)
    AA_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white",fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = AA)
    AA_entry.pack()
    AA_entry.place(x=320,y=120)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=147)
    Label(frame, text = "Atrial Pulse Width (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=170)
    APW_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white",fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = APW)
    APW_entry.pack()
    APW_entry.place(x=320,y=170)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=197)
    Label(frame, text = "Ventricular Amplitude (V)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=220)
    VA_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VA)
    VA_entry.pack()
    VA_entry.place(x=320,y=220)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=247)
    Label(frame, text = "Ventricular Pulse Width (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=270)
    VPW_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VPW)
    VPW_entry.pack()
    VPW_entry.place(x=320,y=270)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=297)
    Label(frame, text = "VRP (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=320)
    VRP_entry = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VRP)
    VRP_entry.pack()
    VRP_entry.place(x=320,y=320)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=347)
    Label(frame, text = "ARP (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=370)
    ARP_entry = Entry(frame, width=25, state = "readonly", readonlybackground =  "white",fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = ARP)
    ARP_entry.pack()
    ARP_entry.place(x=320,y=370)
    Frame(frame,width=202,height=2,bg='black').place(x=320,y=397)

def incorrect_password():
    Label(root, text = "Incorrect Password",bg='white', fg = "red", font = ('Microsoft YaHei UI Light', 11)).place(x=595, y=315)
    
def unknown_user():
    Label(root, text = "Unknown User", padx = 40, fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=565, y=315)

def register_user():
    global numUsers

    inp1 = username_entry.get()
    inp2 = password_entry.get()
    inp3 = serial_entry.get()

    if(inp1 == "Username" or inp1 == ""):
        Label(root, text = "Username Field Empty", padx = 40, fg = "red", bg='white',font = ('Microsoft YaHei UI Light', 11)).place(x=545, y=365)
    elif(inp2 == "Password" or inp2 == ""):
        Label(root, text = "Password Field Empty", padx = 40, fg = "red", bg='white',font = ('Microsoft YaHei UI Light', 11)).place(x=545, y=365)
    elif(inp3 == "Serial Number" or inp3 == ""):
        Label(root, text = "Serial Number Field Empty", fg = "red", bg='white',font = ('Microsoft YaHei UI Light', 11)).place(x=568, y=365)
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
            serial_info = serial.get()

            file = open(username_info, "w")
            file.write(username_info + "\n")
            file.write(password_info + "\n")
            file.write(serial_info)
            file.close()

            username_entry.delete(0, END)
            password_entry.delete(0, END)
            serial_entry.delete(0, END)

            Label(root, text = "Registration Successful", padx = 40, fg = "green", bg='white',font = ('Microsoft YaHei UI Light', 11)).place(x=540, y=365)
        else:
            Label(root, text = "Maximum Amount of Users Reached", fg = "red", bg='white',font = ('Microsoft YaHei UI Light', 11)).place(x=540, y=365)

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
    global serial
    global username_entry
    global password_entry
    global serial_entry
    
    root.title('Pacemaker Registration Screen')

    frame = Frame(root,width=350, height= 450, bg='white')
    frame.place(x=480,y=50)
    img = PhotoImage(file = 'login.png')
    Label(root, image = img, bg = 'white').place(x=50,y=80)

    heading = Label(frame,text = 'Register', fg = '#983cc8', bg='white', font=('Microsoft YaHei UI Light',23, 'bold'))
    heading.place(x=110,y=5)

    user = StringVar()
    password = StringVar()
    serial = StringVar()
     
    ###

    def onClick(x):
        username_entry.delete(0,'end')

    def onUnClick(x):
        name = username_entry.get()
        if name == '':
            username_entry.insert(0, 'Username')


    username_entry = Entry(frame, width=25, fg='black', border=0, bg="white", font=('Microsoft YaHei UI Light',11), textvariable = user)
    username_entry.pack()
    username_entry.place(x=30,y=80)
    username_entry.insert(0,'Username')
    username_entry.bind('<FocusIn>', onClick)
    username_entry.bind('<FocusOut>', onUnClick)

    Frame(frame,width=288,height=2,bg='black').place(x=30,y=107)

    ###

    def onClick(x):
        password_entry.delete(0,'end')

    def onUnClick(x):
        name = password_entry.get()
        if name == '':
            password_entry.insert(0, 'Password')
            
    password_entry = Entry(frame, width=25, fg='black', border=0, bg="white", font=('Microsoft YaHei UI Light',11), textvariable = password)
    password_entry.pack()
    password_entry.place(x=30,y=150)
    password_entry.insert(0,'Password')
    password_entry.bind('<FocusIn>', onClick)
    password_entry.bind('<FocusOut>', onUnClick)

    Frame(frame,width=288,height=2,bg='black').place(x=30,y=177)

    ###

    def onClick(x):
        serial_entry.delete(0,'end')

    def onUnClick(x):
        name = serial_entry.get()
        if name == '':
            serial_entry.insert(0, 'Serial Number')
            
    serial_entry = Entry(frame, width=25, fg='black', border=0, bg="white", font=('Microsoft YaHei UI Light',11), textvariable = serial)
    serial_entry.pack()
    serial_entry.place(x=30,y=220)
    serial_entry.insert(0,'Serial Number')
    serial_entry.bind('<FocusIn>', onClick)
    serial_entry.bind('<FocusOut>', onUnClick)

    Frame(frame,width=288,height=2,bg='black').place(x=30,y=247)

    ###

    
    Button(frame, width=39, pady=7, text='Register', bg='#983cc8', fg='white', border=0, command = register_user).place(x=35, y=274)
    label=Label(frame, text="Already have an account?", fg='black', bg='white', font=('Microsoft YaHei UI Light',9))
    label.place(x=80, y=340)
    sign_up= Button(frame, width=6, text='Sign in', border=0, bg='white', cursor='hand2', fg='#983cc8', command = main_screen)
    sign_up.place(x=225, y=340)
    
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

    frame = Frame(root,width=350, height= 450, bg='white')
    frame.place(x=480,y=50)

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
