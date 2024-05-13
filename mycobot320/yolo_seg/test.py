from ultralytics import YOLO
import cv2
import numpy as np

# Load the YOLO model (specify a model capable of segmentation)
model = YOLO("best.pt")

# Open camera device
cap = cv2.VideoCapture(0)

# Check if the camera was opened correctly
if not cap.isOpened():
    raise IOError("Cannot open webcam")

# Read an image from the camera
success, img = cap.read()
if not success:
    raise Exception("Failed to read image from camera")

# Get the height and width of the image
H, W = img.shape[:2]

results = model(img)

for i, result in enumerate(results):
    for j, mask in enumerate(result.masks.data):
        mask = mask.cpu().numpy()
        class_id = int(result.boxes.cls[j])
        model_name = model.names[class_id]

        window_name = f'{model_name}_{i}_{j}'
        mask_resized = cv2.resize(mask, (W, H))
        mask_3d = np.stack([mask_resized]*3, axis=-1)
        seg_img = np.where(mask_3d, img, 0)

        cv2.imwrite(f'{model_name}_{i}_{j}.jpg', seg_img)
        cv2.imshow(window_name, seg_img)
        # cv2.imshow(f'mask{j}', plotted_image)

# Show processed image using OpenCV
# cv2.imshow('Segmentation Result', img)
if cv2.waitKey(0) == 27:  # If ESC key is pressed, close the window
    cv2.destroyAllWindows()
