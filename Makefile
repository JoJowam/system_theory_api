myvensym_dll: bin
	g++ -fPIC -shared -o bin/libMyVensym.so src/*.cpp -I src

funcional_dll: myvensym_dll
	g++ -o bin/funcionalExe test/funcional/main.cpp test/funcional/funcionalTests.cpp -Lbin -lMyVensym -I src -I test/funcional

clean:
	rm -f bin/*.so bin/*.exe

run_funcional:
	LD_LIBRARY_PATH=bin ./bin/funcionalExe

funcional:
	g++ src/*.cpp test/funcional/*.cpp -o bin/funcionalTests

unit:
	g++ src/*.cpp test/unit/*.cpp -o bin/unitTests

clean: 
	rm -f *.o main

run:
	./main
