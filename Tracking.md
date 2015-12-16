![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png)

# Tracking #
![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/met5.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/met5.png)

## 1.Introduction ##
This part presents the tracking implementation of our project. We have started with a simple tracking algorithm based on background subtraction and motion estimation. Based on the real requirements of the project, the proposed algorithm failed in a large number of cases and a more stable algorithm was needed: particle filter. In the next sections short details of both algorithms will be presented.

## 2.Background subtraction and Motion estimation ##
The algorithm is based on subtraction between each frame and background. Due to the fact that the robot was supposed to be placed in a bar, with highly changeable background, the reference frame known as background, is update from time to time in order to keep a stable algorithm.

### Algorithm: ###

**1. Background subtraction**
> In order to make the system more stable and to estimate the motion, we have used both the difference between the current frame and the background and the difference between current and previous frame. Doing the difference between the corresponding regions of the frame and the background, if the value obtained is higher than a given threshold, then the blob in the frame is considered as the foreground and could be part of the tracked person.

**2. Candidate object identification**
> In this part the candidates are located based on the difference image, that is first thresholded. The candidates will be represented by bounding boxes obtained after finding the connected components from the binary image. A threshold is used in order to keep only the most important bounding boxes.

**3. Target object selection**
> Having all the foreground information, the goal is to track the object of interest among all the candidates. In order to do this the colour information is used. A certain foreground object will be considered as the tracked object if it has the maximum colour-based similarity and minimum distance to the object marked by the detection. For the colour-based similarity the histogram matching was used and for the distance similarity, the distance between the centre of the object and the backprojection was used.


### Results ###

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/tracking_sub.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/tracking_sub.png)

In the left figure you can see the image subtraction, while in the right image is the result of the tracking based on this subtraction. The red rectangle represents the tracking, while the blue rectangle represent the candidates for the tracking. In order to obtain the candidates from the foreground blobs a threshold was used that it will eliminate the small blobs in the left image.

### Problems ###

1. One problem that can be seen from the previous results represents the shadow of the people, increasing the size of the tracked person.

2. For our purpose, the method proved to be  unreliable due to the unstable background provided by a bar.

3. People being close to each other can be considered as a single person, making the tracking to fail.

4. Similar to other tracking methods, occlusions remains one of the problems.


In order to solve a couple of this problems we have used the particle filter, explained in the next section, as a final tracking method in our project.

## 3.Particle filter ##

Tracking using particle filter uses the probability distribution over the state (the location) of the person being tracked.The probability distribution is represented by a set of weighted particles, where each of the particles represents a guess about one possible location of the person being tracked. The weight is higher at the points where the object being tracked has a higher possibility to be. The distribution is propagated through time in order to determine the trajectory of the tracked person.

### Algorithm ###

The particle filter proposed for tracking uses the color-based image features and depth information. The reason of choosing color histograms is due to the fact that are robust to partial occlusion, rotational and scale invariant. The depth information was combine with the color information in order to solve the similarity between background and target person and also the illumination conditions. The model is tracked with particle filter by comparing the obrained histogram with the sample histogram using the Bhattacharyya distance between histograms.
An additional texture information can be added, using Local Binary Pattern. Using this method has the disadvantage of increasing the computational time.

The target regions are represented by rectangles, so that a sample is given as position and velocity of the target. The sample set is propagated through the application of a dynamic mode. Each hypothetical region that can correspond to the target is specified by its state vector. As we want to favour samples whose color distributions are
similar to the target model, the Bhattacharyya distance is used to weight the samples.

For the initialization of the particle filter we use the information of the detection part. In the update of the filter we update the confidence of each particle as mentioned previously, project the state forward in time and update the confidence at the mean state. If the target has been lost due to a mismatch between the modelled motion and actual motion than a redistribution of the particles is done.

### Summary ###

1. Specify the person to be tracked.

2. Obtain the color-depth model for target person.

3. Initialize weighted sample set.

4. Compute color-depth distribution at sample locations.

5. Compare distributions using Bhattacharryya coefficient.

6. Use Bhattacharryya distance to assign weight to sample.

7. Position estimation using weighted samples.

8. Samples selected based on re-sampling.


### Results ###

<a href='http://www.youtube.com/watch?feature=player_embedded&v=2vcpExT5k6M' target='_blank'><img src='http://img.youtube.com/vi/2vcpExT5k6M/0.jpg' width='425' height=344 /></a>