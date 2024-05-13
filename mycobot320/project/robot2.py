import time
from pymycobot.mycobot import MyCobot

# 전역 변수 설정
red_state = 0
yellow_state = 0
blue_state = 0
block_height = 23
default_height = 330
red_cor = [40, 160, 180, 180, 0, 90]
yellow_cor = [40, 200, 180, 180, 0, 90]
blue_cor = [40, -200, 180, 180, 0, 90]
camera_cor = [160, 80, 330, 180, 0, 0]
grap_cor = [200, 80, 330, 180, 0, 0]
mc = None

def gripper_use2():
    mc.set_gripper_mode(0)
    mc.init_eletric_gripper()
    time.sleep(1)
    mc.set_eletric_gripper(1)
    mc.set_gripper_value(80, 50)
    print("Gripper activated.")
    time.sleep(1)
    state = mc.get_coords()
    mc.send_coords([state[0], state[1], default_height, state[3], state[4], state[5]], 40, 1)
    time.sleep(2)
    print("Moved to default height.")
    gripper_use()



def gripper_use() :
    mc.set_gripper_mode(0)
    mc.init_eletric_gripper()
    time.sleep(1)
    mc.set_eletric_gripper(1)
    mc.set_gripper_value(50,50)
    time.sleep(1)
    
    mc.send_coords(camera_cor, 40, 1) # Initial positioning to camera_cor
    time.sleep(2)


def gripper_close():
    mc.set_gripper_mode(0)
    mc.init_eletric_gripper()
    time.sleep(1)
    mc.set_eletric_gripper(1)
    mc.set_gripper_value(10,50)
    time.sleep(1)


def move_block(block_color):
    global red_state, yellow_state, blue_state
    coords_map = {'Orange': red_cor, 'Yellow': yellow_cor, 'Blue': blue_cor}
    state_map = {'Orange': red_state, 'Yellow': yellow_state, 'Blue': blue_state}
    
    cor = coords_map[block_color]
    state = state_map[block_color]
    mc.send_coords(grap_cor, 40, 1)
    time.sleep(2)
    mc.send_coords([grap_cor[0], grap_cor[1], grap_cor[2] - 35, grap_cor[3], grap_cor[4], grap_cor[5]], 40, 1)
    time.sleep(2)
    gripper_close()
    time.sleep(2)
    mc.send_coords(grap_cor, 40, 1)
    time.sleep(2)

    mc.send_coords([cor[0], cor[1], default_height, cor[3], cor[4], cor[5]], 40, 1)
    time.sleep(5)
    mc.send_coords([cor[0], cor[1], cor[2] + block_height * state, cor[3], cor[4], cor[5]], 40, 1)
    time.sleep(3)
    gripper_use2()
    
    if block_color == 'red':
        red_state += 1
        print(f"{block_color.capitalize()} block moved.")
    elif block_color == 'yellow':
        yellow_state += 1
        print(f"{block_color.capitalize()} block moved.")
    elif block_color == 'blue':
        blue_state += 1
        print(f"{block_color.capitalize()} block moved.")

    print("red_state:", red_state, "yellow_state:", yellow_state, "blue_state:", blue_state)

    mc.send_coords(camera_cor, 40, 1)

def start():
    while True:
        print("Enter the color of the block to move (red, yellow, blue) or type 'exit' to quit:")
        block_color = input().strip().lower()
        if block_color == 'exit':
            print("Exiting program.")
            break
        elif block_color in ['red', 'yellow', 'blue']:
            move_block(block_color)
        else:
            print("Invalid color entered. Please try again.")



def main():
    global mc
    port = 'COM3'  # MyCobot이 연결된 포트 (Windows 기준)
    baudrate = 115200  # 통신 속도
    mc = MyCobot(port, baudrate)
    mc.send_coords(camera_cor, 40, 1)  # Initial positioning to camera coordinates
    print("Initial positioning to camera coordinates.")
    time.sleep(3)
    start()

if __name__ == '__main__':
    main()
