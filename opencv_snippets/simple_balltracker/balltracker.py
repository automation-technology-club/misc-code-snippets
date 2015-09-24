__author__ = 'jeremy'

import cv2
import cv2.cv as cv
import numpy


def main():
    # capture video from web camera
    cap = cv2.VideoCapture(0)

    while True:
        # get frame from camera
        ret, frame = cap.read()


        # Find circles

        # get grayscale image from frame
        gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # get list of circles using HoughCircles function. See documentation for details.
        # param1 is for the edge detection. param2 is for center detection.
        # these parameters will need a lot of tweaking.
        circles = cv2.HoughCircles(gray_frame, cv.CV_HOUGH_GRADIENT, 1, 20, param1=50, param2=50, minRadius=10, maxRadius=40)

        # mark the found circles with  visiblecircles on the frame.
        try:
            l = len(circles[0,:])
            for i in circles[0,:]:
                cv2.circle(frame,(i[0],i[1]),15,(0,0,255),5)
        except TypeError:
            pass


        # Find green things TODO: Finish this snippet

        # get color image from frame
        color_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        # Threshold the HSV image for only green colors
        lower_green = numpy.array([40,70,70])
        upper_green = numpy.array([80,200,200])

        # Threshold the HSV image to get only blue colors
        mask = cv2.inRange(color_frame, lower_green, upper_green)

        # Blur the mask
        bmask = cv2.GaussianBlur(mask, (5,5),0)

        # Take the moments to get the centroid
        moments = cv2.moments(bmask)
        m00 = moments['m00']
        centroid_x, centroid_y = None, None
        if m00 != 0:
            centroid_x = int(moments['m10']/m00)
            centroid_y = int(moments['m01']/m00)

        # Assume no centroid
        ctr = (-1,-1)

        # Use centroid if it exists
        if centroid_x != None and centroid_y != None:

            ctr = (centroid_x, centroid_y)

            # Put black circle in at centroid in image
            cv2.circle(frame, ctr, 15, (0,0,0), 5)


        # show the frame
        cv2.imshow('ball tracker', frame)
        cv2.waitKey(1)

    # remove window
    cv2.destroyAllWindows()



if __name__=='__main__':
    main()
