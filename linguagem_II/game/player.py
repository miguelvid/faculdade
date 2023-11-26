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