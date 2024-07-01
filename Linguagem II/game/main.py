import pyxel
from game import Game

def run_game():
    game = Game()
    game.start_timer = pyxel.frame_count
    pyxel.run(game.update, game.draw)

run_game()