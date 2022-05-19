#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

/* Signal Handler for SIGINT */
void sigint_handler(int sig_num)
{
    /* Reset handler to catch SIGINT next time.
       Refer http://en.cppreference.com/w/c/program/signal */
    printf("\n User provided signal handler for Ctrl+C \n");

    /* Do a graceful cleanup of the program like: free memory/resources/etc and exit */
    exit(0);
}

char *Month(int choice) {

  char *str;
   switch(choice)
    {
        case 1: str="Jan";
printf("Month %\n", str);

                break;
        case 2: str="Feb";
                break;
        case 3: str="Mar";
                break;
        case 4: str="Apr";
                break;
        case 5: str="May";
printf("Month %s\n",str);
                break;
        case 6: str="Jun";
                break;
        case 7: str="Jul";
                break;
        case 8: str="Aug";
                break;
        case 9: str="Sep";
                break;
        case 10: str="Oct";
                break;
        case 11: str="Nov";
                break;
        case 12: str="Dec";
                break;
        default : printf("invalid number");
    }

 
   return str; 
}

int main ()
{
    signal(SIGINT, sigint_handler);

    /* Infinite loop */
    while(1)
    {
        time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
printf("Month: %s\n",Month(tm.tm_mon+1));
     
    }
    return 0;
}