from tkinter import *
from tkinter.ttk import Combobox

import serial
import serial.tools.list_ports

class robotArmCTR() :
    def __init__(self, master):
        self.master = master
        self.master.title("Robot Arm CTR")

        self.setup_serial_frame()

    def setup_serial_frame():
        serial_frame = Frame(self.master, width = 300)
        serial_frame.pack()

        serial_label = Label(serial_frame, text = "Serial Port 선택", bg="yellow", fg="black", padx=100)
        serial_label.pack()

        

if __name__ == "__main__":
    root = Tk()
    app = robotArmCTR(root)
    root.mainloop()