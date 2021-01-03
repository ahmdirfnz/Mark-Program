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
