#include <iostream>
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include "calc_sphere_dist.h"

using namespace std;

#define EARTH_RADIUS  6378.137
#define PI 3.1415926   

double inline rad(double d)    
{    
	return d * PI / 180.0;    
}  

double getDistance(unsigned long num)
{
  cout << "run " << num << " times" << endl;
  num--;
  while( num-- ){
    getDistance2();
  }
  return getDistance2();
}

double getDistance2()
{
	double lat1, lat2, lon1, lon2;

  //*
	lat1 = 0.6994578910525888 * 180 - 90;
	lon1 = 0.13747660745866597 * 360 - 180;

	lat2 = 0.14322569407522678 * 180 - 90;
	lon2 = 0.07900970987975597 * 360 - 180;
  /*/
	unsigned int x = (unsigned int)clock();
	srand(x);

	lat1 = rand_r(&x) % 180 - 90;
	lat2 = rand_r(&x) % 180 - 90;
	lon1 = rand_r(&x) % 360 - 180;
	lon2 = rand_r(&x) % 360 - 180;
  //*/

	double radLat1 = rad(lat1);    
	double radLat2 = rad(lat2);    
	double a = radLat1 - radLat2;
	double b = rad(lon1) - rad(lon2);    
	double s = 2 * asin(sqrt(pow(sin(a/2),2) + cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)));    
	s = s * EARTH_RADIUS;    
	return s;    
}    

int main(int argc, char** argv) {
  unsigned long num = atol(argv[1]);
  clock_t start = clock();
  double lr = getDistance( num );
  cout << "last result: " << lr << endl;
  clock_t end = clock();
  cout << "c++: " << (int)(((float)end-(float)start)/CLOCKS_PER_SEC*1000) << "ms" << endl;

  return 0;
}
