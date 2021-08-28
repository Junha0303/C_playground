#ifndef __LIB_STRING_H
#define __LIB_STRING_H
#include <stdio.h>

/* Standard. */
char *strncat (char *, const char *, size_t);
int strcmp (const char *, const char *);
char *strchr (const char *, int);
size_t strcspn (const char *, const char *);
char *strpbrk (const char *, const char *);
char *strrchr (const char *, int);
size_t strspn (const char *, const char *);
char *strstr (const char *, const char *);
size_t strlen (const char *);

/* Extensions. */
size_t strlcpy (char *, const char *, size_t);
size_t strlcat (char *, const char *, size_t);
char *strtok_r (char *, const char *, char **);
size_t strnlen (const char *, size_t);

#endif /* lib/string.h */