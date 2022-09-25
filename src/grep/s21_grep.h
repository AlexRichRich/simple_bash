#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>

#define MAX_SIZE 500

struct grep_flags {
    int e;  // Шаблон поиска
    int i;  // Игнорирует различия регистра
    int v;  // Инвертирует смысл поиска соответствий
    int c;  // Выводит только количество совпадающих строк
    int l;  // Выводит только названия совпадающих файлов
    int n;  // Предваряет каждую строку вывода номером строки из файла ввода
    int h;  // Выводит совпадающие строки, не предваряя их именами файлов
    int s;  // Подавляет сообщения об ошибках о несуществующих или нечитаемых файлах
    int f;  // Получает регулярные выражения из файла
    int o;  // Печатает только совпадающие (непустые) части совпавшей строки
    int status;  // Статус корректности флагов
};

void data_manager(int argc, char* argv[]);
void file_manager(char **files, char **words,
            struct grep_flags flags, int fls);
int basic_word_finder(char* line, char *words, struct grep_flags flags, int print);
void fill_flags(struct grep_flags* flag_list, const char* flags, size_t *status);
int f_e_words(const char *flags);
void str_manager(FILE *target, char **words, struct grep_flags flags, char* filename, int num_files);

#endif  // SRC_GREP_S21_GREP_H_
