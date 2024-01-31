//menu driven program to read and display details of students 

#include<stdio.h>
#include<stdlib.h>

struct student
{ char Name[25];
  int reg_no;
  int marks[3];
  float avgmarks;
};
 void readinfo(struct student *st,int n)
 {for(int i=0;i<n;i++) 
  {printf("\nEnter the details of the student %d",i+1);
   printf("\nName:");
   scanf("%s",&st[i].Name);
   printf("\nRegister number:");
   scanf("%d",&st[i].reg_no);
   printf("\nMarks for three tests:");
   for(int j=0;j<3;j++)
   {scanf("%d",&st[i].marks[j]);
   }
   }} 
   void displayinfo(struct student *st,int n)
   {printf("\n\nStudent details:\n");
    for(int i=0;i<n;i++)
    {printf("\nStudent %d details:",i+1);
     printf("\nStudent name:%s",st[i].Name);
     printf("\nRgistration number:%d",st[i].reg_no);
     printf("\nMarks for three test:");
     printf("%d %d %d",st[i].marks[0],st[i].marks[1],st[i].marks[2]);
     printf("\nAverage marks:%.3f\n",st[i].avgmarks);
     }
     }
  void avgmarks(struct student *st,int n)
  {
    for(int i=0;i<n;i++)
  {
     for(int j=0;j<2;j++)
    { 
        for(int k=0;k<2-j;k++)
  
    {
        if(st[i].marks[k]<st[i].marks[k+1])
    { int temp=st[i].marks[k];
      st[i].marks[k]=st[i].marks[k+1];
      st[i].marks[k+1]=temp;
    } st[i].avgmarks=(st[i].marks[0]+st[i].marks[1])/2.0;
       
    }
    }
  }
  }
       int main()
     { int n;
       printf("\nEnter number of students:");
       scanf("%d",&n);
       struct student *st;
       st=(struct student *)malloc (n*sizeof(struct student));
       int choice;
       do
       {
        printf("\nMenu:\n");
        printf("1.Read student information\n");
        printf("2.Display student information\n");
        printf("3.Average of best of 2 marks\n");
        printf("4,Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
      {case 1: readinfo(st,n);
               break;
       case 2: displayinfo(st,n);
               break;
       case 3: avgmarks(st,n);
            printf("\nAverage calculated for each student:");
            break;
       case 4: printf("\nExit the program");
            break;
       default:printf("Invalid choice,please enter a valid option.\n");
               break;                  
     } 
  
         }  
while (choice!=4);
   free(st);
 return 0;  
}






