import pyxel
import random

pyxel.init(160, 120)

# Lista para armazenar informações dos retângulos
rectangles = []

for _ in range(5):  # Adiciona 5 retângulos
    x = random.randint(0, 150)
    y = random.randint(0, 120)
    rectangles.append({'x': x, 'y': y})

second_rectangle_x = 75
second_rectangle_y = 95
game_over = False

def update():
    global second_rectangle_x, game_over

    if pyxel.btnp(pyxel.KEY_Q):
        pyxel.quit()

    if not game_over:
        if pyxel.btn(pyxel.KEY_LEFT):
            second_rectangle_x -= 4
        if pyxel.btn(pyxel.KEY_RIGHT):
            second_rectangle_x += 4

        # Atualiza a posição dos retângulos que vêm de cima
        for rectangle in rectangles:
            rectangle['y'] += 4

            # Verifica a colisão entre o segundo retângulo e os retângulos que vêm de cima
            if (second_rectangle_x < rectangle['x'] + 10 and second_rectangle_x + 10 > rectangle['x']) and (second_rectangle_y < rectangle['y'] + 20 and second_rectangle_y + 20 > rectangle['y']):
                game_over = True

def draw():
    pyxel.cls(0)

    # Desenha os retângulos que vêm de cima
    for rectangle in rectangles:
        pyxel.rect(rectangle['x'], rectangle['y'], 10, 20, 11)

    # Desenha o segundo retângulo
    pyxel.rect(second_rectangle_x, second_rectangle_y, 10, 20, 14)

    if game_over:
        pyxel.text(60, 50, "Game Over", 8)

pyxel.run(update, draw)
