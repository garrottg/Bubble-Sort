//The goal of this code is to create a bubble sort. This will put an array in increasing or decreasing order depending on user input.

#include<iostream>
#include<string>

using namespace std;

void show_array(const int array[], int size);
void bubblesort(int array[], int size, string order);
string to_upper(string order);

int main(){
    string order;
    int array1[] = {4,6,3,7,4,5,67,10};
    // set size to be size of array
    int size = 8;
    
    cout << "Increasing or Decreasing?" << endl;

    //create a while loop to make sure the input is increasing or decreasing.
    bool flag = true;
    while (flag){
        cin >> order;
        order = to_upper(order);
        if (order == "INCREASING" || order == "DECREASING"){
            flag = false;
        }
        else{
            cout << "Increasing or Decreasing?"<< endl;
        }
    }
    
    //Lets show the array before and after
    show_array(array1, size);

    bubblesort(array1, size, order);
    
    show_array(array1, size);
}

void show_array(const int array[], int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << ", ";
    }
    cout << endl;
}

void bubblesort(int array[], int size, string order){
    bool swap;
    int temp;
    if (order == "INCREASING"){
        do{
            swap = false;
            for (int i = 0; i < size-1; i++){
                if (array[i + 1] < array[i]){
                    temp = array[i+1];
                    array[i+1] = array[i];
                    array[i] = temp;
                    swap = true;
                }
            }
        }while (swap);
    }
    //int array1[] = {4,6,7,3,4,5,67,10};
    else if(order == "DECREASING"){
        do{
            swap = false;
             for (int i = 0; i < size-1; i++){
                if (array[i] < array[i + 1]){
                    temp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = temp;
                    swap = true;
                }
            }
        } while (swap);
    }
}

string to_upper(string order){
    for (int i = 0; i < order.length(); i++){
            order[i] = toupper(order[i]);
        }
    
    return order;
}


