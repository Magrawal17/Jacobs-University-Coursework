function [ h, trf_viz_link ] = link_sphere( radius, trf_viz_link, facecolor, edgecolor, transparency )
% Draws a sphere of the given radius in the visualization (viz) frame.
% trf_viz_link is the transform of the viz-frame w.r.t. the actual link-frame.
% It is passed back out since it could have been created by a
% make_transform in the input arguments list while calling this function.
% If trf_viz_link is not passed in, it is passed back as an identity
% transform.

hgrp= hggroup;

[Xc, Yc, Zc]= sphere();
Xc= Xc*radius;
Yc= Yc*radius;
Zc= Zc*radius;

h= surface(Xc, Yc, Zc);

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

