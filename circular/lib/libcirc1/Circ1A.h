#ifndef _Circ1A_H
#define _Circ1A_H

#include <string>
#include "CP1.h"
class Circ1A 
{

public:
  Circ1A(const std::string &msg);
  virtual ~Circ1A();

  void printCirc1A(const std::string &tag);
  void echo();

private:
  std::string mMsg;
  CP1 *mCp1Obj;
};


#endif