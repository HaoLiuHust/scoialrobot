![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png)

# Preprocessing #
![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/met1.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/met1.png)

# Introduction #

Depth and disparity images from Kinect have some pixels where we do not have correct information due to noise, shadows, windows, etc.

In order to avoid to work with these raw images, the preprocessing part will fill with information these regions.


# Description #

Disparity and depth images are processed separately because they have different image types.
For both images it is applied inpainting to fill the holes. It is the best approach against other low-pass filters and interpolations.


# Results #

## Disparity ##

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/disparity_prepro.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/disparity_prepro.png)

Before preprocessing & After preprocessing


## Depth ##

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/depth_prepro.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/depth_prepro.png)

Before preprocessing & After preprocessing