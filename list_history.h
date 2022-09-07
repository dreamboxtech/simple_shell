#ifndef _history_h_
#define _history_h_
/**
 * struct ListHistory - Singly linked list for the history
 * @command: command to be received
 * @next: points to the next node of the list
 *
 * Description: A SLL structure
 */
typedef struct ListHistory
{
	char *command;
	struct ListHistory *next;
} ListHistory;
#endif
