clear all
close all
clf
handle_axes= axes('XLim', [-0.4,0.4], 'YLim', [-0.2,0.4], 'ZLim', [0,0.4]);

xlabel('e_1'); 
ylabel('e_2');
zlabel('e_3');

view(-130, 26);
grid on;
axis equal
camlight
axis_length= 0.05;

%% Root frame E
trf_E_axes= hgtransform('Parent', handle_axes); 
% The root-link transform should be created as a child of the axes from the
% beginning to avoid the error "Cannot set property to a deleted object".
% E is synonymous with the axes, so there is no need for plot_axes(trf_E_axes, 'E');
%% Link-0: Base Orange Cylinder

trf_link0_E= make_transform([0, 0, 0], 0, 0, pi/2, trf_E_axes);
%plot_axes(trf_link0_E, 'L_0', false, axis_length); 

trf_viz_link0= make_transform([0, 0, 0.1], 0, 0, 0, trf_link0_E);
length0= 0.3; radius0= 0.05;
h(1)= link_cylinder(radius0, length0, trf_viz_link0, [0.823529 0.411765 0.117647]); 
%plot_axes(trf_viz_link0, ' ', true, axis_length); % V_0
%% Blue Box
trf_viz_link1p2= make_transform([0.1, 0, 0], 0, 0, 0); % Do not specify parent yet: It will be done in the joint
h(3)= link_box([0.2, 0.02, 0.04], trf_viz_link1p2, [0, 0, 1]); 
%plot_axes(trf_viz_link1p2, ' ', true, axis_length); % V_{1-2}
%% Rotating Black Cylinder
trf_viz_link1= make_transform([0, 0, 0], 0, 0, 0); % Do not specify parent yet: It will be done in the joint
length1= 0.05; radius1= 0.04;
h(2)= link_cylinder(radius1, length1, trf_viz_link1, [0, 0, 0]); 
% V_1 and L_1 are the same.
%% Orange Cylinder
trf_viz_link2p2= make_transform([0, -0.05, 0], pi/2, 0, 0); % Do not specify parent yet: It will be done in the joint
h(6)= link_cylinder(0.015, 0.1, trf_viz_link2p2, [1, 0.54902, 0]); 
% plot_axes(trf_viz_link2p2, ' ', true, axis_length); % V_{2-2}

%% Green Cylinder
trf_viz_link3p2= make_transform([0, 0, 0], pi/2, 0, 0); % Do not specify parent yet: It will be done in the joint
h(8)= link_cylinder(0.012, 0.04, trf_viz_link3p2, [0.196078, 0.803922, 0.196078]); 
% plot_axes(trf_viz_link3p2, ' ', true, axis_length); % V_{3-2}
%% Long Gray Tube 
trf_viz_link4= make_transform([0, 0, -0.075], 0, 0, 0); % Do not specify parent yet: It will be done in the joint
h(9)= link_cylinder(0.004, 0.3, trf_viz_link4, [0.482353 0.507843 0.933333]); 
% plot_axes(trf_viz_link4, ' ', true, axis_length); % V_{4}

%% Small Red Sphere
trf_viz_linkEE= make_transform([0, 0, 0.001], 0, 0, 0); % Do not specify parent yet: It will be done in the joint
h(10)= link_sphere(0.005, trf_viz_linkEE, [1, 0, 0]); 
% plot_axes(trf_viz_linkEE, ' ', true, axis_length); % V_{EE}


%% Joint 0: Ornage Cylinder and Blue Box:Fixed
trf_link1p2_link1= make_transform([0.05, 0, 0.17], 0, 0, 0, trf_link0_E); 
plot_axes(trf_link1p2_link1, 'L_0', false, axis_length); 
make_child(trf_link1p2_link1, trf_viz_link1p2);
%% Joint 1: Blue Box and Rotating Black Cylinder:Rotating
j1_rot_axis_j1= [0,0,1]';
j1_rot_angle= pi; % [-pi/2, pi/2]

trf_joint1_link0= make_transform([0.1, 0, 0.01], 0, 0, 0, trf_viz_link1p2); 
trf_link1_joint1= make_transform_revolute(j1_rot_axis_j1, j1_rot_angle, trf_joint1_link0); 
plot_axes(trf_link1_joint1, 'L_1', false, axis_length); 
make_child(trf_link1_joint1, trf_viz_link1);
%% Joint 2: Black Cyclinder and Orange Cylinder: Fixed
trf_link2p2_link2= make_transform([0, 0, 0], 0, 0, 0, trf_link1_joint1); 
plot_axes(trf_link2p2_link2, 'L_2', false, axis_length); 
make_child(trf_link2p2_link2, trf_viz_link2p2);

