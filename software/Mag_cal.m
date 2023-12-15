clear
close all
IMU_data = csvread("monitor_to_csv/training_data.csv",1,0);
Magx = IMU_data(:,4);
Magy = IMU_data(:,5);
Magz = IMU_data(:,6);
D = [Magx(:),Magy(:),Magz(:)];
[A,b,expmfs] = magcal(D);
C = (D-b)*A;

figure(1)
plot3(Magx(:),Magy(:),Magz(:),"LineStyle","none","Marker","X","MarkerSize",1)
hold on
grid(gca,"on")
plot3(C(:,1),C(:,2),C(:,3),"LineStyle","none","Marker","o", ...
      "MarkerSize",1,"MarkerFaceColor","r")
axis equal
xlabel("uT")
ylabel("uT")
zlabel("uT")
legend("Uncalibrated Samples","Calibrated Samples","Location","southoutside")
title("Uncalibrated vs Calibrated" + newline + "Magnetometer Measurements")
hold off

mean(abs(C-D))