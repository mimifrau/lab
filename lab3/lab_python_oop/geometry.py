from abc import ABC, abstractmethod

class Geometry(ABC):
    @abstractmethod
    def area(self):
        pass
