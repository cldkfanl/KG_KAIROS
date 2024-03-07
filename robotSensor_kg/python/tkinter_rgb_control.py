import tkinter as tk
import serial

def send_command(command):
    ser.write(command.encode())

def to_red():
    send_command('R')

def to_yellow():
    send_command('Y')

def to_green():
    send_command('G')

def to_blue():
    send_command('B')

def clear():
    send_command('X')

ser = serial.Serial('COM4', 115200, timeout=1)

def Cbutton(master, text, color, side, text_color, command):
    button = tk.Button(master, text=text, bg=color, fg=text_color, width=10, height=3, command=command)
    button.pack(side=side, padx=10, pady=10)

window = tk.Tk()
window.geometry("400x400")
window.title('Color Buttons')

Cbutton(window, '빨강', 'red', 'left', 'white', to_red)
Cbutton(window, '노랑', 'yellow', 'right', 'black', to_yellow)
Cbutton(window, '초록', 'green', 'top', 'white', to_green)
Cbutton(window, '파랑', 'blue', 'bottom', 'white', to_blue)

offButton = tk.Button(window, text="꺼짐", command=clear, bg="white", fg='black', width=10, height=3 )
offButton.place(relx=0.5,rely=0.5, anchor="center")

window.mainloop()