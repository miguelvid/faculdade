
import pyxel
import random



pyxel.init(160, 120)

x = random.randint(0, 150)
second_rectangle_x = 75
game_over = False

def update():
    global second_rectangle_x, game_over

    if pyxel.btnp(pyxel.KEY_Q):
        pyxel.quit()

    if not game_over:
    
        if pyxel.btn(pyxel.KEY_LEFT):
            second_rectangle_x -= 2
        
        if pyxel.btn(pyxel.KEY_RIGHT):
            second_rectangle_x += 2

        if (x + 10 > second_rectangle_x and x < second_rectangle_x + 10) and (95 < pyxel.frame_count < 115):
            game_over = True
def draw():
    pyxel.cls(0)
   
    y = pyxel.frame_count
    pyxel.rect(x, y, 10, 20, 11)
    pyxel.rect(second_rectangle_x, 95, 10, 20, 14)
    # pyxel.rect(75, 95, 10, 20, 14)
    
    if game_over:
        pyxel.text(60, 50, "Game Over", 8)
    
pyxel.run(update, draw)