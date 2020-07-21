function [C,vn]= crosspr(v, normalize)
% This function returns the cross-product matrix 
% v is the input vector
% if normalize is true, v is normalized before
% computing the matrix
% C is the output matrix
% If vn is needed, it is set to the norm of v.
a= norm(v);
if (nargin == 2)
    if normalize
        v= v./a;
    end
end
        
% C= zeros(3,3);
% C(3,2)= v(1); C(2,3)= -v(1);
% C(1,3)= v(2); C(3,1)= -v(2);
% C(2,1)= v(3); C(1,2)= -v(3);

C= [0, -v(3), v(2); ...
    v(3), 0, -v(1); ...
    -v(2), v(1), 0];

if nargout==2
    vn= a;
end