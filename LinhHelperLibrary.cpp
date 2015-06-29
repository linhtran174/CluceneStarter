#ifndef LINH_HELPER_
#define LINH_HELPER_

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include <iostream>
#include <string>

void LinhTest()
{
    printf("LinhTestOK!!\n");
}
void ProcessDirectory(std::string directory);
void ProcessFile(std::string file);
void ProcessEntity(struct dirent* entity);

void _LINH_DIRECTORY_FACTORY(std::string directory, int command){
    
}



void ProcessDirectory(std::string directory)
{
	std::string path = "/";
    std::string dirToOpen = path + directory;
    DIR *dir = opendir(dirToOpen.c_str());

    //set the new path for the content of the directory
    path = dirToOpen + "/";

    //Output dirToOpen.c_str();
    std::cout << "Process directory: " << dirToOpen.c_str() << std::endl;
    _LINH_DIRECTORY_LIST(dirToOpen.c_str());

    if(NULL == dir)
    {
        std::cout << "could not open directory: " << dirToOpen.c_str() << std::endl;
        return;
    }

    struct dirent *entity = readdir(dir);

    while(entity != NULL)
    {
        ProcessEntity(entity);
        entity = readdir(dir);
    }

    //we finished with the directory so remove it from the path
    path.resize(path.length() - 1 - directory.length());
    closedir(dir);
}

void ProcessEntity(struct dirent* entity)
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
        ProcessDirectory(std::string(entity->d_name));
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
    std::cout << "Process file     : " << file.c_str() << std::endl;

    //if you want to do something with the file add your code here
}

#endif
