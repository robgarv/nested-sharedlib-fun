#include <iostream>
#include "Circ2A.h"
#include "Circ0B.h"
Circ2A::Circ2A(const std::string &msg) : mMsg( msg ) 
{ }

Circ2A::~Circ2A() {}

void Circ2A::printCirc2A(const std::string &tag)
{
  std::cout << "Circ2A: " << mMsg << " / " << tag << std::endl;
  std::string tmsg = "From Circ2A";
  Circ0B circ0b( tmsg);
  circ0b.printCirc0B(tmsg.c_str());
}

// For call from libcirc0
void Circ2A::echo(void)
{
  std::cout << "libcirc2: echo: " << mMsg << std::endl;
}
