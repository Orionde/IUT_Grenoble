compilo-gcc = gcc -g -Wall -W -Werror -Os -std=gnu11
compilo-clang = clang -g -Os -std=gnu11 -Weverything -Werror -Wno-padded -Wno-disabled-macro-expansion -fcaret-diagnostics

executables = march_hare fork0 fork1 fork2 fork3 forkZ waitpidZ exec1 exec2 exec3 mon-time

executables-gcc := $(foreach exe,$(executables),bin-gcc/$(exe))
executables-clang := $(foreach exe,$(executables),bin-clang/$(exe))

default: $(executables-gcc)

$(executables-gcc): %: %.o
	@make --no-print-directory $(subst bin-gcc,bin-clang,$@)
	$(compilo-gcc) $^ -o $@

$(executables-clang): %: %.o
	$(compilo-clang) $^ -o $@

bin-gcc/%.o: %.c
	@mkdir -p bin-gcc
	@make --no-print-directory $(subst bin-gcc,bin-clang,$@)
	$(compilo-gcc) -c $< -o $@

bin-clang/%.o: %.c
	@mkdir -p bin-clang
	$(compilo-clang) -c $< -o $@

menage:
	rm -rf *~ bin* a.out core
