function [ trf_B_A ] = make_transform_revolute( axis_A, angle, parent )
% This is a convenience function to create a homogeneous transform of 
% frame-B (left subscript) w.r.t. frame-A (left superscript) given the
% rotation axis in frame-A and the rotation angle in radians.
% Since it is the rotation-axis, its components in frames A and B are the
% same (lecture slides). So, we could also call it axis_B.
% parent is the transform or the axes-object which should be the parent of this
% transform.
trf_B_A= hgtransform;

trf= makehgtform; % identity transform
trf(1:3, 1:3)= Rodrigues( axis_A, angle );
trf(1:3, 4)= [0; 0; 0];
set(trf_B_A, 'Matrix', trf);

if (nargin >= 3)
    make_child(parent, trf_B_A);
    % set(trf_B_A, 'Parent', parent);
end

end
