CC = gcc

#CFLAGS = -g -Wall -Werror -lpthread 

OBJS = mproxy.o data.o log.o
INCLUDE = 	-I 	/usr/local/zwall.h.c  



#CFLAGS = -g -Wall -Werror 
CFLAGS = -g -Wall 



mproxy: $(OBJS)
%.o   : %.c %.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@





clean:
	rm -rf $(OBJS) mproxy 

