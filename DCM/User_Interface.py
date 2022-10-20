from tkinter import *
import os

def close2():
    screen5.destroy()

def close3():
    screen6.destroy()

def session():
    screen7 = Toplevel(screen)
    screen7.title("dashboard")
    screen7.geometry("400x400")
    Label(screen7, text = "Welcome to the dashboard").pack()
    


def successful_login():
    session()

def incorrect_password():
    global screen5
    
    screen5 = Toplevel(screen)
    screen5.title("success")
    screen5.geometry("150x100")
    Label(screen5, text = "Incorrect Password").pack()
    Button(screen5, text = "Continue", command = close2).pack()

def unknown_user():
    global screen6
    
    screen6 = Toplevel(screen)
    screen6.title("success")
    screen6.geometry("150x100")
    Label(screen6, text = "Unknown User").pack()
    Button(screen6, text = "Continue", command = close3).pack()

def register_user():
    username_info = username.get()
    password_info = password.get()

    file = open(username_info, "w")
    file.write(username_info + "\n")
    file.write(password_info)
    file.close()

    username_entry.delete(0, END)
    password_entry.delete(0, END)

    Label(screen2, text = "Registration Successful", fg = "green", font = ("calibri", 11)).pack()

def login_verify():
    username1 = username_verify.get()
    password1 = password_verify.get()
    username_entry1.delete(0, END)
    password_entry1.delete(0, END)

    list_of_files = os.listdir()
    if username1 in list_of_files:
       file1 = open(username1, "r")
       verify = file1.read().splitlines()
       if password1 in verify:
           successful_login()
       else:
           incorrect_password()
    else:
        unknown_user()

def register():
    global screen2
    global username
    global password
    global username_entry
    global password_entry
    
    screen2 = Toplevel(screen)
    screen2.title("Register")
    screen2.geometry("300x250")

    username = StringVar()
    password = StringVar()

    Label(screen2, text = "Enter details below").pack()
    Label(screen2, text = "").pack()
    Label(screen2, text = "Username * ").pack()
    
    username_entry = Entry(screen2, textvariable = username)
    username_entry.pack()

    Label(screen2, text = "Password * ").pack()
    
    password_entry = Entry(screen2, textvariable = password)
    password_entry.pack()
    
    Label(screen2, text = "").pack()
    Button(screen2, text = "Resigter", width = 10, height = 1, command = register_user).pack()

def login():
     global screen3
     global username_verify
     global password_verify
     global username_entry1
     global password_entry1
     
     screen3 = Toplevel(screen)
     screen3.title("login")
     screen3.geometry("300x250")
     Label(screen3, text = "please enter details below").pack()
     Label(screen3, text = "").pack()

     username_verify = StringVar()
     password_verify = StringVar()
     
     Label(screen3, text = "Username * ").pack()
     username_entry1 = Entry(screen3, textvariable = username_verify)
     username_entry1.pack()
     
     Label(screen3, text = "Password * ").pack()
     password_entry1 = Entry(screen3, textvariable = password_verify)
     password_entry1.pack()
     Label(screen3, text = "").pack()
     Button(screen3, text = "login", width = 10, height = 1, command = login_verify).pack()


def main_screen():
    global screen
    
    screen = Tk()
    screen.geometry("300x250")
    screen.title("PaceMaker")
    Label(text = "Pacemaker User Interface", bg = "grey", width = "300", height = "2", font = ("calibri", 13)).pack()
    Button(text = "Login", height = "2", width = "30", command = login).pack()
    Label(text = "").pack()
    Button(text = "Register", height = "2", width = "30", command = register).pack()
    
    screen.mainloop
    
main_screen()


 
