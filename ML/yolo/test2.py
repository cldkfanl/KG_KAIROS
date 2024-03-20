import torch
import torchvision.transforms as transforms
from torch.utils.data import DataLoader
from torchvision.datasets import VOCDetection
from ultralytics import YOLO

# 데이터셋 및 전처리 설정
transform = transforms.Compose([
    transforms.Resize((416, 416)),
    transforms.ToTensor(),
])

# VOC 데이터셋 로드 및 DataLoader 생성
train_dataset = VOCDetection(root='VOCdevkit', year='2007', image_set='train',download=True, transform=transform)
train_loader = DataLoader(train_dataset, batch_size=8, shuffle=True)

# YOLO 모델 설정
model = YOLO('yolov8n.pt')
model = model.to('cuda')

# 학습 설정
optimizer = torch.optim.Adam(model.parameters(), lr=0.001)
criterion = torch.nn.CrossEntropyLoss()  # 예시로 CrossEntropyLoss 사용

# 학습 루프
num_epochs = 10  # 예시로 10 에폭 사용
for epoch in range(num_epochs):
    model.train()
