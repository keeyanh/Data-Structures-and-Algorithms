#include <iostream>

using namespace std;

 class ArbitraryQueue{

private:
     
    struct Node{
    
    Node* next;
    Node* prev;
    string data;
};
    Node* T; // creating a temporary arrow for temporary
    Node* fir; // creating am arrow that points to the first part of the queue
    Node* last; // creating am arrow that points to the last part of the queue
    int elem=0; // saying that elemtents in the queue are zero

public:
     void Enqueue(string input){

         if(elem>=1){
             // if the elements in the queue are greater than or equal to 1, because we want there to be stuff in the queue
             T=new Node; // creating a new node and saying its temporary
             T->data=input; // put the data into the node
             last->next=T;//then the last node points to the next node which was the old temp
             T->prev=last; // then t points to the previous node which is now the last
             last=T;//now last is the last
             elem++; // the elements now increment up because we just added soemthing to the end of line
         }

         else if(elem<1){
             T=new Node;
             T->data=input;
             fir=T;
             last=fir;
             elem++;
         }
     }

     string Dequeue(){

         if(elem>1){
             cout<<last->data<<"\n"<<endl; // if there are things in the queue we point the last element to the data
             last=last->prev; // we set the last thing in the list equal to the pointer that points to the previous element
             last->next=NULL; // the next element does not exists anymore so its null
             elem--;
         }
         else if(elem==1){
             cout<<last->data<<endl;
             elem--;
         }
         else{
             cout<<"No elements in the list error"<<endl;
             return "error";}


         return last->data;
     }


     void Push(string input){

        if(elem >=1){
        T= new Node;
        T->data=input;//input the data in the node
        T->next=fir;//this nent pointer in the node now points the current first
        fir->prev=T;//now the first pointer points to the temporary pointer which was the previous
        fir=T; // now the temp pointer is the first
        elem++;
        }
        else if(elem<1){
            T=new Node;
        T->data=input;
        fir=T;  // now the first node is equal to the temp node and its data
        last=fir; // the last node is now equal to the old first node
        elem++;
        }
    }

    string Pop(){
        if(elem>1){
            cout<<fir->data<<"\n"<<endl;
            fir=fir->next; // first node now points to the next node in that list
            fir->prev=NULL;
            elem--;
        }
        else if(elem==1){
            cout<<fir->data<<endl;
            elem--;
        }
        else {
            cout<<"There are no elements in the list"<<endl;
        }
        return fir->data;
    }


    string Traverse(int index){
    if(index==0){



        cout<<fir->data<<endl;
    }
    else if(index >elem-1){
            cout<<"there arent enough elements"<<endl;
    }
    else{
            T=fir;
        for(int i=0;i<index;i++){
            T=T->next;
        }
        cout<<T->data<<endl;
    }
  return T->data;
    }

};

int main() {

    char ans = 'X';
    string input;

    int index;
    string returns;

    ArbitraryQueue myQ;


    while (ans != 'N') {
        cout << "Please select what you wish to do\n"
             << "P = Push\n"
             << "E = Enqueue\n"
             << "Po = Pop\n"
             << "D = Dequeue\n"
             << "T = Traverse\n"
             << "Nothing\n";
        cin >> ans;
        if (ans == 'P') {
            cout << "Please enter storing data\n";
            cin >> input;
            myQ.Push(input);
        } else if (ans == 'E') {
            cout << "Please enter storing data\n";
            cin >> input;
            myQ.Enqueue(input);
        } else if (ans == 'Po') {
            returns = myQ.Pop();
        } else if (ans == 'D') {
            returns = myQ.Dequeue();
        } else if (ans == 'T') {
            cout << "Please enter the index of the data you want\n";
            cin >> index;
            returns = myQ.Traverse(index);
        } else if (ans == 'N') {
            cout << "Peace Out" << endl;
        } else {
            cout << "i dont know what you are trying to do goodbye\n";
        }
    }

    return 0;
}
