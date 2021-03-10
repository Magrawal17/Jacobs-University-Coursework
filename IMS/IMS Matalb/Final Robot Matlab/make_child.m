function make_child(trf_B_A, trf_C_B)
% Makes trf_C_B the child of trf_B_A.
% Both arguments are of hgtransform type.

set(trf_C_B, 'Parent', trf_B_A);

% TODO line from the parent of this transform to it.


end

