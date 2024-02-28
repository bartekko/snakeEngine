all: snake

snake:
	cc -o snake snake.c Point2D.c Snake.c Render_objects.c Renderer.c Food.c Board.c Hud.c -lncurses -g3
clean:
	rm snake
