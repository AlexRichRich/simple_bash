CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c11

s21_grep: s21_grep.c
	$(CC) $(CFLAGS) $^ -o $@

tests: s21_grep
	sh t_grep.sh

clean:
	rm -rf s21_grep *.o *.dSYM log.txt

cpp:
	cp ../../materials/linters/CPPLINT.cfg ./
	python3 ../../materials/linters/cpplint.py --extensions=c *.c
	python3 ../../materials/linters/cpplint.py --extensions=h *.h
	rm CPPLINT.cfg
	cppcheck --enable=all s21_grep.c s21_grep.h