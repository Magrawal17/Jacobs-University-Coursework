function [ h, trf_viz_link ] = link_box( sides, trf_viz_link, facecolor, edgecolor, transparency )
% Draws an axes-aligned centered box in the visualization (viz) frame.
% sides is a 3-vectors containing the 3 sides of the box.
% trf_viz_link is the transform of the viz-frame w.r.t. the actual link-frame.
% It is passed back out since it could have been created by a
% make_transform in the input arguments list while calling this function.
% If trf_viz_link is not passed in it is passed back as an identity
% transform.

hgrp= hggroup;

ax= sides(1);
ay= sides(2);
az= sides(3);

verts = ([0 0 0;...
    0 ay 0;...
    ax ay 0;...
    ax 0 0;...
    0 0 az;...
    0 ay az;...
    ax ay az;...
    ax 0 az]);
verts= verts - repmat(0.5*[ax, ay, az], 8, 1);

face = [1 2 3 4;5 6 7 8;3 4 8 7;1 2 6 5;2 3 7 6;1 4 8 5];

h = patch('Faces',face,'Vertices',verts);

if (nargin < 2)
    trf_viz_link= hgtransform;
end
if (nargin < 3)
    facecolor= [0.9, 0.1, 0.1]; % default
end;
if (nargin < 4)
    edgecolor= 0.5*facecolor; % default
end;
if (nargin < 5)
    transparency= 0.3; % default
end;

set(h, 'Parent', hgrp);
set(h, 'FaceColor', facecolor);
set(h, 'EdgeColor', edgecolor);
set(h, 'FaceAlpha', transparency, 'EdgeAlpha', transparency);
make_child(trf_viz_link, hgrp);
drawnow;

end

