
import pyxel
import random



pyxel.init(160, 120)

positions = [40 + 3.8, 66.6 + 3.8, 92.6 + 3.8]

x = random.choice(positions)
second_rectangle_x = 66.6 + 3.8
game_over = False  
movement_delay = 1.5
movement_timer = 0

def update():
    global second_rectangle_x, game_over, movement_timer

    if pyxel.btnp(pyxel.KEY_Q):
        pyxel.quit()
    if pyxel.btn(pyxel.KEY_0):
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

def draw():
    pyxel.cls(0)
    #y = pyxel.frame_count * 2
    pyxel.rect(40, 0, 26.6, 120, 11)
    pyxel.rect(66.6, 0, 26.6, 120, 12)
    pyxel.rect(92.6, 0, 26.6, 120, 13)
    #pyxel.rect(x, y, 20, 30, 15)
    pyxel.rect(second_rectangle_x, 95, 20, 30, 14)

def obstaculo():
    y = pyxel.frame_count * 2
    pyxel.rect(x, y, 20, 30, 15)
    
    if game_over:
        pyxel.text(60, 50, "Game Over", 8)
    
  
obstaculo()

pyxel.run(update, draw)