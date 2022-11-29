from tkinter import *
from tkinter import messagebox
from tkinter import ttk
import os
import linecache
import serial
import serial.tools.list_ports
import numpy as np
from matplotlib import pyplot as plt
from matplotlib import animation

#This whole function is the first frame the program goes to after login. It asks for the user's pacemaker serial number to verify that the same pacemaker is being used
#If the pacemaker serial number is different than the one on file, then it stays on this screen and presents an error
#If the pacemaker serial number matches the one on file, then it goes to the next frame called "session()", this frame unlocks the ability to select modes and edit parameters
def serialsession():
    root.geometry('1250x600') #session screen settings
    root.configure(bg='white')
    root.resizable(False,False)
    root.title('Pacemaker Dashboard')
    
    frame = Frame(root,width=1250, height= 600, bg='white')
    frame.place(x=0,y=0)
    OFF()
    
    options = ["OFF", #differnet mode types
               "AOO",
               "VOO",
               "AAI",
               "VVI",
               "AOOR",
               "VOOR",
               "AAIR",
               "VVIR"]

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
        elif(menu.get() == "AOOR"):
            AOOR()
        elif(menu.get() == "VOOR"):
            VOOR()
        elif(menu.get() == "AAIR"):
            AAIR()
        elif(menu.get() == "VVIR"):
            VVIR()
            
    menu = ttk.Combobox(root, value=options, state = "disabled")
    menu.current(0)
    menu.bind("<<ComboboxSelected>>", optionselected)
    menu.pack()


    def connected():
        session()
        try:
            for i in serial.tools.list_ports.comports():
                if(i.device == "COM4"):
                    frdm_port = i.device
                    print("connected")
                    session()
            return [frdm_port,True]

        except:
            print("not connected")
            return [None, False]

    serial_verify = StringVar()
    Label(frame, text = "Pacemaker Disconnected", bg = "white", fg = "red", font = ('Microsoft YaHei UI Light', 14)).place(x=0,y=0)

    Button(root, width=10, height=1, pady=2, text='Refresh', bg='#983cc8', fg='white', border=0, command = connected).place(x=3, y=30)


    



