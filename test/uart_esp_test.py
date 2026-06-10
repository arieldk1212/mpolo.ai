import serial

def main():
    print("UART Test:")
    ser = serial.Serial("/dev/ttyAMA1", 300)
    ser.write("X")


if __name__ == "__main__":
    main()
