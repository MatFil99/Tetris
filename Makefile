

Tetris: Main.o ./objects/Point.o ./manageAndInterface/Manage.o ./manageAndInterface/Interface.o ./objects/Block.o ./objects/IntNum.o ./engine/Map.o
	g++ Main.o ./objects/Point.o ./manageAndInterface/Manage.o ./manageAndInterface/Interface.o ./objects/IntNum.o ./objects/Block.o ./engine/Map.o -o Tetris

Main.o: Main.cpp ./list/List.h ./engine/Map.h
	g++ -c Main.cpp ./list/List.h ./engine/Map.h

Block.o: ./objects/Block.cpp ./objects/Block.h ./objects/Point.h
	g++ -c ./objects/Block.cpp ./objects/Block.h ./objects/Point.h

Map.o: ./engine/Map.cpp ./engine/Map.h ./list/List.h
	g++ -c ./engine/Map.cpp ./engine/Map.h ./list/List.h

IntNum.o: ./objects/IntNum.cpp ./objects/IntNum.h
	g++ -c ./objects/IntNum.cpp ./objects/IntNum.h

Point.o: ./objects/Point.cpp ./objects/Point.h
	g++ -c ./objects/Point.cpp ./objects/Point.h

Manage.o: ./manageAndInterface/Manage.cpp ./manageAndInterface/Manage.h ./list/List.h ./manageAndInterface/Interface.h
	g++ -c ./manageAndInterface/Manage.cpp ./manageAndInterface/Manage.h ./list/List.h ./manageAndInterface/Interface.h

Interface.o: ./manageAndInterface/Interface.cpp ./manageAndInterface/Interface.h
	g++ -c ./manageAndInterface/Interface.cpp ./manageAndInterface/Interface.h

clean: 
	rm -f *.gch *.o ./objects/*.gch ./objects/*.o ./engine/*.gch ./engine/*.o ./manageAndInterface/*.gch ./manageAndInterface/*.o ./list/*.gch ./list/*.o



	

start:
	./Tetris

startVal:
	valgrind --leak-check=full ./Tetris
