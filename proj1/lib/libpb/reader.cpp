/* This test driver program reads an encoded record from a file         */
/* and decodes it and displays the results..                            */

#include <stdio.h>
#include <stdlib.h>
#include "rtxsrc/rtxStream.h"
#include "rtxsrc/OSRTFileInputStream.h"
#include "simpleArray.h"
#include "rtxmlsrc/rtXmlCppMsgBuf.h"

int BReader (int argc, const char** argv)
{
   int		i, stat;
   const char*  filename = "message.xml";
   OSBOOL       trace = TRUE, verbose = FALSE;

   /* Process command line arguments */

   if (argc > 1) {
      for (i = 1; i < argc; i++) {
         if (!strcmp (argv[i], "-v")) verbose = TRUE;
         else if (!strcmp (argv[i], "-i")) filename = argv[++i];
         else if (!strcmp (argv[i], "-notrace")) trace = FALSE;
         else {
            printf ("usage: reader [ -v ] [ -i <filename>] [ -notrace ]\n");
            printf ("   -v  verbose mode: print trace info\n");
            printf ("   -i <filename>  read encoded msg from <filename>\n");
            printf ("   -notrace  do not display trace info\n");
            return 0;
         }
      }
   }

   OSRTFileInputStream in (filename);
   OSXMLDecodeBuffer decodeBuffer (in);

   if (decodeBuffer.getStatus ()) {
      decodeBuffer.printErrorInfo();
      return decodeBuffer.getStatus ();
   }

   SimpleArray  value;
   simpleArray_CC simpleArray (decodeBuffer, value);

   if (verbose) 
      rtxSetDiag (simpleArray.getCtxtPtr(), 1);

   // Decode

   stat = simpleArray.decode();

   if (0 == stat) {
      if (trace) {
         printf ("decoded XML message:\n");
         simpleArray.print ("simpleArray");
         printf ("\n");
      }
   }
   else {
      printf ("Encoding failed\n");
      decodeBuffer.printErrorInfo();
      return stat;
   }

   return 0;
}

