#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

#define _GNU_SOURCE
#define gettid() syscall(SYS_gettid)                        

void main(){
  int random_num;
  int ttid, count;
  char str[300];
  FILE *fp;
  struct timeval t1, t2;

  gettimeofday(&t1, NULL);
  ttid=gettid();
  count=0;

  /*open a file for writing. The filename consist of the following two substrings, 
  "file_" and the string converting from the result of gettid(). Hence, if the result of gettid is 123,
  the file name is file_123. We use file_gettid to call this file in the following pseudo code. */
  char filename[30];
  sprintf(filename, "file_%d.txt\n", ttid);

  for(;;){
   gettimeofday(&t2, NULL);           

  /*If the time difference between t2 and t1 is greater than 3 minutes, break;*/
   int timediff=t2.tv_sec-t1.tv_sec;
   if (timediff>=180)break; 
    random_num= (rand()%3)+1;
    count++;
    sprintf(str, "process %d is added into wait queue project2_queue_%d the %d th time at time ...\n", ttid, random_num, count);

    /*write the string stored in array str[] into file file_gettid.*/
    printf("%d\n",random_num);  
    fp = fopen(filename, "w");
    fprintf(fp,str);
    fclose(fp);           
    int a= syscall(359,random_num); 
    printf("%d\n",a);               

    }
  printf("process %d completes!\n", ttid);
 }