%% Joint 3: Orange Cylinder and Green Cylinder: Fixed
trf_link3_joint3= make_transform([0, -0.1, 0], pi/2, 0, 0, trf_link2p2_link2);
plot_axes(trf_link3_joint3, 'L_3', false, axis_length); 
make_child(trf_link3_joint3, trf_viz_link3p2);
%% Joint 4: Green Cylinded and Grey Rod: Prismatic
j4_translation_axis_j4= [0,0,1]';
j4_translation= 0; % [-0.04, 0.04]

trf_joint4_link3= make_transform([0, -0.2, 0], pi/2, 0, 0, trf_link3_joint3); 
trf_link4_joint4= make_transform_prismatic(j4_translation_axis_j4, j4_translation, trf_joint4_link3);
plot_axes(trf_link4_joint4, 'L_4', false, axis_length); 
make_child(trf_link4_joint4, trf_viz_link4);

%% Joint: Grey Rod and Small Red Sphere,EE: Fixed
trf_linkEE_link4= make_transform([0, 0, 0], 0, 0, 0, trf_link4_joint4); 
make_child(trf_linkEE_link4, trf_viz_linkEE);

%% Second Part

%% Blue Box
secondarybluebox= make_transform([0.075, 0, -0.055], 0, 0, 0); % Do not specify parent yet: It will be done in the joint
h(3)= link_box([0.2, 0.02, 0.04], secondarybluebox, [0, 0, 1]); 
%plot_axes(secondarybluebox, ' ', true, axis_length); % V_{1-2}

%% Rotating Black Cylinder
Blackcylinder= make_transform([0, 0, 0], 0, 0, 0); % Do not specify parent yet: It will be done in the joint
length1= 0.05; radius1= 0.04;
h(2)= link_cylinder(radius1, length1, Blackcylinder, [0, 0, 0]); 
% V_1 and L_1 are the same.

%% Orange Cylinder
Orangecylinder= make_transform([0, -0.06, 0], pi/2, 0, 0); % Do not specify parent yet: It will be done in the joint
h(6)= link_cylinder(0.015, 0.1, Orangecylinder, [1, 0.54902, 0]); 
% plot_axes(trf_viz_link2p2, ' ', true, axis_length); % V_{2-2}

%% Green Cylinder
Greencylinder= make_transform([0, 0, 0], pi/2, 0, 0); % Do not specify parent yet: It will be done in the joint
h(8)= link_cylinder(0.012, 0.04, Greencylinder, [0.196078, 0.803922, 0.196078]); 
% plot_axes(trf_viz_link3p2, ' ', true, axis_length); % V_{3-2}
%% Long Gray Tube 
Graytube= make_transform([0, 0, -0.075], 0, 0, 0); % Do not specify parent yet: It will be done in the joint
h(9)= link_cylinder(0.004, 0.3, Graytube, [0.482353 0.507843 0.933333]); 
% plot_axes(trf_viz_link4, ' ', true, axis_length); % V_{4}

%% Small Red Sphere
Smallred= make_transform([0, 0, 0.001], 0, 0, 0); % Do not specify parent yet: It will be done in the joint
h(10)= link_sphere(0.005, Smallred, [1, 0, 0]); 
% plot_axes(trf_viz_linkEE, ' ', true, axis_length); % V_{EE}

%% Joint 1: Blue Box and Rotating Black Cylinder:Rotating
j1_rot_axis_j1= [0,0,1]';
j1_rot_angle= pi; % [-pi/2, pi/2]

xyz= make_transform([-0.1, 0, 0], 0, 0, 0, secondarybluebox); 
trf_link1_joint12= make_transform_revolute(j1_rot_axis_j1, j1_rot_angle, xyz); 
plot_axes(trf_link1_joint12, 'L_2', false, axis_length); 
make_child(trf_link1_joint12, Blackcylinder);
%% Joint 2: Black Cyclinder and Orange Cylinder: Fixed
trf_link2p2_link21= make_transform([0, 0.1, 0], 0, 0, 0, trf_link1_joint12);
%lot_axes(trf_link2p2_link21, 'L_2', false, axis_length); 
make_child(trf_link2p2_link21, Orangecylinder);
%% Joint 0: Ornage Cylinder and Blue Box:Fixed
trf_link1p2_link2= make_transform([-0.225, 0, 0.225], 0, 0, 0, trf_link0_E); 
make_child(trf_link1p2_link2, secondarybluebox);%% Joint 3: Orange Cylinder and Green Cylinder: Fixed
trf_link3_joint31= make_transform([0, 0.01, 0], pi/2, 0, 0, trf_link2p2_link21);
plot_axes(trf_link3_joint31, 'L_3', false, axis_length); 
make_child(trf_link3_joint31, Greencylinder);
%% Joint 4: Green Cylinded and Grey Rod: Prismatic
j4_translation_axis_j4= [0,0,1]';
j4_translation= 0; % [-0.04, 0.04]

