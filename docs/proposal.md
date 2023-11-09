# Project Proposal

## 1. Motivation & Objective

An Inertial Measurement Unit (IMU) is important for various applications, particulary in the fields of robotics, virtual reality and wearable technology. IMUs play a crucial role in providing valuable information about motion sensing. However, gyroscopes are more expensive and power hungry compared to accelerometers and magnetometers. In IoT, power consumption is a critical concern and the project aims to reduce power consumption by using alternative sensors to mimic a gyro's functionality to make IoT devices more energy-efficient. Machine learning method is used for accurate inclination estimation based on accelerometers and magnetometers and limited number of gyro samples.

## 2. State of the Art & Its Limitations

Accelerameters and magnetometers based gyroscope emulation is studied for a long time while all of the algorithms are based on mathematical derivation and physical modeling,which requires the data is highly accurate and noise free, especially for magnetometers. Hard-iron offset elimination is proposed for tilt-compensation but the algorithm is still not robust for accurate inclination estimation.

## 3. Novelty & Rationale

In this undertaking, I introduced a machine learning approach aimed at estimating inclination angles by utilizing accelerometers, magnetometers, and a limited set of gyroscope data. It has been demonstrated that accelerometers and magnetometers possess the capability to reconstruct gyroscope information, and a small set of gyroscope samples contributes to the overall robustness of the emulation process. When compared to model-based techniques, machine learning exhibits enhanced accuracy and resilience to noise. Similar works have done in other areas, such as computer vision, using key frames to recontruct higher resolution pictures give low resolution input.

## 4. Potential Impact

For practical situations, this project offers a sulution to achive highly-accurate inclination estimation with low power consumption due to limited gyro's samples. It can be used in motion sensing, robotics, virtual reality and wearale devices and extend the life of IoT devices.

## 5. Challenges

Data collection is really important in this project. There is no suitable dataset online to train the machine learning model to reconstruct gyroscopes. I need to collect the data using Arduino Nano 33 Sense Rev2. The data collected will be noisy and suffer from drift and the environment, which means calibration is required and the quality of the calibration directly inference the traning result. Another challenge is the machine learning model design and the computation time is cruicial in a real-time system for inclination estimation.

## 6. Requirements for Success

In order to perform the project, a reliable data set is required for the training phase due to there is no suitable public data set online. I have to collect the data using Arduino Nano 33 Sense Rev2 after clibration. Also a great understand of physical model is required to better design the neural network.

For skills required for this project, the core skill is to design a neural network that can achieve accurate inclination estimation with low computational complexity. Also implementing the machine learning model using Arduino Nano 33 Sense Rev2 and run the model in real-time is required.

## 7. Metrics of Success

In this project, the metrics of success are based on inclination estimation accuracy. The angles of inclination fusing accelerometers, magnerometers and gyroscopes can be treated as groud truth. Estimated inclination can be obtained using machine learning model. We can determine whether an accurate estimation is made based on mean square error.

## 8. Execution Plan

Key tasks include data collection, neural network design, real-time implementation.

## 9. Related Work

### 9.a. Papers

[1]Bandhav Veluri, Collin Pernu, Ali Saffari, Joshua Smith, Michael Taylor, and Shyamnath Gollakota. 2023. NeuriCam: Key-Frame Video Super-Resolution and Colorization for IoT Cameras. In Proceedings of the 29th Annual International Conference on Mobile Computing and Networking (ACM MobiCom '23). Association for Computing Machinery, New York, NY, USA, Article 26, 1–17. https://doi.org/10.1145/3570361.3592523

### 9.b. Datasets

No public dataset is used.

### 9.c. Software

List softwate that you have identified and plan to use. Provide references (with full citation in the References section below).

## 10. References

List references correspondign to citations in your text above. For papers please include full citation and URL. For datasets and software include name and URL.
