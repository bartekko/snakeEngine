all: snake

snake:
	cc -o snake snake.c Point2D.c Snake.c Render_objects.c Renderer.c Food.c Board.c Hud.c Message.c GameObject.c -lncurses -g3
clean:
	rm snake
