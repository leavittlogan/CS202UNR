//
// Name: Sensor.h
// Author: Logan K. Leavitt
// Purpose: declaration of Sensor class
//
#ifndef SENSOR_H_
#define SENSOR_H_
#include "proj4.h"

const char * const DFLT_TYPE = "none";

class Sensor {
	public:
		// Default constructor
		Sensor();
		// paramaterized constructor
		Sensor(const char * type);
		// copy constructor
		Sensor(const Sensor & sensor);

		// getters
		const char * getType() const;
		float getExtraCost() const;

		// setters
		void setType(const char * type);

		bool operator ==(const Sensor & sensor) const;

		// static functions
		static int getGpsCnt();
		static int getCameraCnt();
		static int getLidarCnt();
		static int getRadarCnt();
		static void resetGpsCnt();
		static void resetCameraCnt();
		static void resetLidarCnt();
		static void resetRadarCnt();
	private:
		char m_type[MAX_STR_SIZE];
		float m_extracost;

		static int gps_cnt;
		static int camera_cnt;
		static int lidar_cnt;
		static int radar_cnt;
};

#endif
