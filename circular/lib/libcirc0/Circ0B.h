#ifndef _Circ0B_H
#define _Circ0B_H

#include <string>
#include "CP1.h"
class Circ0B 
{

public:
  Circ0B(const std::string &msg);
  virtual ~Circ0B();

  void printCirc0B(const std::string &tag);

private:
  std::string mMsg;
  CP1 *mCp1Obj;
};


#endif