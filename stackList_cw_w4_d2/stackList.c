#include <time.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

struct item {
	int val;
	int val2;
	int id;
	struct item* next;
	struct item* prev;
};

struct item* head=NULL;
struct item* tail = NULL;

int id_counter = 1;
int itemCounter = 0;
void push(int, int);
void printTheList();
void releaseFromHead();
struct item* pop();

int main()
{
	struct item* popItem;
	srand(time(NULL));
	char userResponses = NULL;
	while (userResponses != 'E') {
		printf("Hi Dear User \n What would you like to do?\n1. I-to add new item\n2.  P-to remove item\n3. L-to print the list\n4. B-to add 100 items\n5. Z-to remove 10 items\n6.E-to exit:");
		scanf(" %c", &userResponses);
	switch (userResponses)
	{
		case  'I':
			push(rand() % 100 + 1, rand() % 100 + 1);
			break;
		case 'P':
			popItem = pop();
			if (!popItem) {
				printf("your list is empty\n");
			}
			else {
			printf("id:%d val=%d val2=%d val+val2=%d\n", popItem->id, popItem->val, popItem->val2, popItem->val + popItem->val2);
			printf("there is %d items in the list\n", itemCounter);
			}
			free(popItem);
			break;
		case 'L':
			printTheList();
			break;
		case 'B':
			for (int i = 0; i < 100; i++)
			{
				push(rand() % 100 + 1, rand() % 100 + 1);
			}
			break;
		case 'Z':
			popItem = pop();
			if (!popItem) {
				printf("your list is empty\n");
			}
			else {
			for (int i = 0; i < 10; i++)
			{
				popItem = pop();
				printf("id:%d val=%d val2=%d val+val2=%d\n", popItem->id, popItem->val, popItem->val2, popItem->val + popItem->val2);
			}
			printf("there is %d items in the list\n", itemCounter);

			}
			free(popItem);
			break;
		default:
			printf("Wrong selection. Try be more sharp\n");
			break;
	}
	}
	releaseFromHead();
}
struct item* pop() 
{
	struct item* freeStuckItem=head;

	if (itemCounter==1)
	{
		head = NULL;
		tail == NULL;
		itemCounter--;
		return head;
	}
	else if(itemCounter > 1)
	{
			head = head->next;
			head->prev = NULL;
			itemCounter--;
			return freeStuckItem;
	}
	else{
			return head;
		}
	}

void push(int val, int val2) {
	struct item* curr = (struct item*)malloc(sizeof(struct item));
	curr->val = val;
	curr->val2 = val2;
	curr->id = id_counter;
	itemCounter++;
	if (head == NULL) {
		head = curr;
		tail = curr;
		curr->next = NULL;
		curr->prev = NULL;
	}
	else {

		curr->prev = NULL;
		curr->next = head;
		head->prev = curr;
		head = curr;
	}
	id_counter++;
	return 0;
}
void printTheList() {
	struct item* curr = head;
	while (curr) {
		printf("val is:%d val2 is:%d id is:%d\n", curr->val, curr->val2, curr->id);
		curr = curr->next;
	}
	printf("amount of items in the list:%d\n", itemCounter);
	return 0;
}
void releaseFromHead() {
	struct item* freeTheList = head;
	while (head) {
		free(freeTheList);
		head = head->next;
		freeTheList = head;
	}
}
