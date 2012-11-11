#include "cv_utils.h"

using namespace cv;
using namespace std;

const static Scalar colors[] =
{
  CV_RGB ( 0, 0, 255 ),
  CV_RGB ( 0, 128, 255 ),
  CV_RGB ( 0, 255, 255 ),
  CV_RGB ( 0, 255, 0 ),
  CV_RGB ( 255, 128, 0 ),
  CV_RGB ( 255, 255, 0 ),
  CV_RGB ( 255, 0, 0 ),
  CV_RGB ( 255, 0, 255 )
};

Mat rgb2bw ( Mat im_rgb )
{
  Mat im_gray;
  if ( im_rgb.channels() == 3 )
    {
      cvtColor ( im_rgb, im_gray, CV_RGB2GRAY );
    }
  else
    {
      im_gray = im_rgb;
    }

  Mat im_bw;
  threshold ( im_gray, im_bw, 128, 255, CV_THRESH_BINARY );
  return im_bw;
}

Mat preprocessing ( Mat image )
{
  Mat dst;
  Mat temp;

  // inpainting
  Mat mask; 
  threshold ( image, mask, 0, 255, CV_THRESH_BINARY_INV );

  inpaint ( image, mask, dst, 5, INPAINT_NS );
  medianBlur ( dst, dst, 5 );
  medianBlur ( dst, dst, 5 );
  
  return dst;
}

Mat preprocessing_16U ( Mat image )
{
  Mat dst;
  Mat temp;

  // inpainting
  Mat mask; 
    
  for (int i = 0; i < image.rows; i++)
   {
    for (int j = 0; j < image.cols; j++)
     {
      if (image.at<unsigned short>(i, j) == 0)
       {
        mask.at<unsigned short>(i, j) = 65535;
       }
     }
   }

  medianBlur ( image, temp, 5 );
  inpaint ( temp, mask, dst, 5, INPAINT_NS );
  medianBlur ( dst, dst, 5 );
  return dst;
}

void get_non_zeros ( Mat img, Mat prob, std::vector<cv::Point3f> *points, cv::Point pdiff, double scale )
{
  int k = 0;
  for ( int i = 0; i < img.rows; i++ )
    {
      float *rowi = img.ptr<float> ( i );
      for ( int j = 0; j < img.cols; j++ )
        {
          if ( rowi[j] != 0 )
            {
              cv::Point3f point;// = ( cv::Point ( j, i ) + pdiff ) * scale;
              point.x = ( cv::Point ( j, i ).x + pdiff.x ) * scale ;
              point.y = ( cv::Point ( j, i ).y + pdiff.y ) * scale;
              point.z = prob.at<float>(i,j);
              points->push_back ( point );
              k++;
            }
        }
    }
}

void draw_rgb_faces ( Mat &img, vector<Rect> faces )
{
  int i = 0;
  for ( vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++ )
    {
      Point center;
      Scalar color = colors[i % 8];
      int radius;
      center.x = cvRound ( r->x + r->width * 0.5 );
      center.y = cvRound ( r->y + r->height * 0.5 );
      radius = ( int ) ( cvRound ( r->width + r->height ) * 0.25 );
      circle ( img, center, radius, color, 3, 8, 0 );
    }
}

void draw_depth_faces ( Mat &img, vector<Rect> faces )
{
  int i = 0;
  for ( vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++ )
    {
      Scalar color = colors[i % 8];
      rectangle ( img, *r, color, 3, 8, 0 );
    }
}

void region_growing ( Mat &src, Mat &dst, unsigned char threshold, vector<Point> seeds )
{
  vector<Point> queue;
  src.copyTo ( dst );
}