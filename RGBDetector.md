![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png)

# Multicascade #
![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/met7.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/met7.png)

# Introduction #

We are going to introduce a very brief explanation of how Multicascade Haar-like features works for face detection.

# Description #

This algorithm introduced by Viola and Jones gives us where the faces are located within the image in space and scale.

## Integral images ##

An integral image is a data structure and algorithm for quickly and efficiently generating the sum of values in an image.

Summed area table gives us in each pixel the sum of all the pixel values above, to the left and the original pixel value itself.

Then the sum of pixels within a region of the original image can be done in constant time.

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/adding_3.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/adding_3.png)

## Haar-like Features ##

Haar features are based on Haar basis functions. Within any image subwindow the total number of Harr-like features is very large, far larger than the number of pixels. The resolution of the detector is 24x24, the exhaustive set of rectangle features is quite large, over 180,000. Using integral images makes faster the computational time.

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/haarcascade_f.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/haarcascade_f.png)

## Cascade of classifiers ##

For the classification it is used a method for combining increasingly more complex classifiers in a cascade, which allows background regions of the image to be quickly discarded while spending more computation on promising regions.

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/multicascade.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/multicascade.png)