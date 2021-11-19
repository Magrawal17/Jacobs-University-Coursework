# creating a class
class Vehicle(object):
    # initialzing it
    def __init__(self, name, max_speed, mileage):
        self._name = name
        self._maxspeed = max_speed
        self._mileage = mileage
    # returning the string
    def __str__(self):
        return "Maximum speed = " + str(self._maxspeed) + \
               " and Mileage = " + str(self._mileage) + " of " + self._name
 
# creating a child class of Vehicle parent class
class Bus(Vehicle):
    # initializing
    def __init__(self, name, max_speed, mileage):
        Vehicle.__init__(self, name, max_speed, mileage)
        self._acceptedname = "BUS"
 
    def __str__(self):
        if self._name.upper() == self._acceptedname:
            return "Bus with maximum speed: " + str(self._maxspeed) + \
                   " and Mileage: " + str(self._mileage)
        else:
            return "Input is not Bus"
 
 
# creating vehicle object
v1 = Vehicle("Car", 110, 50)
v2 = Vehicle("Jeep", 115, 60)
 
# printing the objects
print(v1)
print(v2)
 
# creating bus object
B1 = Bus("Bus", 95, 50)
B2 = Bus("Car", 110, 50)
 
# printing the object
print(B1)
print(B2)