#This is the session mode, this frame unlocks the ability to select modes and edit parameters
#Templates are used to set up all labels and entry fields
#Based on the dropdown that the user selects, the program will change its frame to the corresponding mode
#The default mode is OFF
def session():

    frame = Frame(root,width=1250, height= 600, bg='white')
    frame.place(x=0,y=0)
    Label(frame, text = "Pacemaker Connected", bg = "white", fg = "green", font = ('Microsoft YaHei UI Light', 14)).place(x=0,y=0)
    OFF()
    def egram():
        figure = plt.figure()
        egraph = plt.axes(xlim=(0, 2), ylim=(-2, 2))
        line, = egraph.plot([], [], lw=2)
        
        def init():
            line.set_data([], [])
            return line,

        def animate(i):
            X = np.linspace(0, 2, 1000)
            Y = np.sin(2 * np.pi * (X - 0.01 * i))
            line.set_data(X, Y)
            return line,
        anim = animation.FuncAnimation(figure, animate, init_func=init, frames=100, interval=25, blit=True)
            
        plt.show()

    Button(root, width=10, height=1, pady=2, text='Egram', bg='#983cc8', fg='white', border=0, command = egram).place(x=1000, y=30)

    options = ["OFF", #differnet mode types
               "AOO",
               "VOO",
               "AAI",
               "VVI",
               "AOOR",
               "VOOR",
               "AAIR",
               "VVIR"]
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
        elif(menu.get() == "AOOR"):
            AOOR()
        elif(menu.get() == "VOOR"):
            VOOR()
        elif(menu.get() == "AAIR"):
            AAIR()
        elif(menu.get() == "VVIR"):
            VVIR()
            
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
    Label(frame, text = "Maximum Sensor Rate",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=660,y=20)
    Label(frame, text = "Atrial Sensitivity",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=660,y=70)
    Label(frame, text = "Ventricular Sensitivity",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=660,y=120)
    Label(frame, text = "PVARP",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=660,y=170)
    Label(frame, text = "Activity Threshold",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=660,y=220)
    Label(frame, text = "Reaction Time",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=660,y=270)
    Label(frame, text = "Response Factor",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=660,y=320)
    Label(frame, text = "Recovery Time",bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 14)).place(x=660,y=370)

    


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
    global MSR
    global AS
    global VS
    global PVARP
    global AT
    global RnT
    global RF
    global RyT
    global LRL_entry 
    global URL_entry 
    global AA_entry  
    global APW_entry  
    global VA_entry  
    global VPW_entry  
    global VRP_entry  
    global ARP_entry
    global MSR_entry
    global AS_entry
    global VS_entry
    global PVARP_entry
    global AT_entry
    global RnT_entry
    global RF_entry
    global RyT_entry
    
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()
    MSR = StringVar()
    AS = StringVar()
    VS = StringVar()
    PVARP = StringVar()
    AT = StringVar()
    RnT = StringVar()
    RF = StringVar()
    RyT = StringVar()

    LRL_values = (30, 35, 40, 45, 50,
                  51, 52, 53, 54, 55,
                  56, 57, 58, 59, 60,
                  61, 62, 63, 64, 65,
                  66, 67, 68, 69, 70,
                  71, 72, 73, 74, 75,
                  76, 77, 78, 79, 80,
                  81, 82, 83, 84, 85,
                  86, 87, 88, 89, 90,
                  95, 100, 105, 110, 115,
                  120, 125, 130, 135, 140,
                  145, 150, 155, 160, 165,
                  170, 175) 
    URL_values = (50, 55, 60, 65, 70,
                  75, 80, 85, 90, 95, 100,
                  105, 110, 115, 120, 125,
                  130, 135, 140, 145, 150,
                  155, 160, 165, 170, 175)
    AA_values = (0,0.1, 0.2, 0.3, 0.4,
                 0.5, 0.6, 0.7, 0.8,
                 0.9, 1, 1.1, 1.2, 1.3,
                 1.4, 1.5, 1.6, 1.7, 1.8,
                 1.9, 2, 2.1, 2.2, 2.3,
                 2.4, 2.5, 2.6, 2.7, 2.8,
                 2.9, 3, 3.1, 3.2, 3.3, 3.4, 3.5,
                 3.6, 3.7, 3.8, 3.9, 4,
                 4.1, 4.2, 4.3, 4.4, 4.5, 4.6,
                 4.7, 4.8, 4.9, 5)
    VA_values = (0,0.1, 0.2, 0.3, 0.4,
                 0.5, 0.6, 0.7, 0.8,
                 0.9, 1, 1.1, 1.2, 1.3,
                 1.4, 1.5, 1.6, 1.7, 1.8,
                 1.9, 2, 2.1, 2.2, 2.3,
                 2.4, 2.5, 2.6, 2.7, 2.8,
                 2.9, 3, 3.1, 3.2, 3.3, 3.4, 3.5,
                 3.6, 3.7, 3.8, 3.9, 4,
                 4.1, 4.2, 4.3, 4.4, 4.5, 4.6,
                 4.7, 4.8, 4.9, 5)
    APW_values = (1, 2, 3, 4, 5,
                  6, 7, 8, 9, 10,
                  11, 12, 13, 14, 15,
                  16, 17, 18, 19, 20,
                  21, 22, 23, 24, 25,
                  26, 27, 28, 29, 30)
    VPW_values = (1, 2, 3, 4, 5,
                  6, 7, 8, 9, 10,
                  11, 12, 13, 14, 15,
                  16, 17, 18, 19, 20,
                  21, 22, 23, 24, 25,
                  26, 27, 28, 29, 30)
    ARP_values = (150, 160, 170, 180, 190,
                  200, 210, 220, 230, 240,
                  250, 260, 270, 280, 290,
                  300, 310, 320, 330, 340,
                  350, 360, 370, 380, 390,
                  400, 410, 420, 430, 440,
                  450, 460, 470, 480, 490,
                  500)
    VRP_values = (150, 160, 170, 180, 190,
                  200, 210, 220, 230, 240,
                  250, 260, 270, 280, 290,
                  300, 310, 320, 330, 340,
                  350, 360, 370, 380, 390,
                  400, 410, 420, 430, 440,
                  450, 460, 470, 480, 490,
                  500)
    MSR_values = (50, 55, 60, 65, 70,
                  75, 80, 85, 90, 95, 100,
                  105, 110, 115, 120, 125,
                  130, 135, 140, 145, 150,
                  155, 160, 165, 170, 175)
    AS_values = (0.1, 0.2, 0.3, 0.4, 0.5,
                 0.6, 0.7 ,0.8, 0.9, 1,
                 1.1, 1.2, 1.3, 1.4, 1.5,
                 1.6, 1.7, 1.8, 1.9, 2,
                 2.1, 2.2, 2.3, 2.4, 2.5,
                 2.6, 2.7, 2.8, 2.9, 3,
                 3.1, 3.2, 3.3, 3.4, 3.5,
                 3.6, 3.7, 3.8, 3.9, 4,
                 4.1, 4.2, 4.3, 4.4, 4.5,
                 4.6, 4.7, 4.8, 4.9, 5)
    VS_values = (0.1, 0.2, 0.3, 0.4, 0.5,
                 0.6, 0.7 ,0.8, 0.9, 1,
                 1.1, 1.2, 1.3, 1.4, 1.5,
                 1.6, 1.7, 1.8, 1.9, 2,
                 2.1, 2.2, 2.3, 2.4, 2.5,
                 2.6, 2.7, 2.8, 2.9, 3,
                 3.1, 3.2, 3.3, 3.4, 3.5,
                 3.6, 3.7, 3.8, 3.9, 4,
                 4.1, 4.2, 4.3, 4.4, 4.5,
                 4.6, 4.7, 4.8, 4.9, 5)
    PVARP_values = (150, 160, 170, 180, 190,
                  200, 210, 220, 230, 240,
                  250, 260, 270, 280, 290,
                  300, 310, 320, 330, 340,
                  350, 360, 370, 380, 390,
                  400, 410, 420, 430, 440,
                  450, 460, 470, 480, 490,
                  500)
    AT_values = (1, 2, 3,
                 4, 5, 6, 7)
    RnT_values = (10, 20, 30, 40, 50)
    RF_values = (1, 2, 3, 4, 5,
                 6, 7, 8, 9, 10,
                 11, 12, 13, 14, 15)
    RyT_values = (2, 3, 4, 5,
                 6, 7, 8, 9, 10,
                 11, 12, 13, 14, 15)
    LRLtextboxState = "disabled"
    URLtextboxState = "disabled"
    AAtextboxState = "disabled"
    APWtextboxState = "disabled"
    VAtextboxState = "disabled"
    VPWtextboxState = "disabled"
    VRPtextboxState = "disabled"
    ARPtextboxState = "disabled"
    MSRtextboxState = "disabled"
    AStextboxState = "disabled"
    VStextboxState = "disabled"
    PVARPtextboxState = "disabled"
    ATtextboxState = "disabled"
    RnTtextboxState = "disabled"
    RFtextboxState = "disabled"
    RyTtextboxState = "disabled"
        
    if(mode == "AOO"): #all the modes with there certain parameters with each having editable boxes and readonly boxes
        LRLtextboxState = "readonly"
        URLtextboxState = "readonly"
        AAtextboxState = "readonly"
        APWtextboxState = "readonly"
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=45)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=95)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=145)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=195)
    elif(mode == "AAI"):
        LRLtextboxState = "readonly"
        URLtextboxState = "readonly"
        AAtextboxState = "readonly"
        APWtextboxState = "readonly"
        ARPtextboxState = "readonly"
        AStextboxState = "readonly"
        PVARPtextboxState = "readonly"
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=45)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=95)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=145)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=195)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=395)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=95)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=195)
    elif(mode == "VOO"):
        LRLtextboxState = "readonly"
        URLtextboxState = "readonly"
        VAtextboxState = "readonly"
        VPWtextboxState = "readonly"
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=45)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=95)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=245)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=295)
    elif(mode == "VVI"):
        LRLtextboxState = "readonly"
        URLtextboxState = "readonly"
        VAtextboxState = "readonly"
        VPWtextboxState = "readonly"
        VRPtextboxState = "readonly"
        VStextboxState = "readonly"
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=45)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=95)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=245)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=295)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=345)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=145)
    elif(mode == "AOOR"):
        LRLtextboxState = "readonly"
        URLtextboxState = "readonly"
        MSRtextboxState = "readonly"
        AAtextboxState = "readonly"
        APWtextboxState = "readonly"
        ATtextboxState = "readonly"
        RnTtextboxState = "readonly"
        RFtextboxState = "readonly"
        RyTtextboxState = "readonly"
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=45)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=95)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=45)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=145)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=195)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=245)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=295)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=345)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=395)
    elif(mode == "VOOR"):
        LRLtextboxState = "readonly"
        URLtextboxState = "readonly"
        MSRtextboxState = "readonly"
        VAtextboxState = "readonly"
        VPWtextboxState = "readonly"
        ATtextboxState = "readonly"
        RnTtextboxState = "readonly"
        RFtextboxState = "readonly"
        RyTtextboxState = "readonly"
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=45)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=95)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=45)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=245)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=295)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=245)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=295)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=345)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=395)
    elif(mode == "AAIR"):
        LRLtextboxState = "readonly"
        URLtextboxState = "readonly"
        MSRtextboxState = "readonly"
        AAtextboxState = "readonly"
        APWtextboxState = "readonly"
        AStextboxState = "readonly"
        ARPtextboxState = "readonly"
        PVARPtextboxState = "readonly"
        ATtextboxState = "readonly"
        RnTtextboxState = "readonly"
        RFtextboxState = "readonly"
        RyTtextboxState = "readonly"
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=45)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=95)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=45)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=145)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=195)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=95)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=395)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=195)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=245)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=295)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=345)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=395)
    elif(mode == "VVIR"):
        LRLtextboxState = "readonly"
        URLtextboxState = "readonly"
        MSRtextboxState = "readonly"
        VAtextboxState = "readonly"
        VPWtextboxState = "readonly"
        VStextboxState = "readonly"
        VRPtextboxState = "readonly"
        ATtextboxState = "readonly"
        RnTtextboxState = "readonly"
        RFtextboxState = "readonly"
        RyTtextboxState = "readonly"
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=45)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=95)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=45)  
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=245)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=295)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=145)
        Frame(frame,width=202,height=2,bg='black').place(x=320,y=345)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=245)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=295)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=345)
        Frame(frame,width=202,height=2,bg='black').place(x=920,y=395)
    else:
        mode = "OFF"

    #Input boxes (spinboxes)
    LRL_entry = Spinbox(frame, width=25, values = LRL_values, state = LRLtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = LRL)
    LRL_entry.pack()
    LRL_entry.place(x=320,y=20)
    
    URL_entry = Spinbox(frame, width=25, values = URL_values, state = URLtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = URL)
    URL_entry.pack()
    URL_entry.place(x=320,y=70)
    
    AA_entry = Spinbox(frame, width=25, values = AA_values, state = AAtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = AA)
    AA_entry.pack()
    AA_entry.place(x=320,y=120)
    
    APW_entry = Spinbox(frame, width=25, values = APW_values, state = APWtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = APW)
    APW_entry.pack()
    APW_entry.place(x=320,y=170)
    
    VA_entry = Spinbox(frame, width=25, values = VA_values, state = VAtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VA)
    VA_entry.pack()
    VA_entry.place(x=320,y=220)
    
    VPW_entry = Spinbox(frame, width=25, values = VPW_values, state = VPWtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VPW)
    VPW_entry.pack()
    VPW_entry.place(x=320,y=270)
    
    VRP_entry = Spinbox(frame, width=25, values = VRP_values, state = VRPtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VRP)
    VRP_entry.pack()
    VRP_entry.place(x=320,y=320)
    
    ARP_entry = Spinbox(frame, width=25, values = ARP_values, state = ARPtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = ARP)
    ARP_entry.pack()
    ARP_entry.place(x=320,y=370)

    MSR_entry = Spinbox(frame, width=25, values = MSR_values, state = MSRtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = MSR)
    MSR_entry.pack()
    MSR_entry.place(x=920,y=20)
