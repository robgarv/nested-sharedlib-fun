#ifndef _Circ0A_H
#define _Circ0A_H

#include <string>
#include "CP1.h"

class Circ0A 
{

public:
  Circ0A(const std::string &msg);
  virtual ~Circ0A();

  void printCirc0A(const std::string &tag);

private:
  std::string mMsg;
  CP1 *mCp1Obj;
};


#endif