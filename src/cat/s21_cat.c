#include <stdio.h>
#include <string.h>

struct kitty {
    int b;  // нумерует только непустые строки
    int e;  // отображает символы конца строки как $
    int n;  // нумерует все выходные строки
    int s;  // сжимает несколько смежных пустых строк
    int t;  // отображает табы как ^I
    int v;  // отображает непечатаемые знаки до 31 и с 127 по 159 по ASCII
    int status;  // 0 если все флаги корректны, 1 если есть некорректный флаг
};


void functions_manager(int argc, char * argv[]);
void fill_flags(char* flags, struct kitty* status);
void print_files(int text);
void file_manager(struct kitty flags, char* file);
void endless_scan_print();
void text_changer(char text, char backup, struct kitty flags,
                int* num_str, int *is_begin);
void print_num_str(int *num_str);

int main(int argc, char * argv[]) {functions_manager(argc, argv);}

void functions_manager(int argc, char * argv[]) {
    struct kitty status_flags = {0};
    if (argc == 1) {
        endless_scan_print();
    }
    if (argc > 1) {
    int lev_vsmisle_lion_ne_vsmisle_imya = 0;
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-' && lev_vsmisle_lion_ne_vsmisle_imya == 0) {
                fill_flags(argv[i], &status_flags);
            } else if (status_flags.status == 0) {
                lev_vsmisle_lion_ne_vsmisle_imya = 1;
                file_manager(status_flags, argv[i]);
            }
            if (status_flags.status == 1) {
            printf("Unknown flag\n");
            break;
            } else if (lev_vsmisle_lion_ne_vsmisle_imya == 0
                        && argv[argc-1][0] == '-') {
                endless_scan_print();
            }
        }
    }
}

void endless_scan_print() {
    char suffer;
    while (1) {
        scanf("%c", &suffer);
        printf("%c", suffer);
    }
}

void fill_flags(char* flags, struct kitty* status) {
    for (int i = 1; flags[i] != 0; i++) {
        if (flags[i] == 'b' || strcmp(flags, "--number-nonblank") == 0) {
            status->b = 1;
        } else if (flags[i] == 'e' || flags[i] == 'E') {
            status->e = 1;
        } else if (flags[i] == 'n' || strcmp(flags, "--number") == 0) {
            status->n = 1;
        } else if (flags[i] == 's' || strcmp(flags, "--squeeze-blank") == 0) {
            status->s = 1;
        } else if (flags[i] == 't' || flags[i] == 'T') {
            status->t = 1;
        } else if (flags[i] == 'v') {
            status->v = 1;
        } else {
            status->status = 1;
            break;
        }
        if (flags[i] == 'e' || flags[i] == 't') status->v = 1;
        if (status->b == 1 && status->n == 1) status->n = 0;
        if (flags[1] == '-') break;
    }
}

void file_manager(struct kitty flags, char* file) {
    FILE *kitty_file;
    int num_str = 1, is_begin = 1;
    kitty_file = fopen(file, "r");
    if (kitty_file != NULL) {
        char text = '\0';
        while (text != EOF) {
            char backup = text;
            text = fgetc(kitty_file);
            text_changer(text, backup, flags, &num_str, &is_begin);
        }
        fclose(kitty_file);
    } else {
         printf("File not found\n");
    }
}

void text_changer(char text, char backup,
                    struct kitty flags, int* num_str, int *is_begin) {
    int fl = 0;
    if (flags.v == 1 && ((text >= 0 && text <= 8) ||
                (text >= 11 && text <= 12) || (text >= 14 && text <= 31) ||
                text >= 127)) {
        if (text >= 0 && text <= 31) {
            fl = 1;  // printf("^");
            text = text+64;
        } else if (text >= 127) {
            if (text == 127) {
                fl = 1;  // printf("M-");
            } else {
                fl = 2;  // printf("^");
            }
            text = text-64;
        }
    } else if (flags.t == 1 && text == '\t') {
        fl = 1;  // printf("^");
        text = text+64;
    }
    if (flags.s == 1 && backup == '\n' &&
        (text == '\n' || text == EOF) && *is_begin >= 2) {
        fl = 3;
    } else if (flags.b == 1 && (backup == '\n' || *is_begin == 1)
    && text != '\n' && text != EOF) {
        print_num_str(num_str);
    } else if (flags.n == 1 && (backup == '\n' || *is_begin == 1)
                && text != EOF) {
        print_num_str(num_str);
        if (flags.e == 1 && text == '\n') {
            print_files('$');
        }
    } else if (flags.e == 1 && text == '\n') {
        print_files('$');
    }
    if (fl == 2) printf("M-^");
    else if (fl == 1) print_files('^');
    if (fl != 3) print_files(text);

    if (*is_begin >= 1 && text != '\n' && text != EOF) *is_begin = 0;
    else if ((backup == '\n' || *is_begin == 1) && text == '\n') *is_begin += 2;
}

void print_num_str(int *num_str) {
    if (*num_str < 10) {
        printf("     %d\t", *num_str);
    } else if (*num_str < 100) {
        printf("    %d\t", *num_str);
    } else if (*num_str < 1000) {
        printf("   %d\t", *num_str);
    } else {
        printf("  %d\t", *num_str);
    }
    *num_str += 1;
}

void print_files(int text) {if (text != EOF) printf("%c", text);}
