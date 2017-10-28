#include "ros/ros.h"
#include "service_cpp/AddTwoInts.h"

class MyClass
{
  public:
    bool add(service_cpp::AddTwoInts::Request &req,
             service_cpp::AddTwoInts::Response &res)
    {
        res.sum = req.a + req.b;
        return true;
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_two_ints_server");
    ros::NodeHandle nodeHandler;

    MyClass obj;
    ros::ServiceServer service = nodeHandler.advertiseService(
        "add_two_ints", &MyClass::add, &obj);
    ros::spin();
}
