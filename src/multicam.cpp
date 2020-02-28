#include <ros/ros.h>
#include <librealsense2/rs.hpp>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "multicam");
  ros::NodeHandle n;

  rs2::context ctx;
  std::vector<rs2::pipeline> pipelines;

  for (auto&& dev : ctx.query_devices())
  {
    ROS_WARN("starting camera");
    rs2::pipeline pipe(ctx);
    rs2::config cfg;
    cfg.enable_device(dev.get_info(RS2_CAMERA_INFO_SERIAL_NUMBER));
    pipe.start(cfg);
    pipelines.emplace_back(pipe);
    ROS_WARN("  success");
  }
}
