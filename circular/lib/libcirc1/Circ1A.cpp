#include <iostream>
#include "Circ1A.h"
#include "Circ0A.h"

Circ1A::Circ1A(const std::string &msg) : mMsg( msg ) 
{
  mCp1Obj = new CP1("constructed by Circ1A");
}

Circ1A::~Circ1A() {}

void Circ1A::printCirc1A(const std::string &tag)
{
  std::cout << "Circ1A: " << mMsg << " / " << tag << std::endl;
  std::string tmsg = "From Circ1A";
  Circ0A circ0a( tmsg);
  circ0a.printCirc0A(tmsg.c_str());
}

// For call from libcirc0
void Circ1A::echo(void)
{
  std::cout << "libcirc1: echo: " << mMsg << std::endl;
}