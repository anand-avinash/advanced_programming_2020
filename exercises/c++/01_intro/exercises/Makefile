CC = g++
EXE = uniq.x getters_int.x getters_double.x unit_convertor.x text_format.x

.PHONY: default clean

default: ${EXE}

%.x: %.cpp
	g++ $< -o $@

clean:
	rm -rf *.x a.out