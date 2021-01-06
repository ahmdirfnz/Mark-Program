# Mark Insertion And Deletion Program

**Marks.h**
```
#ifndef MARKS_H_INCLUDED
#define MARKS_H_INCLUDED

class Result {
private:
    int size, cho, mx, del;
    float *marks;
    float total, average;

public:
    Result();
    ~Result();
    void input_result();    //Key in all marks
    void calc_total();     //Calculate the total mark
    void calc_average();   //Calculate the mark average
    void display();         //Display the list of marks, total and marks’ average.
    void insertion();       //Insertion algorithm
    void deletion();        //Deletion algorithm
    void menu();            //Menu for insert and delete

};

#endif // MARKS_H_INCLUDED
```
***The class Result is created in this file which contain function and variable definition***


**Marks.cpp**
```
#include <iostream>
#include <iomanip>
#include "Marks.h"

using namespace std;

Result::Result()                 //constructor
{
    cout<<"\n\n*******************************************************************";
    cout<< "\n\n\t\tHow many marks you want to insert : ";
    cin>>size;
    marks=new float[size];
    total = 0.0;
    average =0.0;
    cho=10;
    mx=0;
    del=size+4;                 //This size is initialize increment by 4 because to suit the size of array when the insertion is reached limit of 3
}

Result::~Result()               //destructor
{
    delete [] marks;

    cout<<"\n\n\n\t -----------------------------------------------";
    cout<<"\n\t|                                               |";
    cout<< "\n\t|\t           Program closed.          \t|";
    cout<<"\n\t|_______________________________________________|\n\n\n\n";
}

void Result::input_result(){                                         //This function is to make the user to input the marks
    cout<<"\n\t -----------------------------------------------";
    cout<<"\n\t|                                               |";
    cout<< "\n\t|\tPlease enter "<<size<<" marks respectively.\t|";
    cout<<"\n\t|_______________________________________________|\n";
    for(int i=0; i<size; i++){
        cout<<"\n\t\t\t> Mark " << i+1 <<": ";
        cin>> marks[i];
    }
    cout<<"\n\t\t\t-------x-------\n";
}

void Result::calc_total(){                                           //This function is to calculate the current total of marks
    for(int i=0; i<size; i++){
        total+=marks[i];
    }
}

void Result::calc_average(){                                        //This function is to calculate average based on the total marks
    average= total/size;
}

void Result::display(){                                             //This function is to display the marks,total and average of the marks   
    cout<<"\n\n\t\t -------------------------";
    cout<<"\n\t\t|           Marks         |";
    cout<<"\n\t\t|-------------------------|";

    for(int i=0; i<size; i++){
        cout<<"\n\t\t|             |\t          |";
        cout<<"\n\t\t|\t"<<i+1<<"     |\t"<< fixed << setprecision(2)<<marks[i]<<"\t  |";
    }
    cout<<"\n\t\t|-------------------------|";
    cout<<"\n\t\t|Total        |\t"<< fixed << setprecision(2)<< total <<"\t  |";
    cout<<"\n\t\t|-------------------------|";
    cout<<"\n\t\t|Average      |\t"<< fixed << setprecision(2)<< average <<"\t  |";
    cout<<"\n\t\t|_________________________|";
    cout<<endl;
}

void Result::insertion(){           //This function make the insertion of the marks until it reached limit of insertion

    if(mx >= 3){
        cout<<"\n\t -----------------------------------------------";
        cout<<"\n\t|                                               |";
        cout<< "\n\t|\t You have reached to maximum size. \t|";
        cout<<"\n\t|_______________________________________________|\n";
    }
    else{
        int sz = size;
        float arr[sz];
        for(int i=0; i<sz; i++){
            arr[i]=marks[i];
        }

        cout<<"\n\n\t -----------------------------------------------";
        cout<<"\n\t|                                               |";
        cout<< "\n\t|\tEnter a number to add at the end. \t|";
        cout<<"\n\t|_______________________________________________|\n";

        size +=1; //increase the array size.
        mx+=1;  //count the limit size.

        marks=new float[size];

        for(int i=0; i<sz; i++){
            marks[i]=arr[i];
        }

        cout<<"\n\t\t\t> Mark " << size <<": ";
        cin>> marks[size-1]; //input the value at the end of the array list.
        cout<<"\n\t\t\t-----x-----\n";
        cout<<"\n\t----- "<<marks[size-1]<<" added successfully to the list. -----";

        total=average=0;
        calc_total();
        calc_average();
    }
}

void Result::deletion(){                    //This function make deletion of marks until it reached the limit of deletion
    if(size<=0){    
        cout<<"\n\t -----------------------------------------------";
        cout<<"\n\t|                                               |";
        cout<< "\n\t|\t There are no marks. Insert first. \t|";
        cout<<"\n\t|_______________________________________________|";
    }
    else{
        cout<<"\n\n\t -----------------------------------------------";
        cout<<"\n\t|                                               |";
        cout<< "\n\t|\tEnter the index number to delete mark. \t|";
        cout<<"\n\t|_______________________________________________|\n";

        size -=1; //increase the array size.
        mx-=1;  //count the limit size.

        cout<<"\n\t\t\t> Index no : ";
        cin>> del; //input the index value to delete the mark.
        del-=1; //get the index number.
        cout<<"\n\t----- "<<marks[del]<<" deleted successfully from the list. -----";
        if (del < size)                                                                 //update algorithm for deletion     
        {
            for(int i=del; i<size; i++){
            marks[i]=marks[i+1];
        }
        
        total=average=0;
        calc_total();
        calc_average();
        }

    }
}

void Result::menu(){                                    //This function is to make a choice for the user to  choose option for the program they want

    //system("clear");
    while (cho!=0)
    {
        display();

        cout<<"\n\t -----------------------------------------------";
        cout<<"\n\t|                                               |";
        cout<< "\n\t|\t 1. Insert an additional marks.  \t|";
        cout<< "\n\t|\t 2. Delete a mark from list.     \t|";
        cout<< "\n\t|\t 0. Exit program.                \t|";
        cout<<"\n\t|_______________________________________________|\n";

        cout<<"\n\tChoose an option from menu : ";
        cin>>cho;

        switch (cho) {

        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 0:
            system("clear");
            break;
        default:

            cout<<"\n\t -----------------------------------------------";
            cout<<"\n\t|                                               |";
            cout<< "\n\t|\tInvalid choice. Please try again.     \t|";
            cout<<"\n\t|_______________________________________________|\n";
            break;
        }
    }
}
```
***Make the program inside the function so that it can be used in main class***


**main.cpp**
```
#include "Marks.h"

int main(){
    Result result;
    result.input_result();
    result.calc_total();
    result.calc_average();
    result.menu();
}
```
***This main class call the function inside Result class by using the object which is 'result'.
   The object is created by declaration of class Result.
   Marks.h file is included to make sure that the Result can be called inside main function.***
