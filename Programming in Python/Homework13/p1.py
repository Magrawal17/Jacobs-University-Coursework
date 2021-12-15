import matplotlib.pyplot as plt
import sys

x = list(range(-20,21))
x_3 = []


try:
    f = open("data.dat", "w")
    f.write("x, x^3\n")
    for elem in x:
        cube = elem ** 3
        x_3.append(cube)
        data = str(elem) + ", " + str(cube) + "\n"
        f.write(data)
except:
    sys.exit("Some error happen while reading or converting")


plt.plot(x, x_3)
plt.xlabel("x")
plt.ylabel("x^3")
plt.title("Cubic Function [-20, 20]")
plt.savefig("result.pdf")
plt.show()
