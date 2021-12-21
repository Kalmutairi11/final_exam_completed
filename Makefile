GPP=g++ -std=c++17

all: run_final

run_final: main.o
	$(GPP) $^ -o $@

main.o: main.cpp
	$(GPP) -c $<

clean:
	-rm *.o run_final
