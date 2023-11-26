import pyxel
import random

class Player:
    def __init__(self, x, y):
        # Inicializa a posição do jogador
        self.x = x
        self.y = y

    def move(self, direction):
        # Dicionário mapeando os movimentos possíveis do jogador
        movement_map = {
            "left": {66.6 + 5: 40 + 5, 92.6 + 5: 66.6 + 5},  # Mapeia os movimentos para a esquerda
            "right": {66.6 + 5: 92.6 + 5, 40 + 5: 66.6 + 5}  # Mapeia os movimentos para a direita
        }

        # Verifica se a direção recebida está no dicionário de movimentos
        if direction in movement_map:
            movement = movement_map[direction]
            # Atualiza a posição do jogador de acordo com a direção
            self.x = movement.get(self.x, self.x)

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

class Game:
    def __init__(self):
        # Inicialização do Pyxel e configurações do jogo
        pyxel.init(160, 120)  # Inicializa a janela do jogo com dimensões 160x120
        pyxel.load("PYXEL_RESOURCE_FILE.pyxres")  # Carrega recursos (imagens, sons, etc.) do arquivo .pyxres
        self.player = Player(66.6 + 5, 95)  # Cria um jogador na posição inicial
        self.obstacles = []  # Lista para armazenar os obstáculos
        self.game_over = False  # Define o estado do jogo como não encerrado
        self.movement_delay = 2  # Atraso entre os movimentos do jogador
        self.movement_timer = 0  # Contador para controlar os movimentos do jogador
        self.start_delay = 5  # Atraso antes do início do jogo
        self.start_timer = 0  # Contador para controlar o início do jogo
        self.started = False  # Define se o jogo foi iniciado ou não
        self.show_start_text = True  # Define se o texto de início é exibido ou não
        self.blt_y = 0  # Posição Y para desenhar o plano de fundo em movimento
        self.blt_speed = 50  # Velocidade do plano de fundo em movimento
        self.v_value = 0  # Valor para controlar a animação do plano de fundo
        self.v_change_delay = 5  # Atraso para alterar a animação do plano de fundo
        self.v_timer = 0  # Contador para controlar a alteração da animação do plano de fundo
        self.score = 0  # Variável para armazenar a pontuação do jogador
    
    def create_obstacle(self):
        positions = [40 + 5, 66.6 + 5, 92.6 + 5]
        x = random.choice(positions)
        obstacle = MovingObstacle(x, 0)
        self.obstacles.append(obstacle)

    def restart_game(self):
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
        self.score = 0  # Reiniciando o score ao reiniciar o jogo

    def update(self):
        if pyxel.btnp(pyxel.KEY_Q):
            pyxel.quit()
        if pyxel.btnp(pyxel.KEY_0):
            self.game_over = True
        
        self.blt_y = (self.blt_y + self.blt_speed) % pyxel.height # Movimenta o plano de fundo em loop

        if not self.game_over:
            # Verifica se o jogo não está encerrado
            if pyxel.btnp(pyxel.KEY_SPACE) and not self.started:
                # Inicia o jogo quando a tecla de espaço é pressionada e o jogo ainda não foi iniciado
                self.started = True  # Define que o jogo foi iniciado
                self.start_timer = pyxel.frame_count  # Inicializa o contador de tempo para controlar o início do jogo
                self.show_start_text = False  # Esconde o texto de início
            
            if self.started:
                if pyxel.frame_count - self.movement_timer >= self.movement_delay:
                    # Controla o movimento do jogador com um atraso entre os movimentos
                    if pyxel.btn(pyxel.KEY_LEFT):
                        self.player.move("left")
                    elif pyxel.btn(pyxel.KEY_RIGHT):
                        self.player.move("right")
                    self.movement_timer = pyxel.frame_count # Reinicia o contador de tempo para o próximo movimento
            
                for obstacle in self.obstacles:
                    # Move os obstáculos e remove-os se estiverem fora da tela
                    obstacle.move()
                    if obstacle.y > 120:
                        self.obstacles.remove(obstacle)

                    if (
                     # Verifica se houve colisão entre o jogador e algum obstáculo
                        self.player.x + 15 > obstacle.x
                        and self.player.x < obstacle.x + 15
                        and self.player.y + 20 > obstacle.y
                        and self.player.y < obstacle.y + 20
                    ):
                        self.game_over = True # Define o estado do jogo como encerrado em caso de colisão
                        return

                if (
                    self.started
                    and pyxel.frame_count - self.start_timer >= self.start_delay
                    and random.random() < 0.03
                    and len(self.obstacles) < 2
                ):
                    # Cria novos obstáculos aleatoriamente após um certo tempo de jogo
                    self.create_obstacle()
                    self.score += 10  # Incrementando o score quando um novo obstáculo é criado

        if self.game_over:
            if pyxel.btnp(pyxel.KEY_SPACE):
                self.restart_game() # Reinicia o jogo se a tecla de espaço for pressionada

        if pyxel.frame_count - self.v_timer >= self.v_change_delay:
            # Controla a mudança na animação do plano de fundo
            self.v_value = (self.v_value + 32) % 64  # Altera o valor da animação
            self.v_timer = pyxel.frame_count # Reinicia o contador para a próxima alteração

    def draw(self):
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

        pyxel.text(120, 4, f"Score: {self.score}", pyxel.COLOR_WHITE)  # Desenha o score na tela

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
