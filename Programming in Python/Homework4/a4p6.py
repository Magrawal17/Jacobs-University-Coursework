
def print_frame_method1(n, m, c):
    total_rows = n
    total_columns = m
    
    for row in range(total_rows):
        # For first and last row
        if row == 0 or row == n-1:
            print(c*total_columns)
        # For all other rows
        else:
            no_space = total_columns - 2
            frame_row = c + (" "*no_space) + c
            print(frame_row)

def print_frame_method2(n, m, c):
    for row in range(n):
        for column in range(m):
            # For first and last row
            if row == 0 or row == n-1:
                print(end=c)
            # For all other rows
            else:
                # For first and last column
                if column == 0 or column == m-1:
                    print(end=c)
                else:
                    print(end=" ")
        print() 

n = int(input("Enter n: "))
m = int(input("Enter m: "))
c = input("Enter char: ")
print_frame_method1(n, m, c)