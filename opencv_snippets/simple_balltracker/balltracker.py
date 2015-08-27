__author__ = 'jeremy'

import cv2
import cv2.cv as cv


def main():
    # capture video from web camera
    cap = cv2.VideoCapture(0)

    while True:
        # get frame from camera
        ret, frame = cap.read()

        # get grayscale image from frame
        gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # get list of circles using HoughCircles function. See OpenCV documentation for details.
        # these parameters will need a lot of tweaking.
        circles = cv2.HoughCircles(gray_frame, cv.CV_HOUGH_GRADIENT, 1, 20, param1=40, param2=40, minRadius=10, maxRadius=40)

        # mark the found circles with  visiblecircles on the frame.
        try:
            l = len(circles[0,:])
            for i in circles[0,:]:
                cv2.circle(frame,(i[0],i[1]),15,(0,0,255),5)
        except TypeError:
            pass

        # show the frame
        cv2.imshow('ball tracker', frame)
        cv2.waitKey(1)

    # remove existing window
    cv2.destroyAllWindows()



if __name__=='__main__':
    main()
