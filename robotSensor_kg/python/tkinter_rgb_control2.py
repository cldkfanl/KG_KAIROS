import tkinter as tk
import serial

ser = serial.Serial('COM4', 115200, timeout=1)

def send_command(command):
    ser.write(command.encode())
def to_red():
    send_command('R')
def to_green():
    send_command('G')
def to_blue():
    send_command('B')
def to_yellow():
    send_command('Y')
def to_clear():
    send_command('X')

def Cbutton(master, text, color, side, text_color, command):
    button = tk.Button(master, text=text, bg=color, fg=text_color, width=10, height=3, command=command)
    button.pack(side=side, padx=10, pady=10)

window = tk.Tk()
window.geometry('400x400')
window.title('RGB Control')

Cbutton(window, '빨강', 'red', 'top', 'black', to_red)
Cbutton(window, '초록', 'green', 'left', 'black', to_green)
Cbutton(window, '파랑', 'blue', 'bottom', 'black', to_blue)
Cbutton(window, '노랑', 'yellow', 'right', 'black', to_yellow)

offButton = tk.Button(window, text='꺼짐', command = to_clear, bg='black', fg='white', width=10, height=3)
offButton.place(relx = 0.5, rely = 0.5, anchor = 'center')


window.mainloop()