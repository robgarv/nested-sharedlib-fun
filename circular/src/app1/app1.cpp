#include <iostream>
#include <CP1.h>
#include <Circ1A.h>

void Circ1ATest()
{
  Circ1A Circ1A("CAP object Constructed from main");
  Circ1A.printCirc1A("Circ1A print called from main");
}


int main(int argc, char* argv[])
{

  Circ1ATest();
  return 0;
}