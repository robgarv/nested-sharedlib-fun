#include <iostream>
#include "Circ0A.h"
#include "Circ1A.h"

Circ0A::Circ0A(const std::string &msg) : mMsg( msg ) 
{
  mCp1Obj = new CP1("constructed by Circ0A");
}

Circ0A::~Circ0A() 
{
  delete mCp1Obj;
}

void Circ0A::printCirc0A(const std::string &tag)
{
  std::cout << "Circ0A: " << mMsg << " / " << tag << std::endl;
  std::string tmsg = "From Circ0A";
  mCp1Obj->printCp1Text(tmsg.c_str());
  Circ1A obj( "Created From Circ0A");
  obj.echo();
}