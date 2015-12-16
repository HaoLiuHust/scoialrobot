![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png)

Project plan of project

# Overview #
We're following the "Human Detection Using Depth Information by Kinect" paper. The project is broken down into the following steps:

## 1. Calibrating the camera ##
Using chess board to calibration, to be done by **week 42**.

## 2. Obtaining the input image from Kinect ##
Reading images from Kinect. It's **done**.

## 3. Perform preprossing ##
Noise removal with median filter. It's **done**.

## 4. 2D chamfer distance matching ##
To get the edge information embedded in the depth array to locate the possible regions that may indicate the appearance of a person. To be done by **week 42**.

## 5. Calculating parameters of the head ##
In order to generate the 3D model to fit on the depth array. To be done by **week 43**.

## 6. Generating 3D model and fitting ##
To be done by **week 43**.

## 7. Separating human from its background ##
Region growing segmentation. To be done by **week 44**.

## 8. Extracting whole contour of human ##
Extracting the contours of the person to be used later on in tracking. To be done by **week 44**

## 9. Tracking ##
To be done by **week 45**.

## 10. Experiment and modification ##
Week 46 - 48.