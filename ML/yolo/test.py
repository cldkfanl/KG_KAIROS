import cv2
from ultralytics import YOLO

model = YOLO('yolov8n.pt')
model = model.to('cuda')

print(type(model.names), len(model.names))
print(model.names)

model.train(data='data.yaml', epochs=100, patience = 30, batch= 32, imgsz = 416)
