#include<stdio.h>
#include<math.h>
#define PI 3.145926543
int main()
{
/
	int y=1,x=0;
	int z=(y++,x++)?y:x;
	printf("%d %d %d",x,y,z);
   	
return 0;
}

