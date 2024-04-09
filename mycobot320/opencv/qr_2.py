#QR Reader

import cv2
from pyzbar.pyzbar import decode
from playsound import playsound

cap = cv2.VideoCapture(0)

while True :
    ret, frame = cap.read()

    flipped_frame = cv2.flip(frame, 1)

    if ret :
        barcodes = decode(flipped_frame)

        for barcode in barcodes:
            qr_data = barcode.data.decode('utf-8')
            print("QR Code Data : ", qr_data)
            playsound('pr_beep.mp3')

        cv2.imshow("QR Code Scanner", flipped_frame)

        key = cv2.waitKey(1)
        if key == ord('q'):
            break

    else :
        print("Webcam is not available")
        break

cap.release()
cv2.destroyAllWindows()