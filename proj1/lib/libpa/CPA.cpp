#include <iostream>
#include "CPA.h"

CPA::CPA(const std::string &msg) : mMsg( msg ) 
{
  mCp1Obj = new CP1("constructed by CPA");
}

CPA::~CPA() {}

void CPA::printCpa(const std::string &tag)
{
  std::cout << "CPA: " << mMsg << " / " << tag << std::endl;
  std::string tmsg = "From CPA";
  mCp1Obj->printCp1Text(tmsg.c_str());
}