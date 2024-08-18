funcional:
	g++ src/*.cpp test/funcional/*.cpp -o bin/funcionalTests

unit:
	g++ src/*.cpp test/unit/*.cpp -o bin/unitTests

clean: 
	rm -f *.o main

run:
	./main