#
    AS_entry = Spinbox(frame, width=25, values = AS_values, state = AStextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = AS)
    AS_entry.pack()
    AS_entry.place(x=920,y=70)

    VS_entry = Spinbox(frame, width=25, values = VS_values, state = VStextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = VS)
    VS_entry.pack()
    VS_entry.place(x=920,y=120)
    
    PVARP_entry = Spinbox(frame, width=25, values = PVARP_values, state = PVARPtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = PVARP)
    PVARP_entry.pack()
    PVARP_entry.place(x=920,y=170)
    
    AT_entry = Spinbox(frame, width=25, values = AT_values, state = ATtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = AT)
    AT_entry.pack()
    AT_entry.place(x=920,y=220)
    
    RnT_entry = Spinbox(frame, width=25, values = RnT_values, state = RnTtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = RnT)
    RnT_entry.pack()
    RnT_entry.place(x=920,y=270)
    
    RF_entry = Spinbox(frame, width=25, values = RF_values, state = RFtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = RF)
    RF_entry.pack()
    RF_entry.place(x=920,y=320)
    
    RyT_entry = Spinbox(frame, width=25, values = RyT_values, state = RyTtextboxState, readonlybackground = "white", fg='black', border=0, bg="#f5f5f5", font=('Microsoft YaHei UI Light',11), textvariable = RyT)
    RyT_entry.pack()
    RyT_entry.place(x=920,y=370)
    
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
    MSR = StringVar()
    AS = StringVar()
    VS = StringVar()
    PVARP = StringVar()
    AT = StringVar()
    RnT = StringVar()
    RF = StringVar()
    RyT = StringVar()
    
    frame = Frame(root,width=1250, height= 600, bg='white')
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
    MSR = StringVar()
    AS = StringVar()
    VS = StringVar()
    PVARP = StringVar()
    AT = StringVar()
    RnT = StringVar()
    RF = StringVar()
    RyT = StringVar()
    

    frame = Frame(root,width=1250, height= 600, bg='white')
    frame.place(x=20,y=80)
    
    LabelsTemplate(frame)
    ModesTemplate("AOO", frame)

    file1 = open(username1, "r")
    LRL_prev = linecache.getline(username1, 5)
    URL_prev = linecache.getline(username1, 6)
    AA_prev = linecache.getline(username1, 7)
    APW_prev = linecache.getline(username1, 8)

    Label(frame, text = ("The previous values were \n" + LRL_prev.strip() + " " + URL_prev.strip() + " " + AA_prev.strip() + " " + APW_prev.strip()),bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 11)).place(x=530,y=415)

    
    def applychanges(): #setting up the confitions for the parameteres
        Frame(frame,width=1000,height=50,bg='white').place(x=50,y=400)
        LRL_value = LRL_entry.get()
        URL_value = URL_entry.get()
        AA_value = AA_entry.get()
        APW_value = APW_entry.get()
        VA_value = VA_entry.get()
        VPW_value = VPW_entry.get()
        VRP_value = VRP_entry.get()
        ARP_value = ARP_entry.get()

        print(LRL_value + " " + URL_value + " " + AA_value + " " + APW_value)

        if (int(URL_value) > int(LRL_value)):
            with open(username1, 'r') as file:
                data = file.readlines()

            data[4] = LRL_value + "\n"
            data[5] = URL_value + "\n"
            data[6] = AA_value + "\n"
            data[7] = APW_value + "\n"

            with open(username1, 'w') as file:
                file.writelines(data)
            with open("data.txt", 'w') as file:
                file.writelines("1" + " ")
                file.writelines(LRL_value + " ")
                file.writelines(URL_value + " ")
                file.writelines(AA_value + " ")
                file.writelines(APW_value + " ")
                file.writelines("0 0 0 0 0 0 0 0 0 0 0 0") 
        else:
            Label(frame, text = "URL must be higher than LRL", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=415)

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
    MSR = StringVar()
    AS = StringVar()
    VS = StringVar()
    PVARP = StringVar()
    AT = StringVar()
    RnT = StringVar()
    RF = StringVar()
    RyT = StringVar()
    

    frame = Frame(root,width=1250, height= 600, bg='white')
    frame.place(x=20,y=80)

    LabelsTemplate(frame)
    ModesTemplate("VOO", frame)

    file1 = open(username1, "r")
    LRL_prev = linecache.getline(username1, 10)
    URL_prev = linecache.getline(username1, 11)
    VA_prev = linecache.getline(username1, 12)
    VPW_prev = linecache.getline(username1, 13)

    Label(frame, text = ("The previous values were \n" + LRL_prev.strip() + " " + URL_prev.strip() + " " + VA_prev.strip() + " " + VPW_prev.strip()),bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 11)).place(x=530,y=415)
    
    def applychanges():
        Frame(frame,width=1000,height=50,bg='white').place(x=50,y=400)
        LRL_value = LRL_entry.get()
        URL_value = URL_entry.get()
        AA_value = AA_entry.get()
        APW_value = APW_entry.get()
        VA_value = VA_entry.get()
        VPW_value = VPW_entry.get()
        VRP_value = VRP_entry.get()
        ARP_value = ARP_entry.get()

        print(LRL_value + " " + URL_value + " " + VA_value + " " + VPW_value)
        
        if (int(URL_value) > int(LRL_value)):
            with open(username1, 'r') as file:
                data = file.readlines()

            data[9] = LRL_value + "\n"
            data[10] = URL_value + "\n"
            data[11] = VA_value + "\n"
            data[12] = VPW_value + "\n"

            with open(username1, 'w') as file:
                file.writelines(data)
            with open("data.txt", 'w') as file:
                file.writelines("2" + " ")
                file.writelines(LRL_value + " ")
                file.writelines(URL_value + " ")
                file.writelines("0 0 ")
                file.writelines(VA_value + " ")
                file.writelines(VPW_value + " ")
                file.writelines("0 0 0 0 0 0 0 0 0 0") 
        else:
            Label(frame, text = "URL must be higher than LRL", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=415)            
        
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
    MSR = StringVar()
    AS = StringVar()
    VS = StringVar()
    PVARP = StringVar()
    AT = StringVar()
    RnT = StringVar()
    RF = StringVar()
    RyT = StringVar()

    frame = Frame(root,width=1250, height= 600, bg='white')
    frame.place(x=20,y=80)

    LabelsTemplate(frame)
    ModesTemplate("AAI", frame)

    file1 = open(username1, "r")
    LRL_prev = linecache.getline(username1, 15)
    URL_prev = linecache.getline(username1, 16)
    AA_prev = linecache.getline(username1, 17)
    APW_prev = linecache.getline(username1, 18)
    ARP_prev = linecache.getline(username1, 19)
    AS_prev = linecache.getline(username1, 20)
    PVARP_prev = linecache.getline(username1, 21)


    Label(frame, text = ("The previous values were \n" + LRL_prev.strip() + " " + URL_prev.strip() + " " + AA_prev.strip() + " " + APW_prev.strip() + " " + ARP_prev.strip() + " " + AS_prev.strip() + " " + PVARP_prev.strip()),bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 11)).place(x=530,y=415)

    def applychanges():
        Frame(frame,width=1000,height=50,bg='white').place(x=50,y=400)
        LRL_value = LRL_entry.get()
        URL_value = URL_entry.get()
        AA_value = AA_entry.get()
        APW_value = APW_entry.get()
        VA_value = VA_entry.get()
        VPW_value = VPW_entry.get()
        VRP_value = VRP_entry.get()
        ARP_value = ARP_entry.get()
        MSR_value = MSR_entry.get()
        AS_value = AS_entry.get()
        VS_value = VS_entry.get()
        PVARP_value = PVARP_entry.get()
        AT_value = AT_entry.get()
        RnT_value = RnT_entry.get()
        RF_value = RF_entry.get()
        RyT_value = RyT_entry.get()

        print(LRL_value + " " + URL_value + " " + AA_value + " " + APW_value + " " + ARP_value)

        if (int(URL_value) > int(LRL_value)):       
            with open(username1, 'r') as file:
                data = file.readlines()

            data[14] = LRL_value + "\n"
            data[15] = URL_value + "\n"
            data[16] = AA_value + "\n"
            data[17] = APW_value + "\n"
            data[18] = ARP_value + "\n"
            data[19] = AS_value + "\n"
            data[20] = PVARP_value + "\n"

            with open(username1, 'w') as file:
                file.writelines(data)
            with open("data.txt", 'w') as file:
                file.writelines("3" + " ")
                file.writelines(LRL_value + " ")
                file.writelines(URL_value + " ")
                file.writelines(AA_value + " ")
                file.writelines(APW_value + " ")
                file.writelines("0 0 0 ")
                file.writelines(ARP_value + " ")
                file.writelines("0 ")
                file.writelines(AS_value + " ")
                file.writelines("0 ")
                file.writelines(PVARP_value + " ")
                file.writelines("0 0 0 0")                
        else:
            Label(frame, text = "URL must be higher than LRL", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=415)            
                       
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
    MSR = StringVar()
    AS = StringVar()
    VS = StringVar()
    PVARP = StringVar()
    AT = StringVar()
    RnT = StringVar()
    RF = StringVar()
    RyT = StringVar()
    

    frame = Frame(root,width=1250, height= 600, bg='white')
    frame.place(x=20,y=80)
    
    LabelsTemplate(frame)
    ModesTemplate("VVI", frame)

    file1 = open(username1, "r")
    LRL_prev = linecache.getline(username1, 23)
    URL_prev = linecache.getline(username1, 24)
    VA_prev = linecache.getline(username1, 25)
    VPW_prev = linecache.getline(username1, 26)
    VRP_prev = linecache.getline(username1, 27)
    VS_prev = linecache.getline(username1, 28)

    Label(frame, text = ("The previous values were \n" + LRL_prev.strip() + " " + URL_prev.strip() + " " + VA_prev.strip() + " " + VPW_prev.strip() + " " + VRP_prev.strip() + " " + VS_prev.strip()),bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 11)).place(x=530,y=415)

    def applychanges():
        Frame(frame,width=1000,height=50,bg='white').place(x=50,y=400)
        LRL_value = LRL_entry.get()
        URL_value = URL_entry.get()
        AA_value = AA_entry.get()
        APW_value = APW_entry.get()
        VA_value = VA_entry.get()
        VPW_value = VPW_entry.get()
        VRP_value = VRP_entry.get()
        ARP_value = ARP_entry.get()
        MSR_value = MSR_entry.get()
        AS_value = AS_entry.get()
        VS_value = VS_entry.get()
        PVARP_value = PVARP_entry.get()
        AT_value = AT_entry.get()
        RnT_value = RnT_entry.get()
        RF_value = RF_entry.get()
        RyT_value = RyT_entry.get()

        print(LRL_value + " " + URL_value + " " + VA_value + " " + VPW_value + " " + VRP_value)

        if (int(URL_value) > int(LRL_value)): 
            with open(username1, 'r') as file:
                data = file.readlines()

            data[22] = LRL_value + "\n"
            data[23] = URL_value + "\n"
            data[24] = VA_value + "\n"
            data[25] = VPW_value + "\n"
            data[26] = VRP_value + "\n"
            data[27] = VS_value + "\n"

            with open(username1, 'w') as file:
                file.writelines(data)
            with open("data.txt", 'w') as file:
                file.writelines("4" + " ")
                file.writelines(LRL_value + " ")
                file.writelines(URL_value + " ")
                file.writelines("0 0 ")
                file.writelines(VA_value + " ")
                file.writelines(VPW_value + " ")
                file.writelines(VRP_value + " ")
                file.writelines("0 0 0 ")
                file.writelines(VS_value + " ")
                file.writelines("0 0 0 0 0")
        else:
            Label(frame, text = "URL must be higher than LRL", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=415)            
            
    Button(frame, width=39, pady=7, text='Apply Changes', bg='#983cc8', fg='white', border=0, command = applychanges).place(x=60, y=450)

