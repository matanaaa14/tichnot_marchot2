//version1
// I used the solution of the test in system programming 1
//for some reason I doesn't understand my code have problem in using the function 
// it get's from the "client" ('delete_book','copy_book'), I tryed my best but I didn't
//could find where is the problem. 
//I know that I get errors if I run this code but they are all relate to the 
//using in the client function and couldn't find why.
#include "AdptArray.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
typedef struct AdptArray_
{
    int size;
    PElement* arr;
    DEL_FUNC del_func;
    COPY_FUNC copy_func;
    PRINT_FUNC print_func;
}AdptArray;

PAdptArray CreateAdptArray(COPY_FUNC cf, DEL_FUNC df,PRINT_FUNC pf){
    if(cf==NULL||df==NULL||pf==NULL){
        return NULL;}
    PAdptArray Parray=(PAdptArray)malloc(sizeof(AdptArray));
    if(Parray==NULL){
        return NULL;}
    Parray->size=0;
    Parray->arr=NULL;
    Parray->del_func=df;
    Parray->copy_func=cf;
    Parray->print_func=pf;
    return Parray;
}
void DeleteAdptArray(PAdptArray parray){
    int i;
    if(parray==NULL){
        return;
    }
    for(i=0;i<(parray->size);++i){
        if(((parray->arr)[i])!=NULL){
            parray->del_func((parray->arr)[i]);
            }
    }
    free(parray->arr);
    free(parray);
}
Result SetAdptArrayAt(PAdptArray parray, int index, PElement pnewElement){
    PElement* newPelementArray;
    if(parray==NULL){
        return FAIL;
    }
    if(index<0){
        return FAIL;
    }
    if(pnewElement==NULL){
        return FAIL;
    }
    if(index>parray->size){
        if((newPelementArray=(PElement*)calloc((index+1),sizeof(PElement)))==NULL){
            free(parray->arr);
            return FAIL;}
        memcpy(newPelementArray,parray->arr,(parray->size)*sizeof(PElement));
        //free(parray->arr);
        parray->arr=newPelementArray;
    }
    if((parray->arr)[index]!=NULL){
        parray->del_func((parray->arr)[index]);}
    //if(parray->copy_func==NULL)
        //return FAIL;
        
    (parray->arr)[index]=parray->copy_func(pnewElement);
    //if((parray->arr)[index]==NULL)
      //  return FAIL;
    if(index>=parray->size){
        parray->size=index+1;}
    return SUCCESS;
}
PElement GetAdptArrayAt(PAdptArray parray, int index){
     if(parray==NULL||index<0){
        return NULL;}
     //if(sizeof(parray->size)!=sizeof(int)){
       // return NULL;
      //}

    if(index>parray->size){
        return NULL;
    } 
    if((parray->arr)[index]==NULL){
        return NULL;}
    return (parray->arr)[index];
}
int GetAdptArraySize(PAdptArray parray){
    if(parray==NULL){
        return -1;}
    if(sizeof(parray->size)!=sizeof(int)){
        return -1;
    }
    return parray->size;
}
void PrintDB(PAdptArray parray){
    if(parray==NULL){
        return;}
    int i;
    for(i=0;i<parray->size;i++){
        if((parray->arr)[i]!=NULL){
            parray->print_func((parray->arr)[i]);}
    }

}