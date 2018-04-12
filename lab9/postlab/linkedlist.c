//Matt Calayo mjc5gh linkedlist.c
#include <stdio.h>
#include <stdlib.h>

struct listnode {
  struct listnode *next;
  int datum;
};

struct list {
  struct listnode *head;
  int length;
};
  
int main(){
  struct list *linked = (struct list *) malloc(sizeof(struct list));
  linked->length = 0;
  linked->head = (struct listnode *) malloc(sizeof(struct listnode));
  linked->head->datum=0;
  struct listnode *temp = linked->head;

  int n;

  printf("Enter how many values to input: ");
  scanf("%d",&n);

  for(int i=0;i<n;i++){
    int data;
    struct listnode *node = (struct listnode *) malloc(sizeof(struct listnode));

    printf("Enter value %d: ", i +1);
    scanf("%d",&data);
    node->datum = data;

    temp->next = node;
    temp = temp->next;
    linked->length++;
  }
  struct listnode *print = linked->head->next;
  for(int i=0;i<linked->length;i++){
    int ret = (int)print->datum;
    printf("%d\n",ret);
    print = print->next;
  }
  free(linked);
      
      

  return 0;
}
