#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26
#define SUCCESS 0
#define FAILURE 1

/* -------- FILE NODE -------- */
typedef struct file_node
{
    char fname[50];
    int count;
    struct file_node *fnext;
} file_node;

/* -------- WORD NODE -------- */
typedef struct word_node
{
    char word[50];
    file_node *fhead;
    struct word_node *next;
} file_list;

/* -------- FUNCTION PROTOTYPES -------- */
int validation_file(char *argv[]);
int create_hash(file_list **hash, int size);
int create_database(file_list **hash, char *filename);
int insert_at_last(file_list **head, char *word, char *filename);
void display_database(file_list **hash);
void search_database(file_list **hash);
int update_database(file_list **hash);
// int update_database_from_backup(file_list **hash);
int get_word_total_count(file_list *word_node);
int is_file_already_indexed(file_list **hash, char *filename);
int save_database(file_list **hash);
void to_lowercase(char *str);


#endif
