function [ h, trf_viz_link ] = link_cylinder(radius, length, trf_viz_link, facecolor, edgecolor, transparency)
% Draws an z-axis-aligned centered cylinder in the visualization (viz) frame
% with the given radius and length.
% trf_viz_link is the transform of the viz-frame w.r.t. the actual link-frame.
% It is passed back out since it could have been created by a
% make_transform in the input arguments list while calling this function.
% If trf_viz_link is not passed in it is passed back as an identity
% transform.

hgrp= hggroup;

[Xc, Yc, Zc]= cylinder(radius);
Zc = Zc*length; % Scale unit-length to the given length.
Zc = Zc - length/2; 
% Move the cylinder down so that its center is aligned with 
% the origin of frame viz.

h= surface(Xc, Yc, Zc);

if (nargin < 3)
    trf_viz_link= hgtransform;
end
if (nargin < 4)
   facecolor= [0.9, 0.1, 0.1]; % default
end;
if (nargin < 5)
    edgecolor= 0.5*facecolor; % default
end;
if (nargin < 6)
    transparency= 0.3; % default
end;

set(h, 'Parent', hgrp);
set(h, 'FaceColor', facecolor);
set(h, 'EdgeColor', edgecolor);
set(h, 'FaceAlpha', transparency, 'EdgeAlpha', transparency);
make_child(trf_viz_link, hgrp);
drawnow;

end

