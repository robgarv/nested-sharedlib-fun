#ifndef _CPA_H
#define _CPA_H

#include <string>
#include "CP1.h"
class CPA 
{

public:
  CPA(const std::string &msg);
  virtual ~CPA();

  void printCpa(const std::string &tag);

private:
  std::string mMsg;
  CP1 *mCp1Obj;
};


#endif