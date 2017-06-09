#include "realsense_wrapper.h"

int rs_wrapper::sensingModeSetting[][4] = {
											{0, 100, 10, 1},
											{0, 100, 7, 1},
											{0, 100, 60, 1},
											{0, 100, 100, 1},
											{0, 100, 140, 1},
										  };

RealsenseWrapper::RealsenseWrapper()	{
	// set the devices count
	connectedDevicesCount = realsenseContext.get_device_count();
	//init number of enable stream to be 0
	numEnableStream = 0;
	// assert there is only 1 connected camera
	if(connectedDevicesCount < 1)	{
		std::cerr<<"Available Camera: "<< connectedDevicesCount<<"\n";
		throw NO_REALSENSE_AVAILABLE;
	}
	// assert(connectedDevicesCount == 1 && "RealsenseWrapper: Asserted connectedDevices count < 1");
	// Use the ONLY 1 realsense camera
	realsenseCamera = realsenseContext.get_device(0);
	if(strcmp(realsenseCamera->get_name(), "Intel RealSense R200") != 0)	{
		std::cerr<<realsenseCamera->get_name()<<" is currently not support/suitable for this application\n";
		throw REALSENSE_NOT_SUPPORTED;
	}
}

RealsenseWrapper::~RealsenseWrapper()	{
	realsenseCamera = NULL;
}

