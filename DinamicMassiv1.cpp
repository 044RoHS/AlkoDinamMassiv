#include <iostream>

using namespace std;

void print_dynamic_array(int *array,int Actually , int Logistik)
{
  
    for (int i = 0 ; i < Actually ; i ++ )
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
    cout << endl;

}
void append_to_dynamic_array(int *&array , int &Actually , int &Logistik)
{
    int EndNumber = 0;
   do
   {
    
    cout <<"Введите элемент для добавления: ";
    cin >> EndNumber; 
    if(EndNumber != 0 )
    {
        if (Logistik <Actually)
    {
        array[Logistik ] = EndNumber;
        Logistik += 1; 
        cout << "Динамический массив: " ;
        print_dynamic_array(array,Actually,Logistik);
    } 
    else if (Logistik == Actually) 
    {
        int *array1 = new int [Actually*2]{};
        for (int y = 0 ; y < Logistik  ; y++ )
        {
            array1[y] = array[y];
        } 
        array1[Logistik ] = EndNumber;
        Logistik += 1;
        Actually *= 2;
        cout << "Динамический массив: " ;
        print_dynamic_array(array1,Actually,Logistik);
        delete[] array;
        array = array1;
    }
    }
    
   
   }while(EndNumber != 0);
  cout << "Спасибо! Ваш массив: ";
  print_dynamic_array(array , Actually,Logistik);
  
}




int main ()
{
    int FactValueArray;
    int LogistikValueArray;
    cout << "Введите фактичеcкий размер массива: ";
    cin >> FactValueArray;
    cout << "Введите логический размер массива: ";
    cin >> LogistikValueArray;
    int  *array = new int [LogistikValueArray]{};
    for (int i = 0; i < LogistikValueArray; ++i)
    {
        cout << "Введите array[" << i << "]: ";
        cin >> array[i];
    }
    if (LogistikValueArray > FactValueArray)
    {
        cout << "Ошибка! Логический размер массива не может превышать фактический!";
        return 0;
    }
    else 
    {
        print_dynamic_array(array,FactValueArray,LogistikValueArray);
        append_to_dynamic_array(array,FactValueArray,LogistikValueArray);
    }
    delete[] array;
    return 0;
}