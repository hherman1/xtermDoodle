doodle: 	doodle.o platform.o
	gcc doodle.o platform.o -o doodle
platform.o:	platform.c
	gcc -c platform.c
doodle.o: doodle.c
	gcc -c doodle.c
doodle.c:
	echo "DNE"
