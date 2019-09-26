OBJDIR	= ./obj/
SRCDIR	= ./src/
LIBDIR 	= ./lib/

OBJS	= $(OBJDIR)main.o $(OBJDIR)tile.o $(OBJDIR)row.o $(OBJDIR)col.o $(OBJDIR)square.o $(OBJDIR)solver.o
HEADER	= 
OUT	= ./bin/solve
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

$(OBJDIR)main.o: $(SRCDIR)main.c
	$(CC) $(FLAGS) -I$(LIBDIR) $(SRCDIR)main.c -o $(OBJDIR)main.o 

$(OBJDIR)tile.o: $(SRCDIR)tile.c
	$(CC) $(FLAGS) -I$(LIBDIR) $(SRCDIR)tile.c -o $(OBJDIR)tile.o 

$(OBJDIR)row.o: $(SRCDIR)row.c
	$(CC) $(FLAGS) -I$(LIBDIR) $(SRCDIR)row.c -o $(OBJDIR)row.o 

$(OBJDIR)col.o: $(SRCDIR)col.c
	$(CC) $(FLAGS) -I$(LIBDIR) $(SRCDIR)col.c -o $(OBJDIR)col.o 

$(OBJDIR)square.o: $(SRCDIR)square.c
	$(CC) $(FLAGS) -I$(LIBDIR) $(SRCDIR)square.c -o $(OBJDIR)square.o 

$(OBJDIR)solver.o: $(SRCDIR)solver.c
	$(CC) $(FLAGS) -I$(LIBDIR) $(SRCDIR)solver.c -o $(OBJDIR)solver.o 

clean:
	rm -f $(OBJS) $(OUT)
