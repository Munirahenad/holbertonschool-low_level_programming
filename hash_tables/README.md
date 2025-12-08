Hash Tables Project
A complete custom implementation of a hash table data structure in C, developed as part of the Holberton School curriculum. This project implements a fully functional hash table with collision handling using chaining.
Project Structure
hash_tables/
├── hash_tables.h
├── 0-hash_table_create.c
├── 1-djb2.c
├── 2-key_index.c
├── 3-hash_table_set.c
├── 4-hash_table_get.c
├── 5-hash_table_print.c
├── 6-hash_table_delete.c
└── README.md
File Descriptions

File	Description
hash_tables.h	Header file containing structure definitions and function prototypes
0-hash_table_create.c	Creates a new hash table with specified size
1-djb2.c	Implements the djb2 hash algorithm
2-key_index.c	Computes the index for a given key
3-hash_table_set.c	Adds or updates a key-value pair in the hash table
4-hash_table_get.c	Retrieves the value associated with a key
5-hash_table_print.c	Prints the entire hash table
6-hash_table_delete.c	Deletes the hash table and frees all memory
Requirements
Editors: vi, vim, emacs

Code Style: Betty style (checked with betty-style.pl and betty-doc.pl)

Global Variables: Not allowed

Functions per file: Maximum 5 functions

Header file: hash_tables.h with include guards

File endings: All files must end with a new line
Authorized Functions and Macros
malloc (man 3 malloc)

free (man 3 free)

strdup (man 3 strdup)

printf (man 3 printf)

fprintf (man 3 fprintf)

putchar (man 3 putchar)

strlen (man 3 strlen)
Task 0: hash_table_t *hash_table_create(unsigned long int size);
Task 1: unsigned long int hash_djb2(const unsigned char *str);
Task 2: unsigned long int key_index(const unsigned char *key, unsigned long int size);
Task 3: int hash_table_set(hash_table_t *ht, const char *key, const char *value);
Task 4: char *hash_table_get(const hash_table_t *ht, const char *key);
Task 5: void hash_table_print(const hash_table_t *ht);
Task 6: void hash_table_delete(hash_table_t *ht);

