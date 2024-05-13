from ultralytics import YOLO
import torch

# GPU 사용 가능 여부 확인
device = 'cuda' if torch.cuda.is_available() else 'cpu'

# Load a model

model = YOLO('yolov8n-seg.yaml').load('yolov8n-seg.pt').to(device)  # build from YAML and transfer weights
if __name__ == '__main__':
    # Train the model
    results = model.train(data='DressME-12/data.yaml', epochs=200, patience=40, imgsz=640, device=device, batch=16)
    print(results)