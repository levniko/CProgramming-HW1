#include<stdio.h>
#include<stdlib.h>
 int main ( )
 {
 	int year, month, day;
 	int lastyear;
 	char checkdate;
 	checkdate='t';
 int year1;
 int year2;
 int daynum;
 int lastyear1;
 int lastyear2;

  printf ( "Enter date [year month day]: " ) ;
  scanf ("%d%d%d",&year,&month,&day);

  if(month==4 || month==6 || month==9 || month==11 ){
 	if(day>30){
 	
 printf ("Invalid date. \n");
 return EXIT_FAILURE;
}
 }


 if(month<1 || month>12){
  checkdate='f';
  printf ("Invalid month. \n");
  return EXIT_FAILURE;
}
 if(day<1 || day>31){
  checkdate='f';
  printf ("Invalid date. \n");
  return EXIT_FAILURE;
}

 if(month==2 && day>28){
  checkdate='f';
  printf ("Invalid date. \n");
  return EXIT_FAILURE;
 }



  printf ( "Enter end year: " ) ;
  scanf ("%d",&lastyear);

  if(year>=lastyear){
  checkdate='f';
  printf ("Invalid end year. \n");
  return EXIT_FAILURE;
}


 if(checkdate=='t'){
 	int yearnext;
 	int monthnext;

 	yearnext=year;
 	monthnext=month;
 	if(month==1 || month==2){
 		month=month+12;
 		year=year-1;
	}

	 year2= year%100;
	 year1=(year-year%100)/100;

	 daynum= (day+(13*(month+1)/5)+year2+(year2/4)+(year1/4)+5*year1);

	 daynum=daynum%7;

	 if(daynum==0)
	 printf ("It's a Saturday. \n");
	 if(daynum==1)
	 printf ("It's a Sunday. \n");
	 if(daynum==2)
	 printf ("It's a Monday. \n");
	 if(daynum==3)
	 printf ("It's a Tuesday. \n");
	 if(daynum==4)
	 printf ("It's a Wednesday. \n");
	 if(daynum==5)
	 printf ("It's a Tursday. \n");
	 if(daynum==6)
	 printf ("It's a Friday. \n");

	 int daynumc;
	 int countday;
	 countday=0;
	 int curryear;
	 int countyear;
	 int currmonth;
	 for(countyear=yearnext;countyear<=lastyear;countyear++)
	 {
	 	curryear=countyear;
	 	currmonth=monthnext;
	 	if(currmonth==1 || currmonth==2){
 		currmonth=currmonth+12;
 		lastyear2=(curryear-1)%100;
	    lastyear1=((curryear-1)-lastyear2)/100;

        }
        else{
            lastyear2=curryear%100;
            lastyear1=(curryear-lastyear2)/100;
        }

	 	daynumc= (day+(13*(currmonth+1)/5)+lastyear2+(lastyear2/4)+(lastyear1/4)+5*lastyear1)%7;

	 	if(daynumc==daynum)
	 	countday=countday+1;

	 }
	 printf ("Same day-and-month on same weekday between %d and %d: %d \n", yearnext+1, lastyear, countday-1);
 }

 return EXIT_SUCCESS;
 }
