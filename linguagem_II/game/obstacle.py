class Obstacle:
    def __init__(self, x, y):
        # Inicializa a posição do obstáculo
        self.x = x
        self.y = y

    def move(self):
        # Movimenta o obstáculo para baixo
        self.y += 7

class MovingObstacle(Obstacle):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.speed = 7  # Define a velocidade do obstáculo móvel

    def move(self):
        # Movimenta o obstáculo móvel para baixo com velocidade variável
        self.y += self.speed