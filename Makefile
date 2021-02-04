all :
	gcc get_next_line_utils.c get_next_line.c main.c -D BUFFER=27 && ./a.out