#include "ros/ros.h"
#include "service_cpp/AddTwoInts.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_two_ints_client");

    ros::NodeHandle nodeHandler;
    ros::ServiceClient client =
        nodeHandler.serviceClient<service_cpp::AddTwoInts>("add_two_ints");

    service_cpp::AddTwoInts srv;
    // リクエストを作成する
    srv.request.a = 1;
    srv.request.b = 2;

    // サービスを呼び出す
    if (client.call(srv))
    {
        ROS_INFO("Sum: %ld", (long int)srv.response.sum);
    }
    else
    {
        ROS_ERROR("Failed to call service add_two_ints");
        return 1;
    }

    return 0;
}
