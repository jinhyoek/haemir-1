from motor import *
192.168.1.10
rom socket import *
#from graphic import *
#from lidar import *
#from camera import *
from imu import *
import calculate as cal
import math
from gps import *


def cmd_l(optimal):
    if 0 < optimal <= 30:
        print("move Left 1")


    elif 30 < optimal <= 60:
        print("move Left 2")
    
    elif 60 < optimal < 90:
        print("move Left 3")
    

def cmd_r(optimal):
    if 0 < optimal <= 30:
        print("move Right 1")

    elif 30 < optimal <= 60:
        print("move Right 2")

    elif 60 < optimal < 90:
        print("move Right 3")

class Lidarmotor:
    def __init__(self):
            if 0 <= optimal <= 90:
            cmd_r(optimal)
        
        elif 90 < optimal <= 180:
            cmd_l(optimal-90)