def AOOR():
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()
    MSR = StringVar()
    AS = StringVar()
    VS = StringVar()
    PVARP = StringVar()
    AT = StringVar()
    RnT = StringVar()
    RF = StringVar()
    RyT = StringVar()
    

    frame = Frame(root,width=1250, height= 600, bg='white')
    frame.place(x=20,y=80)
    
    LabelsTemplate(frame)
    ModesTemplate("AOOR", frame)

    file1 = open(username1, "r")
    LRL_prev = linecache.getline(username1, 30)
    URL_prev = linecache.getline(username1, 31)
    AA_prev = linecache.getline(username1, 32)
    APW_prev = linecache.getline(username1, 33)
    MSR_prev = linecache.getline(username1, 34)
    AT_prev = linecache.getline(username1, 35)
    RnT_prev = linecache.getline(username1, 36)
    RF_prev = linecache.getline(username1, 37)
    RyT_prev = linecache.getline(username1, 38)

    Label(frame, text = ("The previous values were \n" + LRL_prev.strip() + " " + URL_prev.strip() + " " + AA_prev.strip() + " " + APW_prev.strip() + " " + MSR_prev.strip() + " " + AT_prev.strip() + " " + RnT_prev.strip() + " " + RF_prev.strip() + " " + RyT_prev.strip()),bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 11)).place(x=530,y=415)

    def applychanges():
        Frame(frame,width=1000,height=50,bg='white').place(x=50,y=400)
        LRL_value = LRL_entry.get()
        URL_value = URL_entry.get()
        AA_value = AA_entry.get()
        APW_value = APW_entry.get()
        VA_value = VA_entry.get()
        VPW_value = VPW_entry.get()
        VRP_value = VRP_entry.get()
        ARP_value = ARP_entry.get()
        MSR_value = MSR_entry.get()
        AS_value = AS_entry.get()
        VS_value = VS_entry.get()
        PVARP_value = PVARP_entry.get()
        AT_value = AT_entry.get()
        RnT_value = RnT_entry.get()
        RF_value = RF_entry.get()
        RyT_value = RyT_entry.get()

        print(LRL_value + " " + URL_value + " " + VA_value + " " + VPW_value + " " + VRP_value)

        if (int(URL_value) > int(LRL_value)): 
            with open(username1, 'r') as file:
                data = file.readlines()

            data[29] = LRL_value + "\n"
            data[30] = URL_value + "\n"
            data[31] = AA_value + "\n"
            data[32] = APW_value + "\n"
            data[33] = MSR_value + "\n"
            data[34] = AT_value + "\n"
            data[35] = RnT_value + "\n"
            data[36] = RF_value + "\n"
            data[37] = RyT_value + "\n"

            with open(username1, 'w') as file:
                file.writelines(data)
            with open("data.txt", 'w') as file:
                file.writelines("5" + " ")
                file.writelines(LRL_value + " ")
                file.writelines(URL_value + " ")
                file.writelines(AA_value + " ")
                file.writelines(APW_value + " ")
                file.writelines("0 0 0 0 ")
                file.writelines(MSR_value + " ")
                file.writelines("0 0 0 ")
                file.writelines(AT_value + " ")
                file.writelines(RnT_value + " ")
                file.writelines(RF_value + " ")
                file.writelines(RyT_value + " ")

        else:
            Label(frame, text = "URL must be higher than LRL", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=415)        
    Button(frame, width=39, pady=7, text='Apply Changes', bg='#983cc8', fg='white', border=0, command = applychanges).place(x=60, y=450)

