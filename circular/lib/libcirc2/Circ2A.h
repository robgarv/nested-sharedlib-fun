#ifndef _Circ2A_H
#define _Circ2A_H

#include <string>
#include "CP1.h"
class Circ2A 
{

public:
  Circ2A(const std::string &msg);
  virtual ~Circ2A();

  void printCirc2A(const std::string &tag);
  void echo(void);

private:
  std::string mMsg;
};


#endif