import sys
#print(sys.path)
sys.path.append('/Users/serega/PycharmProjects/lab3')

import numpy as np
from lab_python_oop.rectangle import Rectangle
from lab_python_oop.circle import Circle
from lab_python_oop.square import Square

def main():
    rectangle = Rectangle(5, 10, "blue")
    circle = Circle(5, "green")
    square = Square(5, "red")

    print(rectangle)
    print(circle)
    print(square)

    print(np.version.version)

if __name__ == "__main__":
    main()


