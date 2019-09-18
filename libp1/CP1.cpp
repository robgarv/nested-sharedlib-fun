#include <iostream>
#include "CP1.h"
CP1::CP1(const char* msg) : mMsg(msg)
{ }

CP1::~CP1() { ; }

void CP1::printCp1Text(const char* tag)
{
  std::cout << "MESSAGE FROM CP1: TAG" << tag << std::endl;
  std::cout << mMsg << std::endl;
}



