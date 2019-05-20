/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** lib function prototypes
*/

#ifndef MY_H
#define MY_H

int my_strlen(char *);
int my_strcmp(char *, char *);
char *my_strcpy(char *, char *);
char *my_strncpy(char *, char *, int);
char *my_strcat(char *, char *);
char **split_by(char *, char);
char **my_str_to_word_array(char *);
char *my_realloc(char *, int);
int find_char(char *, char);
char *my_strdup(char *);
void my_putstr(char *);
int my_str_isalpha(char *);
int my_isnum(char *);
int my_getnbr(char *);
char *my_int_to_str(int);
int power(int, int);
void my_put_tab(char **);
char *get_next_line(int);
char *clean_str(char *);
int my_isnum(char *);
int array_size(void **);
char **get_content_of_dir_with_ext(char *, char *);
int my_printf(int fd, char *str, ...);
int tab_len(char **);
char **tab_realloc(char **, int);
char *get_env_variable(char **, char *);
void free_2d_arr(char **);
char **read_file(char *);
int my_char_isnum(char);
int find_str(char *, char *);

char *get_next_line(int fd);

#endif
