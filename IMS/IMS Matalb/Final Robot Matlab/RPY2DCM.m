function R = RPY2DCM( roll, pitch, yaw )
% Angles given in radians
R_roll=  Rodrigues([1, 0, 0]', roll);
R_pitch= Rodrigues([0, 1, 0]', pitch);
R_yaw= Rodrigues([0, 0, 1]', yaw);
R= R_yaw*R_pitch*R_roll;
end

