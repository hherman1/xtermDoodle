doodle: 	doodle.o world.o
	gcc doodle.o world.o -o doodle
doodle.o: doodle.c 
	gcc -c doodle.c 
world.o: world.c keyboard.o xterm_control.o
	gcc -c world.c keyboard.o xterm_control.o
keyboard.o: keyboard.c
	gcc -c keyboard.c
xterm_control.o: xterm_control.c
	gcc -c xterm_control.c