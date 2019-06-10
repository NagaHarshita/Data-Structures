#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <main.h>


int main(){
  int choice;
  g_head=malloc(sizeof(student));
  b_student* tree;
  tree=NULL;
  while(1){
    printf("\nPlease enter the choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        {
           student *stud_inst,*tmp;
           int i=1;
         stud_inst=(student*)malloc(sizeof(student));
      scanf("%s %d %f %d",stud_inst->name,&stud_inst->rollno,&stud_inst->cgpa,&stud_inst->hackerrank);
         addstudent(stud_inst);
        }
        break;
        case 2:{
           student *stud_inst,*tmp;
         stud_inst=(student*)malloc(sizeof(student));
         scanf("%s %d %f %d",stud_inst->name,&stud_inst->rollno,&stud_inst->cgpa,&stud_inst->hackerrank);
         updateStudentbyrollno(stud_inst);
        }
        break;
        case 3:
        {   int n;
          scanf("%d",&n);
          DeleteStudentbyrollno(n);
        }
        break;
        case 4:{
          int n;
          scanf("%d",&n);
          Printbystudentrollno(n);
        }
        break;
        case 5:
        {
              print_all(g_head);
        }
        break;

        case 6:
         {int n;
          scanf("%d",&n);
          tree=Initialize(n);
         }
         break;
         case 7:{int i=1;
          student* current;
          current=g_head->next;
           while(current!=NULL){
            data_with_rank* tmp;
            tmp=malloc(sizeof(data_with_rank));
            tmp->rank=current->hackerrank;
            tmp->node=current;
            tree->g_heap[i]=tmp;
            tree->count++;
            //printf("$\n");
            i++;
            current=current->next;
           }
           //printf("@\n");
           //printf("%d\n",tree->count );
           buildheap(tree);
         }
         break;
         case 8:{
             getTOPranking(tree);
         }
         break;
         case 9:{
          Deletemin(tree);
         }
         break;
         case 10:{
           Printheap(tree);
         } 
         break;
         case 11:{
          student *stud_inst;
         stud_inst=(student*)malloc(sizeof(student));
         data_with_rank*tmp;
         scanf("%s %d %f %d",stud_inst->name,&stud_inst->rollno,&stud_inst->cgpa,&stud_inst->hackerrank);
          tmp=malloc(sizeof(data_with_rank));
            tmp->rank=stud_inst->hackerrank;
            tmp->node=stud_inst;
            tree->g_heap[tree->count+1]=tmp;
            addstudent(stud_inst);
          Insert(tree,tmp);
          

          
         }

      }
}}
