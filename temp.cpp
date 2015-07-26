/* fwprintf example */
#include <stdio.h>
#include <stddef.h>
#include <wchar.h>

int main ()
{
   FILE * pFile;
   wchar_t name = L'\xb31';

   pFile = fopen ("searchResults.html","w");
   fwprintf(pFile,L"Character: %lc",name);
   // for (n=0 ; n<3 ; n++)
   // {
   //   fwprintf (stdout, L"please, enter a name: ");
   //   fgetws (name, 100, stdin);
   //   fwprintf (pFile, L"Name %d: %s",n,name);
   // }
   fclose (pFile);

   return 0;
}

// int C()
// {
// 	fstream f;
// 	f.open("searchResults.html", ios::out);

// }