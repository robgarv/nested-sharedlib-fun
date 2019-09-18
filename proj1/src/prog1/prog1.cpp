#include <iostream>
#include <libpb.h>
#include <CPA.h>

void CPATest()
{
  CPA cpa("CAP object Constructed from main");
  cpa.printCpa("CPA print called from main");
}

void XBinderTest()
{
  const char* options[] = { "-v", "-o", "/home/rgarvey/tmp/xwriter.txt" };
  BWriter(3, options);
}

int main(int argc, char* argv[])
{

  CPATest();
  XBinderTest();
  return 0;
}