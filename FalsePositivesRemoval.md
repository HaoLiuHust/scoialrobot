![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png)

# False Positives Removal #
![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/met4.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/met4.png)

# Introduction #

Once the position and the radius of the head have been computed, the next step is to remove all the false positives.

# Description #

In order to reduce the number of "heads" in our image, the following steps are computed:

  1. Approximate the contours by polygons.
  1. Merged the heads.
  1. Matching with 3D template.

> ## Approximate by polygons ##

> For each region of interest containing the detected possible head, the edge image within this region is taken. Based on this contour, a polygon is approximated. Based on the number of polygons we can discard those that do not correspond to circles or semicircles. The values selected for thresholding are 7 and 17.

> ## Merging ##

It happens that many potential heads are very close to each other, so computing the Euclidean distance between them, and setting a threshold we can merged more than one head in a single one based on the highest probability of these heads with the binary template matching.

> ## Matching with 3D template ##

Sometimes it is not enough only with the previous steps, so another matching is performance with the disparity image and a 3D template of a human bust.

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/template3D.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/template3D.png)

We discard low matchings based on a threshold.

# Results #

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/final_result.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/final_result.png)