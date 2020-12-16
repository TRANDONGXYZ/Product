import cv2
import math

face_cascade = cv2.CascadeClassifier('cascades/data/haarcascade_frontalface_alt2.xml')
eye_cascade = cv2.CascadeClassifier('cascades/data/haarcascade_eye.xml')

cap = cv2.VideoCapture(0)
if not cap.isOpened():
    print("Can\'t open camera!")
    exit()

while True:

    # create frame
    ret, frame = cap.read()
    if not ret:
        print("Can\'t read frame!")
        exit()

    # convert color frame to gray frame
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # detect faces
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.5, minNeighbors=5)
    for x, y, w, h in faces:
        # print(x, y, w, h)
        roi_gray = gray[y: y + h, x: x + w]

        # draw rectangle around face
        color = (0, 204, 255)  # BGR
        stroke = 2
        cv2.rectangle(frame, (x, y), (x + w, y + h), color, stroke)

        # draw rectangle fill to write name
        color_fill = (0, 204, 255)
        stroke_fill = -1

        cv2.rectangle(frame, (x - math.ceil(stroke / 2), y + h - math.ceil(stroke / 2)),
                      (x + w + math.ceil(stroke / 2), y + h + 30), color_fill, stroke_fill)

        # im_item = "my-image.png"
        # cv2.imwrite(im_item, roi_gray)

        # Detect eye
        color_eye = (255, 0, 0)
        eyes = eye_cascade.detectMultiScale(gray)
        for ex, ey, ew, eh in eyes:
            cv2.rectangle(frame, (ex, ey), (ex + ew, ey + eh), color_eye, stroke)

    # show image
    cv2.imshow("Face Detect", frame)

    # press "q" to exit
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

# destroy anything used
cap.release()
cv2.destroyAllWindows()
