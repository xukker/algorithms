#!/usr/bin/python3
import cv2, math
import numpy as np 

ramp = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,^`'."
ascii = ""
img = cv2.cvtColor(cv2.imread("bart.jpg"), cv2.COLOR_BGR2GRAY)

for i in range(img.shape[0]):
    for k in range(img.shape[1]):
        ascii += ramp[int(img[i][k]*len(ramp)/255)-1]
    ascii += "\n"
print(ascii)
