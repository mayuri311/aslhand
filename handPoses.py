import serial
import time


class aslLetter:
    def __init__(self, thumb, index, middle, ring, pinky):
        self.thumb = thumb
        self.index = index
        self.middle = middle
        self.ring = ring
        self.pinky = pinky

    def serial(self):
        return f"{self.thumb},{self.index},{self.middle},{self.ring},{self.pinky}"
    
class ServoController:
    def __init__(self, port="/dev/cu.usbserial-1430", baudrate=9600):
        self.arduino = serial.Serial(port, baudrate, timeout=1)
        time.sleep(2)

    def send_pose(self, pose):
        command = pose.serial() + "\n"
        self.arduino.write(command.encode())
        time.sleep(1)

    def close(self):
        self.arduino.close()

controller = ServoController()

asl_map = {
    # (thumb, index, middle, ring, pinky)
    "A": aslLetter(1, 0.5, 0, 0, 0),
    "B": aslLetter(0, 1, 1, 1, 0),
    "C": aslLetter(0, 0, 0, 0, 1),
    "D": aslLetter(1, 1, 0, 0, 0),
}


text = "ABCD"

for char in text:
    if char in asl_map:
        controller.send_pose(asl_map[char])
    else:
        print("skipping")  # no movement for other characters

controller.close()
    

