from lab_python_oop.rectangle import Rectangle

class Square(Rectangle):
    FIGURE_TYPE = "Square"

    def __init__(self, side, color):
        super().__init__(side, side, color)

    def __repr__(self):
        return 'type: {} color: {} side: {} area: {}'.format(
            self.FIGURE_TYPE,
            self.color.color,
            self.width,
            self.area()
        )

