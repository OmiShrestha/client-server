/* Program:     Message list in C
   File name:   list.c
   Description: the program shows how to implement a message list
                with only append function. 
   Note:        1. Spaces allocated for the list and messages are 
                   NOT freed in this sample program. 
                2. newline is not removed from getline() use input
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// define the struct of nodes
struct MESSAGE {
   char *message;
   struct MESSAGE *next;
};
// give "struct MESSAGE" a short name (Message)
typedef struct MESSAGE  Message;

// define a struct and give it a short name
typedef struct LIST {
   Message *first;
   Message *last;
   int count;
} List; 

void init(List *msgList);
void append(List *msgList, Message *message);
Message *createMessage(char* msgString);
void printList(List *msgList);

int main() {
   List *msgList = (List *) malloc(sizeof(List));
   Message *message = NULL;

   init(msgList);

   char *inputBuf = NULL; // input buffer used by getline
   size_t size = 0;

   // read 4 messages, one per line and append them to list
   for (int i = 0; i < 4; i++) {
      inputBuf = NULL;   // let getline allocate space
      getline(&inputBuf, &size, stdin);

      // create a message node for the list
      message = createMessage(inputBuf);

      append(msgList, message);
   }

   // prints all messages in the list
   printList(msgList);
}

// initialize the msgList
void init(List *msgList) {
   msgList->first = NULL;
   msgList->last = NULL;
   msgList->count = 0;
}

void append(List *msgList, Message *message) {
   if (msgList->first == NULL) {
      msgList->first = message;
      msgList->last = message;
   }
   else {
      msgList->last->next = message;
      msgList->last = message;
   }
   msgList->count++;
}

Message *createMessage(char* msgString) {
   Message *msg = (Message *) malloc(sizeof(Message));
   msg->message = msgString;
   msg->next = NULL;

   return msg;
}

void printList(List *msgList) {
   Message *ptr = msgList->first;
   for (int i = 0; i < msgList->count; i++) {
      printf("Message #%d - %s\n", i, ptr->message);
      ptr = ptr->next;
   }
}
