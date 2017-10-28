#include <boost/shared_ptr.hpp>

#include "ros/ros.h"
#include "service_cpp/AddTwoInts.h"

class MyClass
{
  public:
    bool add(ros::ServiceEvent<service_cpp::AddTwoInts::Request,
                               service_cpp::AddTwoInts::Response> &event)
    {
        event.getResponse().sum = event.getRequest().a + event.getRequest().b;
        return true;
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_two_ints_server");
    ros::NodeHandle nodeHandler;

    boost::shared_ptr<MyClass> objPtr = boost::make_shared<MyClass>();
    ros::ServiceServer service = nodeHandler.advertiseService(
        "add_two_ints", &MyClass::add, objPtr);
    ros::spin();
}
