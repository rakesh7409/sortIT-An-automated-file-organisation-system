#include <stdio.h>
#include <dirent.h>
#include <stdlib.h> //malloc
#include <string.h>
#include "split.c"

// char ptr for storing retrieved words from the user
struct data{	
  char *a;
  char *b;
  char *c;
  char *d;
  char *e;
  char *f;
  char *g;
  char *h;
  char *i;
  char *j;
  char *k;
  char *l;	
}obj[209]; 

//storing char ptr values to array  
struct data Convert(char **t)
{
struct data d;

d.a=t[0];
d.b=t[1];
d.c=t[2];
d.d=t[3];
d.e=t[4];
d.f=t[5];
d.g=t[6];
d.h=t[7];
d.i=t[8];
d.j=t[9];
d.k=t[10];
d.l=t[11];
return(d);
}

//function declaration
int docfiles(char *name);  
void listFilesRecursively(char *path);
void listFilesRecursively1(char *path,char *fname);
void listFilesRecursively2(char *path);


int main()
{
    // Directory path to list files
    char path[100];
	
	printf("                                 SORT IT - An Automated File Organization System\n\n");
    // Input path from user
    printf("Enter path to list files: ");
    scanf("%s", path);
    printf("\n\n1. Content based\n");
    printf("2. Extention based\n");
    printf("3. User-Oriented\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
    	printf("if 1 ");
    	listFilesRecursively(path); //function call
	}
	else if(choice==3)
	{
		printf("if 3 ");
		char filename[100];
		printf("Enter folder name: ");
    	scanf("%s", &filename);
    	listFilesRecursively1(path,filename); //function call

	}
	else if(choice==2)
	{
		printf("if 2 ");
		listFilesRecursively2(path); //function call
	}
	else
	{
		printf("Wrong input\n");
		exit(0);
	}
    return 0;
}


/**
 * Lists all files and sub-directories recursively 
 * considering path as base path.
 */
void listFilesRecursively(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

	char bPath[100];
	char bPath1[100];
	char bPath2[100];
	char bPath3[100];
	
	strcpy(bPath1, basePath);
	strcpy(bPath2, basePath);
	strcpy(bPath3, basePath);
	
    // Unable to open directory stream
    if (!dir)
        return;
	  
	// Path for creating directory
	const char* mkdoc = strcat(bPath1, "\\JAVA\\");
	const char* mkdoc1 = strcat(bPath2, "\\C++\\");
	const char* mkdoc2 = strcat(bPath3, "\\Others\\");
	// Creating directory
	mkdir(mkdoc);
	mkdir(mkdoc1);
	mkdir(mkdoc2);

    int count1 = 0,count2 = 0,count3 = 0;
	
	strcpy(bPath, basePath);
    while ((dp = readdir(dir)) != NULL)
    {	
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
        	if(strstr(dp->d_name, ".doc"))
        	{
        		char dest[100];
        		char* first = strcat(strcat(bPath, "\\"),dp->d_name);
        		int option=docfiles(first);
        		if(option==1)
        		{
        		strcpy(dest, mkdoc);
        		char* first = bPath;
        		//char* first = strcat(strcat(bPath, "\\"),dp->d_name);
            	char* second = strcat(dest,dp->d_name);
            	printf("%s\n%s\n\n", first, second);
            	rename(first, second);
            	count1++;
				}
				else if(option==0)
        		{
        		strcpy(dest, mkdoc1);
        		char* first = bPath;
				//char* first = strcat(strcat(bPath, "\\"),dp->d_name);
            	char* second = strcat(dest,dp->d_name);
            	printf("%s\n%s\n\n", first, second);
            	rename(first, second);
            	count2++;
				}
				else
				{
					strcpy(dest, mkdoc2);
        		char* first = bPath;
				//strcat(strcat(bPath, "\\"),dp->d_name);
            	char* second = strcat(dest,dp->d_name);
            	printf("%s\n%s\n\n", first, second);
            	rename(first, second);
            	count3++;
				}
			}				
				strcpy(bPath, basePath);

 /*           // Construct new path from our base path
           strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            listFilesRecursively(path); 
*/
        }
    }
	
	if (count1==0)
		rmdir(mkdoc);
	if (count2==0)
		rmdir(mkdoc1);
	if (count3==0)
		rmdir(mkdoc2);		

		
    closedir(dir);
}

