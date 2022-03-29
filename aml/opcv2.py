import cv2 as cv
import matplotlib.pyplot as plt

img = cv.imread("img.jpg")
h,w = img.shape[:2]
rot_matrix = cv.getRotationMatrix2D((w/2,h/2),-180,0.5)
rot_image = cv.warpAffine(img,rot_matrix,(w,h))
plt.imshow(cv.cvtColor(rot_image,cv.COLOR_BGR2RGB))

