#ifndef _CP1_H
#define _CP1_H

#include <string>

class CP1
{
  public:
    CP1(const char* msg);
    virtual ~CP1();

    void printCp1Text(const char* tag);

  private:
    std::string mMsg;
};

#endif
