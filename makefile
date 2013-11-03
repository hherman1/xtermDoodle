doodle: 	doodle.o world.o
	gcc doodle.o world.o -o doodle
doodle.o: doodle.c 
	gcc -c doodle.c 
world.o: world.c keyboard.o xterm_control.o
	gcc -c world.c keyboard.o xterm_control.o
