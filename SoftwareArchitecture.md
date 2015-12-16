![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png)

# Software Architecture #

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/ros.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/ros.png)

# Introduction #

In this page we're going to explain how different ROS topics work with each other in our application. In addition to this page we have created Doxygen documentation for our source code, which is available [here](http://scoialrobot.googlecode.com/svn/trunk/social_robot/documentation/html/index.html).

# Overview #

The high level component diagram of our application can be observed in figure below. Kinect publishes three different topics, RGB, disparity and depth images. The details of these topics can be read in [OpenNI Lunch Package](http://www.ros.org/wiki/openni_launch).

We have used two independent detectors, RGB and depth. Therefore, RGB detector subscribes to the RGB images. And depth detector subscribes to the depth and disparity images. Each of these detector perform their tasks and publish their data.

Tracking component subscribes to both detectors. It performs its tracking assignment and publishes the result of tracking, which is ultimately the result of our application.

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/flowchart_diagram.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/flowchart_diagram.png)

The ROS topic communication can be observed in figure below:

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/rostopics.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/rostopics.png)

# Low level description #

In this section we are going to explain in detail how each component exactly works.

## Kinect ##

We first have to run the OpenNI Launch as follow:

```
  roslaunch openni_launch openni.launch
```

Since we're interested in the depth registered images we set the depth registration parameter as true, this is done in c++ code as follow:

```
  ros::NodeHandle nh;
  // to register the depth
  nh.setParam ( "/camera/driver/depth_registration", true );
```

[OpenNI Lunch Package](http://www.ros.org/wiki/openni_launch) publishes many topics, we're interested in mainly three of them:
  * camera/rgb/image\_color
  * camera/depth\_registered/image\_raw
  * camera/depth\_registered/disparity

## RGB Detector ##

RGB detector subscribes to _camera/rgb/image\_color_ which publishes [sensor\_msgs/Image](http://www.ros.org/doc/api/sensor_msgs/html/msg/Image.html). We do perform detection every _n_ frame. _n_ can be updated dynamically during the run time, by calling _rosparam set_.

For detection we're using OpenCV [Cascade Classifier](http://docs.opencv.org/doc/tutorials/objdetect/cascade_classifier/cascade_classifier.html#cascade-classifier). We are using [Front Face Alt](http://scoialrobot.googlecode.com/svn/trunk/social_robot/rsrc/haarcascades/haarcascade_frontalface_alt.xml) classifier. For a list of other OpenCV already made classifiers please check [here](http://scoialrobot.googlecode.com/svn/trunk/social_robot/rsrc/haarcascades/).

RGB detector publishes its detected faces under _/social\_robot/rgb/rois_ ([RegionOfInterests](http://scoialrobot.googlecode.com/svn/trunk/social_robot/msg/RegionOfInterests.msg)) which is  basically list of [sensor\_msgs/RegionOfInterest](http://www.ros.org/doc/api/sensor_msgs/html/msg/RegionOfInterest.html).

## Depth Detector ##

Depth detector subscribes to  _camera/depth\_registered/image\_raw_ ([sensor\_msgs/Image](http://www.ros.org/doc/api/sensor_msgs/html/msg/Image.html)) and _camera/depth\_registered/disparity_ ([stereo\_msgs/DisparityImage](http://www.ros.org/doc/api/stereo_msgs/html/msg/DisparityImage.html)). Similar to the RGB detector we perform detection in every _n_ frame. And _n_ can be changed dynamically during runtime.

The algorithm for this detection is basically implemented in [DepthFaceDetector.h](http://scoialrobot.googlecode.com/svn/trunk/social_robot/src/DepthFaceDetector.h) and [DepthFaceDetector.c](http://scoialrobot.googlecode.com/svn/trunk/social_robot/src/DepthFaceDetector.c). The explanation of this algorithm can be found in our [wiki pages](https://code.google.com/p/scoialrobot/wiki/Initialpage#Method) as well as [3](References.md).

The result of detected faces in depth are published in topic _/social\_robot/depth/rois_ ([RegionOfInterests](http://scoialrobot.googlecode.com/svn/trunk/social_robot/msg/RegionOfInterests.msg)) which is  basically list of [sensor\_msgs/RegionOfInterest](http://www.ros.org/doc/api/sensor_msgs/html/msg/RegionOfInterest.html).

## Tracking ##

This module can be run as an standalone application, in which both detection and tracking is performed, however this is not advised because of computational time. That's why this module can also be run only as tracking module in which it subscribes to both the detected faces by RGB and depth.

For tracking we're performing particle filter, explained in [tracking](Tracking.md) page of our wiki. The result of this module is published under _/social\_robot/track/rois_ ([RegionOfInterests](http://scoialrobot.googlecode.com/svn/trunk/social_robot/msg/RegionOfInterests.msg)) which is  basically list of [sensor\_msgs/RegionOfInterest](http://www.ros.org/doc/api/sensor_msgs/html/msg/RegionOfInterest.html).

## User interface ##

We have implemented a simple QT application, in which user can select the view change the parameters, etc. The intention is mainly for testing purposes.

# Rationale #

We have tried to achieve many quality attributes in our software architecture.

## Modularity ##

The architecture of our programme is designed in a manner which makes them as modular as possible. This means each topic has a specific task to do. This makes it very usable for any other usage, e.g. if someone just to use our face detector in RGB or depth independently they can simply do so.

Additionally, new components can be easily added to the system and current components can easily replaced. The architecture is designed in a low-couple manner, this means simply you can plug-in new modules.

## Robustness ##

If one components stops working, let's say the depth detector, other components can continue to perform their tasks. This means crashing in one area doesn't influence the entire system.

## Parallelism ##

Detection and tracking are both very heavy computationally speaking. With our design each of these modules are run in one thread and therefore the speed is much better. This also gives the opportunity to work in a distributed system. Detections can happen from multiple on-line cameras and send the results to tracking.