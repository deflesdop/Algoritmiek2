CC = g++

CompileParms = -c -Wall

OBJS = standaard.o steen.o stand.o main.o

Opdr: $(OBJS)
	$(CC) $(OBJS) -o Spel

standaard.o: standaard.cc standaard.h
	$(CC) $(CompileParms)  standaard.cc

steen.o: steen.cc steen.h
	$(CC) $(CompileParms)  steen.cc

stand.o: stand.cc stand.h
	$(CC) $(CompileParms)  stand.cc

main.o: main.cc stand.h
	$(CC) $(CompileParms)  main.cc

