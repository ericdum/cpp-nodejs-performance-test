#include <ctime>
#include <math.h>
#include <stdlib.h>
#include "calc_sphere_dist.h"
#include <node.h>
#include <v8.h>

#define EARTH_RADIUS  6371004    
#define PI 3.1415926   
using namespace v8;
using namespace std;

double inline rad(double d)    
{    
	return d * PI / 180.0;    
}  

double getDistance(unsigned long num)
{
  while( num-- ){
    getDistance2();
  }
  return getDistance2();
}

double getDistance2()
{
	double lat1, lat2, lon1, lon2;

	unsigned int x = (unsigned int)clock();

	srand(x);

	lat1 = rand_r(&x) % 180 - 90;
	lat2 = rand_r(&x) % 180 - 90;
	lon1 = rand_r(&x) % 360 - 180;
	lon2 = rand_r(&x) % 360 - 180;

	return getDistanceVer2(lat1, lon1, lat2, lon2);
}



double getDistanceVer2(double lat1, double lng1, double lat2, double lng2)    
{    
	double radLat1 = rad(lat1);    
	double radLat2 = rad(lat2);    
	double a = radLat1 - radLat2;    
	double b = rad(lng1) - rad(lng2);    
	double s = 2 * asin(sqrt(pow(sin(a/2),2) + cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)));    
	s = s * EARTH_RADIUS;    
	return s;    
}    
   
Handle<Value> randomDistance(const Arguments& args) {
  HandleScope scope;
  unsigned long num = args[0]->NumberValue();
  return scope.Close(Number::New(getDistance(num)));
}
   
Handle<Value> distance(const Arguments& args) {
  HandleScope scope;
  if (args.Length() < 4) {
    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
    return scope.Close(Undefined());
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsNumber() || !args[3]->IsNumber()) {
    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
    return scope.Close(Undefined());
  }
  double lat1 = args[0]->NumberValue();
  double lng1 = args[1]->NumberValue();
  double lat2 = args[2]->NumberValue();
  double lng2 = args[3]->NumberValue();
  return scope.Close(Number::New(getDistanceVer2(lat1, lng1, lat2, lng2)));
}

void Initialize(Handle<Object> exports) {
    exports->Set(String::NewSymbol("randomDistance"),
              FunctionTemplate::New(randomDistance)->GetFunction());

    exports->Set(String::NewSymbol("distance"),
              FunctionTemplate::New(distance)->GetFunction());
}

NODE_MODULE(performance, Initialize)
