/*
** EPITECH PROJECT, 2018
** dir_content
** File description:
** get the content of a directory
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

int my_strcmp(char *, char *);
int my_strlen(char *);
char *my_strcpy(char *, char *);

int count_contents(char *pathToDir)
{
	DIR *dir = opendir(pathToDir);
	struct dirent *drt = readdir(dir);
	int i = 0;

	if (dir == NULL || drt == NULL)
		return (-1);
	while (drt) {
		if (drt->d_name[0] != '.') {
			i++;
		}
		drt = readdir(dir);
	}
	closedir(dir);
	return (i);
}

int check_ext(char *file, char *ext)
{
	int i = 0;

	for (; file[i] != '.' && file[i] != '\0'; i++);
	if (my_strcmp(&file[i], ext) == 0)
		return (1);
	return (0);
}

char **get_content_of_dir_with_ext(char *path, char *ext)
{
	DIR *dir = opendir(path);
	struct dirent *drt = readdir(dir);
	char **files = malloc(sizeof(char *) * (count_contents(path) + 1));
	int i = 0;

	if (dir == NULL || files == NULL || drt == NULL)
		return (NULL);
	for (; drt; drt = readdir(dir)) {
		if (drt->d_name[0] != '.' && check_ext(drt->d_name, ext)) {
			files[i] = malloc(my_strlen(drt->d_name) + 1);
			files[i] = my_strcpy(files[i], drt->d_name);
			i++;
		}
	}
	closedir(dir);
	files[i] = NULL;
	return (files);
}
