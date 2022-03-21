# pip installs
"""
pip install pyserial
pip install keyboard
pip install controller
pip install pynput 

"""
import serial
from pynput.keyboard import Controller

print("Hello Welcome to Alternative Mario Brothers:)")

print("""Please enter the COM port of your controller.
You can find it if you go to your device manager and look for COM & LPT
section. find your device by unpluging it and pluging it again.
You write it like:
ex: COM8
""")

ser = serial.Serial(input(">>"), 9600)

print("connection established")

keyboard = Controller()

while True:
    data = ser.readline()
    # jump button
    if data.decode().strip() == "space":
        keyboard.press("space")
        print("Player jump")

    if data.decode().strip() == "!Space":
        keyboard.release("Space")

    # left
    if data.decode().strip() == "a":
        keyboard.press("a")
        print("Player left")

    if data.decode().strip() == "!a":
        keyboard.release("a")

    # Right
    if data.decode().strip() == "d":
        keyboard.press("d")
        print("Player right")
        
    if data.decode().strip() == "!d":
        keyboard.release("d")

    # Shoot button
    if data.decode().strip() == "shift":
        keyboard.press("shift")

    if data.decode().strip() == "!shift":
        keyboard.release("shift")
