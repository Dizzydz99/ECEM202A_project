import serial
import csv
import time

# Set the serial port and baud rate
ser = serial.Serial('/dev/cu.usbmodem1101', 9600)  # Change 'COM3' to your Arduino's serial port

# Open a CSV file for writing
with open('sensor_train.csv', 'w', newline='') as file:
    writer = csv.writer(file)

    start_time = time.time()  # Record the start time

    try:
        while time.time() - start_time < 300:  # Run the loop for 3 minutes
            # Read a line from the Arduino Serial Monitor
            data = ser.readline().decode('utf-8').strip()

            # Print the data to the console
            print(data)

            # Write the data to the CSV file
            writer.writerow([data])

    except KeyboardInterrupt:
        # Close the serial port when you exit the script
        ser.close()
