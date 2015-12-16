![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png)

# 2D Chamfer Distance Matching #
![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/met2.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/met2.png)

# Introduction #

In this section we are going to match a head template with the disparity image. For that propose the 2D Chamfer distance matching is going to be applied. It is computationally fast and scale invariant.

# Description #

The steps followed for computing 2D Chamfer Distance Matching are:
  1. Calculate edge image.
  1. Compute distances between pixel and the closest edge to it.
  1. Calculate different scales for the resulting distance image.
  1. Match the template with all the scale images.
  1. Use a threshold in order to get the best matches.

## Edge image ##

For this step it has been chosen Canny algorithm. The two thresholds used are 5 and 7.

## Distance image ##

The Euclidean distance has been chosen for this step.

## Distance image pyramid ##

The number of scales depends on the depth range, even though the maximum number of computed scales will be 5.

The scale factor used is 3/4.

## Matching with the template ##

The template used for the matching

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/head_template.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/head_template.png)

It will be matched with all the scale images and a threshold will be used in order to keep the best results. A high threshold has been chosen 10, to reduce as much as possible the number of false negatives.

# Results #

Edge image & Distance image

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/chamfer2d.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/chamfer2d.png)


Location of potential heads

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/potential_heads.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/potential_heads.png)