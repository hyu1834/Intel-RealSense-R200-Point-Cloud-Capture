#ifndef REALSENSE_WRAPPER_H
	#define REALSENSE_WRAPPER_H

/*
Standard Libraries
*/
#include <iostream>
#include <cassert>
#include <cstring>

/*
	3rd party libraries
*/
//Librealsense
#include <librealsense/rs.hpp>
//PCL
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
//OpenCV
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

/*
	Local Libraries
*/

/*
	MACRO
*/
#define REALSENSE_ERROR 0x30913873
#define NO_REALSENSE_AVAILABLE 0x30913874
#define REALSENSE_NOT_SUPPORTED 0x30913875


namespace rs_wrapper	{
	enum SENSINGMODE 	{
		INDOOR = 0x00,
		OUTDOOR1,
		OUTDOOR2,
		OUTDOOR3,
		OUTDOOR4,
		OUTDOOR5
	};
	//stream mode
	enum STREAMMODE	{
		COLOR = 0x02,
		DEPTH = 0x04,
		LEFTINFRARED = 0x08,
		RIGHTINFRARED = 0x10,
		ALL = 0x20
	};

	enum COORDMODE	{
		RIGHTHANDED = 0x00,
		LEFTHANDED
	};

	extern "C" int sensingModeSetting[][4];
}

class RealsenseWrapper	{
	private:
		rs::context realsenseContext;
		rs::device* realsenseCamera;

		int connectedDevicesCount;
		int numEnableStream;
		float* streamFovX;
		float* streamFovY;
		int* streamWidth;
		int* streamHeight;

	protected:
	public:
		RealsenseWrapper();
		~RealsenseWrapper();

		/*
			Class Methods
		*/
		void init(int streamMode);
		uint8_t* getColorFrame();
		uint16_t* getDepthFrame();
		rs::intrinsics getStreamIntrinsics(int mode);
		rs::extrinsics getStreamExtrinsics(int mode);
		float getDepthScale();
		const uint16_t getDepthMeterScale();
		int getStreamWidth(rs_wrapper::STREAMMODE mode);
		int getStreamHeight(rs_wrapper::STREAMMODE mode);
		//obtain an test frame size
		int getSamplePointCloudSize();
		//obtain an XYZ pointcloud with no color
		void getPCLXYZPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr pointCloud, rs_wrapper::COORDMODE cmode);
		void getNPCLXYZPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr pointCloud, int N, rs_wrapper::COORDMODE cmode);
		void getPCLXYZPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud, rs_wrapper::COORDMODE cmode);
		void getNPCLXYZPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud, int N, rs_wrapper::COORDMODE cmode);

		//obtain an XYZ pointcloud with color
		void getPCLXYZRGBPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud, rs_wrapper::COORDMODE cmode);
		void getNPCLXYZRGBPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud, int N, rs_wrapper::COORDMODE cmode);

		// obtain XYZRGB point cloud with depth and color image
		void getXYZRGBDepthColor(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud, rs_wrapper::COORDMODE cmode, 
									cv::Mat& depth, cv::Mat& color);
		

		//return connected devices count
		int getConnectedDevicesCount();
		//\brief Return number of enabled stream
		int getNumEnableStream();
		float getFovX(rs_wrapper::STREAMMODE mode);
		float getFovY(rs_wrapper::STREAMMODE mode);
		

		void setOptions(rs::option opCode, double value);
		void setSensingMode(rs_wrapper::SENSINGMODE mode);

		//print all connected devices information
		void listAllConnectedDevicesInfo();
		//print selected decives information
		void listSelectedDeviceInfo();
};
#endif
