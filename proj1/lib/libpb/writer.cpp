// This test driver program encodes a data record and writes the 
// encoded result to an output file..

#include <stdio.h>
#include <stdlib.h>
#include "rtxmlsrc/rtXmlCppMsgBuf.h"
#include "simpleArray.h"

int BWriter (int argc, const char** argv)
{
   int		i, stat;
   const char*  filename = "message.xml";
   OSBOOL       trace = TRUE, verbose = FALSE;
   const OSOCTET* msgptr;

   // Process command line arguments

   if (argc > 1) {
      for (i = 1; i < argc; i++) {
         if (!strcmp (argv[i], "-v")) verbose = TRUE;
         else if (!strcmp (argv[i], "-o")) filename = argv[++i];
         else if (!strcmp (argv[i], "-notrace")) trace = FALSE;
         else {
            printf ("usage: writer [ -v ] [ -o <filename>\n");
            printf ("   -v  verbose mode: print trace info\n");
            printf ("   -o <filename>  write encoded msg to <filename>\n");
            printf ("   -notrace  do not display trace info\n");
            return 0;
         }
      }
   }

   // Create buffer and control objects

   SimpleArray myArray;
   OSXMLEncodeBuffer buffer;
   simpleArray_CC pdu (buffer, myArray);

   buffer.setDiag (verbose);

   // Populate structure of generated type

   OSXMLStringClass* str;

   str = new OSXMLStringClass ("Fred Jones");
   myArray.item.append (str);

   str = new OSXMLStringClass ("John Smith");
   myArray.item.append (str);

   for (i = 0; i < 10; i++) {
      myArray.numbers.elem[i] = i + 1;
   }
   myArray.numbers.n = 10;

   // Encode

   stat = pdu.encode();

   if (0 == stat) {
      if (trace) {
         msgptr = buffer.getMsgPtr();
         printf ("encoded XML message:\n");
         printf ("%s\n", (const char*)msgptr);
      }
   }
   else {
      printf ("Encoding failed\n");
      buffer.printErrorInfo();
      return stat;
   }

   // Write the encoded message out to the output file

   if (buffer.write (filename) <= 0) {
      printf ("Can't write to %s\n", filename);
      return -1;
   }

   return 0;
}
