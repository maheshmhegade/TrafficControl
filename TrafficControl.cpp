#include <stdio.h>
#include </usr/include/opencv/cv.h>
#include </usr/include/opencv/highgui.h>
using namespace std;
#include <iostream>
#define  TPL_WIDTH       20      /* template width       */
#define  TPL_HEIGHT      20     /* template height      */

IplImage *frame,
*seg1,*seg2,*seg3,*seg4,*seg5,*seg6,*seg7,*seg8,
*tpl1,*tpl2,*tpl3,*tpl4,*tpl5,*tpl6,*tpl7,*tpl8,
*diff11,*imggray11,*imggray22,
*imggray1,*imggray2,*imggray3,*imggray4,*imggray5,*imggray6,*imggray7,*imggray8;
CvScalar sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8;
int  object_x0, object_y0,
pos1x,pos1y,pos2x,pos2y,pos3x,pos3y,pos4x,pos4y,pos5x,pos5y,pos6x,pos6y,pos7x,pos7y,pos8x,pos8y,
threshold=20,speed=19000,slow=20000,ithresh=4500;
void mouseHandler( int event, int x, int y, int flags, void *param );
int main( int argc, char** argv )

{
    int inccount1=1,inccount2=1,inccount3=1,inccount4=1,inccount5=1,inccount6=1,inccount7=1,inccount8=1,
    count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0;
    CvCapture   *capture,*cap1,*cap2,*cap3,*cap4,*cap5,*cap6,*cap7,*cap8;
    int         key;
    capture = cvCaptureFromFile( "traffic5.mpg" );
    cap1 = cvCaptureFromFile( "traffic5.mpg" );
    cap2 = cvCaptureFromFile( "traffic5.mpg" );
    cap3 = cvCaptureFromFile( "traffic5.mpg" );
    cap4 = cvCaptureFromFile( "traffic5.mpg" );
    cap5 = cvCaptureFromFile( "traffic5.mpg" );
    cap6 = cvCaptureFromFile( "traffic5.mpg" );
    cap7 = cvCaptureFromFile( "traffic5.mpg" );
    cap8 = cvCaptureFromFile( "traffic5.mpg" );
    if( !capture ) return 1;
    int fps = ( int )cvGetCaptureProperty( capture, 5 );
    seg1 = cvQueryFrame( cap1 );
    seg2 = cvQueryFrame( cap2 );
    seg3 = cvQueryFrame( cap3 );
    seg4 = cvQueryFrame( cap4 );
    seg5 = cvQueryFrame( cap5 );
    seg6 = cvQueryFrame( cap6 );
    seg7 = cvQueryFrame( cap7 );
    seg8 = cvQueryFrame( cap8 );
    frame = cvQueryFrame( capture );
    if ( !frame ) return 1;
    tpl1 = cvCreateImage( cvSize( TPL_WIDTH, TPL_HEIGHT ),frame->depth, frame->nChannels );
    tpl2 = cvCreateImage( cvSize( TPL_WIDTH, TPL_HEIGHT ),frame->depth, frame->nChannels );
    tpl3 = cvCreateImage( cvSize( TPL_WIDTH, TPL_HEIGHT ),frame->depth, frame->nChannels );
    tpl4 = cvCreateImage( cvSize( TPL_WIDTH, TPL_HEIGHT ),frame->depth, frame->nChannels );
    tpl5 = cvCreateImage( cvSize( TPL_WIDTH, TPL_HEIGHT ),frame->depth, frame->nChannels );
    tpl6 = cvCreateImage( cvSize( TPL_WIDTH, TPL_HEIGHT ),frame->depth, frame->nChannels );
    tpl7 = cvCreateImage( cvSize( TPL_WIDTH, TPL_HEIGHT ),frame->depth, frame->nChannels );
    tpl8 = cvCreateImage( cvSize( TPL_WIDTH, TPL_HEIGHT ),frame->depth, frame->nChannels );
    imggray11 = cvCreateImage( cvGetSize( tpl1 ), IPL_DEPTH_8U, 1);
    imggray22 = cvCreateImage( cvGetSize( tpl1 ), IPL_DEPTH_8U, 1);
    imggray1 = cvCreateImage( cvGetSize( tpl1 ), IPL_DEPTH_8U, 1);
    imggray2 = cvCreateImage( cvGetSize( tpl1 ), IPL_DEPTH_8U, 1);
    imggray3 = cvCreateImage( cvGetSize( tpl1 ), IPL_DEPTH_8U, 1);
    imggray4 = cvCreateImage( cvGetSize( tpl1 ), IPL_DEPTH_8U, 1);
    imggray5 = cvCreateImage( cvGetSize( tpl1 ), IPL_DEPTH_8U, 1);
    imggray6 = cvCreateImage( cvGetSize( tpl1 ), IPL_DEPTH_8U, 1);
    imggray7 = cvCreateImage( cvGetSize( tpl1 ), IPL_DEPTH_8U, 1);
    imggray8 = cvCreateImage( cvGetSize( tpl1 ), IPL_DEPTH_8U, 1);
    cvNamedWindow( "video", CV_WINDOW_AUTOSIZE );
    cvSetMouseCallback( "video", mouseHandler, NULL );
    cvShowImage( "video", frame );
    cvWaitKey(15000);
    //cout << pos1x << endl;
    //cout << pos2x << endl;
    //cout << pos3x << endl;
    //cout << pos4x << endl;
    //cout << pos5x << endl;
    //cout << pos6x << endl;
    //cout << pos7x << endl;
    //cout << pos8x << endl;
    if (pos1x && pos2x && pos3x && pos4x && pos5x && pos6x && pos7x && pos8x )
 {
  while( key != 'q' ) {
       seg1 = cvQueryFrame( cap1 );
       seg2 = cvQueryFrame( cap2 );
       seg3 = cvQueryFrame( cap3 );
       seg4 = cvQueryFrame( cap4 );
       seg5 = cvQueryFrame( cap5 );
       seg6 = cvQueryFrame( cap6 );
       seg7 = cvQueryFrame( cap7 );
       seg8 = cvQueryFrame( cap8 );
       frame = cvQueryFrame( capture );
        cvRectangle( frame,cvPoint( pos1x, pos1y ),cvPoint( pos1x + TPL_WIDTH,pos1y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        cvRectangle( frame,cvPoint( pos2x, pos2y ),cvPoint( pos2x + TPL_WIDTH,pos2y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        cvRectangle( frame,cvPoint( pos3x, pos3y ),cvPoint( pos3x + TPL_WIDTH,pos3y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        cvRectangle( frame,cvPoint( pos4x, pos4y ),cvPoint( pos4x + TPL_WIDTH,pos4y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        cvRectangle( frame,cvPoint( pos5x, pos5y ),cvPoint( pos5x + TPL_WIDTH,pos5y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        cvRectangle( frame,cvPoint( pos6x, pos6y ),cvPoint( pos6x + TPL_WIDTH,pos6y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        cvRectangle( frame,cvPoint( pos7x, pos7y ),cvPoint( pos7x + TPL_WIDTH,pos7y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        cvRectangle( frame,cvPoint( pos8x, pos8y ),cvPoint( pos8x + TPL_WIDTH,pos8y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        cvCvtColor( seg1, imggray11, CV_RGB2GRAY );
        cvCvtColor( tpl1, imggray22, CV_RGB2GRAY );
        cvAbsDiff (imggray11,imggray22,imggray1);
        cvCvtColor( seg2, imggray11, CV_RGB2GRAY );
        cvCvtColor( tpl2, imggray22, CV_RGB2GRAY );
        cvAbsDiff (imggray11,imggray22,imggray2);
        cvCvtColor( seg3, imggray11, CV_RGB2GRAY );
        cvCvtColor( tpl3, imggray22, CV_RGB2GRAY );
        cvAbsDiff (imggray11,imggray22,imggray3);
        cvCvtColor( seg4, imggray11, CV_RGB2GRAY );
        cvCvtColor( tpl4, imggray22, CV_RGB2GRAY );
        cvAbsDiff (imggray11,imggray22,imggray4);
        cvCvtColor( seg5, imggray11, CV_RGB2GRAY );
        cvCvtColor( tpl5, imggray22, CV_RGB2GRAY );
        cvAbsDiff (imggray11,imggray22,imggray5);
        cvCvtColor( seg6, imggray11, CV_RGB2GRAY );
        cvCvtColor( tpl6, imggray22, CV_RGB2GRAY );
        cvAbsDiff (imggray11,imggray22,imggray6);
        cvCvtColor( seg7, imggray11, CV_RGB2GRAY );
        cvCvtColor( tpl7, imggray22, CV_RGB2GRAY );
        cvAbsDiff (imggray11,imggray22,imggray7);
        cvCvtColor( seg8, imggray11, CV_RGB2GRAY );
        cvCvtColor( tpl8, imggray22, CV_RGB2GRAY );
        cvAbsDiff (imggray11,imggray22,imggray8);
        cvThreshold(imggray1, imggray1, threshold, 255, CV_THRESH_BINARY);
        cvThreshold(imggray2, imggray2, threshold, 255, CV_THRESH_BINARY);
        cvThreshold(imggray3, imggray3, threshold, 255, CV_THRESH_BINARY);
        cvThreshold(imggray4, imggray4, threshold, 255, CV_THRESH_BINARY);
        cvThreshold(imggray5, imggray5, threshold, 255, CV_THRESH_BINARY);
        cvThreshold(imggray6, imggray6, threshold, 255, CV_THRESH_BINARY);
        cvThreshold(imggray7, imggray7, threshold, 255, CV_THRESH_BINARY);
        cvThreshold(imggray8, imggray8, threshold, 255, CV_THRESH_BINARY);
        sum1 = cvSum(imggray1);
        sum2 = cvSum(imggray2);
        sum3 = cvSum(imggray3);
        sum4 = cvSum(imggray4);
        sum5 = cvSum(imggray5);
        sum6 = cvSum(imggray6);
        sum7 = cvSum(imggray7);
        sum8 = cvSum(imggray8);
        int num1=sum1.val[0];
        int num2=sum2.val[0];
        int num3=sum3.val[0];
        int num4=sum4.val[0];
        int num5=sum5.val[0];
        int num6=sum6.val[0];
        int num7=sum7.val[0];
        int num8=sum8.val[0];
        if (num1 >= ithresh)
          {if (inccount1 == 1){count1 = count1 + 1;inccount1 =0;}
          cvRectangle( frame,cvPoint( pos1x, pos1y ),cvPoint( pos1x + TPL_WIDTH,pos1y + TPL_HEIGHT ),cvScalar( 0, 0, 255, 0 ), 1, 0, 0 );}
        else if (num1 < ithresh){inccount1 =1;}
        if (num2 >= ithresh)
        {if (inccount2 == 1){count2 = count2 + 1;inccount2 =0;}
            cvRectangle( frame,cvPoint( pos2x, pos2y ),cvPoint( pos2x + TPL_WIDTH,pos2y + TPL_HEIGHT ),cvScalar( 0, 0, 255, 0 ), 1, 0, 0 );}
        else if (num2 < ithresh){inccount2 =1;}
        if (num3 >= ithresh)
        {if (inccount3 == 1){count3 = count3 + 1;inccount3 =0;}
            cvRectangle( frame,cvPoint( pos3x, pos3y ),cvPoint( pos3x + TPL_WIDTH,pos3y + TPL_HEIGHT ),cvScalar( 0, 0, 255, 0 ), 1, 0, 0 );}
        else if (num3 < ithresh){inccount3 =1;}
        if (num4 >= ithresh)
        {if (inccount4 == 1){count4 = count4 + 1;inccount4 =0;}
        cvRectangle( frame,cvPoint( pos4x, pos4y ),cvPoint( pos4x + TPL_WIDTH,pos4y + TPL_HEIGHT ),cvScalar( 0, 0, 255, 0 ), 1, 0, 0 );}
        else if (num4 < ithresh){inccount4 =1;}
        if (num5 >= ithresh)
        {if (inccount5 == 1){count5 = count5 + 1;inccount5 =0;}
        cvRectangle( frame,cvPoint( pos5x, pos5y ),cvPoint( pos5x + TPL_WIDTH,pos5y + TPL_HEIGHT ),cvScalar( 0, 0, 255, 0 ), 1, 0, 0 );}
        else if (num5 < ithresh){inccount5 =1;}
        if (num6 >= ithresh)
        {if (inccount6 == 1){count6 = count6 + 1;inccount6 =0;}
        cvRectangle( frame,cvPoint( pos6x, pos6y ),cvPoint( pos6x + TPL_WIDTH,pos6y + TPL_HEIGHT ),cvScalar( 0, 0, 255, 0 ), 1, 0, 0 );}
        else if (num6 < ithresh){inccount6 =1;}
        if (num7 >= ithresh)
        {if (inccount7 == 1){count7 = count7 + 1;inccount7 =0;}
        cvRectangle( frame,cvPoint( pos7x, pos7y ),cvPoint( pos7x + TPL_WIDTH,pos7y + TPL_HEIGHT ),cvScalar( 0, 0, 255, 0 ), 1, 0, 0 );}
        else if (num7 < ithresh){inccount7 =1;}
        if (num8 >= ithresh)
        {if (inccount8 == 1){count8 = count8 + 1;inccount8 =0;}
        cvRectangle( frame,cvPoint( pos8x, pos8y ),cvPoint( pos8x + TPL_WIDTH,pos8y + TPL_HEIGHT ),cvScalar( 0, 0, 255, 0 ), 1, 0, 0 );}
        else if (num8 < ithresh){inccount8 =1;}

    cout << count1 << endl;
    cout << count2 << endl;
    cout << count3 << endl;
    cout << count4 << endl;
    cout << count5 << endl;
    cout << count6 << endl;
    cout << count7 << endl;
    cout << count8 << endl;
        cvShowImage( "video", frame );
        key = cvWaitKey( (slow-speed)/fps );
    }


}

    cvDestroyWindow( "video" );
    cvReleaseCapture( &capture );
    cvReleaseImage( &tpl1 );
    cvReleaseImage( &tpl2 );
    cvReleaseImage( &tpl3 );
    cvReleaseImage( &tpl4 );
    cvReleaseImage( &tpl5 );
    cvReleaseImage( &tpl6 );
    cvReleaseImage( &tpl7 );
    cvReleaseImage( &tpl8 );
    cvReleaseImage( &seg1 );
    cvReleaseImage( &seg2 );
    cvReleaseImage( &seg3 );
    cvReleaseImage( &seg4 );
    cvReleaseImage( &seg5 );
    cvReleaseImage( &seg6 );
    cvReleaseImage( &seg7 );
    cvReleaseImage( &seg8 );
    cvReleaseImage( &frame );


    return 0;

}

void mouseHandler( int event, int x, int y, int flags, void *param )
{
        if( event == CV_EVENT_LBUTTONUP ) {
        object_x0 = x - ( TPL_WIDTH  / 2 );
        object_y0 = y - ( TPL_HEIGHT / 2 );
        cvSetImageROI( frame,cvRect( object_x0,object_y0,TPL_WIDTH,TPL_HEIGHT ) );
        if (pos7x != 0 && pos8x == 0){
        pos8x = object_x0;pos8y = object_y0;cvCopy( frame, tpl8, NULL );
        cvSetImageROI( seg8,cvRect( object_x0,object_y0,TPL_WIDTH,TPL_HEIGHT ) );cvResetImageROI( frame );
        cvRectangle( frame,cvPoint( pos8x, pos8y ),cvPoint( pos8x + TPL_WIDTH,pos8y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        }
        if (pos6x != 0 && pos7x == 0){
        pos7x = object_x0;pos7y = object_y0;cvCopy( frame, tpl7, NULL );
        cvSetImageROI( seg7,cvRect( object_x0,object_y0,TPL_WIDTH,TPL_HEIGHT ) );cvResetImageROI( frame );
        cvRectangle( frame,cvPoint( pos7x, pos7y ),cvPoint( pos7x + TPL_WIDTH,pos7y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        }
        if (pos5x != 0 && pos6x == 0){
        pos6x = object_x0;pos6y = object_y0;cvCopy( frame, tpl6, NULL );
        cvSetImageROI( seg6,cvRect( object_x0,object_y0,TPL_WIDTH,TPL_HEIGHT ) );cvResetImageROI( frame );
        cvRectangle( frame,cvPoint( pos6x, pos6y ),cvPoint( pos6x + TPL_WIDTH,pos6y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        }
        if (pos4x != 0 && pos5x == 0){
        pos5x = object_x0;pos5y = object_y0;cvCopy( frame, tpl5, NULL );
        cvSetImageROI( seg5,cvRect( object_x0,object_y0,TPL_WIDTH,TPL_HEIGHT ) );cvResetImageROI( frame );
        cvRectangle( frame,cvPoint( pos5x, pos5y ),cvPoint( pos5x + TPL_WIDTH,pos5y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        }
        if (pos3x != 0 && pos4x == 0){
        pos4x = object_x0;pos4y = object_y0;cvCopy( frame, tpl4, NULL );
        cvSetImageROI( seg4,cvRect( object_x0,object_y0,TPL_WIDTH,TPL_HEIGHT ) );cvResetImageROI( frame );
        cvRectangle( frame,cvPoint( pos4x, pos4y ),cvPoint( pos4x + TPL_WIDTH,pos4y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        }
        if (pos2x != 0 && pos3x == 0){
        pos3x = object_x0;pos3y = object_y0;cvCopy( frame, tpl3, NULL );
        cvSetImageROI( seg3,cvRect( object_x0,object_y0,TPL_WIDTH,TPL_HEIGHT ) );cvResetImageROI( frame );
        cvRectangle( frame,cvPoint( pos3x, pos3y ),cvPoint( pos3x + TPL_WIDTH,pos3y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        }
        if (pos1x != 0 && pos2x == 0){
        pos2x = object_x0;pos2y = object_y0;cvCopy( frame, tpl2, NULL );
        cvSetImageROI( seg2,cvRect( object_x0,object_y0,TPL_WIDTH,TPL_HEIGHT ) );cvResetImageROI( frame );
        cvRectangle( frame,cvPoint( pos2x, pos2y ),cvPoint( pos2x + TPL_WIDTH,pos2y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        }
        if (pos1x == 0){
        pos1x = object_x0;pos1y = object_y0;cvCopy( frame, tpl1, NULL );
        cvSetImageROI( seg1,cvRect( object_x0,object_y0,TPL_WIDTH,TPL_HEIGHT ) );cvResetImageROI( frame );
        cvRectangle( frame,cvPoint( pos1x, pos1y ),cvPoint( pos1x + TPL_WIDTH,pos1y + TPL_HEIGHT ),cvScalar( 0, 255, 0, 0 ), 1, 0, 0 );
        }
        if (pos8x != 0){
        cvResetImageROI( frame );
        }
      cvShowImage( "video", frame );
      }
}

