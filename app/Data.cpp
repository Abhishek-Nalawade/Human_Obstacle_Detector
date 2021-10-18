/**
 * @file Data.cpp
 * @author Aditya Jadhav (amjadhav@umd.edu)
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Data Class Definition
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "../include/Data.hpp"
#include "../include/Detect.hpp"
#include <opencv2/opencv.hpp>

/**
 * @brief Construct a new Data:: Data object
 */
Data::Data() {}

/**
 * @brief to take the camera frames as input
 * @param camMode: Camera mode to view the camera or not
 */
int Data::getCamera(int mode) {
    cv::VideoCapture cap(mode);
    if (cap.isOpened() == false) {
      std::cout << "Camera cannot be opened! " << std::endl;
      std::cin.get();
      return -1;
    } else {
        while (true) {
            cap >> frame;
            resizedFrame = preProcessing(frame);
            human_detector.detectHuman(resizedFrame);
            human_detector.putBox(resizedFrame);
            cv::imshow("Detected Humans", resizedFrame);
            cv::waitKey(1);
            char q = static_cast<char> (cv::waitKey(25));
            if (q == 27) {
              break;
            }
        }
    }
}

/**
 * @brief to take frames from a video file as input frames
 * @param filePath path to the video file
 */
int Data::loadVideo(std::string filePath) {
  cv::VideoCapture cap(filePath);
    if (cap.isOpened() == false) {
      std::cout << "Video File cannot be opened! " << std::endl;
      std::cin.get();
      break;
    } else {
        while (true) {
          cap >> frame;
          resizedFrame = preProcessing(frame);
          human_detector.detectHuman(resizedFrame);
          human_detector.putBox(resizedFrame);
          cv::imshow("Detected Humans", resizedFrame);
          cv::waitKey(1);
          char q = static_cast<char> (cv::waitKey(25));
          if (q == 27) {
            break;
          }
        }
    }
}

/**
 * @brief to resize and filter input images to operate on
 */
cv::Mat Data::preProcessing(const cv::Mat &frame) {
  frame_copy = frame.clone();
  int row, col;
  cv::resize(frame_copy, resizedFrame, cv::Size(frame_copy.cols*2, frame_copy.rows*2));
  row = resizedFrame.rows;
  col = resizedFrame.cols;
  return resizedFrame;
}

/**
 * @brief Destroy the Data:: Data object
 */
Data::~Data() {}
