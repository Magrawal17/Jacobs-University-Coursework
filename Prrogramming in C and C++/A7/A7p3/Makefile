start: use_linked_list.o linked_list.o 
	gcc -Wall -o hello linked_list.o use_linked_list.o

linked_list.o: linked_list.h linked_list.c

use_linked_list.o: linked_list.h use_linked_list.c

delete:
	rm -f start *.o *.exe
		
		