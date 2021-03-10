function [ myhandles ] = make_spaceship(trf_root, transparency)
% Makes a space-ship with the root transform as the given transform.
% The surfaces are drawn with the given transparency in [0,1]
% A vector of handles to all the surfaces is returned.

ship_dish_profile= 2*sin(linspace(0, pi, 15));
[Xc, Yc, Zc]= cylinder(ship_dish_profile);

% Top dish
trf_top_root= hgtransform('Parent', trf_root);
set(trf_top_root, 'Matrix', makehgtform('translate', [0, 0, -0.2]));
color_top= [0.2, 0.5, 0.2];
myhandles(1)= surface(Xc, Yc, Zc, 'Parent', trf_top_root, 'FaceColor', color_top, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_top, 'EdgeAlpha', transparency);

% Bottom dish
trf_bottom_root= hgtransform('Parent', trf_root);
set(trf_bottom_root, 'Matrix', makehgtform('translate', [0, 0, 0.2]));
color_bottom= [0.6, 0.1, 0.5];
myhandles(2)= surface(Xc, Yc, Zc, 'Parent', trf_bottom_root, 'FaceColor', color_bottom, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_bottom, 'EdgeAlpha', transparency);

% creates x, y, z coordinates of unit cylinder to draw left tail
[Xt, Yt, Zt]= cylinder([0.4 , 0.3 , 0]);


% Left tail
trf_tailleft_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [1,1,3]);
trf_Ry= makehgtform('yrotate', -pi/2);
trf_T= makehgtform('translate', [-1.5, -0.5, -0.1]);

% Interpret the order as BFT (left to right)
set(trf_tailleft_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color_tail_left= [0.6 0.1 0.5]; 
myhandles(3)= surface(Xt, Yt, Zt, 'Parent', trf_tailleft_root, 'FaceColor', color_tail_left, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_tail_left, 'EdgeAlpha', transparency);

% Your code here. Use left tail as a reference and design spaceship as
% shown in the class. You can come up with a new design.

[X2, Y2, Z2]= cylinder([0.4 , 0.3 , 0]);

% Right tail
trf_tailright_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [1,1,3]);
trf_Ry= makehgtform('yrotate', -pi/2);
trf_T= makehgtform('translate', [-1.5, 0.8, -0.1]);

% Interpret the order as BFT (left to right)
set(trf_tailright_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color_tail_right= [0.2 0.5 0.2]; 
myhandles(4)= surface(X2, Y2, Z2, 'Parent', trf_tailright_root, 'FaceColor', color_tail_right, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_tail_right, 'EdgeAlpha', transparency);

[X2, Y2, Z2]= cylinder([0 , 0 , 0.8]);

% Right head
trf_headright_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [0.3,0.3,2]);
trf_Ry= makehgtform('yrotate', pi/2);
trf_T= makehgtform('translate', [0, 0.5, 0.8]);

% Interpret the order as BFT (left to right)
set(trf_headright_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color_head_right= [0 0 0]; 
myhandles(4)= surface(X2, Y2, Z2, 'Parent', trf_headright_root, 'FaceColor', color_head_right, 'FaceAlpha', transparency, 'EdgeColor', 1*color_head_right, 'EdgeAlpha', transparency);


% Left head
trf_headleft_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [0.3,0.3,2]);
trf_Ry= makehgtform('yrotate', pi/2);
trf_T= makehgtform('translate', [0, -0.5, 0.8]);

% Interpret the order as BFT (left to right)
set(trf_headleft_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color_head_left= [0 0 0]; 
myhandles(4)= surface(X2, Y2, Z2, 'Parent', trf_headleft_root, 'FaceColor', color_head_left, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_head_left, 'EdgeAlpha', transparency);

[X2, Y2, Z2]= cylinder([0.4 , 0.3 , 0]);

% Connector left
trf_connectorleft_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [0.8,0.8,2]);
trf_Ry= makehgtform('yrotate', -pi/4);
trf_T= makehgtform('translate', [-2.5, 0.8, 0.05]);

% Interpret the order as BFT (left to right)
set(trf_connectorleft_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color_connector_left= [0.6 0.1 0.5]; 
myhandles(4)= surface(X2, Y2, Z2, 'Parent', trf_connectorleft_root, 'FaceColor', color_connector_left, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_connector_left, 'EdgeAlpha', transparency);


% Connector Right
trf_connectorright_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [0.8,0.8,2]);
trf_Ry= makehgtform('yrotate', -pi/4);
trf_T= makehgtform('translate', [-2.5, -0.5, 0.05]);

% Interpret the order as BFT (left to right)
set(trf_connectorright_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color_connector_right= [0.2 0.5 0.2]; 
myhandles(4)= surface(X2, Y2, Z2, 'Parent', trf_connectorright_root, 'FaceColor', color_connector_right, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_connector_right, 'EdgeAlpha', transparency);

% Booster Right
trf_boosterright_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [0.8,0.8,2]);
trf_Ry= makehgtform('yrotate', -pi/2);
trf_T= makehgtform('translate', [-3, -0.5, 1.5]);

% Interpret the order as BFT (left to right)
set(trf_boosterright_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color_booster_right= [0.6 0.1 0.5]; 
myhandles(4)= surface(X2, Y2, Z2, 'Parent', trf_boosterright_root, 'FaceColor', color_booster_right, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_booster_right, 'EdgeAlpha', transparency);


% Booster Left
trf_boosterleft_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [0.8,0.8,2]);
trf_Ry= makehgtform('yrotate', -pi/2);
trf_T= makehgtform('translate', [-3, 0.8, 1.5]);

% Interpret the order as BFT (left to right)
set(trf_boosterleft_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color_booster_left= [0.2 0.5 0.2]; 
myhandles(4)= surface(X2, Y2, Z2, 'Parent', trf_boosterleft_root, 'FaceColor', color_booster_left, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_booster_left, 'EdgeAlpha', transparency);

[X2, Y2, Z2]= sphere;

% Exhaust Left 
trf_exhaustleft_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [0.3,0.3,0.3]);
trf_Ry= makehgtform('yrotate', -pi/2);
trf_T= makehgtform('translate', [-3, -0.5, 1.5]);

% Interpret the order as BFT (left to right)
set(trf_exhaustleft_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color_exhaust_left= [1 1 0]; 
myhandles(4)= surface(X2, Y2, Z2, 'Parent', trf_exhaustleft_root, 'FaceColor', color_exhaust_left, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_exhaust_left, 'EdgeAlpha', transparency);


% Exhaust Right 
trf_exhaustright_root= hgtransform('Parent', trf_root);
trf_scale= makehgtform('scale', [0.3,0.3,0.3]);
trf_Ry= makehgtform('yrotate', -pi/2);
trf_T= makehgtform('translate', [-3, 0.8, 1.5]);

% Interpret the order as BFT (left to right)
set(trf_exhaustright_root, 'Matrix', trf_T*trf_Ry*trf_scale);
color_exhaust_right= [1 1 0]; 
myhandles(4)= surface(X2, Y2, Z2, 'Parent', trf_exhaustright_root, 'FaceColor', color_exhaust_right, 'FaceAlpha', transparency, 'EdgeColor', 0.5*color_exhaust_right, 'EdgeAlpha', transparency);
end





