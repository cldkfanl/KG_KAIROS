from pymycobot import MyCobotSocket
import time

# Use port 9000 by default
# Where "192.168.10.22" is the IP of the robot arm

mc = MyCobotSocket("192.168.137.249",9000)


time.sleep(1)
# #After the connections is normal, the robot arm can be controlled.
# res = mc.get_angles()
# print(res)
mc.send_angles([10,10,10,10,10,10],10)