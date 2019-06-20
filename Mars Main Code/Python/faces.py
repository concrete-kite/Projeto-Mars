import numpy as np 
import cv2
import serial
import os

frame_width = 768
frame_height = 432

saveArray = [(00,00,00,00)]


def sendData(faceX, faceY, width, height):
	data = str(faceX) + "," + str(faceY) + "," + str(width) + "," + str(height) + "," + "\n"
	arduino.write(data.encode())
	print(data)


def outData(centerX, centerY, fWidth, fHeight):
	output = [0,0]
	output[0] = int(centerX + (fWidth/2))
	output[1] = int(centerY + (fWidth/2))
	return output

print("Developed by Waza. Pernambuco")
print("_______________________")
print("|Mars face recognition|")
print("_______________________")

while True:
	print("Press 'q' to start and exit:")
	key = input()
	if key == 'q':
		port = input("Type in the arduino port:")
		break


arduino = serial.Serial(port,9600) # Definir o port antes de mandar


frame_center = (int(frame_width/2) , int(frame_height/2))

face_cascade = cv2.CascadeClassifier("cascade/data/haarcascade_frontalface_alt2.xml")

cap = cv2.VideoCapture(0)

while True:
	ret, frame = cap.read()
	frame = cv2.resize(frame, (frame_width, frame_height))
	grayframe = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

	faces = face_cascade.detectMultiScale(grayframe, scaleFactor = 1.5, minNeighbors = 5)

	for (x,y,w,h) in faces:
		roi_color = frame[y:y+h, x:x+w]

		color = (0,255,0)
		stroke = 3
		face_width = x + w
		face_height = y + h
		print("Pos x:",x,"Pos y:",y)

		pos = outData(x,y,w,h)
		cv2.rectangle(frame, (x, y) , (face_width, face_height), color, stroke)
		sendData(pos[0], pos[1], frame_width, frame_height)

		saveArray += [(x,y,w,h)]


	cv2.imshow('frame',frame)
	if cv2.waitKey(20) & 0xFF == ord('q'):
		break

f = open("/Users/concretekite/Documents/Projetos/Mars Main Code/C/pyNumericData.txt","a+")

for (x,y,w,h) in saveArray:
	outputData = str(x) + " " + str(y) + " " + str(w) + " " + str(h) + "\n"
	f.write(outputData)

f.close()

cap.release()
cv2.destroyAllWindows()







