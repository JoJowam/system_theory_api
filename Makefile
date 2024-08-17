funcional:
	g++ src/*.cpp test/funcional/*.cpp -o bin/funcionalTests

clean: 
	rm -f *.o main

run:
	./main