void RealsenseWrapper::init(int streamMode)	{
	//init stream based on selected stream mode
	if(streamMode == rs_wrapper::STREAMMODE::COLOR)	{
		//enable color stream
		realsenseCamera->enable_stream(rs::stream::color, rs::preset::best_quality);
		numEnableStream = 1;
	}
	else if(streamMode == rs_wrapper::STREAMMODE::DEPTH)	{
		//enable depth stream
		realsenseCamera->enable_stream(rs::stream::depth, rs::preset::best_quality);
		numEnableStream = 1;
	}
	else if(streamMode == rs_wrapper::STREAMMODE::LEFTINFRARED)	{
		//enable left IR stream
		realsenseCamera->enable_stream(rs::stream::infrared, rs::preset::best_quality);
		numEnableStream = 1;
	}
	else if(streamMode == rs_wrapper::STREAMMODE::RIGHTINFRARED)	{
		//enable right IR stream
		realsenseCamera->enable_stream(rs::stream::infrared2, rs::preset::best_quality);
		numEnableStream = 1;
	}
	else if(streamMode == (rs_wrapper::STREAMMODE::COLOR | rs_wrapper::STREAMMODE::DEPTH))	{
		//enable color and depth stream
		realsenseCamera->enable_stream(rs::stream::color, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::depth, rs::preset::best_quality);
		numEnableStream = 2;
	}
	else if(streamMode == rs_wrapper::STREAMMODE::COLOR | rs_wrapper::STREAMMODE::LEFTINFRARED)	{
		//enable color and left IR stream
		realsenseCamera->enable_stream(rs::stream::color, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::infrared, rs::preset::best_quality);
		numEnableStream = 2;
	}
	else if(streamMode == rs_wrapper::STREAMMODE::COLOR | rs_wrapper::STREAMMODE::RIGHTINFRARED)	{
		//enable color and rightt IR stream
		realsenseCamera->enable_stream(rs::stream::color, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::infrared2, rs::preset::best_quality);
		numEnableStream = 2;
	}
	else if(streamMode == rs_wrapper::STREAMMODE::COLOR | rs_wrapper::STREAMMODE::DEPTH | rs_wrapper::STREAMMODE::LEFTINFRARED)	{
		//enable color, depth, and left IR
		realsenseCamera->enable_stream(rs::stream::color, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::depth, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::infrared, rs::preset::best_quality);
		numEnableStream = 3;
	}
	else if(streamMode == rs_wrapper::STREAMMODE::COLOR | rs_wrapper::STREAMMODE::DEPTH | rs_wrapper::STREAMMODE::RIGHTINFRARED)	{
		//enable color, depth, and right IR
		realsenseCamera->enable_stream(rs::stream::color, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::depth, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::infrared2, rs::preset::best_quality);
		numEnableStream = 3;
	}
	else if(streamMode == rs_wrapper::STREAMMODE::COLOR | rs_wrapper::STREAMMODE::LEFTINFRARED | rs_wrapper::STREAMMODE::RIGHTINFRARED)	{
		//enable color, left IR, and right IR
		realsenseCamera->enable_stream(rs::stream::color, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::infrared, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::infrared2, rs::preset::best_quality);
		numEnableStream = 3;
	}
	else if(streamMode == rs_wrapper::STREAMMODE::DEPTH | rs_wrapper::STREAMMODE::LEFTINFRARED)	{
		//enable depth, left IR, and right IR
		realsenseCamera->enable_stream(rs::stream::depth, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::infrared, rs::preset::best_quality);
		numEnableStream = 2;
	}
	else if(streamMode == rs_wrapper::STREAMMODE::DEPTH | rs_wrapper::STREAMMODE::RIGHTINFRARED)	{
		//enable depth, left IR, and right IR
		realsenseCamera->enable_stream(rs::stream::depth, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::infrared2, rs::preset::best_quality);
		numEnableStream = 2;
	}
	else if(streamMode == rs_wrapper::STREAMMODE::DEPTH | rs_wrapper::STREAMMODE::LEFTINFRARED | rs_wrapper::STREAMMODE::RIGHTINFRARED)	{
		//enable depth, left IR, and right IR
		realsenseCamera->enable_stream(rs::stream::depth, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::infrared, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::infrared2, rs::preset::best_quality);
		numEnableStream = 3;
	}
	else if(streamMode == rs_wrapper::STREAMMODE::LEFTINFRARED | rs_wrapper::STREAMMODE::RIGHTINFRARED)	{
		//enable left IR, and right IR
		realsenseCamera->enable_stream(rs::stream::infrared, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::infrared2, rs::preset::best_quality);
		numEnableStream = 2;
	}
	else {
		realsenseCamera->enable_stream(rs::stream::color, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::depth, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::infrared, rs::preset::best_quality);
		realsenseCamera->enable_stream(rs::stream::infrared2, rs::preset::best_quality);
		numEnableStream = 4;
	}

	//Start streaming
	realsenseCamera->start();
	//init stream setting variables
	streamFovX = new float[numEnableStream];
	streamFovY = new float[numEnableStream];
	streamWidth = new int[numEnableStream];
	streamHeight = new int[numEnableStream];
	// calculate the fov and resolution for each stream
	for(int i = 0; i < numEnableStream; i++)	{
		auto stream = rs::stream(i);
        if(!realsenseCamera->is_stream_enabled(stream)) continue;
        auto intrin = realsenseCamera->get_stream_intrinsics(stream);
        streamFovX[i] = intrin.hfov();
        streamFovY[i] = intrin.vfov();
        streamWidth[i] = intrin.width;
        streamHeight[i] = intrin.height;
	}
}

uint8_t* RealsenseWrapper::getColorFrame()	{
	return (uint8_t*)realsenseCamera->get_frame_data(rs::stream::color);
}

uint16_t* RealsenseWrapper::getDepthFrame()	{
	return (uint16_t*)realsenseCamera->get_frame_data(rs::stream::depth);
}

rs::intrinsics RealsenseWrapper::getStreamIntrinsics(int mode)	{
	if(mode == rs_wrapper::STREAMMODE::COLOR)	
		return realsenseCamera->get_stream_intrinsics(rs::stream::color);
	else if(mode == rs_wrapper::STREAMMODE::DEPTH)
		return realsenseCamera->get_stream_intrinsics(rs::stream::depth);
}

rs::extrinsics RealsenseWrapper::getStreamExtrinsics(int mode)	{
	if(mode == (rs_wrapper::STREAMMODE::COLOR | rs_wrapper::STREAMMODE::DEPTH))	{
		return realsenseCamera->get_extrinsics(rs::stream::depth, rs::stream::color);
	}
}

