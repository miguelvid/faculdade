import pyxel
import random

class Player:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def move(self, direction):
        if direction == "left":
            if self.x == 66.6 + 3.8:
                self.x = 40 + 3.8
            elif self.x == 92.6 + 3.8:
                self.x = 66.6 + 3.8
        elif direction == "right":
            if self.x == 66.6 + 3.8:
                self.x = 92.6 + 3.8
            elif self.x == 40 + 3.8:
                self.x = 66.6 + 3.8

class Obstacle:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def move(self):
        self.y += 7

class MovingObstacle(Obstacle):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.speed = 7

    def move(self):
        self.y += self.speed

class Game:
    def __init__(self):
        pyxel.init(160, 120)
        self.player = Player(66.6 + 3.8, 95)
        self.obstacles = []
        self.game_over = False
        self.movement_delay = 2
        self.movement_timer = 0
        self.start_delay = 5
        self.start_timer = 0
        self.started = False
        self.show_start_text = True  # Flag para mostrar o texto de início

    def create_obstacle(self):
        positions = [40 + 3.8, 66.6 + 3.8, 92.6 + 3.8]
        x = random.choice(positions)
        obstacle = MovingObstacle(x, 0)
        self.obstacles.append(obstacle)

    def update(self):
        if pyxel.btnp(pyxel.KEY_Q):
            pyxel.quit()
        if pyxel.btnp(pyxel.KEY_0):
            self.game_over = True

        if not self.game_over:
            if pyxel.btnp(pyxel.KEY_SPACE) and not self.started:
                self.started = True
                self.start_timer = pyxel.frame_count
                self.show_start_text = False

            if self.started:
                if pyxel.frame_count - self.movement_timer >= self.movement_delay:
                    if pyxel.btn(pyxel.KEY_LEFT):
                        self.player.move("left")
                    elif pyxel.btn(pyxel.KEY_RIGHT):
                        self.player.move("right")
                    self.movement_timer = pyxel.frame_count

                for obstacle in self.obstacles:
                    obstacle.move()
                    if obstacle.y > 120:
                        self.obstacles.remove(obstacle)

                    if (
                        self.player.x + 20 > obstacle.x
                        and self.player.x < obstacle.x + 20
                        and self.player.y + 30 > obstacle.y
                        and self.player.y < obstacle.y + 30
                    ):
                        self.game_over = True
                        return

                if (
                    self.started
                    and pyxel.frame_count - self.start_timer >= self.start_delay
                    and random.random() < 0.03
                    and len(self.obstacles) < 2
                ):
                    self.create_obstacle()

    def draw(self):
        pyxel.cls(0)

        pyxel.rect(40, 0, 26.6, 120, 11)
        pyxel.rect(66.6, 0, 26.6, 120, 12)
        pyxel.rect(92.6, 0, 26.6, 120, 13)

        pyxel.rect(self.player.x, self.player.y, 20, 30, 14)

        for obstacle in self.obstacles:
            pyxel.rect(obstacle.x, obstacle.y, 20, 30, 15)

        if self.show_start_text:
            pyxel.cls(0)
            pyxel.text(68, 50, "Start", pyxel.frame_count // 3 % 16)  # Alternando cores
            pyxel.text(50, 60, "Pressione Espaco", 7)

        if self.game_over:
            pyxel.text(60, 50, "Game Over", 8)

def run_game():
    global game
    game = Game()
    game.start_timer = pyxel.frame_count
    pyxel.run(game.update, game.draw)

run_game()
