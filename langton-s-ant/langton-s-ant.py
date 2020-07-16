import turtle

#Function to update the step recorder 
def update_maps(graph, turtle, color):
    graph[turtle_pos(turtle)] = color
    return None

#Returns the position of the ant
def turtle_pos(turtle):
    return (round(turtle.xcor()), round(turtle.ycor()))

#The Primary function that colours the tiles on the Screen
def langton_move(turtle, pos, maps, step):
    if pos not in maps or maps[pos] == "white":
        turtle.fillcolor("black")
        turtle.stamp()
        update_maps(maps, turtle, "black")
        turtle.right(90)
        turtle.forward(step)
        pos = turtle_pos(turtle)
    elif maps[pos] == "black":
        turtle.fillcolor("white")
        update_maps(maps, turtle, "white")
        turtle.stamp()
        turtle.left(90)
        turtle.forward(step)
        pos = turtle_pos(turtle)
    return pos



#Steps Recorder to recall if the tile is coloured 'white' or 'black'
maps = {}

# Initialize Screen
screen = turtle.Screen()

# Initialize Langton's Ant
Lant = turtle.Turtle()
Lant.shape('square')
Lant.shapesize(0.5)
Lant.penup()
Lant.speed(0)
Lant.right(180)
pos = turtle_pos(Lant)

moves = 0
while True:
    pos = langton_move(Lant, pos, maps, 11)
    moves += 1
    print ("Steps:", moves)


