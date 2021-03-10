function [ trf_B_A ] = make_transform_prismatic( axis_A, movement_along_axis, parent )
% This is a convenience function to create a homogeneous transform of 
% frame-B (left subscript) w.r.t. frame-A (left superscript) given the
% translation axis in frame-A and the translation amount in length-units.
% parent is the transform or the axis which should be the parent of this
% transform.
trf_B_A= hgtransform;

trf= makehgtform; % identity transform
trf(1:3, 1:3)= eye(3);
trf(1:3, 4)= axis_A*movement_along_axis;
set(trf_B_A, 'Matrix', trf);

if (nargin >= 3)
    make_child(parent, trf_B_A);
    % set(trf_B_A, 'Parent', parent);
end

end