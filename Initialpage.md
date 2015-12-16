![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png)

# Social Robotics using NAO and Kinect #

## Robotics Project - Interaction Lab - Heriot-Watt University ##

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo2.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo2.png)

## [Members](Members.md) ##

## Contents ##

  1. [Introduction](#Introduction.md)
  1. [Problem Statement](#Problem_Statement.md)
  1. [Objectives](#Objectives.md)
  1. [Algorithm](#Algorithm.md)
    * [Preprocessing](Preprocessing.md)
    * [2D Chamfer Distance Matching](Matchingdistance.md)
    * [Head Parameters Estimation](HeadParameters.md)
    * [False Positives Removal](FalsePositivesRemoval.md)
    * [Detection in the RGB Image](RGBDetector.md)
    * [Tracking](Tracking.md)
    * [Torso Orientation](TorsoOrientation.md)
  1. [Implementation](#Implementation.md)
    * [Getting Started with Kinect](Kinect.md)
    * [Installation](Installation.md)
    * [Software Architecture](SoftwareArchitecture.md)
    * [Documentation](http://scoialrobot.googlecode.com/svn/trunk/social_robot/documentation/html/index.html)
  1. [Evaluation and Results](Evaluation.md)
  1. [Demo](#Demo.md)
  1. [Conclusions](#Conclusions.md)
  1. [Future Work](#Future_Work.md)
  1. [References](References.md)
  1. [Links of Interest](#Links_of_Interest.md)

## Introduction ##

As robots become involved into daily life, they must need to deal under situations in which social interaction is essential. It implies robot must be able to satisfy the social goals and obligations that come up through interactions with people in real-world settings. [1](References.md) Usually, these interactions demand challenges on reasoning, decision making and action selection components of the system.

A social robot is defined as "an autonomous robot that interacts and communicates with humans or other autonomous physical agents by following social behaviours and rules attached to its role" Additionally, social robots need to understand and react intelligently to the actions and intentions of multiple humans in a visual scene.

One of the most advanced research groups, the [Personal Robots Group from  Massachusetts Institute of Technology](http://web.media.mit.edu/~cynthiab/research/research.html) develops techniques and technologies for social robot applications. The figure below shows four important projects: [Leonardo Robot](http://www.youtube.com/watch?v=ilmDN2e_Flc&feature=related), [the sociable robot car AIDA](http://www.youtube.com/watch?v=wGowILhHCCo),[TOFU](http://www.youtube.com/watch?v=JxmZyEH4IVI), and [the Mobile, Dexterous, Social Robot](http://www.youtube.com/watch?v=aQS2zxmrrrA)

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/socialrobots.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/socialrobots.png)

Detecting people in images or videos represents a challenging problem due to changes in pose, clothing, lighting conditions and backgrounds. Some methods oriented to the human detection involve statistical training based on local features, i.e. gradient-based features such as HOG; and some involve extracting interest points in the image, such as scale-invariant feature transform (SIFT). [2](References.md)

Depth information is an important cue that can be found in range images.  These have several advantages over 2D intensity images. For instance, range images are robust to the changes in color and illumination; and offer a simple representation of 3D information. The first range sensors were expensive and difficult to use in human environments because of lasers. The develop of depth sensors, such as Kinect from Microsoft, has allowed the application of range sensors in human environment, and hence, the encouragement of research in human detection, tracking and activity analysis.

This project combines a NAO torso with a Kinect controller in order to estimate the social scene in a bar/pub/café style interaction with multiple users. The main work in the project will be in vision by using the Kinect to detect multiple humans and perform face tracking and gaze estimation. A particular focus will be on detecting when humans want attention from the robot.

## Problem Statement ##

Humans use head pose and gaze direction as nonverbal cues to express communicative acts and their visual focus of attention. Additionally, head direction and pointing gestures can contribute significantly to the computation of the attention of an interaction partner.

A combination of head pose estimation and recognition of gaze directions is needed to exactly determine the visual attention of an interaction partner.  Gaschler et al. show in [3](References.md) that head pose is an important cue that is used by customers and bartenders in all steps of the ordering sequence.

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/bar_scene.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/bar_scene.png)

Humans can easily estimate the head pose of an interaction partner, but for a computer vision system this ability is rather difficult to achieve. The pose is described by the approximate position of the head in space, and an angle that describes torso orientation.

Many methods have been used to generate a head pose estimation. Appearance-based methods consider the image region of the face as a whole, while Feature-based methods extract from the actual region and recover low-dimensional features (position of facial features). Both techniques can be combined in order to track facial features.

## Objectives ##

The objective is to estimate the social scene in a bar/pub/cafe style interaction with multiple users by using Kinect controller.
  * To detect multiple humans when they ask for attention.
  * To perform face tracking and gaze estimation

## Algorithm ##

This algorithm performs face detection, tracking and torso orientation; by combining depth information and RGB color space (see flowchart in the figure below). This strategy represents a significant and original contribution to the field of Social Robotics; created, developed and evaluated by students of the [Erasmus Mundus Master Courses in Vision and Robotics](http://www.vibot.org/), through the [Heriot-Watt University](http://www.hw.ac.uk/).

The advantages of this algorithm are:

  * First, the face detection and tracking stages, can be executed even under the lack of illumination, due to the depth information is **light invariant**; which provides robustness to the algorithm.

  * Although, the algorithm was designed to work in specific social scenes, it has shown satisfactory results under any kind of environment. It means that **the social scene does not need to be controlled externally** (i.e. it is not necessary to initialize a specific background for detection)

  * Finally, the accuracy to estimate the head position during the face detection and tracking performances, reveals a **good estimation of torso orientation**.

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/scheme.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/scheme.png)
  * [Preprocessing](Preprocessing.md)
  * [2D Chamfer Distance Matching](Matchingdistance.md)
  * [Head Parameters Estimation](HeadParameters.md)
  * [False Positives Removal](FalsePositivesRemoval.md)
  * [Detection in the RGB Image](RGBDetector.md)
  * [Tracking](Tracking.md)
  * [Torso Orientation](TorsoOrientation.md)

## Implementation ##
  * [Getting Started with Kinect](Kinect.md)
  * [Installation](Installation.md)
  * [Software Architecture](SoftwareArchitecture.md)
  * [Documentation](http://scoialrobot.googlecode.com/svn/trunk/social_robot/documentation/html/index.html)

## Demo ##

<a href='http://www.youtube.com/watch?feature=player_embedded&v=qnr3Msk-Vwk' target='_blank'><img src='http://img.youtube.com/vi/qnr3Msk-Vwk/0.jpg' width='425' height=344 /></a>

## Conclusions ##

**Real time vs amount of information**

Kinect performs 30 frames per second, while 1 out of 7 frames can
be processed. It generates that some frames can not be evaluated, which has important implications on evaluation: The amount of frames in ground-truth is different from the number of processed frames.

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/realtime.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/realtime.png)

**Lighting conditions**

Kinect offers a wide spectrum of scenarios with different lighting
conditions. In absentia of light, RGB color space does not provide enough information to differentiate our targets. In this case, depth information plays an important role that provides robustness to the tracking and detection algorithm.

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/light.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/light.png)

## Future Work ##

  1. **Classifier** The type of values used for depth information is 16 bits. It generates some difficulties to train specific classifiers. A classification algorithm on depth image that provides robustness to the template matching.
  1. **Torso Orientation** is sensitive to different poses. The use of first order moment in horizontal and vertical directions, can improve the estimation of the centroid by implementing a robust segmentation algorithm. Experimentally, the use of watershed segmentation could not provide satisfactory results for detected persons located far from the kinect (more than 2 meters). Additionally, it could be very interesting to extend the estimations to roll and pitch angles.
  1. **Depth Sensor**, like Kinect, does not provide information that allows to characterize features with high definition.
  1. **Evaluation:** The incorporation of the depth data in the accuracy estimation can provide a better estimation of the algorithm performance.
  1. The tracking algorithm can also serve as an initial step of the research on face recognition by adding depth information.

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/limits.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/limits.png)

## Links of Interest ##
**Presentations**
  1. [Presentation 1 -  October 17th, 2012](http://prezi.com/e-5801a4gmsm/rp-presentation-1/)
  1. [Presentation 2 -  October 30th, 2012](http://prezi.com/qvdukdcb9ikg/rp-presentation-2/)
  1. [Reading Group - November 13th, 2012](https://www.dropbox.com/s/opstijhwz57f6fd/ReadingGroup.pdf)
  1. [Final Presentation - November 29th, 2012](https://www.dropbox.com/s/pljba2f627jbdp0/FinalPresentation.pdf)
  1. [Introduction to Demo - November 30th, 2012](https://www.dropbox.com/s/d0fwrbmr7wxadyh/IntroductionDemo.pdf)


**Dataset and Demo for Human Detections**
  1. [RGB-D People Dataset](http://www.informatik.uni-freiburg.de/~spinello/RGBD-dataset.html)
  1. [People Detection in RGB-D Data](http://www.youtube.com/watch?feature=player_embedded&v=UwHOGfXxajM)

**Projects, Demos and Group Research**
  1. [EU project JAMES](http://www.james-project.eu)
  1. [Interaction Lab - Heriot-Watt University](https://sites.google.com/site/hwinteractionlab/home)
  1. [JAMES, the robot bartender, system evaluation April / May 2012](http://www.youtube.com/watch?v=8k7Pd-CbbhE&feature=youtu.be)