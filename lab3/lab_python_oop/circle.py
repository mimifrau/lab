import math
from lab_python_oop.geometry import Geometry
from lab_python_oop.color import Color

class Circle(Geometry):
    FIGURE_TYPE = "Circle"

    def __init__(self, radius, color):
        self.radius = radius
        self.color = Color(color)

    def area(self):
        return math.pi * self.radius ** 2

    def __repr__(self):
        return 'type: {} color: {} radius: {} area: {}'.format(
            self.FIGURE_TYPE,
            self.color.color,
            self.radius,
            self.area()
        )
