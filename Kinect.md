![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png)

# Getting Started with KINECT #

First of all, let us introduce the device used in this project: _Kinect_ .

# Introduction #

The Kinect is not only used for playing games, its dimensions and its price makes it achievable for everyone who wants to combine color with depth information.

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/kinect.jpg](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/kinect.jpg)

  * **3D sensor**
> It consists of an infrared laser projector and a monochrome CMOS sensor. This sensing system is called Time of Flight (TOF) because it determines the depth based on the time the light takes to return to the source.

> Resolution: 320 x 240

> Frames per second: 30

> Format: 16 bits

> The depth is given in mm.

  * **RGB camera**
> Resolution: 6400 x 480

> Frames per second: 30

> Format: 32 bits color


  * **Motorized tilt**
> It deals with the ﬁeld of view:

> Horizontal FoV: 57 degrees.

> Vertical FoV: 43 degrees.

> Motor Tilt Range: ±27 degrees.

> Depth range: 1.2 - 3.5 m.

  * **Microphones**
> Four microphones are located  along the horizontal bar. It enables speech recognition with acoustic source localization, ambient noise suppression, and echo cancellation. The data stream in that case is 16-bit at 16kHz.



# Calibration #

Kinect has its own default calibration for all the devices. Even so your own calibration can be done by following these links. Notice that everything has been done within ROS package.

**Intrinsic parameters for each camera**

<font color='BLUE'><a href='http://www.ros.org/wiki/openni_launch/Tutorials/IntrinsicCalibration?action=show&redirect=openni_camera%2Fcalibration'>http://www.ros.org/wiki/openni_launch/Tutorials/IntrinsicCalibration?action=show&amp;redirect=openni_camera%2Fcalibration</a> </font>

**Extrinsic parameters**

<font color='BLUE'><a href='http://www.ros.org/wiki/openni_launch/Tutorial/ExtrinsicCalibration#Intrinsic_calibration'>http://www.ros.org/wiki/openni_launch/Tutorial/ExtrinsicCalibration#Intrinsic_calibration</a> </font>


## <font color='RED'> <b>IMPORTANT</b> </font> ##

If the default parameters are used, make sure that <font color='PURPLE'> <b>/camera/driver/depth_registration</b> </font> is set to <font color='GREEN'> <b>TRUE</b> </font>.

We need depth image to be aligned with the RGB image. We can also select the rectified images from RGB camera and 3D sensor by taking <font color='PURPLE'> <b>/image_rect</b></font> instead of **image\_raw**.

<font color='BLUE'> <a href='http://www.ros.org/wiki/openni_camera'>http://www.ros.org/wiki/openni_camera</a> </font>