function plot_axes(trf_B_A, name_string, frame_B_is_visual_object, axis_length)
% Plots the xyz axes of frame B in RGB of unit length.
% trf_B_A is a hgtransform.
% If frame_B_is_visual_object is true, the colors are made lighter to mark that
% they are the axes of a surface/mesh object.

if (nargin < 3)
    frame_B_is_visual_object= false;
end
if (nargin < 4)
    axis_length= 0.5;
end

if (frame_B_is_visual_object)
    x_color= 'm-';
    y_color= 'y-';
    z_color= 'c-';    
else
    x_color= 'r-';
    y_color= 'g-';
    z_color= 'b-';
end
    
plot3([0, axis_length], [0, 0], [0, 0], x_color, 'LineWidth', 2, 'Parent', trf_B_A);
hold on;
plot3([0, 0], [0, axis_length], [0, 0], y_color, 'LineWidth', 2, 'Parent', trf_B_A);
hold on;
plot3([0, 0], [0, 0], [0, axis_length], z_color, 'LineWidth', 2, 'Parent', trf_B_A);

if (nargin >= 2)
    if numel(name_string) ~= 0
        formatted_name_string= sprintf('  $%s$', name_string);
        name_txt = text('String', formatted_name_string, ...
            'Interpreter', 'latex',...
            'Color','black', 'FontWeight', 'bold', 'FontSize', 14, ...
            'Parent', trf_B_A);
        
        Xtext= 0.3*axis_length; Ytext= 0.3*axis_length; Ztext= 0.3*axis_length;
        set(name_txt,'Position',[Xtext Ytext Ztext],...
            'HorizontalAlignment','left',...
            'VerticalAlignment','middle')
    end
end

end

% Other useful text attributes
%'BackgroundColor', [1 1 0.5], 'LineStyle', 'none', ...  
% sprintf $\\mathcal{F}_{%s}$


