#include <iostream>

using namespace std;
class NormalStack{

private:
    struct Node{
        int d;
        Node* n;
        Node* p;
    };
    Node* temp;
    Node* first;
    int Ele=0;

public:

    void InsertionSorting(){

        bool Swapped = true;

        if (  bool Swapped = true ){

            temp=first->n;
        }

        while(Swapped==true)
        {

            Swapped=false;

            if((temp->d < temp-> p->d)  
            {

                if((temp->p->d==first->d))
                
                {
                    first=temp;
                }

                cout<<"Swapped "<<temp->d<<" with "<<temp->p->d<<endl;
                temp->p->n=temp->n;
                temp->n->p=temp->p;
                temp->n=temp->p;
                temp->p=temp->n->p;
                Swapped=true;
            } 
                    else if (temp->n!=NULL)){

                     Swapped=false;

                            if((temp->d < temp-> p->d)
                            {
            
                                if((temp->p->d==first->d))
            
                                {
                                    first=temp;
                                }
            
                                cout<<"Swapped "<<temp->d<<" with "<<temp->p->d<<endl;

                                temp->p->n=temp->n;
                                temp->n->p=temp->p;
                                temp->n=temp->p;
                                temp->p=temp->n->p;
                                Swapped=true; 
                            
                
                
            }
                
                
                
                
            else if((temp->d<temp->p->d)&&(temp->n==NULL)){
                cout<<"Swapped "<<temp->d<<" with "<<temp->p->d<<endl;
                temp->p->n=NULL;
                temp->n=temp->p;
                temp->p=temp->p->p;
                temp->p->n->p=temp;
            }
        }
        cout<<"Sorting is finished "<<endl;
    }


    void Push(int in)
    {
        if(Ele>=1){
            
            
            temp=new Node;
            temp->d=in;
            temp->n=first;
            temp->p=NULL;
            first->p=temp;
            first=temp;
            Ele++;
        }
        else if(Ele<1){
            temp=new Node;
            temp->d=in;
            temp->n=NULL;
            first=temp;
            Ele++;
        }
    }

    int Pop(){
        if(Ele>1){
            cout<<first->d<<"\n"<<endl;
            first=first->n;
            first->p=NULL;
            Ele--;
        }
        else if(Ele==1){
            cout<<first->d<<endl;
            Ele--;
        }
        else {
            cout<<"no elements in list"<<endl;
        }
        ret first->d;
    }

    int Peek(){
        cout<<first->d<<"\n"<<endl;
        ret first->d;
    }

}
    
int main()
{   NormalStack starter;
    char select;
    int in;
    int ret;

    if (select!= 'N'){
        cout<<"What do you want to do \n"
            <<"P: Push\n"
            <<"O: Pop\n"
            <<"S: Sort\n"
            <<"K: Peek\n"
            <<"N: Nothing else\n";

        cin>>select;
        if(select=='P'){
            cout<<"eneter what you want to be stored\n";
            cin>>in;
            starter.Push(in);
        }
        if(select=='O'){
            ret=starter.Pop();
        }
        if(select=='S'){
            starter.InsertionSorting();
        }
        if(select=='K'){
            starter.Peek();
        }
        if(select=='N'){
            cout<<"bye"<<endl;
        }
        else{
            cout<<"invalid\n";
        }
    }

    return  0;
}