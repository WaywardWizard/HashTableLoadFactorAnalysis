/* * * * * * * * *
 * Interface for using various hash table data structures through a
 * single unified list of functions
 *
 * created for COMP20007 Design of Algorithms - Assignment 2, 2017
 * by Matt Farrugia <matt.farrugia@unimelb.edu.au>
 *
 * Modified by:
 * 14/05/17
 * Ben Tomlin
 * SN: 834198
 * btomlin@student.unimelb.edu.au
 *
 * Summary of modification
 * Added code to print out csv data for analysis
 *
 */

#ifndef HASHTBL_H
#define HASHTBL_H

#include <stdbool.h>
#include "inthash.h"

// enumerated type containing constants for the various types of hash table
// supported
typedef enum type {
	NOTYPE = -1, LINEAR, XTNDBL1, CUCKOO, XTNDBLN, XUCKOO, XUCKOON
} TableType;

// converts from a string representation to a TableType constant:
// "linear"			->	LINEAR
// "xtndbl1"		->	XTNDBL1
// "1" or "cuckoo"	->	CUCKOO
// "2" or "xtndbln"	->	XTNDBLN
// "3" or "xuckoo"	->	XUCKOO
// "xuckoon"        ->  XUCKOON
TableType strtotype(char *str);

typedef struct table HashTable;

// initialise a hash table of type 'type' with initial size 'size',
// and return its pointer
HashTable *new_hash_table(TableType type, int size);

// free all memory associated with 'table'
void free_hash_table(HashTable *table);

// insert 'key' into 'table', if it's not in there already
// returns true if insertion succeeds, false if it was already in there
bool hash_table_insert(HashTable *table, int64 key);

// lookup whether 'key' is inside 'table'
// returns true if found, false if not
bool hash_table_lookup(HashTable *table, int64 key);

// print the contents of 'table' to stdout
void hash_table_print(HashTable *table);

// print some statistics about 'table' to stdout
void hash_table_stats(HashTable *table);

void hash_table_csv_stats(HashTable *table);

void hash_table_csv_stats_header(HashTable *table);
#endif