float RealsenseWrapper::getDepthScale()	{
	return realsenseCamera->get_depth_scale();
}

//return the depth value corresponding to 1 meter
const uint16_t RealsenseWrapper::getDepthMeterScale()	{
	return static_cast<uint16_t>(1.0f / realsenseCamera->get_depth_scale());
}

int RealsenseWrapper::getStreamWidth(rs_wrapper::STREAMMODE mode)	{
	if(mode == rs_wrapper::STREAMMODE::COLOR)
		return streamWidth[1];
	else if(mode == rs_wrapper::STREAMMODE::DEPTH)
		return streamWidth[0];
	else if(mode == rs_wrapper::STREAMMODE::LEFTINFRARED)
		return streamWidth[2];
	else if(mode == rs_wrapper::STREAMMODE::RIGHTINFRARED)
		return streamWidth[3];

	return -1;
}

int RealsenseWrapper::getStreamHeight(rs_wrapper::STREAMMODE mode)	{
	if(mode == rs_wrapper::STREAMMODE::COLOR)
		return streamHeight[1];
	else if(mode == rs_wrapper::STREAMMODE::DEPTH)
		return streamHeight[0];
	else if(mode == rs_wrapper::STREAMMODE::LEFTINFRARED)
		return streamHeight[2];
	else if(mode == rs_wrapper::STREAMMODE::RIGHTINFRARED)
		return streamHeight[3];
	
	return -1;
}

//obtain an test frame size
int RealsenseWrapper::getSamplePointCloudSize()	{
	//size
	int size = 0;
	//wait until a frame is avaiable
	realsenseCamera->wait_for_frames();
	//get a depth frame
	const uint16_t* depthFrame = getDepthFrame();
	//retrieve camera parmeters for mapping
	rs::intrinsics depthIntrinsics = getStreamIntrinsics(rs_wrapper::STREAMMODE::DEPTH);

	//for every pixel
	for(int y = 0; y < depthIntrinsics.height; y++)	{
		for(int x = 0; x < depthIntrinsics.width; x++)	{
			//depth in meter
			float z = (depthFrame[y * depthIntrinsics.width + x]) * getDepthScale();
			// ignore all points that z = 0
			if(z == 0)
				continue;

			//since we are just counting, we dont need to do any calculation
			size++;
		}
	}

	return size;
}

//obtain an XYZ pointCloud with no color
void RealsenseWrapper::getPCLXYZPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr pointCloud, rs_wrapper::COORDMODE cmode)	{
	//make sure the container is clean
	pointCloud->clear();
	//wait until a frame is avaiable
	realsenseCamera->wait_for_frames();
	//get a depth frame
	const uint16_t* depthFrame = getDepthFrame();
	//retrieve camera parmeters for mapping
	rs::intrinsics depthIntrinsics = getStreamIntrinsics(rs_wrapper::STREAMMODE::DEPTH);

	//for every pixel
	for(int y = 0; y < depthIntrinsics.height; y++)	{
		for(int x = 0; x < depthIntrinsics.width; x++)	{
			//depth in meter
			float z = (depthFrame[y * depthIntrinsics.width + x]) * getDepthScale();
			// ignore all points that z = 0
			if(z == 0)
				continue;
			//mapping the pixel into 3D space
			rs::float2 depthPixel = {(float)x, (float)y};
			rs::float3 depthPoint = depthIntrinsics.deproject(depthPixel, z);

			//push point into PCL container
			pointCloud->push_back(pcl::PointXYZ());
			pointCloud->back().y += (cmode == rs_wrapper::COORDMODE::RIGHTHANDED) ? -depthPoint.y : depthPoint.y;
			pointCloud->back().x = depthPoint.x;
			pointCloud->back().z = depthPoint.z;
		}
	}
}

