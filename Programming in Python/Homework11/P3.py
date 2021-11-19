# creating a class to raise error
class FormulaError(Exception): pass
 
 
# defining a function
def maths(ab):
 
    sign = ["+","-"]
    # looking at the length of input
    if len(ab) != 3:
        # raising an error
        raise FormulaError("Formula Error: Input doesn't consist of 3 element")
    # looking if the sign is + or -
    elif ab[1] not in sign:
        raise FormulaError("Formula Error: Only + or - is allowed")
 
    else:
        # trying to convert to float
        try:
            num1 = float(ab[0])
            num2 = float(ab[2])
            if ab[1] == "+":
                return num1 + num2
            else:
                return num1 - num2
        # raising an error as value error
        except ValueError as ess:
            raise FormulaError(ess)
 
 
i = 1
 
while i:
    # asking for the input
    formula = input("Enter num '+'/'-' num: ")
    b = formula.split()
    # try and exception to carry out the operation
    try:
        print(formula, "=", maths(b))
    except FormulaError as err:
        print(err)
 
    prompt = input("Type 'quit' if you want to exit: ")
    if prompt.lower() == "quit":
        i = 0
        print("Thank you")
    