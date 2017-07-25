/*
 * This program displays the names of all files in the current directory.
 */

#include <dirent.h> 
#include <stdio.h> 
 #define _GNU_SOURCE
 #include <string.h>

#include <stdlib.h>



int imageFolder(char* name,char* number){


  int len = strlen(number);
  if (len > 0 && number[len-1]== '\n')
  {
    number[len-1] = 0;

    int len = strlen(number);
    if (len > 0 && number[len-1] == '\r')
    {
      number[len-1] = 0;
    }
  }

    len = strlen(name);

    if(strstr(".txt", name) == NULL) {
      name[len-4] = '\0';    
    }
    

    char dir[90]= "";
    strcat(dir," mkdir -p ./images/");
    strcat(dir,"query");
    system(dir);



    char src[90] ="";

    strcpy(src,  "cp ./mirflickr/im");

    number[strcspn(number, "\n")] = 0;
    strcat(src,number);
    strcat(src,".jpg ");
    strcat(src,"./images/");
    strcat(src,"query");
    strcat(src,"/");
    strcat(src,number);
    strcat(src,".jpg ");
    system(src);
}


int folderized(char* name){


   FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char src[50], dest[50];

    strcpy(src,  "./anotations/");
    strcpy(dest, name);

    strcat(src,dest);
    //printf("%s\n",src );

    fp = fopen(src,"r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

	int counter=0;
int counter_files=0;
    while ((read = getline(&line, &len, fp)) != -1) {
	counter=counter+1;
	if(counter>50)
	{
        char teste[50]="";
        strcat(teste,name);
        imageFolder(teste,line);
	counter_files=counter_files+1;
	if(counter_files>36)
	break;
	}

    }

    fclose(fp);
    if (line)
        free(line);
}

int main(void)
{
  DIR           *d;
  struct dirent *dir;
  d = opendir("./anotations");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
      folderized(dir->d_name);
    }

    closedir(d);
  }

  return(0);
}


