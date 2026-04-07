class Robot:

    def __init__(self, width: int, height: int):
        self.w = width
        self.h = height
        self.x = 0
        self.y = 0
        self.dir = 0  # 0=East, 1=North, 2=West, 3=South 
        self.cycle = 2 * (width + height) - 4
        self.moved = False

    def step(self, num: int) -> None:
        num %= self.cycle
        if num == 0 and self.moved:
            num = self.cycle

        self.moved = True

        for _ in range(num):
            if self.dir == 0:  # East
                if self.x + 1 < self.w:
                    self.x += 1
                else:
                    self.dir = 1
                    self.y += 1

            elif self.dir == 1:  # North
                if self.y + 1 < self.h:
                    self.y += 1
                else:
                    self.dir = 2
                    self.x -= 1

            elif self.dir == 2:  # West
                if self.x - 1 >= 0:
                    self.x -= 1
                else:
                    self.dir = 3
                    self.y -= 1

            else:  # South
                if self.y - 1 >= 0:
                    self.y -= 1
                else:
                    self.dir = 0
                    self.x += 1

    def getPos(self):
        return [self.x, self.y]

    def getDir(self):
        return ["East", "North", "West", "South"][self.dir]
