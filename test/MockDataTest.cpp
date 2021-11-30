/**
 * MIT License

 * Copyright (c) 2021 Abhishek Nalawade

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

/**
 * @file MockDistance.hpp
 * @author Abhishek Nalawade (abhi1793@umd.edu)
 * @brief Mock Distance Class Declaration
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright Copyright (c) 2021
 *
 */

 #include <Eigen/Dense>
 #include <gtest/gtest.h>
 #include <gmock/gmock.h>
 #include <string>
 #include "../include/MockData.hpp"
 #include <opencv2/opencv.hpp>

TEST(CheckFile, FileExists) {
  MockData video = new MockData();
  // std::string filePath = "../67.webm";
  // std::string test = "OFF";
  // EXPECT_EQ(video.loadVideo(filePath, test), 3);

}
