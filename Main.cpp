/*------------------------------------------------------------------------------
* Copyright (C) 2003-2006 Ben van Klinken and the CLucene Team
* 
* Distributable under the terms of either the Apache License (Version 2.0) or 
* the GNU Lesser General Public License, as specified in the COPYING file.
------------------------------------------------------------------------------*/
#include "CLucene/StdHeader.h"
#include "CLucene/clucene-config.h"

#include "CLucene.h"
#include "CLucene/util/Misc.h"

//test for memory leaks:
#ifdef _MSC_VER
#ifdef _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#endif
#endif

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <cctype>
#include <string.h>
#include <algorithm>

#include "CLucene/StdHeader.h"
#include "CLucene/clucene-config.h"

#include "CLucene.h"
#include "CLucene/util/CLStreams.h"
#include "CLucene/util/dirent.h"
#include "CLucene/config/repl_tchar.h"
#include "CLucene/util/Misc.h"
#include "CLucene/util/StringBuffer.h"


using namespace std;
using namespace lucene::index;
using namespace lucene::analysis;
using namespace lucene::util;
using namespace lucene::store;
using namespace lucene::document;

#include <stack>
#include "LinhHelperLibrary.h"

//void DeleteFiles(const char* dir);
void IndexFiles(const string& path, const string& target, const bool clearIndex);
void SearchFiles(const char* index);
void getStats(const char* directory);

int main( int32_t argc, char** argv ){

	//Dumper Debug
	#ifdef _MSC_VER
	#ifdef _DEBUG
		_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_CHECK_CRT_DF );
		_crtBreakAlloc=-1;
	#endif
	#endif

	uint64_t str = Misc::currentTimeMillis();
	try{
		printf("____________________________________________________\n");
		printf("LinhTran's customized Clucene search application\n");
		printf("____________________________________________________\n");
		printf("Location of text files to be indexed: ");
		string files;
		cin >> files;
		cout << "files: \"" << files << "\"" << endl;
		
		/*printf("Location to store the LUCENE index: ");
		char ndx[250];
		tmp = fgets(ndx,250,stdin);
		if ( tmp == NULL ) return 1;
		ndx[strlen(ndx)-1] = 0;*/
		char ndx[] = "/home/linh/Desktop/index";

		//Find folder in C++


		IndexFiles(files,ndx,true);
		cout << "Index Done!!" << endl;
		getchar();
		getStats(ndx);
		SearchFiles(ndx);
		//DeleteFiles(ndx);

    }catch(CLuceneError& err){
        printf("Error: %s\n", err.what());
    }catch(...){
        printf("Unknown error\n");
    }

	_lucene_shutdown(); //clears all static memory
    //print lucenebase debug

	//Debugging techniques:
	//For msvc, use this for breaking on memory leaks: 
	//	_crtBreakAlloc
	//for linux, use valgrind

	printf ("\n\nTime taken: %d\n\n", (int32_t)(Misc::currentTimeMillis() - str));
	return 0;
}