//get N average frame XYZRGB point cloud
void RealsenseWrapper::getNPCLXYZPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr pointCloud, int N, rs_wrapper::COORDMODE cmode)	{
	int frameWidth = getStreamWidth(rs_wrapper::DEPTH);
	int frameHeight = getStreamHeight(rs_wrapper::DEPTH);
	int frameResolution = frameHeight * frameWidth;
	//make sure the container is clean
	pointCloud->clear();
	// create an array to keep track point frame amount
	int* pointFrame = new int[frameResolution];
	// push NxM points into the container
	for(int i = 0; i < frameResolution; i++)	{
		pointCloud->push_back(pcl::PointXYZ());
		// also set pointFrame to all 0
		pointFrame[i] = 0;
	}

	// for N sample frame
	for(int i = 0; i < N; i++)	{
		//wait until a frame is avaiable
		realsenseCamera->wait_for_frames();
		//get a depth frame
		const uint16_t* depthFrame = getDepthFrame();
		//retrieve camera parmeters for mapping
		rs::intrinsics depthIntrinsics = getStreamIntrinsics(rs_wrapper::STREAMMODE::DEPTH);	

		// just making sure they are equal
		if((depthIntrinsics.height != frameHeight) ||(depthIntrinsics.width != frameWidth))	{
			continue;
		}

		for(int y = 0; y < frameHeight; y++)	{
			for(int x = 0; x < frameWidth; x++)	{
				int index = y * frameWidth + x;
				//depth in meter
				float z = (depthFrame[index]) * getDepthScale();
				// ignore all points that z = 0
				if(z == 0)
					continue;
				//mapping the pixel into 3D space
				rs::float2 depthPixel = {(float)x, (float)y};
				rs::float3 depthPoint = depthIntrinsics.deproject(depthPixel, z);

				// update point value
				pointCloud->points[index].y += (cmode == rs_wrapper::COORDMODE::RIGHTHANDED) ? -depthPoint.y : depthPoint.y;
				pointCloud->points[index].x += depthPoint.x;
				pointCloud->points[index].z += depthPoint.z;
				pointFrame[index] += 1;
			}//end for width
		}//end for height
	}//end for N

	// take the average
	for(int i = 0; i < frameHeight * frameWidth; i++)	{
		if(pointFrame[i] < 1)	{
			continue;
		}
		pointCloud->points[i].x /= (double)pointFrame[i];
		pointCloud->points[i].y /= (double)pointFrame[i];
		pointCloud->points[i].z /= (double)pointFrame[i];
	}

	// for(int y = 0; y < frameHeight *; y++)	{
	// 	for(int x = 0; x < frameWidth; x++)	{
	// 		int index = y * frameWidth + x;
	// 		if(pointFrame[index] < 1)	{
	// 			continue;
	// 		}
	// 		pointCloud->points[index].x /= (double)pointFrame[index];
	// 		pointCloud->points[index].y /= (double)pointFrame[index];
	// 		pointCloud->points[index].z /= (double)pointFrame[index];
	// 	}
	// }

	delete[] pointFrame;
}

//get XYZRGB point cloud without color
void RealsenseWrapper::getPCLXYZPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud, rs_wrapper::COORDMODE cmode)	{
	//make sure the container is clean
	pointCloud->clear();
	//wait until a frame is avaiable
	realsenseCamera->wait_for_frames();
	//get a depth frame
	const uint16_t* depthFrame = getDepthFrame();
	//retrieve camera parmeters for mapping
	rs::intrinsics depthIntrinsics = getStreamIntrinsics(rs_wrapper::STREAMMODE::DEPTH);

	//for every pixel
	for(int y = 0; y < depthIntrinsics.height; y++)	{
		for(int x = 0; x < depthIntrinsics.width; x++)	{
			//depth in meter
			float z = (depthFrame[y * depthIntrinsics.width + x]) * getDepthScale();
			// ignore all points that z = 0
			if(z == 0)
				continue;
			//mapping the pixel into 3D space
			rs::float2 depthPixel = {(float)x, (float)y};
			rs::float3 depthPoint = depthIntrinsics.deproject(depthPixel, z);

			//push point into PCL container
			pointCloud->push_back(pcl::PointXYZRGB(255, 255, 255));
			pointCloud->back().y += (cmode == rs_wrapper::COORDMODE::RIGHTHANDED) ? -depthPoint.y : depthPoint.y;
			pointCloud->back().x = depthPoint.x;
			pointCloud->back().z = depthPoint.z;
		}
	}
}

