#include <iostream>

using namespace std;

//C++ doesnt allow there to be arbitrary multidimensonal arrays thats why i have bounds
void ProblemFourB(int myA[10][2],int sum){
    int C1;
    int C2;
    for(C1=0;C1<10;C1++){
        for(C2=0;C2<10;C2++){
            
            if((myA[C1][0]+myA[C2][1])==sum){
                cout<<"("<<myA[C1][0]<<" , "<<myA[C2][1]<<")"<<endl;
            }
        }
    }
}
int main()
{
    
    int storedInt[10][2]={{0,0},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8},{9,9}};
    bool outofB=true;
    int Sum;
    while(outofB==true){
        cout<<"Enter numbers between 1-18"<<endl;
        cin>>Sum;
        if(Sum<0||Sum>18){
            cout<<"outside of bounds\n";
        }
        else{
            outofB=false;
        }
    }
    ProblemFourB(storedInt,Sum);
    return 0;
}