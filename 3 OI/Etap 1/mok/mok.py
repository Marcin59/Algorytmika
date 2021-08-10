class Vessel:
    def __init__(self, capasity):
        self.capasity = capasity
        self.max_capasity = capasity

    def effusion(self):
        self.capasity = 0

    def pour(self, new_vessel):
        if self.capasity > new_vessel.max_capasity - new_vessel.capasity:
            self.capasity -= new_vessel.max_capasitt - new_vessel.capasity
            new_vessel.capasity = new_vessel.max_capasity
        else:
            self.capasity = 0
            new_vessel.capasity = new_vessel.capasity + self.capasity

if __name__ == "__main__":
    pass