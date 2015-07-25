#ifndef LINH_HELPER_CPP
#define LINH_HELPER_CPP

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include <iostream>
#include <string>
#include <stack>

using namespace std;


void LINH_PRINT_WEB(int num, const wchar_t* path, float score){
    static FILE *__result_output_html = fopen("searchResults.html","w");
    if (__result_output_html != NULL) printf("OK, ");
    if(fwprintf(__result_output_html,
        L"<p>%d. <a href=%s>%s</a></p><br>\n",
        num,
        path,
        path))
        printf("Print OK!");

}

void ProcessDirectory(std::string, stack<string>& );
void ProcessFile(std::string);
void ProcessEntity(struct dirent*, stack<string>& );

void LINH_LIST_DIRECTORY(std::string directory, stack<string>& output)
{
    ProcessDirectory(directory, output);
}

string __temp_root_path = "";
void ProcessDirectory(std::string directory, stack<string>& output)
{
    std::string dirToOpen = __temp_root_path + directory;
    DIR *dir = opendir(dirToOpen.c_str());

    //set the new path for the content of the directory
    __temp_root_path = dirToOpen + "/";

    //Output dirToOpen.c_str();
    //std::cout << "Process directory: " << dirToOpen.c_str() << std::endl;
    output.push(dirToOpen);

    if(NULL == dir)
    {
        std::cout << "could not open directory: " << dirToOpen.c_str() << std::endl;
        return;
    }

    struct dirent *entity = readdir(dir);

    while(entity != NULL)
    {
        ProcessEntity(entity,output);
        entity = readdir(dir);
    }

    //we finished with the directory so remove it from the path
    __temp_root_path.resize(__temp_root_path.length() - 1 - directory.length());
    closedir(dir);
}

void ProcessEntity(struct dirent* entity, stack<string>& output)
{
    //find entity type
    if(entity->d_type == DT_DIR)
    {//it's an direcotry
        //don't process the  '..' and the '.' directories
        if(entity->d_name[0] == '.')
        {
            return;
        }

        //it's an directory so process it
        ProcessDirectory(std::string(entity->d_name),output);
        return;
    }

    if(entity->d_type == DT_REG)
    {//regular file
        ProcessFile(std::string(entity->d_name));
        return;
    }

    //there are some other types
    //read here http://linux.die.net/man/3/readdir
    std::cout << "Not a file or directory: " << entity->d_name << std::endl;
}


void ProcessFile(std::string file)
{
    //std::cout << "Process file     : " << file.c_str() << std::endl;
    //if you want to do something with the file add your code here
}

#endif
