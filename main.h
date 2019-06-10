typedef struct Student student;
typedef struct Binaryheap b_student;
typedef struct Data_with_rank data_with_rank;

struct Student
{
	char name[10];
	int rollno;
	float cgpa;
  int hackerrank;
	struct Student *next;
};
//student* g_array[10]={NULL};
struct  Data_with_rank{
    int rank;
    student* node;
   };

struct  Binaryheap
{
	int capacity;
  int count;
  data_with_rank **g_heap;

};


student* g_head;

void addstudent(student* current);
void print(student* stud);
void print_from(student* stud);
void print_all(student* head);
void updateStudentbyrollno(student* current);
void DeleteStudentbyrollno(int roll);
void Printbystudentrollno(int roll);
b_student* Initialize(int max);
void percolateup(int x,b_student* H);
void percolatedown(int x,b_student* H);
void Insert(b_student* H,data_with_rank* n);
void Deletemin(b_student* H);
void Printheap(b_student* H);
void getTOPranking(b_student* H);
void buildheap(b_student* H);
