#include <iostream>


using namespace std;

void print_dynamic_array(int *array,int Actually , int Logistik)
{
    
    for (int i = 0 ; i < Actually - 1 ; i ++ )
    {
        if (i < Logistik  )
        {
            cout << array[i] << " ";
        } 
        else 
        {
            cout << "_ " ;
        }
    }


}


int main () 
{
    int ActuallySize;
    int LogistikSize;
    cout << "Введите фактический размер массива: ";
    cin >> ActuallySize;
    cout << endl;
    cout << "Введите логический размер массива:";
    cin >> LogistikSize;
    int *array = new int [ActuallySize]{};
    for (int i = 0; i < LogistikSize; ++i)
    {
        cout << "Введите array[" << i << "]: ";
        cin >> array[i];
    }
    if (LogistikSize > ActuallySize|| ActuallySize <= 0 ||LogistikSize < 0)
    {
        cout << "Ошибка! Логический размер массива не может превышать фактический!";
    }
    else 
    {
        cout << "Динамический массив: " ;
        print_dynamic_array(array,ActuallySize,LogistikSize);
    }
    
    delete [] array;
}