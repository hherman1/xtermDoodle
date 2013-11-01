doodle: 	doodle.o world.o
	gcc doodle.o world.o -o doodle
world.o: world.c platforms.o
	gcc -c world.c platforms.o
platforms.o: platforms.c
	gcc -c platforms.c 
doodle.o: doodle.c
	gcc -c doodle.c
