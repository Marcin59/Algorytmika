
class Object(Sprite):
    def __init__(self):
        self.color = Color()
        self.position = Vector()
        self.image = 0
        self.size = 10

class Pen(Sprite):
    def __init__(self):
        self.position = Vector()
        self.image = 0
        self.pen.color = Color()
        self.pen.on = False

for elem in input:
    data = elem.split()
    print()