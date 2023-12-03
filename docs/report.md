# Table of Contents
* Abstract
* [Introduction](#1-introduction)
* [Related Work](#2-related-work)
* [Technical Approach](#3-technical-approach)
* [Evaluation and Results](#4-evaluation-and-results)
* [Discussion and Conclusions](#5-discussion-and-conclusions)
* [References](#6-references)

# Abstract

Computing the angles of tilt for a device serves various purposes in the realms of human motion tracking and virtual reality. Conventional approaches involve integrating data from accelerometers, magnetometers, and gyroscopes to fuse sensor information. Nonetheless, gyroscopes are more demanding in terms of power consumption and cost when compared to the aforementioned sensors. In this project,I employed a machine learning approach on Arduino Nano 33 BLE Rev2 to attain accurate inclination estimation, leveraging data from accelerometers, magnetometers, and a limited number of gyroscope samples. 

# 1. Introduction

This section should cover the following items:

* Motivation & Objective

An Inertial Measurement Unit (IMU) is important for various applications, particulary in the fields of robotics, virtual reality and wearable technology. IMUs play a crucial role in providing valuable information about motion sensing. However, gyroscopes are more expensive and power hungry compared to accelerometers and magnetometers. In IoT, power consumption is a critical concern and the project aims to reduce power consumption by using alternative sensors to mimic a gyro's functionality to make IoT devices more energy-efficient. Machine learning method is used for accurate inclination estimation based on accelerometers and magnetometers and limited number of gyro samples.

* State of the Art & Its Limitations

Accelerameters and magnetometers based gyroscope emulation is studied for a long time while all of the algorithms are based on mathematical derivation and physical modeling,which requires the data is highly accurate and noise free, especially for magnetometers. Hard-iron offset elimination is proposed for tilt-compensation but the algorithm is still not robust for accurate inclination estimation.

* Novelty & Rationale

In this undertaking, I introduced a machine learning approach aimed at estimating inclination angles by utilizing accelerometers, magnetometers, and a limited set of gyroscope data. It has been demonstrated that accelerometers and magnetometers possess the capability to reconstruct gyroscope information, and a small set of gyroscope samples contributes to the overall robustness of the emulation process. When compared to model-based techniques, machine learning exhibits enhanced accuracy and resilience to noise. Similar works have done in other areas, such as computer vision, using key frames to recontruct higher resolution pictures give low resolution input.

* Potential Impact

For practical situations, this project offers a sulution to achive highly-accurate inclination estimation with low power consumption due to limited gyro's samples. It can be used in motion sensing, robotics, virtual reality and wearale devices and extend the life of IoT devices.

* Challenges

Data collection is really important in this project. There is no suitable dataset online to train the machine learning model to reconstruct gyroscopes. I need to collect the data using Arduino Nano 33 Sense Rev2. The data collected will be noisy and suffer from drift and the environment, which means calibration is required and the quality of the calibration directly inference the traning result. Another challenge is the machine learning model design and the computation time is cruicial in a real-time system for inclination estimation. The machine learning model should be carefully design to make sure to find the balance between the estimation accuracy and the computation time.

* Requirements for Success

In order to perform the project, a reliable data set is required for the training phase due to there is no suitable public data set online. I have to collect the data using Arduino Nano 33 Sense Rev2 after clibration. Also a great understand of physical model is required to better design the neural network.

For skills required for this project, the core skill is to design a neural network that can achieve accurate inclination estimation with low computational complexity. Also implementing the machine learning model using Arduino Nano 33 Sense Rev2 and run the model in real-time is required.

* Metrics of Success

In this project, the metrics of success are based on inclination estimation accuracy. The angles of inclination fusing accelerometers, magnerometers and gyroscopes can be treated as groud truth. Estimated inclination can be obtained using machine learning model. We can determine whether an accurate estimation is made based on mean absolute error and the computation time required for the estimation.


# 2. Related Work

# 3. Technical Approach

# 4. Evaluation and Results

# 5. Discussion and Conclusions

# 6. References
