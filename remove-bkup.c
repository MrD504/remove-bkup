/*********************************************************************************
 *  Description: Remove backup files from computer
 *  Author: Dave
 *  Date: 29/08/2108
 ********************************************************************************/

#include<stdio.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char **argv)
{
    DIR *d;

    struct dirent *dir;
    printf("Please enter the root path of the folder structure you would like to clean\n");
    char * filepath = argv[1];
    printf("Filepath chosen: %s\n", filepath);
    d = opendir(filepath);

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            char * filename = dir->d_name;
            if(strstr(filename,".bkup"))
            {
                printf("%s\n", dir->d_name);
                if(remove(filename) == 0){
                    printf("Removed %s successfully\n", filename);
                } else {
                    printf("Unable to delete file\n");
                };
            }
        }
        closedir(d);
    }

    return 0;
}