#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "librealsense2/rs.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "pcl/point_cloud.h"
#include "pcl/point_types.h"
#include "pcl_conversions/pcl_conversions.h"

using namespace std::chrono_literals;

class LidarPublisher : public rclcpp::Node
{
public:
    LidarPublisher() : Node("lidar_publisher")
    {
        publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("pcl", 10);
        timer_ = this->create_wall_timer(1s, std::bind(&LidarPublisher::timer_callback, this));
    }

private:
    void timer_callback()
    {
        sensor_msgs::msg::PointCloud2 msg;
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing pointcloud");
        pcl::PCLPointCloud2 pcl;
        rs2::pipeline pipe;
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr publisher_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LidarPublisher>());
    rclcpp::shutdown();
    return 0;
}