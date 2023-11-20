import pyxel
import random

class Player:
    def __init__(self, x, y):
        # Inicializa a posição do jogador
        self.x = x
        self.y = y

    def move(self, direction):
        # Movimentação do jogador para esquerda e direita
        # Verifica se o jogador está em determinadas posições para limitar o movimento
        # Adiciona 5 para evitar erros de precisão de ponto flutuante
        # Exemplo: self.x == 66.6 + 5, self.x == 92.6 + 5
        # Se estiver nessas posições, move para outra posição específica
        if direction == "left":
            if self.x == 66.6 + 5:
                self.x = 40 + 5
            elif self.x == 92.6 + 5:
                self.x = 66.6 + 5
        elif direction == "right":
            if self.x == 66.6 + 5:
                self.x = 92.6 + 5
            elif self.x == 40 + 5:
                self.x = 66.6 + 5

class Obstacle:
    def __init__(self, x, y):
        # Inicializa a posição do obstáculo
        self.x = x
        self.y = y

    def move(self):
        # Movimentação do obstáculo descendo na tela
        self.y += 7

class MovingObstacle(Obstacle):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.speed = 7

    def move(self):
        # Movimentação específica para um obstáculo em movimento
        self.y += self.speed

class Game:
    def __init__(self):
        # Inicialização do jogo e definição de variáveis
        pyxel.init(160, 120)
        pyxel.load("PYXEL_RESOURCE_FILE.pyxres")
        self.player = Player(66.6 + 5, 95)
        self.obstacles = []
        self.game_over = False
        self.movement_delay = 2
        self.movement_timer = 0
        self.start_delay = 5
        self.start_timer = 0
        self.started = False
        self.show_start_text = True
        self.blt_y = 0
        self.blt_speed = 50
        self.v_value = 0
        self.v_change_delay = 5
        self.v_timer = 0

    def create_obstacle(self):
        # Criação de obstáculos em posições aleatórias
        positions = [40 + 5, 66.6 + 5, 92.6 + 5]
        x = random.choice(positions)
        obstacle = MovingObstacle(x, 0)
        self.obstacles.append(obstacle)

    def restart_game(self):
        # Reinicialização do jogo
        self.player = Player(66.6 + 5, 95)
        self.obstacles = []
        self.game_over = False
        self.started = False
        self.show_start_text = True
        self.movement_timer = 0
        self.blt_y = 0
        self.blt_speed = 50
        self.v_value = 0
        self.v_timer = 0

    def update(self):
        # Atualização do estado do jogo
        if pyxel.btnp(pyxel.KEY_Q):
            pyxel.quit()
        if pyxel.btnp(pyxel.KEY_0):
            self.game_over = True
        
        self.blt_y = (self.blt_y + self.blt_speed) % pyxel.height

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
                        self.player.x + 15 > obstacle.x
                        and self.player.x < obstacle.x + 15
                        and self.player.y + 20 > obstacle.y
                        and self.player.y < obstacle.y + 20
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

        if self.game_over:
            if pyxel.btnp(pyxel.KEY_SPACE):
                self.restart_game()

        if pyxel.frame_count - self.v_timer >= self.v_change_delay:
            self.v_value = (self.v_value + 32) % 64
            self.v_timer = pyxel.frame_count

    def draw(self):
        # Desenho dos elementos na tela
        pyxel.cls(pyxel.COLOR_LIME)
        pyxel.rect(40, 0, 26.6, 120, 13 )
        pyxel.rect(66.6, 0, 26.6, 120, 13)
        pyxel.rect(92.6, 0, 26.6, 120, 13)
        
        if self.game_over:
            self.blt_speed = 0
        for i in range(-1, pyxel.height // 8):
            pyxel.blt(60, self.blt_y + i * pyxel.height, img=0, u=0, v=self.v_value, w=1000, h=120, colkey=pyxel.COLOR_BLACK)
            pyxel.blt(86, self.blt_y + i * pyxel.height, img=0, u=0, v=self.v_value, w=1000, h=120, colkey=pyxel.COLOR_BLACK)

        pyxel.rect(self.player.x, self.player.y, 15, 20, 13)
        pyxel.blt(self.player.x, self.player.y, img=1, u=0, v=self.v_value, w=1000, h=120, colkey=5)
        for obstacle in self.obstacles:
            pyxel.rect(obstacle.x, obstacle.y, 15, 20, 13)
            pyxel.blt(obstacle.x, obstacle.y, img=2, u=0, v=0, w=1000, h=120, colkey=5)

        if self.show_start_text:
            pyxel.cls(0)
            pyxel.text(69, 50, "Start", pyxel.frame_count // 3 % 16)
            pyxel.text(50, 60, "Pressione Espaco", 7)

        if self.game_over:
            pyxel.rect(59, 48, 40, 10, 0)
            pyxel.text(62, 50, "Game Over", pyxel.COLOR_ORANGE)
            pyxel.text(50, 60, "Pressione Espaco", 7)

def run_game():
    game = Game()
    game.start_timer = pyxel.frame_count
    pyxel.run(game.update, game.draw)

run_game()
