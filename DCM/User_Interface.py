from tkinter import *
from tkinter import messagebox
from tkinter import ttk
import os
import linecache


#This whole function is the first frame the program goes to after login. It asks for the user's pacemaker serial number to verify that the same pacemaker is being used
#If the pacemaker serial number is different than the one on file, then it stays on this screen and presents an error
#If the pacemaker serial number matches the one on file, then it goes to the next frame called "session()", this frame unlocks the ability to select modes and edit parameters
def serialsession():
    global LRL, URL, AA, APW, VA, VPW, VRP, ARP #all the parameters
    root.geometry('925x600') #session screen settings
    root.configure(bg='white')
    root.resizable(False,False)
    root.title('Pacemaker Dashboard')

    frame = Frame(root,width=925, height= 600, bg='white')
    frame.place(x=0,y=0)
    
    options = ["OFF", #differnet mode types
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
            
    menu = ttk.Combobox(root, value=options, state = "disabled") #the dropdown box for modes
    menu.current(0)
    menu.bind("<<ComboboxSelected>>", optionselected)
    menu.pack()

    def connected():
        serial1 = serial_verify.get()

        list_of_files = os.listdir()
        if username1 in list_of_files:
            file1 = open(username1, "r")
            content = linecache.getline(username1, 3)
            if (serial1 == content.strip()):
                session()
                Label(root, text = "Pacemaker Connected", bg = "white", fg = "green", font = ('Microsoft YaHei UI Light', 14)).place(x=0,y=0)
            else:
                Label(root, text = "This pacemaker does not match the one previously used. \n Please create a new account if you are using a different pacemaker", bg = "white", fg = "red", font = ('Microsoft YaHei UI Light', 14)).place(x=175,y=250)

    serial_verify = StringVar()
    Label(frame, text = "Pacemaker Disconnected", bg = "white", fg = "red", font = ('Microsoft YaHei UI Light', 14)).place(x=0,y=0)
    Label(frame, text = "Enter Pacemaker Serial Number", bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=332,y=80)
    SerialNumberCheck = Entry(frame, width=25, fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = serial_verify)
    SerialNumberCheck.pack()
    SerialNumberCheck.place(x=370, y = 110)

    Button(root, width=30, height=1, pady=7, text='Connect', bg='#983cc8', fg='white', border=0, command = connected).place(x=362, y=140)


#This is the session mode, this frame unlocks the ability to select modes and edit parameters
#Templates are used to set up all labels and entry fields
#Based on the dropdown that the user selects, the program will change its frame to the corresponding mode
#The default mode is OFF
def session():

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

#This is a template to display all parameter labels
def LabelsTemplate(frame):
    
    Label(frame, text = "Lower Rate Limit (ppm)", bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=20)
    Label(frame, text = "Upper Rate Limit (ppm)",bg = "white",fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=70)
    Label(frame, text = "Atrial Amplitude (V)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=120)
    Label(frame, text = "Atrial Pulse Width (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=170) 
    Label(frame, text = "Ventricular Amplitude (V)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=220)
    Label(frame, text = "Ventricular Pulse Width (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=270)
    Label(frame, text = "VRP (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=320)
    Label(frame, text = "ARP (ms)",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=60,y=370)

#This is a template to display all entry fields and it also sets the variables
def ModesTemplate(mode, frame):

    global LRL 
    global URL 
    global AA 
    global APW 
    global VA 
    global VPW 
    global VRP 
    global ARP
    global LRL_entry 
    global URL_entry 
    global AA_entry  
    global APW_entry  
    global VA_entry  
    global VPW_entry  
    global VRP_entry  
    global ARP_entry 
    
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()
    
    LRLtextboxState = "readonly"
    URLtextboxState = "readonly"
    AAtextboxState = "readonly"
    APWtextboxState = "readonly"
    VAtextboxState = "readonly"
    VPWtextboxState = "readonly"
    VRPtextboxState = "readonly"
    ARPtextboxState = "readonly"
        
    if(mode == "AOO"): #all the modes with there certain parameters with each having editable boxes and readonly boxes
        LRLtextboxState = "normal"
        URLtextboxState = "normal"
        AAtextboxState = "normal"
        APWtextboxState = "normal"
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=47)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=97)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=147)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=197)
    elif(mode == "AAI"):
        LRLtextboxState = "normal"
        URLtextboxState = "normal"
        AAtextboxState = "normal"
        APWtextboxState = "normal"
        ARPtextboxState = "normal"
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=47)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=97)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=147)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=197)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=397)
    elif(mode == "VOO"):
        LRLtextboxState = "normal"
        URLtextboxState = "normal"
        VAtextboxState = "normal"
        VPWtextboxState = "normal"
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=47)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=97)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=247)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=297)
    elif(mode == "VVI"):
        LRLtextboxState = "normal"
        URLtextboxState = "normal"
        VAtextboxState = "normal"
        VPWtextboxState = "normal"
        VRPtextboxState = "normal"
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=47)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=97)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=247)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=297)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=347)
    else:
        mode = "OFF"

    #CSS
    LRL_entry = Entry(frame, width=25, state = LRLtextboxState, readonlybackground =  "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = LRL)
    LRL_entry.pack()
    LRL_entry.place(x=320,y=20)
    
    URL_entry = Entry(frame, width=25, state = URLtextboxState, readonlybackground =  "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = URL)
    URL_entry.pack()
    URL_entry.place(x=320,y=70)
    
    AA_entry = Entry(frame, width=25, state = AAtextboxState, readonlybackground =  "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = AA)
    AA_entry.pack()
    AA_entry.place(x=320,y=120)
    
    APW_entry = Entry(frame, width=25, state = APWtextboxState, readonlybackground =  "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = APW)
    APW_entry.pack()
    APW_entry.place(x=320,y=170)
    
    VA_entry = Entry(frame, width=25, state = VAtextboxState, readonlybackground =  "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VA)
    VA_entry.pack()
    VA_entry.place(x=320,y=220)
    
    VPW_entry = Entry(frame, width=25, state = VPWtextboxState, readonlybackground =  "white",fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VPW)
    VPW_entry.pack()
    VPW_entry.place(x=320,y=270)
    
    VRP_entry = Entry(frame, width=25, state = VRPtextboxState, readonlybackground =  "white",fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VRP)
    VRP_entry.pack()
    VRP_entry.place(x=320,y=320)
    
    ARP_entry = Entry(frame, width=25, state = ARPtextboxState, readonlybackground =  "white",fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = ARP)
    ARP_entry.pack()
    ARP_entry.place(x=320,y=370)

#This is the OFF mode
def OFF():
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()
    
    frame = Frame(root,width=875, height= 500, bg='white')
    frame.place(x=20,y=80)

    LabelsTemplate(frame)
    ModesTemplate("OFF", frame)
    
#This is the AOO mode, it has if statements that set restrictions on what users can enter in the textboxes, if the user is out of bounds, then it sends an error
def AOO():

    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()

    frame = Frame(root,width=875, height= 500, bg='white')
    frame.place(x=20,y=80)
    
    LabelsTemplate(frame)
    ModesTemplate("AOO", frame)
    
    def applychanges(): #setting up the confitions for the parameteres
        Frame(frame,width=500,height=500,bg='white').place(x=530,y=20)
        LRL_value = LRL_entry.get()
        URL_value = URL_entry.get()
        AA_value = AA_entry.get()
        APW_value = APW_entry.get()
        VA_value = VA_entry.get()
        VPW_value = VPW_entry.get()
        VRP_value = VRP_entry.get()
        ARP_value = ARP_entry.get()

        print(LRL_value + " " + URL_value + " " + AA_value + " " + APW_value)

        if(LRL_value == "" or URL_value == "" or AA_value == "" or APW_value == ""): #make sure all boxes are filled else gives error
            Label(frame, text = "Please fill in all fields", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=415)
        else: #goes through the conditions of the parameters 
            #LRL##################################################################################################################################################
            if(int(LRL_value) > 30 and int(LRL_value) < 50) or (int(LRL_value) > 90 and int(LRL_value) < 175):
                if(int(LRL_value) % 5 != 0): #multiple of 5
                    Label(frame, text = "Must be mulitple of 5", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=20)
            else: #makes sure is between 50-90
                if(not(int(LRL_value) > 50 and int(LRL_value) < 90)):
                    Label(frame, text = "Value must be inbetween 30-175", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=20)
                

            #URL##################################################################################################################################################
            if(int(URL_value) > 50 and int(URL_value) < 175): #makes sure is bwetween 50-175
                if(int(URL_value) % 5 != 0): #mulitple of 5
                    Label(frame, text = "Must be mulitple of 5", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=70)
            else:
                Label(frame, text = "Value must be inbetween 50-175", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=70)

            #AA###################################################################################################################################################
            if(float(AA_value) >= 0.5 and float(AA_value) <= 3.2): #makes sure is between .5 and 3.2
                if(not(float(format((float(AA_value) % 0.1), ".4f")) == 0.1 or float(format((float(AA_value) % 0.1), ".4f")) == 0)): #makes sure is multiple of 0.01
                    Label(frame, text = ("Must be a multiple of 0.1"), fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=120)
            elif(float(AA_value) >= 3.5 and float(AA_value) <= 7.0): #makes sure is between 3.5 and 7
                if(not(float(format((float(AA_value) % 0.5), ".4f")) == 0)): #multiple of 0.5
                    Label(frame, text = ("Must be a multiple of 0.5"), fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=120)
            else: #allows value to be 0
                if(float(AA_value) != 0):
                    Label(frame, text = "Value must be either 0 or between 0.5-3.2 or 3.5-7", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=120)

            #APW##################################################################################################################################################
            if(float(APW_value) >= 0.1 and float(APW_value) <= 1.9): #makes sure value is between 0.1 and 1.9
                if(not(float(format((float(APW_value) % 0.5), ".4f")) == 0.1 or float(format((float(APW_value) % 0.1), ".4f")) == 0)):
                    Label(frame, text = ("Must be a multiple of 0.1"), fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=170)
            else: #makes sure value can equal 0.05
                if(float(APW_value) != 0.05):
                    Label(frame, text = "Value must be either 0.05 or between 0.1-1.9", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=170)

            
        
    Button(frame, width=39, pady=7, text='Apply Changes', bg='#983cc8', fg='white', border=0, command = applychanges).place(x=60, y=450)
    
#This is the VOO mode, it has if statements that set restrictions on what users can enter in the textboxes, if the user is out of bounds, then it sends an error
def VOO():
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()

    frame = Frame(root,width=875, height= 500, bg='white')
    frame.place(x=20,y=80)

    LabelsTemplate(frame)
    ModesTemplate("VOO", frame)
    
    def applychanges():
        Frame(frame,width=500,height=500,bg='white').place(x=530,y=20)
        LRL_value = LRL_entry.get()
        URL_value = URL_entry.get()
        AA_value = AA_entry.get()
        APW_value = APW_entry.get()
        VA_value = VA_entry.get()
        VPW_value = VPW_entry.get()
        VRP_value = VRP_entry.get()
        ARP_value = ARP_entry.get()

        print(LRL_value + " " + URL_value + " " + VA_value + " " + VPW_value)
        
        if(LRL_value == "" or URL_value == "" or VA_value == "" or VPW_value == ""):
            Label(frame, text = "Please fill in all fields", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=415)
        else:
            #LRL##################################################################################################################################################
            if(int(LRL_value) > 30 and int(LRL_value) < 50) or (int(LRL_value) > 90 and int(LRL_value) < 175):
                if(int(LRL_value) % 5 != 0):
                    Label(frame, text = "Must be mulitple of 5", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=20)
            else:
                if(not(int(LRL_value) > 50 and int(LRL_value) < 90)):
                    Label(frame, text = "Value must be inbetween 30-175", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=20)
                

            #URL##################################################################################################################################################
            if(int(URL_value) > 50 and int(URL_value) < 175):
                if(int(URL_value) % 5 != 0):
                    Label(frame, text = "Must be mulitple of 5", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=70)
            else:
                Label(frame, text = "Value must be inbetween 50-175", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=70)

            #VA###################################################################################################################################################
            if(float(VA_value) >= 0.5 and float(VA_value) <= 3.2): #same as AA
                if(not(float(format((float(VA_value) % 0.1), ".4f")) == 0.1 or float(format((float(VA_value) % 0.1), ".4f")) == 0)):
                    Label(frame, text = ("Must be a multiple of 0.1"), fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=220)
            elif(float(VA_value) >= 3.5 and float(VA_value) <= 7.0):
                if(not(float(format((float(VA_value) % 0.5), ".4f")) == 0)):
                    Label(frame, text = ("Must be a multiple of 0.5"), fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=220)
            else:
                if(float(VA_value) != 0):
                    Label(frame, text = "Value must be either 0 or between 0.5-3.2 or 3.5-7", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=220)

            #VPW##################################################################################################################################################
            if(float(VPW_value) >= 0.1 and float(VPW_value) <= 1.9): #same as APW
                if(not(float(format((float(VPW_value) % 0.5), ".4f")) == 0.1 or float(format((float(VPW_value) % 0.1), ".4f")) == 0)):
                    Label(frame, text = ("Must be a multiple of 0.1"), fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=270)
            else:
                if(float(VPW_value) != 0.05):
                    Label(frame, text = "Value must be either 0.05 or between 0.1-1.9", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=270)
        
    Button(frame, width=39, pady=7, text='Apply Changes', bg='#983cc8', fg='white', border=0, command = applychanges).place(x=60, y=450)
    
#This is the AAI mode, it has if statements that set restrictions on what users can enter in the textboxes, if the user is out of bounds, then it sends an error 
def AAI():
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()

    frame = Frame(root,width=875, height= 500, bg='white')
    frame.place(x=20,y=80)

    LabelsTemplate(frame)
    ModesTemplate("AAI", frame)

    def applychanges():
        Frame(frame,width=500,height=500,bg='white').place(x=530,y=20)
        LRL_value = LRL_entry.get()
        URL_value = URL_entry.get()
        AA_value = AA_entry.get()
        APW_value = APW_entry.get()
        VA_value = VA_entry.get()
        VPW_value = VPW_entry.get()
        VRP_value = VRP_entry.get()
        ARP_value = ARP_entry.get()

        print(LRL_value + " " + URL_value + " " + AA_value + " " + APW_value + " " + ARP_value)
        
        if(LRL_value == "" or URL_value == "" or AA_value == "" or APW_value == "" or ARP_value == ""):
            Label(frame, text = "Please fill in all fields", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=415)
        else:
        #LRL##################################################################################################################################################
            if(int(LRL_value) > 30 and int(LRL_value) < 50) or (int(LRL_value) > 90 and int(LRL_value) < 175):
                if(int(LRL_value) % 5 != 0):
                    Label(frame, text = "Must be mulitple of 5", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=20)
            else:
                if(not(int(LRL_value) > 50 and int(LRL_value) < 90)):
                    Label(frame, text = "Value must be inbetween 30-175", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=20)
                

        #URL##################################################################################################################################################
            if(int(URL_value) > 50 and int(URL_value) < 175):
                if(int(URL_value) % 5 != 0):
                    Label(frame, text = "Must be mulitple of 5", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=70)
            else:
                Label(frame, text = "Value must be inbetween 50-175", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=70)

        #AA###################################################################################################################################################
            if(float(AA_value) >= 0.5 and float(AA_value) <= 3.2):
                if(not(float(format((float(AA_value) % 0.1), ".4f")) == 0.1 or float(format((float(AA_value) % 0.1), ".4f")) == 0)):
                    Label(frame, text = ("Must be a multiple of 0.1"), fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=120)
            elif(float(AA_value) >= 3.5 and float(AA_value) <= 7.0):
                if(not(float(format((float(AA_value) % 0.5), ".4f")) == 0)):
                    Label(frame, text = ("Must be a multiple of 0.5"), fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=120)
            else:
                if(float(AA_value) != 0):
                    Label(frame, text = "Value must be either 0 or between 0.5-3.2 or 3.5-7", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=120)

        #APW##################################################################################################################################################
            if(float(APW_value) >= 0.1 and float(APW_value) <= 1.9):
                if(not(float(format((float(APW_value) % 0.5), ".4f")) == 0.1 or float(format((float(APW_value) % 0.1), ".4f")) == 0)):
                    Label(frame, text = ("Must be a multiple of 0.1"), fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=170)
            else:
                if(float(APW_value) != 0.05):
                    Label(frame, text = "Value must be either 0.05 or between 0.1-1.9", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=170)
            
         #ARP##################################################################################################################################################
            if(int(ARP_value) < 150 or int(ARP_value) > 500): #makes sure value is between 150 - 500
                Label(frame, text = "Value must be inbetween 150-500", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=370)
            elif(int(ARP_value) % 10 != 0): #makes sure value is multiple of 10
                Label(frame, text = "Must be mulitple of 10", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=370)
            
    Button(frame, width=39, pady=7, text='Apply Changes', bg='#983cc8', fg='white', border=0, command = applychanges).place(x=60, y=450)

#This is the VVI mode, it has if statements that set restrictions on what users can enter in the textboxes, if the user is out of bounds, then it sends an error
def VVI():
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()

    frame = Frame(root,width=875, height= 500, bg='white')
    frame.place(x=20,y=80)
    
    LabelsTemplate(frame)
    ModesTemplate("VVI", frame)

    def applychanges():
        Frame(frame,width=500,height=500,bg='white').place(x=530,y=20)
        LRL_value = LRL_entry.get()
        URL_value = URL_entry.get()
        AA_value = AA_entry.get()
        APW_value = APW_entry.get()
        VA_value = VA_entry.get()
        VPW_value = VPW_entry.get()
        VRP_value = VRP_entry.get()
        ARP_value = ARP_entry.get()

        print(LRL_value + " " + URL_value + " " + VA_value + " " + VPW_value + " " + VRP_value)
        
        if(LRL_value == "" or URL_value == "" or VA_value == "" or VPW_value == "" or VRP_value == ""):
            Label(frame, text = "Please fill in all fields", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=415)
        else:
        #LRL##################################################################################################################################################
            if(int(LRL_value) > 30 and int(LRL_value) < 50) or (int(LRL_value) > 90 and int(LRL_value) < 175):
                if(int(LRL_value) % 5 != 0):
                    Label(frame, text = "Must be mulitple of 5", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=20)
            else:
                if(not(int(LRL_value) > 50 and int(LRL_value) < 90)):
                    Label(frame, text = "Value must be inbetween 30-175", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=20)
                

        #URL##################################################################################################################################################
            if(int(URL_value) > 50 and int(URL_value) < 175):
                if(int(URL_value) % 5 != 0):
                    Label(frame, text = "Must be mulitple of 5", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=70)
            else:
                Label(frame, text = "Value must be inbetween 50-175", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=70)

        #VA###################################################################################################################################################
            if(float(VA_value) >= 0.5 and float(VA_value) <= 3.2):
                if(not(float(format((float(VA_value) % 0.1), ".4f")) == 0.1 or float(format((float(VA_value) % 0.1), ".4f")) == 0)):
                    Label(frame, text = ("Must be a multiple of 0.1"), fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=120)
            elif(float(VA_value) >= 3.5 and float(VA_value) <= 7.0):
                if(not(float(format((float(VA_value) % 0.5), ".4f")) == 0)):
                    Label(frame, text = ("Must be a multiple of 0.5"), fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=120)
            else:
                if(float(VA_value) != 0):
                    Label(frame, text = "Value must be either 0 or between 0.5-3.2 or 3.5-7", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=120)

        #VPW##################################################################################################################################################
            if(float(VPW_value) >= 0.1 and float(VPW_value) <= 1.9):
                if(not(float(format((float(VPW_value) % 0.5), ".4f")) == 0.1 or float(format((float(VPW_value) % 0.1), ".4f")) == 0)):
                    Label(frame, text = ("Must be a multiple of 0.1"), fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=170)
            else:
                if(float(VPW_value) != 0.05):
                    Label(frame, text = "Value must be either 0.05 or between 0.1-1.9", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=170)
            
        #VRP##################################################################################################################################################
            if(int(VRP_value) < 150 or int(VRP_value) > 500):
                Label(frame, text = "Value must be inbetween 150-500", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=320)
            elif(int(VRP_value) % 10 != 0):
                Label(frame, text = "Must be mulitple of 10", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=320)

    Button(frame, width=39, pady=7, text='Apply Changes', bg='#983cc8', fg='white', border=0, command = applychanges).place(x=60, y=450)

#This function is called when a user clicks the register button
#It takes all entry fields (username, password, and serial number) and stores them in a new file
#Error messages and success messages are also included in this function
def register_user():
    global numUsers
    
    inp1 = username_entry.get()
    inp2 = password_entry.get()
    inp3 = serial_entry.get()

    if(inp1 == "Username" or inp1 == ""): #makes sure input1,2,3 have something in them
        Label(root, text = "Username Field Empty", padx = 40, fg = "red", bg='white',font = ('Microsoft YaHei UI Light', 11)).place(x=545, y=365)
    elif(inp2 == "Password" or inp2 == ""):
        Label(root, text = "Password Field Empty", padx = 40, fg = "red", bg='white',font = ('Microsoft YaHei UI Light', 11)).place(x=545, y=365)
    elif(inp3 == "Serial Number" or inp3 == ""):
        Label(root, text = "Serial Number Field Empty", fg = "red", bg='white',font = ('Microsoft YaHei UI Light', 11)).place(x=568, y=365)
    else:
        f = open("users.txt","r") #opens file and overwrites the user counter
        numUsers = int(f.readline())
        f.close()
        
        f = open("users.txt", "w")
        numUsers += 1
        f.write(str(numUsers))
        f.close()
        
        if (numUsers <= 10):  #set a limit of 10 users
            username_info = user.get()
            password_info = password.get()
            serial_info = serial.get()

            file = open(username_info, "w") #writes all the info inside file (username, password, and serial number)
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

#This function is called after the user clicks the login button
#It checks if the username is on file, if yes, it goes to that file and checks line 2 for the password, if the password matches, it sends the program to the serialsession() frame, if not, it shows an error
def login_verify():
    global username1
    username1 = username_verify.get()
    password1 = password_verify.get()
    user.delete(0, END)
    password.delete(0, END)

    list_of_files = os.listdir() #checks if username is in list of files where python file is and reads the file to check password verifcation
    if username1 in list_of_files:
       file1 = open(username1, "r")
       content = linecache.getline(username1, 2)
       if (password1 == content.strip()): #confirms password inorder to open dashboard
           serialsession()
       else:
           Label(root, text = "Incorrect Password",bg='white', fg = "red", font = ('Microsoft YaHei UI Light', 11)).place(x=595, y=315)
    else:
        Label(root, text = "Unknown User", padx = 40, fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=565, y=315)

#This function is the register frame. This is brought forward when a user clicks the sign up button
#It includes entry fields and a register button. If all is well in their registration, it sends them to the register_user() function
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


    username_entry = Entry(frame, width=25, fg='black', border=0, bg="white", font=('Microsoft YaHei UI Light',11), textvariable = user) #input of username
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
            
    password_entry = Entry(frame, width=25, fg='black', border=0, bg="white", font=('Microsoft YaHei UI Light',11), textvariable = password) #input of password
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
            
    serial_entry = Entry(frame, width=25, fg='black', border=0, bg="white", font=('Microsoft YaHei UI Light',11), textvariable = serial) #input of serial number
    serial_entry.pack()
    serial_entry.place(x=30,y=220)
    serial_entry.insert(0,'Serial Number')
    serial_entry.bind('<FocusIn>', onClick)
    serial_entry.bind('<FocusOut>', onUnClick)

    Frame(frame,width=288,height=2,bg='black').place(x=30,y=247)

    ###

    
    Button(frame, width=39, pady=7, text='Register', bg='#983cc8', fg='white', border=0, command = register_user).place(x=35, y=274) #button to register
    label=Label(frame, text="Already have an account?", fg='black', bg='white', font=('Microsoft YaHei UI Light',9))
    label.place(x=80, y=340)
    sign_up= Button(frame, width=6, text='Sign in', border=0, bg='white', cursor='hand2', fg='#983cc8', command = main_screen)
    sign_up.place(x=225, y=340)
    
    root.mainloop()
    
#This is the main login screen
#It holds entry fields for username and password, and a login button. The login button will either prompt an error message (if password/user is wrong) or it will send them to the login_verify() function
def main_screen():
    global root
    global username_verify
    global password_verify
    global user
    global password

    root.title('Pacemaker Login Screen') #development of the main screen

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


    user = Entry(frame, width=25, fg='black', border=0, bg="white", font=('Microsoft YaHei UI Light',11), textvariable = username_verify) #input for login username
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
            
    password = Entry(frame, show="*", width=25, fg='black', border=0, bg="white", font=('Microsoft YaHei UI Light',11), textvariable = password_verify) #input for login password
    password.pack()
    password.place(x=30,y=170)
    password.insert(0,'Password')
    password.bind('<FocusIn>', onClick)
    password.bind('<FocusOut>', onUnClick)

    Frame(frame,width=288,height=2,bg='black').place(x=30,y=197)


    ###
    Button(frame, width=39, pady=7, text='Sign in', bg='#983cc8', fg='white', border=0, command = lambda:[login_verify()]).place(x=35, y=224) #login button
    label=Label(frame, text="Don't have an account?", fg='black', bg='white', font=('Microsoft YaHei UI Light',9))
    label.place(x=75, y=290)
    sign_up= Button(frame, width=6, text='Sign up', border=0, bg='white', cursor='hand2', fg='#983cc8', command = register)
    sign_up.place(x=215, y=290)

    root.mainloop()

#This is the setup for the window
#It includes the size, and makes it not resizeable
root = Tk()
root.geometry('925x500+300+200')
root.configure(bg='white')
root.resizable(False,False)
main_screen()
