import mod_conversion
import sys

def main():
    s=float(input("Enter start value = "))
    e=float(input("Enter start value = "))
    g=float(input("Enter start value = "))
    ch=input("Enter a character = ")
    if ch=='s':
        mod_conversion.in2cm_table(s,e,g)
    else:
        mod_conversion.in2cm_table_html(s,e,g)
main()