//get N average frame XYZRGB point cloud without color
void RealsenseWrapper::getNPCLXYZPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud, int N, rs_wrapper::COORDMODE cmode)	{
	int frameWidth = getStreamWidth(rs_wrapper::DEPTH);
	int frameHeight = getStreamHeight(rs_wrapper::DEPTH);
	int frameResolution = frameHeight * frameWidth;
	//make sure the container is clean
	pointCloud->clear();
	// create an array to keep track point frame amount
	int* pointFrame = new int[frameResolution];
	// push NxM points into the container
	for(int i = 0; i < frameResolution; i++)	{
		pointCloud->push_back(pcl::PointXYZRGB(255, 255, 255));
		// also set pointFrame to all 0
		pointFrame[i] = 0;
	}

	// for N sample frame
	for(int i = 0; i < N; i++)	{
		//wait until a frame is avaiable
		realsenseCamera->wait_for_frames();
		//get a depth frame
		const uint16_t* depthFrame = getDepthFrame();
		//retrieve camera parmeters for mapping
		rs::intrinsics depthIntrinsics = getStreamIntrinsics(rs_wrapper::STREAMMODE::DEPTH);	

		// just making sure they are equal
		if((depthIntrinsics.height != frameHeight) ||(depthIntrinsics.width != frameWidth))	{
			continue;
		}

		for(int y = 0; y < frameHeight; y++)	{
			for(int x = 0; x < frameWidth; x++)	{
				int index = y * frameWidth + x;
				//depth in meter
				float z = (depthFrame[index]) * getDepthScale();
				// ignore all points that z = 0
				if(z == 0)
					continue;
				//mapping the pixel into 3D space
				rs::float2 depthPixel = {(float)x, (float)y};
				rs::float3 depthPoint = depthIntrinsics.deproject(depthPixel, z);

				// update point value
				pointCloud->points[index].y += (cmode == rs_wrapper::COORDMODE::RIGHTHANDED) ? -depthPoint.y : depthPoint.y;
				pointCloud->points[index].x += depthPoint.x;
				pointCloud->points[index].z += depthPoint.z;
				pointFrame[index] += 1;
			}//end for width
		}//end for height
	}//end for N

	// take the average
	for(int i = 0; i < frameHeight * frameWidth; i++)	{
		if(pointFrame[i] < 1)	{
			continue;
		}
		pointCloud->points[i].x /= (double)pointFrame[i];
		pointCloud->points[i].y /= (double)pointFrame[i];
		pointCloud->points[i].z /= (double)pointFrame[i];
	}

	delete[] pointFrame;
}


