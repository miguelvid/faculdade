import pyxel
import random

# Classe para representar o jogador
class Player:
    def __init__(self, x, y):
        self.x = x  # Posição X do jogador
        self.y = y  # Posição Y do jogador

    # Método para mover o jogador
    def move(self, direction):
        if direction == "left":
            # Movimenta o jogador para a esquerda entre as posições dos retângulos
            if self.x == 66.6 + 3.8:
                self.x = 40 + 3.8
            elif self.x == 92.6 + 3.8:
                self.x = 66.6 + 3.8
        elif direction == "right":
            # Movimenta o jogador para a direita entre as posições dos retângulos
            if self.x == 66.6 + 3.8:
                self.x = 92.6 + 3.8
            elif self.x == 40 + 3.8:
                self.x = 66.6 + 3.8

# Classe base para os obstáculos
class Obstacle:
    def __init__(self, x, y):
        self.x = x  # Posição X do obstáculo
        self.y = y  # Posição Y do obstáculo

    # Método para mover obstáculos
    def move(self):
        self.y += 7  # Move o obstáculo para baixo

# Subclasse de Obstacle para obstáculos móveis
class MovingObstacle(Obstacle):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.speed = 7  # Velocidade do obstáculo móvel

    # Método para mover obstáculos com velocidade específica
    def move(self):
        self.y += self.speed  # Move o obstáculo móvel para baixo com a velocidade

# Classe principal para o jogo
class Game:
    def __init__(self):
        # Inicialização do Pyxel e definição das variáveis do jogo
        pyxel.init(160, 120)
        self.player = Player(66.6 + 3.8, 95)  # Cria um jogador na posição inicial
        self.obstacles = []  # Lista para armazenar os obstáculos
        self.game_over = False  # Flag para indicar o fim do jogo
        self.movement_delay = 2  # Atraso entre os movimentos
        self.movement_timer = 0  # Contador para controlar os movimentos

    # Método para criar novos obstáculos
    def create_obstacle(self):
        positions = [40 + 3.8, 66.6 + 3.8, 92.6 + 3.8]
        x = random.choice(positions)
        obstacle = MovingObstacle(x, 0)  # Cria um obstáculo móvel na posição inicial
        self.obstacles.append(obstacle)  # Adiciona o obstáculo à lista de obstáculos

# Função de atualização do jogo
def update():
    global game
    # Verifica se o jogador quer encerrar o jogo
    if pyxel.btnp(pyxel.KEY_Q):
        pyxel.quit()
    if pyxel.btnp(pyxel.KEY_0):
        game.game_over = True

    if not game.game_over:
        # Verifica se é hora de mover o jogador
        if pyxel.frame_count - game.movement_timer >= game.movement_delay:
            if pyxel.btn(pyxel.KEY_LEFT):
                game.player.move("left")
            elif pyxel.btn(pyxel.KEY_RIGHT):
                game.player.move("right")
            game.movement_timer = pyxel.frame_count  # Atualiza o contador de movimento

        # Movimenta os obstáculos e remove aqueles que saem da tela
        for obstacle in game.obstacles:
            obstacle.move()
            if obstacle.y > 120:
                game.obstacles.remove(obstacle)

        # Cria novos obstáculos com uma certa probabilidade
        if random.random() < 0.03 and len(game.obstacles) < 2:
            game.create_obstacle()

        # Verifica a colisão entre o jogador e os obstáculos
        for obstacle in game.obstacles:
            if (
                game.player.x + 20 > obstacle.x
                and game.player.x < obstacle.x + 20
                and game.player.y + 30 > obstacle.y
                and game.player.y < obstacle.y + 30
            ):
                game.game_over = True
                return

# Função para desenhar os elementos do jogo na tela
def draw():
    pyxel.cls(0)  # Limpa a tela

    # Desenha os retângulos de cada posição
    pyxel.rect(40, 0, 26.6, 120, 11)
    pyxel.rect(66.6, 0, 26.6, 120, 12)
    pyxel.rect(92.6, 0, 26.6, 120, 13)

    # Desenha o jogador
    pyxel.rect(game.player.x, game.player.y, 20, 30, 14)

    # Desenha os obstáculos
    for obstacle in game.obstacles:
        pyxel.rect(obstacle.x, obstacle.y, 20, 30, 15)

    # Exibe a mensagem de "Game Over" quando o jogo termina
    if game.game_over:
        pyxel.text(60, 50, "Game Over", 8)

# Função para iniciar o jogo
def run_game():
    global game
    game = Game()
    game.create_obstacle()  # Cria o primeiro obstáculo
    pyxel.run(update, draw)

# Inicia o jogo
run_game()
