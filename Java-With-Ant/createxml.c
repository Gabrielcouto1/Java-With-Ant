#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "createxml.h"

void createxml(char *projectname){
    FILE *fp;

    fp=fopen("build.xml","w+");
    
    if(fp==NULL){
        printf("\nNao foi possivel criar o projeto.");
        return;
    }

    fprintf(fp,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    fprintf(fp,"\n<project name=\"%s\" default=\"run\" basedir=\".\">",projectname);
    fprintf(fp,"\n\n  <target name=\"compile\">");
    fprintf(fp,"\n    <mkdir dir=\"bin\"/>");
    fprintf(fp,"\n    <javac srcdir=\"src/%s\" destdir=\"bin\"/>",getPackageName(projectname));
    fprintf(fp,"\n  </target>");
    fprintf(fp,"\n\n  <target name=\"jar\" depends=\"compile\">");
    fprintf(fp,"\n    <jar destfile=\"%s.jar\" basedir=\"bin\">",getJarName(projectname));
    fprintf(fp,"\n      <manifest>");
    fprintf(fp,"\n        <attribute name=\"Main-Class\" value=\"%s.%s\"/>",getPackageName(projectname),projectname);
    fprintf(fp,"\n      </manifest>");
    fprintf(fp,"\n    </jar>");
    fprintf(fp,"\n  </target>");
    fprintf(fp,"\n\n  <target name=\"run\" depends=\"jar\">");
    fprintf(fp,"\n    <java fork=\"true\" jar=\"%s.jar\"/>",getJarName(projectname));
    fprintf(fp,"\n  </target>");
    fprintf(fp,"\n</project>");

    fclose(fp);
    createProjectDirectories(projectname);
}

char* getJarName(char str[]){
    char *new_str;
    int j = 0;

    new_str=malloc(255*sizeof(char));

    for (int i = 0; i < strlen(str); i++) {
        if (isupper(str[i])) {
            if (i > 0) {
                new_str[j++] = '_';
            }
            new_str[j++] = tolower(str[i]);
        } else {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';
    return new_str;
}

char *getPackageName(char str[]){
    char *new_str;
    int i;
    new_str=malloc(255*sizeof(char));

    for(i=0;str[i];i++)
        new_str[i]=tolower(str[i]);
    new_str[i]='\0';
    return new_str;
}

void createProjectDirectories(char *projectname){
    char str[255], projname[255];
    strcpy(projname,projectname);
    strcat(projname,"\0");
    strcpy(str,"\0");

    system("mkdir src");
    system("mkdir bin");

    strcpy(str,"mkdir ");
    strcat(str,getPackageName(projectname));
    system(str);

    strcpy(str, move);
    strcat(str,createMain(projectname));
    strcat(str," ");
    strcat(str, getPackageName(projectname));
    system(str);

    strcpy(str, move);
    strcat(str, getPackageName(projectname));
    strcat(str," src\0");
    system(str);
    
    strcpy(str, "mkdir ");
    strcat(str, projname);
    system(str);

    strcpy(str, move);
    strcat(str,"src ");
    strcat(str, projname);
    system(str);

    strcpy(str, move);
    strcat(str,"bin ");
    strcat(str, projname);
    system(str);

    strcpy(str, move);
    strcat(str,"build.xml ");
    strcat(str, projname);
    system(str);

}

char* createMain(char *projectname){
    FILE *fp;
    int size=strlen(projectname)+5;
    char *main;
    main=malloc(size*sizeof(char));

    strcpy(main,"");
    strcpy(main,projectname);
    strcat(main,".java");

    fp=fopen(main,"w+");

    fprintf(fp,"package %s;",getPackageName(projectname));
    fprintf(fp,"\n\npublic class %s{",projectname);
    fprintf(fp,"\n    public static void main(String[] args){");
    fprintf(fp,"\n        ");
    fprintf(fp,"\n    }");
    fprintf(fp,"\n}");

    fclose(fp);
    return main;
}