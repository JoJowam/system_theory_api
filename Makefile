#Gera DLL para FlowImpl.cpp
flow_dll: bin
	g++ -shared -o bin/flow.dll src/FlowImpl.cpp -I src

#Gera DLL para ModelImpl.cpp
model_dll: bin
	g++ -shared -o bin/model.dll src/ModelImpl.cpp src/SystemImpl.cpp -I src

#Gera DLL para SystemImpl.cpp
system_dll: bin
	g++ -shared -o bin/system.dll src/SystemImpl.cpp -I src

#Gera todas as DLLs (Flow, Model, System)
src_dlls: flow_dll model_dll system_dll

#Gera DLL para o teste funcional
funcional_dll: bin
	g++ -shared -o bin/funcionalTests.dll test/funcional/funcionalTests.cpp src/ModelImpl.cpp src/SystemImpl.cpp src/FlowImpl.cpp -I src -I test/funcional

#Gera DLL para os testes unitários
unit_dll: bin
	g++ -shared -o bin/unitTests.dll test/unit/UnitFlow.cpp test/unit/UnitModel.cpp test/unit/UnitSystem.cpp \
        src/FlowImpl.cpp src/ModelImpl.cpp src/SystemImpl.cpp -I src -I test/unit

#Gera todas as DLLs dos testes
tests_dlls: funcional_dll unit_dll

#Compila o executável para os testes funcionais
funcional: src_dlls funcional_dll
	g++ -o bin/funcionalExe test/funcional/main.cpp -Lbin -lfuncionalTests -lflow -lmodel -lsystem -I src -I test/funcional

#Compila o executável para os testes unitários
unit: src_dlls unit_dll
	g++ -o bin/unit.exe test/unit/main.cpp -Lbin -lunitTests -lflow -lmodel -lsystem -I src -I test/unit

#Limpa os arquivos gerados
clean:
	rm -f bin/*.dll bin/*.exe

#Executa os testes funcionais
run_funcional: funcional
	LD_LIBRARY_PATH=bin ./bin/funcionalExe

#Executa os testes unitários
run_unit: unit
	LD_LIBRARY_PATH=bin ./bin/unitExe
