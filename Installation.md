![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png)

# Introduction #

In this page we give a step by step how to install and use our programmes.

# Download and compilation #

Download the source code from our SVN:

```
  svn checkout http://scoialrobot.googlecode.com/svn/trunk/ scoialrobot-read-only
```

Navigate to the folder of social robot:

```
  roscd social_robot
```

And compile the project:

```
  rosmake
```

This creates number of executable files that you can use, we have explained each of them one by one.

# Usage #

After you have compiled our project you can run any of the following executables files.

## ROS Topics ##

### Social Robot RGB ###

This module is dependant on _roscore_ and subscribes to Kinect RGB images, so as prerequisite you have to make sure they're running

```
  roscore
  roslaunch openni_launch openni.launch
```

Please note that instead _real_ Kinect you can use _.oni_ files as virtual Kinect. We have explained it further down how to do it.

Run the topic:

```
  rosrun social_robot social_robot_rgb
```

You can use this module as you wish, the detected faces are published. You can subscribe to them and use them as you wish.

### Social Robot Depth ###

Similar to above, we need _roscore_ and Kinect images.

Run the topic:

```
  rosrun social_robot social_robot_depth
```

You can use this module as you wish, the detected faces are published. You can subscribe to them and use them as you wish.

### Social Robot Track ###

Similar to above, we need _roscore_ and Kinect images.

This module can be run either as stand alone application, it performs detection and tracking together. However this is not advised, since it will be very slow and the performance wont be very good. If you still wish you run it as standalone do as follow:

```
  rosrun social_robot social_robot -s -d -c
```

For further understanding of the passed arguments please refer to our [documentation](http://scoialrobot.googlecode.com/svn/trunk/social_robot/documentation/html/index.html).

If you want to run this module merely as tracking just run:

```
  rosrun social_robot social_robot
```

Please note this module is listening to the detected faces by other topics. Therefore, you have to run _social\_robot social\_robot\_rgb_ or/and _social\_robot social\_robot\_depth_ in parallel to this topics, so they can perform the face detections.

The region of interests are published, you can subscribe to them and do as you wish them.

### Virtual Kinect ###

The [OpenNI Launch](http://www.ros.org/wiki/openni_launch) package currently does not support to run _.oni_ files as virtual Kinect. Therefore we created a package _openni\_ros_ which is basically same as OpenNI Launch, which this difference that you can run _.oni_ files as virtual Kinect.

First you need to install this package if you want to use it

```
  roscd openni_ros
```

And then compile it

```
  rosdep install openni_camera_deprecated
```

Now you can run this topic as follow:

```
  roslaunch openni_camera_deprecated openni_node.launch file_path:=/examplefolder/example.oni to_be_repeated:=false
```

where _/examplefolder/example.oni_ is the path to your _.oni_ file. And _to\_be\_repeated:=false_ specifies whether you want to start over the video when it finishes.

### Social Robot GUI ###

We implemented a simple user interface for our application, which shows the results of detection and/or tracking.

Run the following command to start the QT application:

```
  rosrun social_robot social_robot_gui
```

## Ground Truth Utils ##

One of the challenges of tracking algorithms is their evaluation. We implemented two utilities to facilitate ground truth making and ground truth comparison with obtained results.

### Ground Truth Maker ###

In order to create ground truth run:

```
  rosrun social_robot create_ground_truth [input_video/.txt] [output file] [input_video/.txt] [output file]
```

This application works both with mouse and keyboard. The results are written in _.yaml_ file.

### Ground Truth Comparator ###

In order to compare the ground truth with our results you can pass two _.yaml_ files to our ground truth comparator:

```
  rosrun social_robot compare_ground_truth [ground_truth.yaml file] [tracking_result.yaml file] [optional:image]
```

The result of this comparison is written in a file and optionally the tracking and ground truth is displayed on an image.