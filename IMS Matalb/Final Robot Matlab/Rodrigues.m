function R_B_E= Rodrigues(a_E, alpha, normalize)

if (nargin > 2)
    if normalize
        a= a_E./norm(a_E);
    else
        a= a_E;
    end
else
    a= a_E./norm(a_E); % By default, normalize
end

A= crosspr(a);
R_B_E= eye(3) + sin(alpha)*A + (1-cos(alpha))*(A*A);