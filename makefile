doodle: 	doodle.o 
	gcc doodle.o -o doodle
doodle.o: doodle.c
	gcc -c doodle.c
doodle.c:
	echo "DNE"
