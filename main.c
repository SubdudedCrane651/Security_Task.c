#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_all(FILE *fp) {
  int c;
  char d[1024];
  while ((c = getc(fp)) != EOF)
    strncat(d, &c, 1024);
  // printf("%s",d);
}

/* Signal Handler for SIGINT */
void sigint_handler(int sig_num) {
  /* Reset handler to catch SIGINT next time.
     Refer http://en.cppreference.com/w/c/program/signal */
  printf("\n User provided signal handler for Ctrl+C \n");

  /* Do a graceful cleanup of the program like: free memory/resources/etc and
   * exit */
  exit(0);
}

char *Security(char *d) {
  char *r = NULL;
  r = malloc(125);
  // char r[1024]= "\0";
  char cmd[125] = "\0";
  snprintf(
      cmd, sizeof(cmd),
      "awk '/Failed/ && /%s/ {print $1, $2, $3,$6,$9,$11,$12,$13}' auth.log",
      d);
  // printf("%s\n",cmd);
  FILE *fp;
  int status;
  sleep(1);
  if ((fp = popen(cmd, "r")) == NULL) {
  } else
    // return "none";

    // print_all(fp);
    snprintf(r, sizeof(r), "%s", "");
  {
    int c;
    while ((c = getc(fp)) != EOF)
      strncat(r, &c, 1);
  }
  pclose(fp);
  return r;
}

char *Month(int choice) {

  char *str;
  switch (choice) {
  case 1:
    str = "Jan";
    break;
  case 2:
    str = "Feb";
    break;
  case 3:
    str = "Mar";
    break;
  case 4:
    str = "Apr";
    break;
  case 5:
    str = "May";
    break;
  case 6:
    str = "Jun";
    break;
  case 7:
    str = "Jul";
    break;
  case 8:
    str = "Aug";
    break;
  case 9:
    str = "Sep";
    break;
  case 10:
    str = "Oct";
    break;
  case 11:
    str = "Nov";
    break;
  case 12:
    str = "Dec";
    break;
  default:
    printf("invalid number");
  }

  return str;
}

int main() {
  signal(SIGINT, sigint_handler);

  /* Infinite loop */
  while (1) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    // printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon
    // + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    // printf("Date and time: %s %d
    // %02d:%02d:%02d\n",Month(tm.tm_mon+1),tm.tm_mday,tm.tm_hour, tm.tm_min,
    // tm.tm_sec); snprintf(d, sizeof(d), "%s %d %d:%d:%d", Month(tm.tm_mon+1),
    // tm.tm_mday,tm.tm_hour, tm.tm_min, tm.tm_sec); d=Month(tm.tm_mon+1);
    char d[1024];
        char hour[20];
        char minute[20];
        char second[20];
        sprintf(hour, "%02d",tm.tm_hour);
        sprintf(minute, "%02d",tm.tm_min);
        sprintf(second, "%02d", tm.tm_sec);
        //snprintf(d, sizeof(d), "%s %d %s:%s:%s", Month(tm.tm_mon+1), tm.tm_mday,hour, minute, second);
    // snprintf(d, sizeof(d), "%s %d %d:%d:%d", Month(tm.tm_mon+1),
    // tm.tm_mday,tm.tm_hour, tm.tm_min, tm.tm_sec);
    snprintf(d, sizeof(d), "%s", "May 20 17:41:02");
    // char *sec=Security(d);
    // strncpy( sec, Security(d), sizeof( sec ) );
    char sec[125] = "\0";
    snprintf(sec, sizeof(sec), "%s", Security(d));

    if (strlen(sec) != 0) {
      printf("%s\n", d);
      printf("%s\n", sec);
    }
  }
  return 0;
}