//obtain an XYZ pointCloud with color
void RealsenseWrapper::getPCLXYZRGBPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud, rs_wrapper::COORDMODE cmode)	{
	//make sure the container is clean
	pointCloud->clear();
	//wait until a frame is avaiable
	realsenseCamera->wait_for_frames();
	//get a depth frame
	const uint16_t* depthFrame = getDepthFrame();
	//get a color frame
	const uint8_t* colorFrame = getColorFrame();
	//retrieve camera parmeters for mapping
	rs::intrinsics depthIntrinsics = getStreamIntrinsics(rs_wrapper::STREAMMODE::DEPTH);
	rs::intrinsics colorIntrinsics = getStreamIntrinsics(rs_wrapper::STREAMMODE::COLOR);
	//depth to color space mapper
	rs::extrinsics depthColorMapper = getStreamExtrinsics(rs_wrapper::STREAMMODE::COLOR | rs_wrapper::STREAMMODE::DEPTH);

	for(int y = 0; y < depthIntrinsics.height; y++)	{
		for(int x = 0; x < depthIntrinsics.width; x++)	{
			//depth in meter
			float z = (depthFrame[y * depthIntrinsics.width + x]) * getDepthScale();
			// ignore all points that z = 0
			if(z == 0)
				continue;
			//mapping the pixel into 3D space
			rs::float2 depthPixel = {(float)x, (float)y};
			rs::float3 depthPoint = depthIntrinsics.deproject(depthPixel, z);
			//mapping to corresponding color pixel
			rs::float3 colorPoint = depthColorMapper.transform(depthPoint);
			//map color point from 3D space to image space
			rs::float2 colorPixel = colorIntrinsics.project(colorPoint);
			//calculate color pixel position
			const int colorX = (int)std::round(colorPixel.x), 
					  colorY = (int)std::round(colorPixel.y);

			//push point into PCL container
			// if pixel position is not within image, just fill with white
			int r = 255, g = 255, b = 255;
			if(!(colorX < 0 || colorX >= colorIntrinsics.width || 
				colorY < 0 || colorY >= colorIntrinsics.height))	{
				// dereference the point at location described below
				r = (int)*(colorFrame + (colorY * colorIntrinsics.width + colorX) * 3);
				g = (int)*(colorFrame + ((colorY * colorIntrinsics.width + colorX) * 3) + 1);
				b = (int)*(colorFrame + ((colorY * colorIntrinsics.width + colorX) * 3) + 2);
			}
			pointCloud->push_back(pcl::PointXYZRGB(r, g, b));
			pointCloud->back().y += (cmode == rs_wrapper::COORDMODE::RIGHTHANDED) ? -depthPoint.y : depthPoint.y;	
			pointCloud->back().x = depthPoint.x;
			pointCloud->back().z = depthPoint.z;
		}
	}
}

//get N average frame XYZRGB point cloud
void RealsenseWrapper::getNPCLXYZRGBPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud, int N, rs_wrapper::COORDMODE cmode)	{
	int frameWidth = getStreamWidth(rs_wrapper::DEPTH);
	int frameHeight = getStreamHeight(rs_wrapper::DEPTH);
	int frameResolution = frameHeight * frameWidth;
	//make sure the container is clean
	pointCloud->clear();
	// create an array to keep track point frame amount
	int* pointFrame = new int[frameResolution];
	// push NxM points into the container
	for(int i = 0; i < frameResolution; i++)	{
		pointCloud->push_back(pcl::PointXYZRGB());
		// also set pointFrame to all 0
		pointFrame[i] = 0;
	}

	// for N sample frame
	for(int i = 0; i < N; i++)	{
		//wait until a frame is avaiable
		realsenseCamera->wait_for_frames();
		//get a depth frame
		const uint16_t* depthFrame = getDepthFrame();
		//get a color frame
		const uint8_t* colorFrame = getColorFrame();
		//retrieve camera parmeters for mapping
		rs::intrinsics depthIntrinsics = getStreamIntrinsics(rs_wrapper::STREAMMODE::DEPTH);
		rs::intrinsics colorIntrinsics = getStreamIntrinsics(rs_wrapper::STREAMMODE::COLOR);
		//depth to color space mapper
		rs::extrinsics depthColorMapper = getStreamExtrinsics(rs_wrapper::STREAMMODE::COLOR | rs_wrapper::STREAMMODE::DEPTH);

		// just making sure they are equal
		if((depthIntrinsics.height != frameHeight) ||(depthIntrinsics.width != frameWidth))	{
			continue;
		}

		for(int y = 0; y < frameHeight; y++)	{
			for(int x = 0; x < frameWidth; x++)	{
				int index = y * frameWidth + x;
				//depth in meter
				float z = (depthFrame[index]) * getDepthScale();
				// ignore all points that z = 0
				if(z == 0)
					continue;
				//mapping the pixel into 3D space
				rs::float2 depthPixel = {(float)x, (float)y};
				rs::float3 depthPoint = depthIntrinsics.deproject(depthPixel, z);
				//mapping to corresponding color pixel
				rs::float3 colorPoint = depthColorMapper.transform(depthPoint);
				//map color point from 3D space to image space
				rs::float2 colorPixel = colorIntrinsics.project(colorPoint);
				//calculate color pixel position
				const int colorX = (int)std::round(colorPixel.x), 
						  colorY = (int)std::round(colorPixel.y);

				//push point into PCL container
				// if pixel position is not within image, just fill with white
				int r = 255, g = 255, b = 255;
				if(!(colorX < 0 || colorX >= colorIntrinsics.width || 
					colorY < 0 || colorY >= colorIntrinsics.height))	{
					// dereference the point at location described below
					r = (int)*(colorFrame + (colorY * colorIntrinsics.width + colorX) * 3);
					g = (int)*(colorFrame + ((colorY * colorIntrinsics.width + colorX) * 3) + 1);
					b = (int)*(colorFrame + ((colorY * colorIntrinsics.width + colorX) * 3) + 2);
				}

				// update point value
				pointCloud->points[index].y = (cmode == rs_wrapper::COORDMODE::RIGHTHANDED) ? -depthPoint.y : depthPoint.y;
				pointCloud->points[index].x = depthPoint.x;
				pointCloud->points[index].z += depthPoint.z;
				pointCloud->points[index].r = r;
				pointCloud->points[index].g = g;
				pointCloud->points[index].b = b;
				pointFrame[index] += 1;
			}//end for width
		}//end for height
	}//end for N

	// take the average
	for(int i = 0; i < frameHeight * frameWidth; i++)	{
		if(pointFrame[i] < 1)	{
			continue;
		}
		// pointCloud->points[i].x /= (double)pointFrame[i];
		// pointCloud->points[i].y /= (double)pointFrame[i];
		pointCloud->points[i].z /= (double)pointFrame[i];
	}

	delete[] pointFrame;
}

