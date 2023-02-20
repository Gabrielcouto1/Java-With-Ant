#ifndef CREATEXML_C
#define CREATEXML_C

#ifdef _WIN32
    #define move "move "
    #define clean "cls"
#elif __linux__
    #define move "mv "
    #define clean "clear"
#endif

void createxml(char *projectname);
char* getJarName(char str[]);
char *getPackageName(char str[]);
void createProjectDirectories(char *projectname);
char* createMain(char *projectname);

#endif