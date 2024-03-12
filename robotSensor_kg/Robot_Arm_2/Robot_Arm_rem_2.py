from tkinter import Tk, Frame, Label, Scale, Button, messagebox, StringVar, Entry, HORIZONTAL
from tkinter.ttk import Combobox
import serial
import serial.tools.list_ports
import time

class RobotArmControl:
    def __init__(self, master):
        self.master = master
        self.master.title("Robot Arm Control")

        # Serial Communication
        self.setup_serial_frame()

        # Robot Arm Frame
        self.setup_robot_arm()

        # Spacer Frame
        self.setup_spacer_frame(pady=20)

        # Buttons
        self.setup_buttons()

        # Position Combobox
        self.setup_position_combobox()

        # Spacer Frame
        self.setup_spacer_frame(pady=20)


    def setup_serial_frame(self):
            serial_frame = Frame(self.master, width=300)
            serial_frame.pack()

            serial_label = Label(
                serial_frame, text="Serial Port 를 선택하세요", bg="yellow", fg="black", padx=100)
            serial_label.pack()

            # 사용가능한 시리얼 포트 받아와 selected_port 변수에 첫번째 값 저장
            port_list = [
                port.device for port in serial.tools.list_ports.comports()]
            self.selected_port = StringVar()
            self.selected_port.set(
                port_list[len(port_list)-1] if port_list else "No ports available")

            # 시리얼 버튼과 콤보 박스를 포함할 프레임 생성
            serial_button_frame = Frame(serial_frame)
            serial_button_frame.pack()

            # Serial Port 선택 콤보 박스 생성 및 배치
            port_combobox = Combobox(serial_button_frame, values=port_list,
                                state="readonly", textvariable=self.selected_port)
            # 시리얼 버튼과 콤보 박스 사이에 5만큼의 패딩 추가
            port_combobox.pack(side='left', padx=(10, 5))
            port_combobox.bind("<<ComboboxSelected>>",
                            self.update_selected_port)  # 선택이 변경될 때마다 변수 업데이트

            # Open Serial 버튼 생성 및 배치
            open_serial_button = Button(serial_button_frame, text="Open Serial",
                                        height=2, width=15, fg="black", command=self.open_serial)
            # 시리얼 버튼과 콤보 박스 사이에 5만큼의 패딩 추가
            open_serial_button.pack(side='left', padx=(0, 5))

            # Close Serial 버튼 생성 및 배치
            close_serial_button = Button(serial_button_frame, text="Close Serial",
                            height=2, width=15, fg="black", command=self.close_serial)
            # 시리얼 버튼과 콤보 박스 사이에 5만큼의 패딩 추가
            close_serial_button.pack(side='left', padx=(0, 10))


    def update_selected_port(self, event):
        # 콤보박스의 선택값을 selected_port 변수에 업데이트
        self.selected_port.set(event.widget.get())

    def open_serial(self):
    # 사용자가 선택한 포트를 가져옴
        selected_port = self.selected_port.get()

        if selected_port:
            try:
                self.ser = serial.Serial(
                    port=selected_port, baudrate=115200, timeout=1)
                messagebox.showinfo("시리얼 연결", f"시리얼 포트 {selected_port}가 열렸습니다")
            except serial.serialutil.SerialException as e:
                messagebox.showerror("시리얼 연결 오류", f"시리얼 포트를 열 수 없습니다: {e}")
        else:
            messagebox.showwarning("시리얼 포트 선택", "시리얼 포트를 선택하세요.")

    def close_serial(self):
        if hasattr(self, 'ser') and self.ser.is_open:
            self.ser.close()
            messagebox.showinfo("시리얼 연결", "시리얼 포트가 닫혔습니다")
        else:
            messagebox.showwarning("시리얼 연결", "시리얼 포트가 열려 있지 않습니다")















