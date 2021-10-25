/**
 * @file Data.hpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Data Class Declaration
 * @version 0.1
 * @date 2021-10-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <Eigen/Dense>
#include <string>
#include <iostream>
#include "../include/Distance.hpp"
#include "../include/Detect.hpp"
#include <opencv2/opencv.hpp>

/**
 * @brief Data class includes methods to get the input data
 *        and a method to put bounging boxes around the
 *        detected humans.
 *
 */
class Data {
 public:
  Data();
  Distance dist;
  Detect human_detector;
  cv::Mat frame;
  int getCamera(int mode);
  double loadVideo(std::string filePath);
  cv::Mat preProcessing(const cv::Mat &frame);
  cv::Mat videoPreProcessing(const cv::Mat &frame);
  ~Data();

 private:
  cv::Mat frame_copy;
  cv::Mat resizedFrame;
};
