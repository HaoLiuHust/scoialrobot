![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/logo3.png)

# Head Parameters #
![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/met3.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/met3.png)

# Introduction #

In this section the radius for the potentially heads from the previous step is calculated based on polynomial regression between depth in mm and the height of the head.

# Description #

Here is the polynomial used for depth vs height:

<wiki:gadget url="http://mathml-gadget.googlecode.com/svn/trunk/mathml-gadget.xml" border="0" up\_content="y = p\_3 x^3 + p\_2 x^2 + p\_1 x + p\_0" height="15"/>

where

<wiki:gadget url="http://mathml-gadget.googlecode.com/svn/trunk/mathml-gadget.xml" border="0" up\_content="p\_3 = -1.3835 \* 10^-9" height="15"/>

<wiki:gadget url="http://mathml-gadget.googlecode.com/svn/trunk/mathml-gadget.xml" border="0" up\_content="p\_2 = 1.8435 \* 10^-5" height="15"/>

<wiki:gadget url="http://mathml-gadget.googlecode.com/svn/trunk/mathml-gadget.xml" border="0" up\_content="p\_1 = -0.091403" height="15"/>

<wiki:gadget url="http://mathml-gadget.googlecode.com/svn/trunk/mathml-gadget.xml" border="0" up\_content="p\_0 = 189.38" height="15"/>

Here it is shown the regression between the depth(mm) and the height of the human(mm).

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/depth_height.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/depth_height.png)

Once we get the height, the next step is to compute the estimate radius in pixels:

<wiki:gadget url="http://mathml-gadget.googlecode.com/svn/trunk/mathml-gadget.xml" border="0" up\_content="R = 1.33 \* h \* 0.5" height="15"/>
<wiki:gadget url="http://mathml-gadget.googlecode.com/svn/trunk/mathml-gadget.xml" border="0" up\_content="R\_p = round ( R / 1.3 )" height="15"/>


# Results #

![https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/radius_f.png](https://scoialrobot.googlecode.com/svn/trunk/social_robot/pictures/radius_f.png)