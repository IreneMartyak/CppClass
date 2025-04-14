#include <iostream>

int main()
{

bool val = true ;
val++;
printf( "What??!\n" ); //trigraph issue
register int a{99} ; // does compiler even care about this command ?

return 0;
}