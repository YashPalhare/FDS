#include<stdio.h>
#include<stdlib.h>

struct Hostel {
  int room_no;
  char name[30];
}

void main() {
  int ch, flag = 0, mult = 1, rn;
  struct Hostel hostel[10];

  do {
    printf("Welcome, what would you like to do?\n");
    printf(" 1.Insert\n 2.Search\n 3.Display\n 6.Exit\n");
    scanf("%d", &ch);
    switch(ch) {
      case 1:
        for(int i=0; i<10; i++) {
          printf("Enter the room no. for student %d: ", i+1);
          scanf("%d", &hostel[i].room_no);
          printf("Enter the student's name: ");
          scanf("%s", hostel[i].name);
          printf("----------------------------------\n");
        }
      break;
      case 2:
          printf("Enter the room no. you want to search: ");
          scanf("%d", &rn);
          for(int i=0; i<10; i++) {
            if(rn == hostel[i].room_no) {
              printf("Room no. found at position %d.\n", i);
              printf("Name of student is %s\n", hostel[i].name);
              printf("------------------------------\n");
              flag = 1;
            }
          }
          if(flag == 0) {
              printf("Room no. not found in database, please try again.\n");
          }
      break;
      case 3:
        for(int i=0; i<10; i++) {
            printf("Room no. %d\n", hostel[i].room_no);
            printf("Name of student: %s\n", hostel[i].name);
        }
      break;
      case 6:
        exit(0);
      default:
        printf
    }
  } while(ch != 6);
}
