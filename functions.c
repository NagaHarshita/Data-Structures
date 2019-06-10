#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <main.h>

void addstudent(student* current){
	student *tmp=g_head;
  while(tmp->next!=NULL){
     tmp=tmp->next;
  }
  tmp->next=current;
}

void print(student* stud){
    printf("%s %d %f %d\n",stud->name,stud->rollno,stud->cgpa,stud->hackerrank);
}

void print_from(student* stud){
    if(stud==NULL)
        {printf("this student doesnt exist\n");
         return;}
    
   print(stud);

    if(stud->next !=NULL)
    print_from(stud->next);
      
}

void print_all(student* head){
    print_from(head->next);
}

void updateStudentbyrollno(student* current){
   student *tmp=g_head->next;
   while(tmp->rollno!=current->rollno && tmp!=NULL){
   	tmp=tmp->next;
   }
   strcpy(tmp->name,current->name);
   tmp->cgpa=current->cgpa;
   tmp->hackerrank=current->hackerrank;
}
void DeleteStudentbyrollno(int roll){
  student *current=g_head;
   while(current!=NULL){
       if(current->next->rollno == roll){
         current->next=current->next->next;
         //deleteinarray(roll);
         break;
       }
       current=current->next;}
}



void Printbystudentrollno(int roll){
  student *tmp=g_head->next;
   while(tmp->rollno!=roll && tmp!=NULL){
    tmp=tmp->next;
   }
  print(tmp);
}

b_student* Initialize(int max){
  b_student* H;
   //printf("@\n");
   H=malloc(sizeof(b_student));
   H->g_heap=malloc((max+1)*sizeof(data_with_rank*));
   H->capacity=max;
   //H->g_heap[0]=-1;
   H->count=0;
   return H;
}

void percolateup(int x,b_student* H){
  int i=H->count;
  int parent;
  while(i && i!=x){
    parent=i/2;
    if(H->g_heap[parent]->rank > H->g_heap[i]->rank)
    {
      data_with_rank* t=H->g_heap[parent];
      H->g_heap[parent]=H->g_heap[i];
      H->g_heap[i]=t;
    }
    i=i/2;
  }
}

void percolatedown(int x,b_student* H){
  int i=x;
  while((2*i)<=H->count){
    int child1=2*i;
    int child2=2*i+1,t;
    if(2*i+1 <=H->count){
     if(H->g_heap[child1]->rank < H->g_heap[child2]->rank)
       t=child1;
     else t=child2;
     
     }
     else
      t=child1;
      

      if(H->g_heap[t]->rank < H->g_heap[i]->rank){
     data_with_rank* p=H->g_heap[t];
     H->g_heap[t]=H->g_heap[i];
     H->g_heap[i]=p;}
     
 i=i*2;

  }
return;}

void Insert(b_student* H,data_with_rank* n){
  H->count++;
  H->g_heap[H->count]=n;
  percolateup(1,H);
}

void Deletemin(b_student* H){
  H->g_heap[1]->rank=H->g_heap[H->count]->rank;
  H->g_heap[1]->node=H->g_heap[H->count]->node;
   H->count--;
   DeleteStudentbyrollno(H->g_heap[1]->node->rollno);
}

void Printheap(b_student* H){
  for(int i=1;i<=H->count;i++)
    printf("%s %d %f %d\n",H->g_heap[i]->node->name,H->g_heap[i]->node->rollno,H->g_heap[i]->node->cgpa,H->g_heap[i]->rank);
}

void getTOPranking(b_student* H){
  printf("%s %d %f %d\n",H->g_heap[1]->node->name,H->g_heap[1]->node->rollno,H->g_heap[1]->node->cgpa,H->g_heap[1]->rank);
Deletemin(H);
}

void buildheap(b_student* H){
printf("%d",H->count);
  for(int i=(H->count)/2;i>0;i--){
    percolatedown(i,H);
  }
  return;

}