int docfiles(char *recf)
{
	int i,k;
  FILE *fp = fopen("vocab.txt", "r");
	if(fp == NULL){
		printf("Could not open file\n");
		return;
	}
	char **data = malloc(2 * sizeof(char *));
	int j;
	for(j = 0 ; j < 2 ; j++)
		data[j] = malloc(500 * sizeof(char));
	j = 0;
	do{
		fscanf(fp, "%s", data[j]);
		j++;
	}while(!feof(fp));

	/*for(j = 0 ; j < 2 ; j++)
		printf("%s\n", data[j]);*/


	//printf("\n\n Converting to stucture variable \n\n");
  	struct data r[2];
	for(i = 0 ; i < 2 ; i++){	
		char **token = split(data[i], ',');
		r[i] = Convert(token);
		/*printf("%s\n", r[i].a);
		printf("%s\n", r[i].b);
		printf("%s\n", r[i].c);
		printf("%s\n", r[i].d);
		printf("%s\n", r[i].e);
		printf("%s\n", r[i].f);
		printf("%s\n", r[i].g);
		printf("%s\n", r[i].h);
		printf("%s\n", r[i].i);
		printf("%s\n", r[i].j);
		printf("%s\n", r[i].k);
		printf("%s\n", r[i].l);*/
		free(data[i]);
	}
  fclose(fp);
  char *ch="s";
	char df;
	//char text;
	long unsigned int offset;
	offset = 2561;

	FILE *fileptr;
	char *buffer,*text;
	long filelen;
	int count,n=0;
	count=0;
	fileptr = fopen(recf, "rb");  // Open the file in binary mode
	fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
	filelen = ftell(fileptr);             // Get the current byte offset in the file
	rewind(fileptr);                      // Jump back to the beginning of the file
	filelen =filelen-2560;
	buffer = (char *)malloc((filelen+1)*sizeof(char)); // Enough memory for file + \0
	fseek(fileptr, 2560, SEEK_CUR);
	fread(buffer, filelen, 1, fileptr); // Read in the entire file
	fclose(fileptr); // Close the file
	for ( i = 0; i < strlen(buffer); ++i)
	{
		if(buffer[i]>127)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	text = (char *)malloc((count+1)*sizeof(char)); // Enough memory for file + \0
	for ( i = 0; i < count; i++)
	{
		text[i]=buffer[i];
		/*****************************************************************************
	    *	This Printf printing text content of the doc in one charchter per line   *
		*****************************************************************************/
	//	printf("%c",text[i]);
		if(text[i]==' ')
		{
			n=n+1;
		}
		
	}
	k=0;
	char str1[n+1][100];
	char temp[100]="\0";
	char t2[100]="\0";
	for(i=0;i<count;i++)
	{
		size_t len = strlen(temp);
		
		if(text[i]!=' ')
		{
			temp[len++]=text[i];
			temp[len] = '\0';
		}
		else
		{
			//printf("1 %s\n",temp);
			strcpy(str1[k],temp);
			k=k+1;
			strcpy(temp,t2);
		}
	}
	for(i=0;i<k;i++)
	{
		char shabd[100];
		strcpy(shabd,str1[i]);
		for(j=0;shabd[j]!='\0';j++)
		{
			if(shabd[j]==',' || shabd[j]=='.')
			{
				shabd[j]='\0';
				break;
			}
		}
		strcpy(str1[i],shabd);
	}
	int counter[2]={0,0};
	int z=0;
	/*for(i=0;i<k;i++)
	{
		printf(" %s\n",str1[i]);
	}*/
	for(i=0;i<2;i++)
	{
		for(j=0;j<k;j++)
		{
			if(strcasecmp(str1[j],r[i].a)==0 || strcasecmp(str1[j],r[i].b)==0 || strcasecmp(str1[j],r[i].c)==0 || strcasecmp(str1[j],r[i].d)==0 || strcasecmp(str1[j],r[i].e)==0 || strcasecmp(str1[j],r[i].f)==0 || strcasecmp(str1[j],r[i].g)==0 || strcasecmp(str1[j],r[i].h)==0 || strcasecmp(str1[j],r[i].i)==0 || strcasecmp(str1[j],r[i].j)==0 || strcasecmp(str1[j],r[i].k)==0 || strcasecmp(str1[j],r[i].l)==0)
			{
				counter[i]=counter[i]+1;
			}
		}
		//printf("Row %d Match Cases:- %d\n",(i+1),counter[i]);
	}
	if(counter[0]>counter[1])
	{
		//printf("this is java");
		return 1;
	}
	else if(counter[1]>counter[0])
	{
		//printf("this is c");
		return 0;
	}
	else
	{
		//printf("this is misc");
		return 2;
	}
}
void listFilesRecursively1(char *basePath,char *folderName)
{
    struct dirent *dp;
    DIR *dir = opendir(basePath);

	char f[100];
	strcpy(f, folderName);
	char bPath[100];
	strcpy(bPath, basePath);
	
	char bPath1[100];
	strcpy(bPath1, basePath);
    // Unable to open directory stream
    
    if (!dir){
    	printf("ERROR");
    	return;
	}
        
	char* mkp1 = strcat(bPath1, "\\");
	char* mkp2 = strcat(folderName, "\\");
	char* mkfolder = strcat(mkp1, mkp2);
	
	mkdir(mkfolder);

	int count1 = 0;
	
	//strcpy(bPath, basePath);
    while ((dp = readdir(dir)) != NULL)
    {
    
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
        
        	if(strstr(dp->d_name, f)&&strstr(dp->d_name, ".")){
        	  //printf("%s\n", dp->d_name);
            	char dest1[100];
            	strcpy(dest1, mkfolder);
            	char* first1 = strcat(strcat(bPath, "\\"),dp->d_name);
            	char* second1 = strcat(dest1,dp->d_name);
              //printf("%s\n%s\n\n", first1, second1);
            	rename(first1, second1);
            	count1++;
			}	
				strcpy(bPath, basePath);
          
 /*           // Construct new path from our base path
           strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            listFilesRecursively(path); 
*/
        }
    }

	if (count1==0)
		rmdir(mkfolder);
		
    closedir(dir);
}
void listFilesRecursively2(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

	char bPath[100];
	char bPath1[100];
	char bPath2[100];
	char bPath3[100];
	char bPath4[100];
	char bPath5[100];
	char bPath6[100];
	char bPath7[100];
	char bPath8[100];
  	char bPath9[100];
	
	strcpy(bPath1, basePath);
	strcpy(bPath2, basePath);
	strcpy(bPath3, basePath);
	strcpy(bPath4, basePath);
	strcpy(bPath5, basePath);
	strcpy(bPath6, basePath);
	strcpy(bPath7, basePath);
	strcpy(bPath8, basePath);
  	strcpy(bPath9, basePath);
	
    // Unable to open directory stream
    if (!dir)
        return;
	  
	// Path for creating directory
	const char* mkdoc = strcat(bPath1, "\\Documents(SortIt)\\");
	const char* mkvid = strcat(bPath2, "\\Videos(SortIt)\\");
	const char* mkimg = strcat(bPath3, "\\Pictures(SortIt)\\");
	const char* mkaud = strcat(bPath4, "\\Audios(SortIt)\\");
	const char* mkpro = strcat(bPath5, "\\Projects(SortIt)\\");
	const char* mkdev = strcat(bPath6, "\\Developer(SortIt)\\");
	const char* mkzip = strcat(bPath7, "\\Zip(SortIt)\\");
	const char* mkapp = strcat(bPath8, "\\Applications(SortIt)\\");
  	const char* mkoth = strcat(bPath9, "\\Others(SortIt)\\");
	
	// Creating directory
	mkdir(mkdoc);
	mkdir(mkvid);
	mkdir(mkimg);
	mkdir(mkaud);
	mkdir(mkpro);
	mkdir(mkdev);
	mkdir(mkzip);
	mkdir(mkapp);
  	mkdir(mkoth);
	
	int count = 0,count1 = 0,count2 = 0,count3 = 0,count4 = 0,count5 = 0,count6 = 0,count7 = 0,count8 = 0;
	strcpy(bPath, basePath);
    while ((dp = readdir(dir)) != NULL)
    {	
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
        	if(strstr(dp->d_name, ".pptx")||strstr(dp->d_name, ".PDF")||strstr(dp->d_name, ".docx")||strstr(dp->d_name, ".pub")||strstr(dp->d_name, ".ppt")||strstr(dp->d_name, ".csv")||strstr(dp->d_name, ".pps")||strstr(dp->d_name, ".xls")||strstr(dp->d_name, ".xlsx")||strstr(dp->d_name, ".doc")||strstr(dp->d_name, ".pdf")||strstr(dp->d_name, ".rtf")||strstr(dp->d_name, ".txt")||strstr(dp->d_name, ".wpd")||strstr(dp->d_name, ".wks")||strstr(dp->d_name, ".tex")||strstr(dp->d_name, ".xlr")||strstr(dp->d_name, ".ods")||strstr(dp->d_name, ".mdb")||strstr(dp->d_name, ".log")||strstr(dp->d_name, ".db")||strstr(dp->d_name, ".dbf")||strstr(dp->d_name, ".dat")||strstr(dp->d_name, ".key")||strstr(dp->d_name, ".odp")){
            //	printf("%s\n", dp->d_name);
            	char dest[100];
            	strcpy(dest, mkdoc);
            	char* first = strcat(strcat(bPath, "\\"),dp->d_name);
            	char* second = strcat(dest,dp->d_name);
            //	printf("%s\n%s\n\n", first, second);
            	rename(first, second);
            	count++;
			}
			
			else if(strstr(dp->d_name, ".mp4")||strstr(dp->d_name, ".mkv")||strstr(dp->d_name, ".wmv")||strstr(dp->d_name, ".mov")||strstr(dp->d_name, ".3gp")||strstr(dp->d_name, ".avi")||strstr(dp->d_name, ".flv")||strstr(dp->d_name, ".m4v")||strstr(dp->d_name, ".mpg")||strstr(dp->d_name, ".mpeg")||strstr(dp->d_name, ".vtt")||strstr(dp->d_name, ".srt")){
            //	printf("%s\n", dp->d_name);
            	char dest1[100];
            	strcpy(dest1, mkvid);
            	char* first1 = strcat(strcat(bPath, "\\"),dp->d_name);
            	char* second1 = strcat(dest1,dp->d_name);
            //	printf("%s\n%s\n\n", first1, second1);
            	rename(first1, second1);
            	count1++;
			}
			
			else if(strstr(dp->d_name, ".png")||strstr(dp->d_name, ".PNG")||strstr(dp->d_name, ".jpg")||strstr(dp->d_name, ".JPG")||strstr(dp->d_name, ".jpeg")||strstr(dp->d_name, ".gif")||strstr(dp->d_name, ".bmp")||strstr(dp->d_name, ".ico")||strstr(dp->d_name, ".psd")||strstr(dp->d_name, ".ai")||strstr(dp->d_name, ".tiff")||strstr(dp->d_name, ".tif")||strstr(dp->d_name, ".CR2")){
            //	printf("%s\n", dp->d_name);
            	char dest2[100];
            	strcpy(dest2, mkimg);
            	char* first2 = strcat(strcat(bPath, "\\"),dp->d_name);
            	char* second2 = strcat(dest2,dp->d_name);
            //	printf("%s\n%s\n\n", first2, second2);
            	rename(first2, second2);
            	count2++;
			}
			
			else if(strstr(dp->d_name, ".mp3")||strstr(dp->d_name, ".aif")||strstr(dp->d_name, ".aiff")||strstr(dp->d_name, ".wav")||strstr(dp->d_name, ".cda")||strstr(dp->d_name, ".mid")||strstr(dp->d_name, ".midi")||strstr(dp->d_name, ".wma")||strstr(dp->d_name, ".mpa")||strstr(dp->d_name, ".ogg")||strstr(dp->d_name, ".wpl")){
            //	printf("%s\n", dp->d_name);
            	char dest3[100];
            	strcpy(dest3, mkaud);
            	char* first3 = strcat(strcat(bPath, "\\"),dp->d_name);
            	char* second3 = strcat(dest3,dp->d_name);
            //	printf("%s\n%s\n\n", first3, second3);
            	rename(first3, second3);
				count3++;
			}
			
			else if(strstr(dp->d_name, ".psd")||strstr(dp->d_name, ".ae")||strstr(dp->d_name, ".pr")||strstr(dp->d_name, ".svg")||strstr(dp->d_name, ".stl")||strstr(dp->d_name, ".stp")){
            //	printf("%s\n", dp->d_name);
            	char dest4[100];
            	strcpy(dest4, mkpro);
            	char* first4 = strcat(strcat(bPath, "\\"),dp->d_name);
            	char* second4 = strcat(dest4,dp->d_name);
            //	printf("%s\n%s\n\n", first4, second4);
            	rename(first4, second4);
            	count4++;
			}
			
			else if(strstr(dp->d_name, ".html")||strstr(dp->d_name, ".py")||strstr(dp->d_name, ".php")||strstr(dp->d_name, ".c")||strstr(dp->d_name, ".cpp")||strstr(dp->d_name, ".java")||strstr(dp->d_name, ".sql")||strstr(dp->d_name, ".css")||strstr(dp->d_name, ".htm")||strstr(dp->d_name, ".js")||strstr(dp->d_name, ".jsp")||strstr(dp->d_name, ".xhtml")||strstr(dp->d_name, ".class")||strstr(dp->d_name, ".h")){
            //	printf("%s\n", dp->d_name);
            	char dest5[100];
            	strcpy(dest5, mkdev);
            	char* first5 = strcat(strcat(bPath, "\\"),dp->d_name);
            	char* second5 = strcat(dest5,dp->d_name);
            //	printf("%s\n%s\n\n", first5, second5);
            	rename(first5, second5);
            	count5++;
			}
			
			else if(strstr(dp->d_name, ".zip")||strstr(dp->d_name, ".rar")||strstr(dp->d_name, ".pkg")||strstr(dp->d_name, ".tar")||strstr(dp->d_name, ".z")||strstr(dp->d_name, ".rpm")||strstr(dp->d_name, ".deb")||strstr(dp->d_name, ".arj")||strstr(dp->d_name, ".7z")||strstr(dp->d_name, ".nc")){
            //	printf("%s\n", dp->d_name);
            	char dest6[100];
            	strcpy(dest6, mkzip);
            	char* first6 = strcat(strcat(bPath, "\\"),dp->d_name);
            	char* second6 = strcat(dest6,dp->d_name);
            //	printf("%s\n%s\n\n", first6, second6);
            	rename(first6, second6);
            	count6++;
			}
			
			else if(strstr(dp->d_name, ".exe")||strstr(dp->d_name, ".apk")||strstr(dp->d_name, ".msi")||strstr(dp->d_name, ".RData")||strstr(dp->d_name, ".Rhistory")){
            //	printf("%s\n", dp->d_name);
            	char dest7[100];
            	strcpy(dest7, mkapp);
            	char* first7 = strcat(strcat(bPath, "\\"),dp->d_name);
            	char* second7 = strcat(dest7,dp->d_name);
            //	printf("%s\n%s\n\n", first7, second7);
            	rename(first7, second7);
            	count7++;
			}
			
			else if(strstr(dp->d_name, ".")){
            	printf("%s\n", dp->d_name);
            	char dest8[100];
            	strcpy(dest8, mkoth);
            	char* first8 = strcat(strcat(bPath, "\\"),dp->d_name);
            	char* second8 = strcat(dest8,dp->d_name);
            //	printf("%s\n%s\n\n", first8, second8);
            	rename(first8, second8);
            	count8++;
			}
			
				
				strcpy(bPath, basePath);

 /*           // Construct new path from our base path
           strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            listFilesRecursively(path); 
*/
        }
    }
	
	if (count==0)
		rmdir(mkdoc);
		
	if (count1==0)
		rmdir(mkvid);
		
	if (count2==0)
		rmdir(mkimg);
		
	if (count3==0)
		rmdir(mkaud);
		
	if (count4==0)
		rmdir(mkpro);
		
	if (count5==0)
		rmdir(mkdev);
		
	if (count6==0)
		rmdir(mkzip);
		
	if (count7==0)
		rmdir(mkapp);
		
	if (count8==0)
		rmdir(mkoth);
		
    closedir(dir);
}
