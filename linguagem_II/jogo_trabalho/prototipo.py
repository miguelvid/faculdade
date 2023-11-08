import pyxel
import random

pyxel.init(160, 120)

positions = [40 + 3.8, 66.6 + 3.8, 92.6 + 3.8]

x = random.choice(positions)
second_rectangle_x = 66.6 + 3.8
second_rectangle_y = 95
game_over = False
movement_delay = 1.5
movement_timer = 0

obstacles = []

def create_obstacle():
    x = random.choice(positions)
    obstacle = {'x': x, 'y': 0}
    obstacles.append(obstacle)

def update():
    global second_rectangle_x, game_over, movement_timer,second_rectangle_y

    if pyxel.btnp(pyxel.KEY_Q):
        pyxel.quit()
    if pyxel.btnp(pyxel.KEY_0):
        game_over = True
    if not game_over:
        if pyxel.frame_count - movement_timer >= movement_delay:
            if pyxel.btn(pyxel.KEY_LEFT):
                if second_rectangle_x == 66.6 + 3.8:
                    second_rectangle_x = 40 + 3.8
                if second_rectangle_x == 92.6 + 3.8:
                    second_rectangle_x = 66.6 + 3.8
            if pyxel.btn(pyxel.KEY_RIGHT):
                if second_rectangle_x == 66.6 + 3.8:
                    second_rectangle_x = 92.6 + 3.8
                if second_rectangle_x == 40 + 3.8:
                    second_rectangle_x = 66.6 + 3.8
            movement_timer = pyxel.frame_count

        for obstacle in obstacles:
            obstacle['y'] += 4
            if obstacle['y'] > 120:
                obstacles.remove(obstacle)

        # Crie novos obstáculos com uma certa probabilidade
        if random.random() < 0.03 and len(obstacles) < 2:  # Ajuste a probabilidade e o limite de obstáculos
            create_obstacle()

def draw():
    pyxel.cls(0)
    second_rectangle_y = 95
    pyxel.rect(40, 0, 26.6, 120, 11)
    pyxel.rect(66.6, 0, 26.6, 120, 12)
    pyxel.rect(92.6, 0, 26.6, 120, 13)
    pyxel.rect(second_rectangle_x, second_rectangle_y, 20, 30, 14)
    for obstacle in obstacles:
        pyxel.rect(obstacle['x'], obstacle['y'], 20, 30, 15)

    if game_over:
        pyxel.text(60, 50, "Game Over", 8)

create_obstacle()  # Crie o primeiro obstáculo

pyxel.run(update, draw)
