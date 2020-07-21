clear all
close all
clf
handle_axes= axes('XLim', [-4,4], 'YLim', [-4,4], 'ZLim', [-4,4]);
xlabel('e_1');
ylabel('e_2');
zlabel('e_3');

view(3);
grid on;
axis equal
camlight

trf_l0_axes= hgtransform('Parent', handle_axes); 
% The l0-transform should be created as a child of the axes from the
% beginning to avoid the error "Cannot set property to a deleted object".
set(trf_l0_axes, 'Matrix', makehgtform('translate', [1,1,0])); 
plot_axes(trf_l0_axes, 'L_0'); % This will show the frame l0. 

%% Link 1 w.r.t. Link 0
% Make the usual homogeneous transform.
roll= pi/4;
pitch= pi/6;
yaw= pi/2;
translation= [1, 1, 1];
trf_l1_l0= make_transform(translation, roll, pitch, yaw, trf_l0_axes);
plot_axes(trf_l1_l0, 'L_1'); % This will show the frame Link-1. 

%% Link-1
len1= 1;
trf_viz_l1= make_transform([0, 0, len1*0.5], 0, 0, pi/6, trf_l1_l0); 
plot_axes(trf_viz_l1, 'V_1', true); % This will show the frame of the geometric-mesh of link L-1. 
h= link_cylinder(0.5, len1, trf_viz_l1); % This will show the geometric-mesh

%% Link 2 w.r.t. Link 0
trf_l2_l0= hgtransform('Parent', trf_l0_axes);

trf1= makehgtform('translate', translation);
trf2= makehgtform; % identity transform
trf2(1:3, 1:3)= RPY2DCM( roll, pitch, yaw );
trf2(1:3, 4)= [0; 0; 0];

set(trf_l2_l0, 'Matrix', trf2 * trf1); 

plot_axes(trf_l2_l0, 'L_2'); % This will show the frame Link-2. 
%% Link-2
trf_viz_l2= make_transform([0, 0, len1*0.5], 0, 0, pi/6, trf_l2_l0); 
plot_axes(trf_viz_l2, 'V_2', true); % This will show the frame of the geometric-mesh of link L-1. 
h= link_cylinder(0.5, len1, trf_viz_l2); % This will show the geometric-mesh


% Another way to do the same thing as for Link 2.
% %% Link 3 w.r.t. Link 0
% % 
% trf_lt_l0= make_transform([0, 0, 0], roll, pitch, yaw, trf_l0_axes); 
% trf_l3_lt=  make_transform(translation, 0, 0, 0, trf_lt_l0);
% 
% plot_axes(trf_l3_lt, 'L_3'); % This will show the frame Link-2. 
% %% Link-3
% trf_viz_l3= make_transform([0, 0, len1*0.5], 0, 0, pi/6, trf_l3_lt); 
% plot_axes(trf_viz_l3, 'V_3', true); % This will show the frame of the geometric-mesh of link L-1. 
% h= link_cylinder(0.5, len1, trf_viz_l3); % This will show the geometric-mesh

