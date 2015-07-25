/* fwprintf example */
#include <stdio.h>
#include <wchar.h>

int main ()
{
   FILE * pFile;
   int n;
   wchar_t name [100];

   pFile = fopen ("searchResults.html","w");
   for (n=0 ; n<3 ; n++)
   {
     fwprintf (stdout, L"please, enter a name: ");
     fgetws (name, 100, stdin);
     fwprintf (pFile, L"Name %d: %s",n,name);
   }
   fclose (pFile);

   return 0;
}