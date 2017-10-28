#include "ros/ros.h"
#include "service_cpp/AddTwoInts.h"

bool add(ros::ServiceEvent<service_cpp::AddTwoInts::Request,
                           service_cpp::AddTwoInts::Response> &event)
{
    event.getResponse().sum = event.getRequest().a + event.getRequest().b;
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_two_ints_server");
    ros::NodeHandle nodeHandler;

    ros::ServiceServer service = nodeHandler.advertiseService(
        "add_two_ints", add);
    ros::spin();
}
