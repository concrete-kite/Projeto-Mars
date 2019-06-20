import numpy as np 
import cv2

frame_width = 768
frame_height = 432


while True:
	print("Press 'q' to start and exit:")
	key = input()
	if key == 'q':
		break


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
		print("Pixel Width: ",w)

		cv2.rectangle(frame, (x, y) , (face_width, face_height), color, stroke)

	cv2.imshow('frame',frame)

	if cv2.waitKey(20) & 0xFF == ord('q'):
		break

cap.release()
cv2.destroyAllWindows()







