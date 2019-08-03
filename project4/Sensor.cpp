//
// Name: Sensor.cpp
// Author: Logan K. Leavitt
// Purpose: definitions of Sensor member functions
//
#include "Sensor.h"
#include "proj4.h"

int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

// Default Constructor
Sensor::Sensor() : Sensor(DFLT_TYPE) {}

// Paramaterized Constructor
// Available types are "gps", "camera", "lidar", "radar", and "none"
// 	note: any other string will result in the defualt type, "none"
Sensor::Sensor(const char * type) {
	setType(type);
}

// Copy Constructor
Sensor::Sensor(const Sensor & sensor) : Sensor(sensor.getType()) {}

//
// Getters
//

const char * Sensor::getType() const {
	return m_type;
}

float Sensor::getExtraCost() const {
	return m_extracost;
}

//
// Setters
//

void Sensor::setType(const char * type) {
	myStringCopy(m_type, type);	

	if (myStringCompare(m_type, "gps") == 0) {
		m_extracost = 5;
		gps_cnt++;
	} else if (myStringCompare(m_type, "camera") == 0) {
		m_extracost = 10;
		camera_cnt++;
	} else if (myStringCompare(m_type, "lidar") == 0) {
		m_extracost = 15;
		lidar_cnt++;
	} else if (myStringCompare(m_type, "radar") == 0) {
		m_extracost = 20;
		radar_cnt++;
	} else if (myStringCompare(m_type, "none") == 0) {
		m_extracost = 0;
	} else {
		myStringCopy(m_type, "none");
		m_extracost = 0;
	}
}

// overload of == operator, returns true if the two sensors are the same type
bool Sensor::operator ==(const Sensor & sensor) const {
	return (myStringCompare(m_type, sensor.getType()) == 0);	
}

//
// Static functions
//

int Sensor::getGpsCnt() {
	return gps_cnt;
}

int Sensor::getCameraCnt() {
	return camera_cnt;
}

int Sensor::getLidarCnt() {
	return lidar_cnt;
}

int Sensor::getRadarCnt() {
	return radar_cnt;
}

void Sensor::resetGpsCnt() {
	gps_cnt = 0;
}

void Sensor::resetCameraCnt() {
	camera_cnt = 0;
}

void Sensor::resetLidarCnt() {
	lidar_cnt = 0;
}

void Sensor::resetRadarCnt() {
	radar_cnt = 0;
}
