/**
 * @file Detect.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Detect Class Definition
 * @version 0.1
 * @date 2021-10-17
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include "../include/Detect.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

/**
 * @brief Construct a new Detect:: Detect object
 */
Detect::Detect() {}

/**
 * @brief Method to detect humans in input frames
 * @param input_frame :Frame to detect humans
 * @return std::vector<double>
 */
std::vector<double> Detect::detectHuman(cv::Mat &input_frame) {
  HOG.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
  std::vector<double> weights;
  HOG.detectMultiScale(input_frame, box_coordinates, weights);
  return weights;
}

/**
 * @brief Method to draw bouding boxes around detected humans
 * @param input_frame : Frame returned from detectHuman method
 * @param weights : Weights used in the classifier
 * @return std::vector<double>
 */
std::vector<double> Detect::putBox(cv::Mat &input_frame,
                                    std::vector<double> &weights) {
  std::vector<double> heights;
  for ( size_t i = 0; i < box_coordinates.size(); i++ ) {
    cv::Rect r = box_coordinates[i];
    cv::rectangle(input_frame, r, cv::Scalar(0, 0, 255), 3);
    std::stringstream temp;
    temp << i + 1;
    cv::putText(input_frame, temp.str(), cv::Point(r.x, r.y+50),
                cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255) );
    heights.push_back(r.height);
  }
  return heights;
}

/**
 * @brief Destroy the Detect:: Detect object
 */
Detect::~Detect() {}
