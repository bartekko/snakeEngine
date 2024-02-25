
snake: #snake.c Point2D Render_objects
	gcc -o snake snake.c Point2D.o Snake.o Render_objects.o -lncurses

Point2D: Point2D.c Point2D.h
	gcc -c Point2D.c 
Snake: Snake.c Snake.h
	gcc -c Snake.c
#Renderer: Renderer.c Renderer.h
#	gcc -c Renderer.c 

Render_objects: Render_objects.c Render_objects.h


#gcc -o snake snake.c Point2D.o Snake.o Render_objects.o -lncurses
