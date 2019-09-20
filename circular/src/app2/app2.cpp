#include <iostream>
#include <CP1.h>
#include <Circ2A.h>

void Circ2ATest()
{
  Circ2A Circ2A("CAP object Constructed from main");
  Circ2A.printCirc2A("Circ2A print called from main");
}


int main(int argc, char* argv[])
{

  Circ2ATest();
  return 0;
}