trf_joint4_link31= make_transform([0, -0.2, 0], pi/2, 0, 0, trf_link3_joint31); 
trf_link4_joint41= make_transform_prismatic(j4_translation_axis_j4, j4_translation, trf_joint4_link31);
plot_axes(trf_link4_joint41, 'L_4', false, axis_length); 
make_child(trf_link4_joint41, Graytube);

%% Joint: Grey Rod and Small Red Sphere,EE: Fixed
trf_linkEE_link41= make_transform([0, 0, 0], 0, 0, 0, trf_link4_joint41); 
make_child(trf_linkEE_link41, Smallred);

%% Head
Head= make_transform([0.05, 0, 0.07], 0, 0, 0); % Do not specify parent yet: It will be done in the joint
h(3)= link_box([0.2, 0.06, 0.22], Head, [0, 1, 1]); 
%plot_axes(secondarybluebox, ' ', true, axis_length); % V_{1-2}

%% Joint 0: Head and Blue Box:Fixed
Headjoint= make_transform([-0.1, 0, 0.12], 0, 0, 0, trf_link1p2_link1); 
%plot_axes(Headjoint, 'L_0', false, axis_length); 
make_child(Headjoint, Head);



%% Animation: One joint at a time
for q1=[linspace(0, pi, 90) linspace(pi, 0, 90) ]
    set(handle_axes, 'XLim', [-0.2,0.2], 'YLim', [-0.4,0.4], 'ZLim', [-0.15,0.5]);
    trf_q1= makehgtform('axisrotate', j1_rot_axis_j1, q1);
    set(trf_link1_joint1, 'Matrix', trf_q1);
    trf_q11= makehgtform('axisrotate', j1_rot_axis_j1, q1);
    set(trf_link1_joint12, 'Matrix', trf_q11);
    drawnow;
    pause(0.02);
end

for q4=[linspace(0, -0.04, 30), linspace(-0.04, 0.04, 30), linspace(0.04, 0, 30)]
    set(handle_axes, 'XLim', [-0.2,0.2], 'YLim', [-0.4,0.4], 'ZLim', [-0.15,0.5]);
    trf_a4= makehgtform('translate', j4_translation_axis_j4*q4);
    set(trf_link4_joint4, 'Matrix', trf_a4);
    trf_a41= makehgtform('translate', j4_translation_axis_j4*q4);
    set(trf_link4_joint41, 'Matrix', trf_a41);
    drawnow;
    pause(0.02);
end

%% Animation: All joints together.
q_init= 0.5*ones(4,1); % This leads to all joints being at 0.

for i= 1:20
    q_next= rand(4,1); 
    % rand() gives uniformly distributed random numbers in the interval [0,1]
    
    for t=0:0.02:1
        q= q_init + t*(q_next - q_init);
        q1= (pi/2)*(4*q(1) - 1);
        q4= (0.04)*(2*q(4) - 1);
        
     set(handle_axes, 'XLim', [-0.2,0.2], 'YLim', [-0.4,0.4], 'ZLim', [-0.15,0.5]);
    trf_q1= makehgtform('axisrotate', j1_rot_axis_j1, q1);
    set(trf_link1_joint1, 'Matrix', trf_q1);
    trf_q11= makehgtform('axisrotate', j1_rot_axis_j1, q1);
    set(trf_link1_joint12, 'Matrix', trf_q11);
    
     set(handle_axes, 'XLim', [-0.2,0.2], 'YLim', [-0.4,0.4], 'ZLim', [-0.15,0.5]);
    trf_a4= makehgtform('translate', j4_translation_axis_j4*q4);
    set(trf_link4_joint4, 'Matrix', trf_a4);
    trf_a41= makehgtform('translate', j4_translation_axis_j4*q4);
    set(trf_link4_joint41, 'Matrix', trf_a41);
    
        drawnow;
        pause(0.005);
        
    end
    
    q_init= q_next;
    
end




