#include<stdio.h>
int main() 
  {
  
  	char number[7],name[12],sname[12], code[7],letter;
  	int i,courses,credit,lab, mid,final,grade;
  	float gpa;
  	int earned_mark=0;
  	float total_marks=0;
  	float total_credit;
  	int i1=0, i2=0, i3=0, i4=0, i5=0;
	 FILE * student=fopen("student1.txt","r");
	 while(!feof(student))
	 {
	 	fscanf(student,"%s%d%s%s",&number, &courses, &name, &sname);
	 	printf("\n\n%s\t\t%d\t%13s%13s\n\n",number, courses, name, sname);
	 	printf("Course  \t Credit   Resulted grade   Letter grade\n\n");
	 	total_marks=0;
	 	total_credit=0;
	 	for(i=0; i<courses; i++){
	 	fscanf(student,"%s%d%d%d%d",&code, &credit, &lab, &mid, &final);
	 	printf("%s\t\t   %d\t",code,credit);
	 	grade=lab*0.15+mid*0.35+final*0.5;
	 	printf("\t%d\t", grade);
	 	if(grade<46){
	 		letter='F';
	 		earned_mark=0;
	 		i1++;
		 }
		 if(grade<60 && grade>45)
		 {
		 	letter='D';
	 		earned_mark=1;
	 		i2++;
		 }
		  if(grade<75 && grade>59)
		 {
		 	letter='C';
	 		earned_mark=2;
	 		i3++;
		 }
	  if(grade<90 && grade>74)
		 {
		 	letter='B';
	 		earned_mark=3;
	 		i4++;
		 }
		  if(grade>90)
		 {
		 	letter='A';
	 		earned_mark=4;
	 		i5++;
		 }
		 printf("\t%c\n",letter);
		 total_marks= total_marks+earned_mark*credit;
		 total_credit=total_credit+credit;
	 }
	 gpa=total_marks/total_credit;
	 printf("\nGPA= %.2f\n",gpa);
	 }
	 printf("\n\nLetter Grade\t Occurrence\n");
	 printf("A\t\t%d\n",i5);
	 printf("B\t\t%d\n",i4);
	 printf("C\t\t%d\n",i3);
	 printf("D\t\t%d\n",i2);
	 printf("F\t\t%d\n",i1);
	 printf("\n");
	 return 0;}