def VOOR():
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()
    MSR = StringVar()
    AS = StringVar()
    VS = StringVar()
    PVARP = StringVar()
    AT = StringVar()
    RnT = StringVar()
    RF = StringVar()
    RyT = StringVar()
    

    frame = Frame(root,width=1250, height= 600, bg='white')
    frame.place(x=20,y=80)
    
    LabelsTemplate(frame)
    ModesTemplate("VOOR", frame)

    file1 = open(username1, "r")
    LRL_prev = linecache.getline(username1, 40)
    URL_prev = linecache.getline(username1, 41)
    VA_prev = linecache.getline(username1, 42)
    VPW_prev = linecache.getline(username1, 43)
    MSR_prev = linecache.getline(username1, 44)
    AT_prev = linecache.getline(username1, 45)
    RnT_prev = linecache.getline(username1, 46)
    RF_prev = linecache.getline(username1, 47)
    RyT_prev = linecache.getline(username1, 48)

    Label(frame, text = ("The previous values were \n" + LRL_prev.strip() + " " + URL_prev.strip() + " " + VA_prev.strip() + " " + VPW_prev.strip() + " " + MSR_prev.strip() + " " + AT_prev.strip() + " " + RnT_prev.strip() + " " + RF_prev.strip() + " " + RyT_prev.strip()),bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 11)).place(x=530,y=415)

    def applychanges():
        Frame(frame,width=1000,height=50,bg='white').place(x=50,y=400)
        LRL_value = LRL_entry.get()
        URL_value = URL_entry.get()
        AA_value = AA_entry.get()
        APW_value = APW_entry.get()
        VA_value = VA_entry.get()
        VPW_value = VPW_entry.get()
        VRP_value = VRP_entry.get()
        ARP_value = ARP_entry.get()
        MSR_value = MSR_entry.get()
        AS_value = AS_entry.get()
        VS_value = VS_entry.get()
        PVARP_value = PVARP_entry.get()
        AT_value = AT_entry.get()
        RnT_value = RnT_entry.get()
        RF_value = RF_entry.get()
        RyT_value = RyT_entry.get()

        print(LRL_value + " " + URL_value + " " + VA_value + " " + VPW_value + " " + VRP_value)

        if (int(URL_value) > int(LRL_value)):         
            with open(username1, 'r') as file:
                data = file.readlines()

            data[39] = LRL_value + "\n"
            data[40] = URL_value + "\n"
            data[41] = VA_value + "\n"
            data[42] = VPW_value + "\n"
            data[43] = MSR_value + "\n"
            data[44] = AT_value + "\n"
            data[45] = RnT_value + "\n"
            data[46] = RF_value + "\n"
            data[47] = RyT_value + "\n"

            with open(username1, 'w') as file:
                file.writelines(data)
            with open("data.txt", 'w') as file:
                file.writelines("6" + " ")
                file.writelines(LRL_value + " ")
                file.writelines(URL_value + " ")
                file.writelines("0 0 ")
                file.writelines(VA_value + " ")
                file.writelines(VPW_value + " ")
                file.writelines("0 0 ")
                file.writelines(MSR_value + " ")
                file.writelines("0 0 0 ")
                file.writelines(AT_value + " ")
                file.writelines(RnT_value + " ")
                file.writelines(RF_value + " ")
                file.writelines(RyT_value + " ")
        else:
            Label(frame, text = "URL must be higher than LRL", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=415)        
            
    Button(frame, width=39, pady=7, text='Apply Changes', bg='#983cc8', fg='white', border=0, command = applychanges).place(x=60, y=450)
    
