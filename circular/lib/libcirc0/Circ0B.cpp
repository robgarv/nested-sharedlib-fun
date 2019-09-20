#include <iostream>
#include "Circ0B.h"
#include "Circ2A.h"

Circ0B::Circ0B(const std::string &msg) : mMsg( msg ) 
{
  mCp1Obj = new CP1("constructed by Circ0B");
}

Circ0B::~Circ0B() 
{
  delete mCp1Obj;
}

void Circ0B::printCirc0B(const std::string &tag)
{
  std::cout << "Circ0B: " << mMsg << " / " << tag << std::endl;
  std::string tmsg = "From Circ0B";
  mCp1Obj->printCp1Text(tmsg.c_str());
  Circ2B obj( "Created From Circ0B");
  obj.echo();
}