import cv2 as cv
img = cv.imread("img.png")
cv.imshow("original",img)
cv.waitKey(0)
gray_img = cv.cvtcolor(img,COLOR_BGR2GRAY)
cv.waitKey(0)