def AAIR():
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()
    MSR = StringVar()
    AS = StringVar()
    VS = StringVar()
    PVARP = StringVar()
    AT = StringVar()
    RnT = StringVar()
    RF = StringVar()
    RyT = StringVar()
    

    frame = Frame(root,width=1250, height= 600, bg='white')
    frame.place(x=20,y=80)
    
    LabelsTemplate(frame)
    ModesTemplate("AAIR", frame)

    file1 = open(username1, "r")
    LRL_prev = linecache.getline(username1, 50)
    URL_prev = linecache.getline(username1, 51)
    AA_prev = linecache.getline(username1, 52)
    APW_prev = linecache.getline(username1, 53)
    ARP_prev = linecache.getline(username1, 54)
    MSR_prev = linecache.getline(username1, 55)
    AS_prev = linecache.getline(username1, 56)
    PVARP_prev = linecache.getline(username1, 57)
    AT_prev = linecache.getline(username1, 58)
    RnT_prev = linecache.getline(username1, 59)
    RF_prev = linecache.getline(username1, 60)
    RyT_prev = linecache.getline(username1, 61)

    Label(frame, text = ("The previous values were \n" + LRL_prev.strip() + " " + URL_prev.strip() + " " + AA_prev.strip() + " " + APW_prev.strip() + " " + ARP_prev.strip() + " " + MSR_prev.strip() + " " + AS_prev.strip() + " " + PVARP_prev.strip() + " " + AT_prev.strip() + " " + RnT_prev.strip() + " " + RF_prev.strip() + " " + RyT_prev.strip()),bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 11)).place(x=530,y=415)

    def applychanges():
        Frame(frame,width=1000,height=50,bg='white').place(x=50,y=400)
        LRL_value = LRL_entry.get()
        URL_value = URL_entry.get()
        AA_value = AA_entry.get()
        APW_value = APW_entry.get()
        VA_value = VA_entry.get()
        VPW_value = VPW_entry.get()
        VRP_value = VRP_entry.get()
        ARP_value = ARP_entry.get()
        MSR_value = MSR_entry.get()
        AS_value = AS_entry.get()
        VS_value = VS_entry.get()
        PVARP_value = PVARP_entry.get()
        AT_value = AT_entry.get()
        RnT_value = RnT_entry.get()
        RF_value = RF_entry.get()
        RyT_value = RyT_entry.get()

        print(LRL_value + " " + URL_value + " " + VA_value + " " + VPW_value + " " + VRP_value)

        if (int(URL_value) > int(LRL_value)): 
            with open(username1, 'r') as file:
                data = file.readlines()

            data[49] = LRL_value + "\n"
            data[50] = URL_value + "\n"
            data[51] = AA_value + "\n"
            data[52] = APW_value + "\n"
            data[53] = ARP_value + "\n"
            data[54] = MSR_value + "\n"
            data[55] = AS_value + "\n"
            data[56] = PVARP_value + "\n"
            data[57] = AT_value + "\n"
            data[58] = RnT_value + "\n"
            data[59] = RF_value + "\n"
            data[60] = RyT_value + "\n"

            with open(username1, 'w') as file:
                file.writelines(data)
            with open("data.txt", 'w') as file:
                file.writelines("7" + " ")
                file.writelines(LRL_value + " ")
                file.writelines(URL_value + " ")
                file.writelines(AA_value + " ")
                file.writelines(APW_value + " ")
                file.writelines("0 0 0 ")
                file.writelines(APR_value + " ")
                file.writelines(MSR_value + " ")
                file.writelines(AS_value + " ")
                file.writelines("0 ")
                file.writelines(PVARP_value + " ")
                file.writelines(AT_value + " ")
                file.writelines(RnT_value + " ")
                file.writelines(RF_value + " ")
                file.writelines(RyT_value + " ")
        else:
            Label(frame, text = "URL must be higher than LRL", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=415)
            
    Button(frame, width=39, pady=7, text='Apply Changes', bg='#983cc8', fg='white', border=0, command = applychanges).place(x=60, y=450)
    
