#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <ros/ros.h>
#include <sensor_msgs/Image.h>

void image_recieved(const sensor_msgs::Image &msg)
{
    ROS_INFO("width: %d, height: %d, encoding: %s, is_bigendian: %d, step: %d",
             msg.height, msg.width, msg.encoding.c_str(),
             msg.is_bigendian, msg.step);

    // sensor_msgs::Image を cv::Mat に変換する。
    cv_bridge::CvImagePtr cvPtr;
    try
    {
        cvPtr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception &e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }

    // ウィンドウに表示する。
    cv::imshow("image", cvPtr->image);
    cv::waitKey(3);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_subscriber_node");

    // ウィンドウを作成する。
    cv::namedWindow("image", cv::WINDOW_AUTOSIZE);

    ros::NodeHandle node_handler;
    ros::Subscriber sub = node_handler.subscribe("/usb_cam/image_raw", 10, image_recieved);

    ros::spin();
    return 0;
}