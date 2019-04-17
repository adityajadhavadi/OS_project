#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>


int main()

{

  int i,k;
  int n;

  int t1,remain;

  int flag=0, t_quantum=10;               // time quantum initilized as 10 and flag value is 0

  int waiting_t=0, turnaround_t=0;         // waiting time and turn around time initially defined as 0
  
  int arrival_t[10], burst_t[10], rt1[10];

  Printf("\n ---------------Operating System Project-----------------");

  printf("\n           Design a Scheduling Program                 ");

  printf("\n Enter the Total number of Process: \t ");

  scanf("\n %d",&n);

  remain=n;


  for(i=0;  i<n; i++)          // for loop started 

     {

         printf("\n Please Enter the Arrival Time for Process Num. %d :",i+1);

         scanf("\n%d",&arrival_t[i]);
         
         printf("\n Please Enter the Burst Time for Process Number %d :", i+1);

         scanf("\n%d",&burst_t[i]);

         rt1[i]=burst_t[i];

     }                         // for loop end
 

   printf("The Given Time Quantum:- %d\n",t_quantum);     //print given time quantum in the question  

 
  printf("\nProcess\t----- Turnaround Time----- Waiting Time\n\n");
  
  for(t1=0,i=0;remain!=0;)            // for loop started
  
     {

          if(rt1[i]<=t_quantum && rt1[i]>0)        // if loop started inside for loop
    
     {
   
          t1+=rt1[i];
 
          rt1[i]=0;

          flag=1;
    
      }

   else if(rt1[i]>0)                      // else if loop

      {
      
          rt1[i]-=t_quantum;
  
        t1+=t_quantum;
   
      }

   if(rt1[i]==0 && flag==1)               // if loop checking the condition
    
      {

          remain--;                     // decrementing the remaining values by 1;

          printf("P[%d]\t----\t%d\t----\t%d\n",i+1,t1-arrival_t[i],t1-arrival_t[i]-burst_t[i]);
          
          waiting_t+=t1-arrival_t[i]-burst_t[i];                 // Waiting time = arrival time - burst time

          turnaround_t+=t1-arrival_t[i];                         

          flag=0;                         // flag value initilized as 0
   
      } 

   if(i==n-1)                            // if loop checking the condition 
 
     {
          i=0;                           // if condition is true then i value is 0

     }
   else if(arrival_t[i+1]<=t1)               
 
     {
          i++;                            // incrementing i value by  1 
     }

   else
  
     {   
 	    i=0;
   
        printf("\n Average Waiting t1= %f\n",waiting_t*1.0/n);           // calculate and print the value of average waiting time

        printf("\n Average Turnaround t1 = %f",turnaround_t*1.0/n);       //calculate and print the value of average turnaround time

        return 0;

     }

  }
}


