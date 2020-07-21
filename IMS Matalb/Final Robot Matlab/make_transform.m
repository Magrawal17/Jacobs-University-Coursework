function [ trf_B_A ] = make_transform( translation_B_A, roll, pitch, yaw, parent )
% This is a convenience function to create a homogeneous transform of 
% frame-B (left subscript) w.r.t. frame-A (left superscript) given the
% translation_B_A and the rotation R_B_A as roll, pitch, yaw in radians.
% parent is the transform or the axis which should be the parent of this
% transform.
trf_B_A= hgtransform;

trf= makehgtform; % identity transform
trf(1:3, 1:3)= RPY2DCM( roll, pitch, yaw );
trf(1:3, 4)= [translation_B_A(1); translation_B_A(2); translation_B_A(3)];
set(trf_B_A, 'Matrix', trf);

if (nargin >= 5)
    make_child(parent, trf_B_A);
    % set(trf_B_A, 'Parent', parent);
end

end

