#include <stdio.h>
#include <unistd.h>

#include "swephexp.h"   /* this includes  "sweodef.h" */

/*
    simple swiss ephemeris calc
*/
int main(int argc, char *argv[] ) {

        int year = 1980;
        int month = 12;
        int day = 21;
        int hour = 12;
        int minute = 0;
        double second = 0.0;
        double lat = 0.0;
        double lng = 0.0;

        int utc_year = 0;
        int utc_month = 0;
        int utc_day = 0;
        int utc_hour = 0;
        int utc_minute = 0;
        double utc_second = 0.0;
        unsigned int iflag = SEFLG_SWIEPH | SEFLG_SPEED;
        int ipl = 0;
        double x[6] = {0, 0, 0, 0, 0, 0};
        double dret[2] = {0, 0};
        char serr[128];
        int ret = 0;
        int i = 0;
int opt = 0;

  while((opt=getopt(argc,argv,"y:m:d:h:i:s:a:o:"))!=-1){
    switch(opt){
    case 'y':
      year = atoi(optarg);
    break;
    case 'm':
      month = atoi(optarg);
    break;
    case 'd':
      day = atoi(optarg);
    break;
    case 'h':
      hour = atoi(optarg);
    break;
    case 'i':
      minute = atoi(optarg);
    break;
    case 's':
      second = atof(optarg);
    break;
    case 'a':
      lat = atof(optarg);
    break;
    case 'o':
      lng = atof(optarg);
    break;
    }
  }
printf("%d %d %d %d %d %f %f %f\n", year, month, day, hour, minute, second, lat, lng);

        swe_utc_time_zone(year, month, day, hour, minute, second, 9.0, &utc_year, &utc_month, &utc_day, &utc_hour, &utc_minute, &utc_second);
        swe_utc_to_jd(utc_year, utc_month, utc_day, utc_hour, utc_minute, utc_second, 1, dret, serr);


        for (i = 0; i < 10; i++) {
            ret = swe_calc_ut(dret[1], i, iflag, x, serr);
            printf("%f\n", x[0]);
        }

}
