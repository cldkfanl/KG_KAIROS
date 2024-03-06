from turtle import *

t1 = Turtle()
t2 = Turtle()
t3 = Turtle()
t4 = Turtle()

def dStart(turtle, x, y):
    turtle.pensize(5)
    turtle.speed(15)
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()

def dFlower(turtle):
    turtle.fillcolor('yellow')
    turtle.begin_fill()
    for i in range(6):
        turtle.circle(50)
        turtle.left(60)
        turtle.circle(50)
        turtle.left(60)
        turtle.circle(50)
        turtle.left(60)
    turtle.end_fill()

def fFlower(turtle, x, y, color):
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()
    turtle.fillcolor(color)
    turtle.begin_fill()
    turtle.circle(50)
    turtle.end_fill()

def stick(turtle, x, y):
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()
    turtle.goto(x, y - 100)

dStart(t1, -200, 200)
dStart(t2, 0, 200)
dStart(t3, 200, 200)
dStart(t4, -250, 0)

dFlower(t1)
dFlower(t2)
dFlower(t3)

fFlower(t1, -200, 150, 'blue')
fFlower(t2, 0, 150, 'red')
fFlower(t3, 200, 150, 'green')

stick(t1, -200, 100)
stick(t2, 0, 100)
stick(t3, 200, 100)

t4.fillcolor('brown')
t4.begin_fill()
for i in range(4):
    t4.forward(500)
    t4.right(90)
t4.end_fill()










