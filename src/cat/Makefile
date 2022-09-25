CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c11

s21_cat: s21_cat.c
	$(CC) $(CFLAGS) $^ -o $@

tests: s21_cat
	sh s21_cat.sh

clean:
	rm -rf s21_cat *.o *.dSYM log.txt

cpp:
	cp ../../materials/linters/CPPLINT.cfg ./
	python3 ../../materials/linters/cpplint.py --extensions=c *.c
	rm CPPLINT.cfg
	cppcheck --enable=all s21_cat.c