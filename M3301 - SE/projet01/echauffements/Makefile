compilo = clang -D_XOPEN_SOURCE -g -Os -std=gnu11 -Weverything -Werror -Wno-disabled-macro-expansion -fcaret-diagnostics

executables = sort_in pere_fils cat_sort signal1 signal2 march_hare

default: $(executables)

$(executables): %: %.o
	$(compilo) $< -o $@

%.o: %.c
	$(compilo) -c $<

menage:
	rm -f *~ $(executables) *.o a.out core
