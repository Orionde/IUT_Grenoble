optimisation = 2

compilo-gcc = gcc -g -Wall -W -Werror -O$(optimisation) -std=gnu11
compilo-clang = clang -g -O$(optimisation) -std=gnu11 -Weverything -Werror -Wno-missing-noreturn -Wno-padded -Wno-disabled-macro-expansion -fcaret-diagnostics

executables = registres tableau1d tableau2d tableau1d-auto

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