def VVIR():
    LRL = StringVar()
    URL = StringVar()
    AA = StringVar()
    APW = StringVar()
    VA = StringVar()
    VPW = StringVar()
    VRP = StringVar()
    ARP = StringVar()
    MSR = StringVar()
    AS = StringVar()
    VS = StringVar()
    PVARP = StringVar()
    AT = StringVar()
    RnT = StringVar()
    RF = StringVar()
    RyT = StringVar()
    

    frame = Frame(root,width=1250, height= 600, bg='white')
    frame.place(x=20,y=80)
    
    LabelsTemplate(frame)
    ModesTemplate("VVIR", frame)

    file1 = open(username1, "r")
    LRL_prev = linecache.getline(username1, 63)
    URL_prev = linecache.getline(username1, 64)
    VA_prev = linecache.getline(username1, 65)
    VPW_prev = linecache.getline(username1, 66)
    VRP_prev = linecache.getline(username1, 67)
    MSR_prev = linecache.getline(username1, 68)
    VS_prev = linecache.getline(username1, 69)
    AT_prev = linecache.getline(username1, 70)
    RnT_prev = linecache.getline(username1, 71)
    RF_prev = linecache.getline(username1, 72)
    RyT_prev = linecache.getline(username1, 73)

    Label(frame, text = ("The previous values were \n" + LRL_prev.strip() + " " + URL_prev.strip() + " " + VA_prev.strip() + " " + VPW_prev.strip() + " " + VRP_prev.strip() + " " + MSR_prev.strip() + " " + VS_prev.strip() + " " + AT_prev.strip() + " " + RnT_prev.strip() + " " + RF_prev.strip() + " " + RyT_prev.strip()),bg = "white", fg = "black", font = ('Microsoft YaHei UI Light', 11)).place(x=530,y=415)


    def applychanges():
        Frame(frame,width=1000,height=50,bg='white').place(x=50,y=400)
        LRL_value = LRL_entry.get()
        URL_value = URL_entry.get()
        AA_value = AA_entry.get()
        APW_value = APW_entry.get()
        VA_value = VA_entry.get()
        VPW_value = VPW_entry.get()
        VRP_value = VRP_entry.get()
        ARP_value = ARP_entry.get()
        MSR_value = MSR_entry.get()
        AS_value = AS_entry.get()
        VS_value = VS_entry.get()
        PVARP_value = PVARP_entry.get()
        AT_value = AT_entry.get()
        RnT_value = RnT_entry.get()
        RF_value = RF_entry.get()
        RyT_value = RyT_entry.get()

        print(LRL_value + " " + URL_value + " " + VA_value + " " + VPW_value + " " + VRP_value)

        if (int(URL_value) > int(LRL_value)):         
            with open(username1, 'r') as file:
                data = file.readlines()

            data[62] = LRL_value + "\n"
            data[63] = URL_value + "\n"
            data[64] = VA_value + "\n"
            data[65] = VPW_value + "\n"
            data[66] = VRP_value + "\n"
            data[67] = MSR_value + "\n"
            data[68] = VS_value + "\n"
            data[69] = AT_value + "\n"
            data[70] = RnT_value + "\n"
            data[71] = RF_value + "\n"
            data[72] = RyT_value + "\n"

            with open(username1, 'w') as file:
                file.writelines(data)
            with open("data.txt", 'w') as file:
                file.writelines("8" + " ")
                file.writelines(LRL_value + " ")
                file.writelines(URL_value + " ")
                file.writelines("0 0 ")
                file.writelines(VA_value + " ")
                file.writelines(VPW_value + " ")
                file.writelines(VRP_value + " ")
                file.writelines("0 ")
                file.writelines(MSR_value + " ")
                file.writelines("0 ")
                file.writelines(VS_value + " ")
                file.writelines("0 ")
                file.writelines(AT_value + " ")
                file.writelines(RnT_value + " ")
                file.writelines(RF_value + " ")
                file.writelines(RyT_value + " ")
        else:
            Label(frame, text = "URL must be higher than LRL", fg = "red", bg='white', font = ('Microsoft YaHei UI Light', 11)).place(x=530, y=415)
            
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
            file.write(serial_info + "\n")
            file.write("AOO" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" +
                       "VOO" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" +
                       "AAI" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" +
                       "VVI" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" +
                       "AOOR" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" +
                       "VOOR" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" +
                       "AAIR" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n"  + "|" + "\n" +
                       "VVIR" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n" + "|" + "\n")
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
