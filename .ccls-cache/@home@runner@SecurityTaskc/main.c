#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void print_all(FILE *fp)
{
    int c;
    char d[1024];
    while ((c = getc(fp)) != EOF)
        strncat(d, &c, 1024);
    // printf("%s",d);
}

/* Signal Handler for SIGINT */
void sigint_handler(int sig_num)
{
    /* Reset handler to catch SIGINT next time.
       Refer http://en.cppreference.com/w/c/program/signal */
    printf("\n User provided signal handler for Ctrl+C \n");

    /* Do a graceful cleanup of the program like: free memory/resources/etc and exit */
    exit(0);
}

char *Security(char *d)
{
    char r[1024];;
    char cmd[1024];
        snprintf(cmd, sizeof(cmd), "awk '/Failed/ && /%s/ {print $1, $2, $3,$6,$9,$11,$12,$13}' auth.log", d);
        printf("%s\n",cmd);
    FILE *fp;
    int status;
    if ((fp = popen(cmd,"r")) == NULL)
        {} else
        //return "none";

    // print_all(fp);
    {int c;
    while ((c = getc(fp)) != EOF)
        strncat(r, &c, 1);}
    pclose(fp);
    return r;
}

char *Month(int choice) {

  char *str;
   switch(choice)
    {
        case 1: str="Jan";
                break;
        case 2: str="Feb";
                break;
        case 3: str="Mar";
                break;
        case 4: str="Apr";
                break;
        case 5: str="May";
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
  // printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
      
// printf("Date and time: %s %d %02d:%02d:%02d\n",Month(tm.tm_mon+1),tm.tm_mday,tm.tm_hour, tm.tm_min, tm.tm_sec);
      // snprintf(d, sizeof(d), "%s %d %d:%d:%d", Month(tm.tm_mon+1), tm.tm_mday,tm.tm_hour, tm.tm_min, tm.tm_sec);
      // d=Month(tm.tm_mon+1);
      char d[1024];
        // snprintf(d, sizeof(d), "%s %d %d:%d:%d", Month(tm.tm_mon+1), tm.tm_mday,tm.tm_hour, tm.tm_min, tm.tm_sec);
      snprintf(d,sizeof(d),"%s","May 20 17:41:02");
      // char *sec=Security(d);
      char sec[1024];
      strncpy( sec, Security(d), sizeof( sec ) );
printf("%s\n",sec);
      printf("%s\n",d);
    }
    return 0;
}