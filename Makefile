all: IndexFiles.o SearchFiles.o Statistics.o LinhHelperLibrary.o DeleteFiles.o Main.o
	g++ -o bin/cl_demo \
	bin/IndexFiles.o \
	bin/SearchFiles.o \
	bin/Statistics.o \
	bin/LinhHelperLibrary.o \
	bin/DeleteFiles.o \
	bin/Main.o \
	-lclucene-core \
	-lclucene-shared

IndexFiles.o: IndexFiles.cpp
	g++ -c IndexFiles.cpp -o bin/IndexFiles.o

SearchFiles.o: SearchFiles.cpp
	g++ -c SearchFiles.cpp -o bin/SearchFiles.o

Statistics.o: Statistics.cpp
	g++ -c Statistics.cpp -o bin/Statistics.o	

LinhHelperLibrary.o: LinhHelperLibrary.cpp
	g++ -c LinhHelperLibrary.cpp -o bin/LinhHelperLibrary.o	

DeleteFiles.o: DeleteFiles.cpp
	g++ -c DeleteFiles.cpp -o bin/DeleteFiles.o	

Main.o: Main.cpp
	g++ -c Main.cpp -o bin/Main.o	

temp: LinhHelperLibrary.o temp.o
	g++ -o temp temp.o bin/LinhHelperLibrary.o

temp.o: temp.cpp
	g++ -c temp.cpp -o temp.o
