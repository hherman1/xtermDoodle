doodle: 	doodle.o world.o
	gcc doodle.o world.o -o doodle
doodle.o: doodle.c keyboard.o xterm_control.o
	gcc -c doodle.c keyboard.o xterm_control.o
world.o: world.c
	gcc -c world.c
