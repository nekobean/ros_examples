#include <boost/function.hpp>

#include "ros/ros.h"
#include "service_cpp/AddTwoInts.h"

typedef boost::function<
    bool(service_cpp::AddTwoInts::Request &,
         service_cpp::AddTwoInts::Response &)>
    CallbackFunc;

class Add
{
  public:
    bool operator()(service_cpp::AddTwoInts::Request &req,
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

    CallbackFunc callback = Add();

    ros::ServiceServer service = nodeHandler.advertiseService(
        "add_two_ints", callback);
    ros::spin();
}
