#include "ros/ros.h"
#include "service_cpp/AddTwoInts.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_two_ints_client");

    ros::NodeHandle nodeHandler;
    ros::ServiceClient client =
        nodeHandler.serviceClient<service_cpp::AddTwoInts>("add_two_ints");

    service_cpp::AddTwoInts::Request req;
    service_cpp::AddTwoInts::Response res;
    // リクエストを作成する
    req.a = 1;
    req.b = 2;

    // サービスを呼び出す
    if (client.call(req, res))
    {
        ROS_INFO("Sum: %ld", (long int)res.sum);
    }
    else
    {
        ROS_ERROR("Failed to call service add_two_ints");
        return 1;
    }

    return 0;
}