void RealsenseWrapper::getXYZRGBDepthColor(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud, rs_wrapper::COORDMODE cmode, 
										   cv::Mat& depthImage, cv::Mat& colorImage)	{
	/*
		Compute Point Cloud
	*/
	//make sure the container is clean
	pointCloud->clear();
	//wait until a frame is avaiable
	realsenseCamera->wait_for_frames();
	//get a depth frame
	uint16_t* depthFrame = getDepthFrame();
	//get a color frame
	uint8_t* colorFrame = getColorFrame();
	//retrieve camera parmeters for mapping
	rs::intrinsics depthIntrinsics = getStreamIntrinsics(rs_wrapper::STREAMMODE::DEPTH);
	rs::intrinsics colorIntrinsics = getStreamIntrinsics(rs_wrapper::STREAMMODE::COLOR);
	//depth to color space mapper
	rs::extrinsics depthColorMapper = getStreamExtrinsics(rs_wrapper::STREAMMODE::COLOR | rs_wrapper::STREAMMODE::DEPTH);

	for(int y = 0; y < depthIntrinsics.height; y++)	{
		for(int x = 0; x < depthIntrinsics.width; x++)	{
			//depth in meter
			float z = (depthFrame[y * depthIntrinsics.width + x]) * getDepthScale();
			// ignore all points that z = 0
			if(z == 0)
				continue;
			//mapping the pixel into 3D space
			rs::float2 depthPixel = {(float)x, (float)y};
			rs::float3 depthPoint = depthIntrinsics.deproject(depthPixel, z);
			//mapping to corresponding color pixel
			rs::float3 colorPoint = depthColorMapper.transform(depthPoint);
			//map color point from 3D space to image space
			rs::float2 colorPixel = colorIntrinsics.project(colorPoint);
			//calculate color pixel position
			const int colorX = (int)std::round(colorPixel.x), 
					  colorY = (int)std::round(colorPixel.y);

			//push point into PCL container
			// if pixel position is not within image, just fill with white
			int r = 255, g = 255, b = 255;
			if(!(colorX < 0 || colorX >= colorIntrinsics.width || 
				colorY < 0 || colorY >= colorIntrinsics.height))	{
				// dereference the point at location described below
				r = (int)*(colorFrame + (colorY * colorIntrinsics.width + colorX) * 3);
				g = (int)*(colorFrame + ((colorY * colorIntrinsics.width + colorX) * 3) + 1);
				b = (int)*(colorFrame + ((colorY * colorIntrinsics.width + colorX) * 3) + 2);
			}
			pointCloud->push_back(pcl::PointXYZRGB(r, g, b));
			pointCloud->back().y += (cmode == rs_wrapper::COORDMODE::RIGHTHANDED) ? -depthPoint.y : depthPoint.y;	
			pointCloud->back().x = depthPoint.x;
			pointCloud->back().z = depthPoint.z;
		}
	}

	/*
		Compute Depth and Color Image
	*/
	rs::intrinsics colorStream = getStreamIntrinsics(rs_wrapper::STREAMMODE::COLOR);
	rs::intrinsics depthStream = getStreamIntrinsics(rs_wrapper::STREAMMODE::DEPTH);
	cv::Mat depthImage16(depthStream.height, depthStream.width, CV_16U, static_cast<uint16_t*>(depthFrame));
	depthImage = depthImage16;
	depthImage.convertTo(depthImage, CV_8UC1, 255.0 / 1000);

	colorImage = cv::Mat(colorStream.height, colorStream.width, CV_8UC3, colorFrame);
}


