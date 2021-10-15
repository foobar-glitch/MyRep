# coding=utf-8
# This is a sample Python script.

# Press Umschalt+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import time
import turtle

screenWidth = 600
screenHeight = 600


class Screen:
    def __init__(self):
        self.win = turtle.Screen()
        self.win.title("Snake Game")
        self.win.bgcolor("blue")
        self.win.setup(width=screenWidth, height=screenHeight)
        self.win.tracer(0)

    def returnScreen(self):
        return self.win


class Snake:
    def __init__(self):
        self.head = turtle.Turtle()
        self.initHead()
        self.headx = 0
        self.heady = 100

    def initHead(self):
        self.head.speed(0)
        self.head.shape("square")
        self.head.color("black")
        self.head.penup()
        self.head.goto(0, 100)

    def setHead(self, x, y):
        self.headx = x
        self.heady = y

    def update(self):
        self.head.goto(self.headx, self.heady)

    def mvR(self):
        self.headx += 1

    def mvL(self):
        self.headx -= 1
    def mvU(self):
        self.heady += 1
    def mvD(self):
        self.heady -= 1

class Game:
    def __init__(self):
        self.x = 0
        self.y = 0

        self.snake = Snake()
        self.screen = Screen().returnScreen()
        self.direction = "w"

    def setDirRight(self):
        if self.direction != "a":
            self.direction = "d"

    def setDirLeft(self):
        if self.direction != "d":
            self.direction = "a"

    def setDirUp(self):
        if self.direction != "s":
            self.direction = "w"

    def setDirDown(self):
        if self.direction != "w":
            self.direction = "s"

    def move(self):
        if self.direction == "d":
            self.snake.mvR()
        elif self.direction == "a":
            self.snake.mvL()
        elif self.direction == "w":
            self.snake.mvU()
        elif self.direction == "s":
            self.snake.mvD()
        else:
            raise ValueError

    def setpos(self, x, y):
        self.x = x
        self.y = y

    def play(self):
        while True:
            self.screen.update()
            self.screen.listen()

            self.screen.onkey(self.setDirRight, "d")
            self.screen.onkey(self.setDirLeft, "a")
            self.screen.onkey(self.setDirUp, "w")
            self.screen.onkey(self.setDirDown, "s")

            self.move()
            self.snake.update()

            time.sleep(0.01)






g = Game()
g.play()


