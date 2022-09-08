#ifndef UNIX_H
#define UNIX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void _puts(char *str);

int prompt(void);
int checkbuiltins(char **tbuffer, char *buffer, int exitstatus);
int _forkprocess(char **tbuffer, char *buffer, char *fbuffer);
int _stringcount(char *str);
int _strcmp(const char *c1, const char *c2);
int _strlen(char *s);
int _splitPATH(char *str);
int _PATHstrcmp(const char *c1, const char *c2);
int _env(void);
int _putchar(char c);

char *_read(void);
char *_fullpathbuffer(char **tbuffer, char *path, char *copy);
char *_strdup(char *str);
char *_strcat(char *str1, char *str2);
char **tokenize(char *buffer);
char *_concat(char *tmp, char **tbuffer, char *tok);
char *_getenv(const char *name);
char *_memset(char *arr, char byte, unsigned int no);

#endif
