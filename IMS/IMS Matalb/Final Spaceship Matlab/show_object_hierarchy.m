% Shows the initial and final pose of a space-ship which undergoes
% roll-pitch-yaw and translation.
clear all
clf
handle_axes= axes('XLim', [-10,10], 'YLim', [-10,10], 'ZLim', [-10,10]);
xlabel('e_1');
ylabel('e_2');
zlabel('e_3');

view(3);
grid on;
axis equal
camlight

% Create ship-1
trf_ship1_root= hgtransform('Parent', handle_axes);
%Parent, specified as an Axes, Group, or Transform object.
h_original_ship= make_spaceship(trf_ship1_root, 0.8);


% Create ship-2 translated and rotated w.r.t. ship-1
trf_ship2_ship1= hgtransform('Parent',trf_ship1_root);
h_ship2= make_spaceship(trf_ship2_ship1, 0.8);


roll= pi;
pitch= pi;
yaw= pi;

trf_roll= makehgtform('xrotate', roll);
trf_pitch= makehgtform('yrotate', pitch);
trf_yaw= makehgtform('zrotate', yaw);
trf_rpy= trf_yaw*trf_pitch*trf_roll;

translation= [4,2,2]; % 4,2,2
trf_translate= makehgtform('translate', translation);
trf_final= trf_translate*trf_rpy;
 set(trf_ship2_ship1, 'Matrix', trf_final);
drawnow;


for i=1.0: 0.1: 40
    
     translation= [i,0,0]; % 4,2,2
     trf_translate= makehgtform('translate', translation);
    trf_final= trf_translate*trf_rpy;
    set(trf_ship1_root, 'Matrix', trf_translate);
    drawnow;
end


