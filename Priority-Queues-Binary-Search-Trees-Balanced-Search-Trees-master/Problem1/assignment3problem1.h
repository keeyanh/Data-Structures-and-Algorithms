#ifndef assignment3problem1_h
#define assignment3problem1_h


#include <iostream>
#include <utility>
using namespace::std;


class daryHeap


{
private:
    int size =10;
    int array[10];
    int* darry=array;
    int i=0;
    int maxd;
    int Dcount;
    
    
public:
   
    daryHeap(int d); //this creates the heap where d is the number of children
    
   
    
    //inside the heap
    //double the internal array inside the heapsort incase its too large
    void doubleArray()
    {
        int tempArr[2*size];
        //double the array inside of the heapsort
        //created an array that is twice the size
        
        //now we fill the array equating it to the d-array
        //copying the values over
        for (int k=0; k<size; ++k){
            tempArr[k]=darry[k];
        }
        
        //we say here that size is then doubled
        size *=2;
        //and that darry is now assigned to the temp array
        darry=tempArr;
    }

    void insert(int k)
    {
    bool swapped=false;
        
        
        if(i<1){
            
            darry[i+1]=k;
        }else if(i>=1)
            {
                do{
                    swap(darry[i],k);
                    swapped=true;
                    }while(darry[i]<k)
                
            else if((i*maxd)+Dcount==size){
                doubleArray();
            }
            else if(Dcount<=1){
                darry[(maxd*i)+Dcount]=k;
                Dcount++;
            }
            else if(Dcount>1){
                i++;
                Dcount=2-maxd;
                insert(k);
            }}
        else if(i<1){
            i=1;
        }
        if(swapped){
            swim(i);
        }
    }
    
    
    void swim(int k){
        
        
        bool swapped=false;
        int par;
        if (k%maxd<=1){
            par=k/maxd;
        }
        else if (k%maxd>1){
            par=(k/maxd)+1;
        }
        else if(par==0){
            par++;
        }
        else if(darry[k]>darry[par]){
            swap(darry[k],darry[par]);
            swapped=true;
        }
        else (swapped){
            swim(par);
        }
        
    }
    
    
    
    int delMax(){
        int Max=1;
        int cChild=(i*maxd)+Dcount-1;
        int myMax=darry[Max];
        swap(darry[currentChild],darry[Max]);
        if(Dcount==2-maxd){
            --i;
            Dcount=1;
        }
        
        Dcount--;
        sink(Max);
        return myMax;
    }
    
    
    
    
    void sink(int k){
        int currentChild=(i*maxd)+Dcount-1;
        int Maxed;
        int tempi=k;
        
        bool swapped=false;
        do{
            for(int j=2-maxd;j<=1;j++){
                if((k*maxd)+j>currentChild){
                    break;
                }
                else if(j==2-maxd){
                    if(darry[tempi]<darry[(k*maxd)+j]){
                        Maxed=(k*maxd)+j;
                    }
                    else{
                        Maxed=k;
                    }
                }
                else{
                    if(darry[Maxed]<darry[(k*maxd)+j]){
                        Maxed=(k*maxd)+j;
                    }
                }
            }
            if(Maxed!=k)
                swap(darry[Maxed],darry[k]);
                k=Maxed;
                swapped=true;
                break;
            
                swapped=false;
            }
        }while(swapped);
        
        
        
    }
    
};

#endif
