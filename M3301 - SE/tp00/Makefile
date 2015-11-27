compilo = gcc -Wall -W -Os -std=c99

executables = prg

default: $(executables)

$(executables): %: %.o
	$(compilo) $< -o $*

%.o: %.c
	$(compilo) -c $<

menage:
	rm -f *~ $(executables) *.o a.out core
