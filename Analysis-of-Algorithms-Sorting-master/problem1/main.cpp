#include<iostream>
using namespace std;

//i need to rank by digit sequence
//i cant compare elements in the array so i need to find a way to sort the array without comparing the elements.
//this function would sort the array without comparing the elements by doing that it could store the frequency of each element in one array
//we can run through the array for the first time to find the frequency of the elemtents,


void InternalSort(int arr[], int n, int power)
{

    int holding[10] = {0}; // empty array that will be filled with occurances of digits, holding is to 10 because its through 0-9
    int i; // holding variable
    int finshedArray[n]; //the finshedArray array

    //this stores the frequency of elements in the array into a seperate array
    //what is does is it moves through the elements of the array
    //this function takes the array and the size of the array and an exponent
    //the exopent will be the iteration varaible because it is the matter of digit places, therefore iterating by a value of 10, 100 etc
    //is needed

    //so i will traverse the array and what this loop will do is store the amount of times each digit will occur.
    //for every iteration in the look it will go through the array, take the element divide it by the expnoent and then mod that result to ensure we get the correct digit

    for (i = 0; i < n; i++)

    {
        holding[(arr[i] / power) % 10]++;
    }

   //i should have the frequencies in which every digit appears
    //what i want to do now is traverse the holding array
    //i am going to change the array again
    //this time i want to edit the holding array so that the array will contain the actual index  of the digit in question in my final array
    //i do this by traversing the array again and summing the previous term to the next term


    for (i = 1; i < 10; i++) {


        holding[i] += holding[i - 1];
    }
    //now i wanna create my final array
    //so take each number from the input and put into my final array
    // i decrement however so that when i have repeats of digits the program will fill the preceding index with the same value


    for (i = n - 1; i >= 0; i--)
    {
        finshedArray[ holding[(arr[i]/power)%10 ] - 1] = arr[i];

        holding[ (arr[i]/power)%10 ]--;
    }

    //now for every element im gonna take my output array and fill the array i wanna sort so i can pass it

    for (i = 0; i < n; i++) {

        arr[i] = finshedArray[i];
    }



}

//i want to know the max number in the array because i want to know how many digits there are
// the max number of the array will help in my loop later



int FindMaxValue(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++){

        if(arr[i] > max){

            max = arr[i];
        }

    }
    return max;
}

//my sorting fucntion

void Problem1Sort(int arr[], int arraySize)
{
    //i use the previous function to find the maxnumber in the array

    int maxNum = FindMaxValue(arr, arraySize);


    //Now i am going to run internal sort for every digit
    //my exponent is incremented upwards by a factor of 10 so that it can move through every digit

    for (int power = 1; maxNum/power > 0; power *= 10){

        InternalSort(arr, arraySize, power);
    }
}

int main()
{
    int arraySize;
    cout << "please enter the size of the array" << endl;
    cin >> arraySize;
    int arr[arraySize];

    cout << "please fill the array" << endl;

    for (int i = 0; i < arraySize; i++){

        cin>>arr[i];
    }

    Problem1Sort(arr, arraySize);

    for(int i = 0; i < arraySize; i++){

        cout << arr[i] << " ";


    }

    return 0;
    
}

