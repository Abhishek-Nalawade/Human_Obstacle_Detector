/**
 * @file Distance.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Distance Class Definition
 * @version 0.1
 * @date 2021-10-17
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include "../include/Distance.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>

/**
 * @brief Construct a new Detect:: Detect object
 */
Distance::Distance() {}

/**
 * @brief Transformation between camera and robot frame
 */
int Distance::camToRobotTransform() {
  std::vector<double> transform = {1, 2, 3, 4};
  int len = transform.size();
  return len;
}

/**
 * @brief Estimates the depth
 */
std::vector<double> Distance::findDepth(std::vector<double> &boxHeight){
  std::vector<double> depth;
  double tempDepth;
  for (double i : boxHeight){
    //std::cout << " i/2 :" << i/4 << std::endl;
    tempDepth = (perceivedFy * avgHumanHeight)/(i/4);
    //std::cout<<""<<tempDepth << "\n";
    depth.push_back(tempDepth);
  }
  return depth;

}

/**
 * @brief Gets the X and Y coordinates w.r.t camera frame
 */
std::vector<std::vector<double>> Distance::getXY(std::vector<double> &depth, std::vector<cv::Rect> &r){
  double X, Y, centx, centy;
  std::vector<std::vector<double>> worldCoordinates;
  for(int i = 0; i < depth.size(); i++){
    std::vector<double> xyzCoordinates;
    // cetroid of human in pixel coordinates
    centx = r[i].x + (r[i].width/2);
    centy = r[i].y + (r[i].height/2);
    // camera frame X coordinate
    X = ((640-centx)*(depth[i]))/(perceivedFx);
    Y = ((360-centy)*(depth[i]))/(perceivedFy);
    xyzCoordinates.push_back(X);
    xyzCoordinates.push_back(Y);
    xyzCoordinates.push_back(depth[i]);
    worldCoordinates.push_back(xyzCoordinates);
  }
  return worldCoordinates;
}


/**
 * @brief To display the location of detected humans on-screen.
 */
void Distance::displayLocation() {
}

/**
 * @brief Destroy the Distance:: Distance object
 */
Distance::~Distance() {}
