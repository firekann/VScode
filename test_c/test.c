#include<stdio.h>
#include<math.h>
#define PI 3.1415926535897932384626

double dtor(double d){return (d*PI/180);}
double rtod(double r){return (r*180/PI);}
double haversine(double x1, double y1, double x2, double y2){
   double lat=sin(dtor(fabs(x1-x2))/2);
   double log=sin(dtor(fabs(y1-y2))/2);
   double dist=sqrt(lat*lat+cos(dtor(x1))*cos(dtor(x2))*log*log);
   dist=2*6371*asin(dist)*1000;
   return dist;
}

int main(){
}