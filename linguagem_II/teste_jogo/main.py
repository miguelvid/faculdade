import pyxel
import random
from math import sqrt

# inicializa os circulos
RADIUS =  5
COLOR_ON = pyxel.COLOR_RED
COLOR_OFF = pyxel.COLOR_GREEN
STEP = 2

pyxel.game_over = False
pyxel.init(160, 120, title='teste')
pyxel.x1 = random.uniform(20, 140)
pyxel.y1 = random.uniform(20, 100)
pyxel.sleep1 = False
pyxel.x2 = random.uniform(20, 140)
pyxel.y2 = random.uniform(20, 100)
pyxel.sleep2 = False
pyxel.x3 = random.uniform(20, 140)
pyxel.y3 = random.uniform(20, 100)
pyxel.sleep3 = False

def in_circle(x, y, cx, cy):
    dist = sqrt ((x - cx)**2 + (y - cy)**2)
    return dist <= RADIUS

def update():
    if pyxel.btnp(pyxel.KEY_Q):
        pyxel.quit()
    
    if pyxel.btnp(pyxel.MOUSE_BUTTON_LEFT):
        if not pyxel.game_over:       
            if in_circle(pyxel.mouse_x,pyxel.mouse_y, pyxel.x1, pyxel.y1):
                pyxel.sleep1 = True

            if in_circle(pyxel.mouse_x,pyxel.mouse_y, pyxel.x2, pyxel.y2):
                pyxel.sleep2 = True

            if in_circle(pyxel.mouse_x,pyxel.mouse_y, pyxel.x3, pyxel.y3):
                pyxel.sleep3 = True
    
    if pyxel.frame_count > 30 * 3:
        if  not (pyxel.sleep1 == pyxel.sleep2 == pyxel.sleep3 == True):
            pyxel.game_over = True
    
    if not pyxel.game_over:  
        if not pyxel.sleep1:
            pyxel.x1 = pyxel.x1 + random.uniform(-STEP, STEP)
            pyxel.y1 = pyxel.y1 + random.uniform(-STEP, STEP)
            
        if not pyxel.sleep2:    
            pyxel.x2 = pyxel.x2 + random.uniform(-STEP, STEP)
            pyxel.y2 = pyxel.y2 + random.uniform(-STEP, STEP)
            
        if not pyxel.sleep3:    
            pyxel.x3 = pyxel.x3 + random.uniform(-STEP, STEP)
            pyxel.y3 = pyxel.y3 + random.uniform(-STEP, STEP)

def draw():
    pyxel.cls(pyxel.COLOR_WHITE)

    if pyxel.sleep1:
        color = COLOR_OFF
    else:
        color = COLOR_ON
    pyxel.circ(pyxel.x1, pyxel.y1, RADIUS, color)
    
    if pyxel.sleep2:
        color = COLOR_OFF
    else:
        color = COLOR_ON
    pyxel.circ(pyxel.x2, pyxel.y2, RADIUS, color)
    
    if pyxel.sleep3:
        color = COLOR_OFF
    else:
        color = COLOR_ON
    pyxel.circ(pyxel.x3, pyxel.y3, RADIUS, color)

    if pyxel.sleep1 == pyxel.sleep2 == pyxel.sleep3 == True:
        if (pyxel.frame_count // 5) % 2 == 0:
            pyxel.text(80 - 3 * pyxel.FONT_WIDTH, 60, "YOU WIN", pyxel.COLOR_DARK_BLUE)

    if pyxel.game_over:
        if (pyxel.frame_count // 5) % 2 == 0:
            pyxel.text(80 - 4 * pyxel.FONT_WIDTH, 60, "GAME OVER", pyxel.COLOR_DARK_BLUE)


pyxel.mouse(True)
pyxel.run(update, draw)