//\brief Return connected devices count
int RealsenseWrapper::getConnectedDevicesCount()	{
	return connectedDevicesCount;
}

//\brief Return number of enabled stream
int RealsenseWrapper::getNumEnableStream()	{
	return numEnableStream;
}

float RealsenseWrapper::getFovX(rs_wrapper::STREAMMODE mode)	{
	if(mode == rs_wrapper::STREAMMODE::COLOR)
		return streamFovX[1];
	else if(mode == rs_wrapper::STREAMMODE::DEPTH)
		return streamFovX[0];
	else if(mode == rs_wrapper::STREAMMODE::LEFTINFRARED)
		return streamFovX[2];
	else if(mode == rs_wrapper::STREAMMODE::RIGHTINFRARED)
		return streamFovX[3];

	return -1;
}

float RealsenseWrapper::getFovY(rs_wrapper::STREAMMODE mode)	{
	return streamFovY[mode];
}

void RealsenseWrapper::setOptions(rs::option opCode, double value)	{
	realsenseCamera->set_option(opCode, value);
}



void RealsenseWrapper::setSensingMode(rs_wrapper::SENSINGMODE mode)	{
	if(mode == rs_wrapper::SENSINGMODE::INDOOR)	{
		realsenseCamera->set_option(rs::option::r200_lr_auto_exposure_enabled, 1);
	    realsenseCamera->set_option(rs::option::r200_emitter_enabled, 1);
	}
	else 	{
		realsenseCamera->set_option(rs::option::r200_lr_auto_exposure_enabled, rs_wrapper::sensingModeSetting[mode][0]);
	    realsenseCamera->set_option(rs::option::r200_lr_gain, rs_wrapper::sensingModeSetting[mode][1]);
	    realsenseCamera->set_option(rs::option::r200_lr_exposure, rs_wrapper::sensingModeSetting[mode][2]);
	    realsenseCamera->set_option(rs::option::r200_emitter_enabled, rs_wrapper::sensingModeSetting[mode][3]);
	}
}

//print all connected devices information
void RealsenseWrapper::listAllConnectedDevicesInfo()	{
	for(int i = 0; i < connectedDevicesCount; i++)	{
		rs::device* dev = realsenseContext.get_device(i);
		std::cout << "Devices 0: " << dev->get_name() <<"\n"
			  << "Serial NumberL "<< dev->get_serial()<<"\n"
			  << "Firmware Version: "<< dev->get_firmware_version()<<"\n";
	}
}

//print selected decives information
void RealsenseWrapper::listSelectedDeviceInfo()	{
	std::cout << "Devices 0: " << realsenseCamera->get_name() <<"\n"
			  << "Serial NumberL "<< realsenseCamera->get_serial()<<"\n"
			  << "Firmware Version: "<< realsenseCamera->get_firmware_version()<<"\n";
}

