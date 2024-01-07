from lab_python_oop.geometry import Geometry
from lab_python_oop.color import Color

class Rectangle(Geometry):
    FIGURE_TYPE = "Rectangle"

    def __init__(self, width, height, color):
        self.width = width
        self.height = height
        self.color = Color(color)

    def area(self):
        return self.width * self.height

    def __repr__(self):
        return 'type: {} color: {} width: {} height: {} area: {}'.format(
            self.FIGURE_TYPE,
            self.color.color,
            self.width,
            self.height,
            self.area()
        )
