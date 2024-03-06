from turtle import *

t = Turtle()
screen = Screen()

def f_move():
    t.forward(10)
def b_move():
    t.backward(10)
def l_move():
    t.left(90)
def r_move():
    t.right(90)
def r_move_2():
    t.right(45)
def l_move_2():
    t.left(45)
def clear_T():
    t.clear()
    t.penup()
    t.goto(0,0)
    t.pendown()
def on_click(x, y):
    t.goto(x,y)

size = 3
def thick_turtle():
    global size
    size+=1
    t.pensize(size)
def thin_turtle():
    global size
    if size > 1:
        size-=1
    t.pensize(size)
screen.title("my screen")
screen.listen()
screen.onkeypress(f_move, "Up")
screen.onkeypress(b_move, "Down")
screen.onkeypress(l_move, "Left")
screen.onkeypress(r_move, "Right")
screen.onkeypress(clear_T, "c")
screen.onkeypress(r_move_2, "d")
screen.onkeypress(l_move_2, "a")
screen.onclick(on_click)
screen.onkeypress(t.undo, "u")
screen.onkeypress(thick_turtle, "+")
screen.onkeypress(thin_turtle, "-")
