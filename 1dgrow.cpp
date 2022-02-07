#include <iostream>
using namespace std;
void outputFun(int *arr, int size);
void inputFun(int *arr, int size, int &total);
int menuFun();
void whatIsMenu();
void searchingFun(int *arr, int &total);
void copyFunction(int *arr, int *temp, int total);
int main()
{
    int num = 0;    // this number use for add extra number into array , by grow function
    int total = 0;  // this variable use for total size of array
    int select = 0; // this variable for menu button
    int size = 0;
    cout << " ENTER A SIZE OF ARRAY : ";
    cout << endl;
    cin >> size;
    int *arr = new int[size];
    inputFun(arr, size, total);
    outputFun(arr, size);
    while (true)
    {
        whatIsMenu();
        select = menuFun();
        if (select == 1)
        {
            if (total == size)
            {
                size = size * 2;
                int *temp = new int[size];
                copyFunction(arr, temp, total);
                delete[] arr;
                arr = nullptr;
                arr = temp;

                cout << " ADDIRESS OF TEMP IS THIS : " << temp;
                cout << endl;
                cout << " ADDIRESS OF arr IS THIS : " << arr;
                cout << endl;
                cout << " ENTER A NUMBER YOU WANT TO ADD ";
                cin >> num;
                arr[total] = num;
                ++total;
                outputFun(arr, total);
                cout << endl;
                cout << " TOTAL ACTUAL SIZE OF ARRAY IS " << total;
                cout << endl;

                cout << " TOTAL REMAINING SIZE OF ARRAY IS " << size - total;
                cout << endl;
                delete[] temp;
                temp = nullptr; // null ptr is very important so after delete it must be equal to null ptr
            }
            else
            {
                cout << " ENTER A NUMBER YOU WANT TO ADD ";
                cin >> num;
                arr[total] = num;
                total++;

                outputFun(arr, total);
                cout << endl;
                cout << " TOTAL ACTUAL SIZE OF ARRAY IS " << total;
                cout << endl;

                cout << " TOTAL REMAINING SIZE OF ARRAY IS " << size - total;
                cout << endl;
            }
        }
        else
        {
            searchingFun(arr, total);
            if (total < size / 2)
            {
                int *temp = new int[total];
                copyFunction(arr, temp, total);
                delete[] arr;
                arr = nullptr;
                arr = temp;
                delete[] temp;
                temp = nullptr; // null ptr is very important so after delete it must be equal to null ptr
            }

            cout << endl;
            cout << " TOTAL ACTUAL SIZE OF ARRAY IS " << total;
            cout << endl;

            cout << " TOTAL REMAINING SIZE OF ARRAY IS " << size - total;
            cout << endl;
        }
    }

    return 0;
}
void inputFun(int *arr, int size, int &total)
{
    cout << " ENTER A VALUES INTO ARRAY  ";
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i + 1 << "] NUMBER ";
        cin >> arr[i];
        total++;
    }
}
void outputFun(int *arr, int size)
{
    cout << " VALUES INTO ARRAY  ";
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i + 1 << "] NUMBER ";
        cout << arr[i] << endl;
    }
}
int menuFun()
{
    int select = 0;
    cout << " PLEASE SELECT OPTION /- ";
    cin >> select;
    cout << endl;
    return select;
}
void whatIsMenu()
{
    cout << endl;
    cout << "--------MENU---------";
    cout << endl;
    cout << " PRESS 1 FOR ENTER DATA \n\t\tOR\n PRESS 2 FOR delter numbers";
    cout << endl;
}
void copyFunction(int *arr, int *temp, int total)
{
    for (int i = 0; i < total; i++)
    {
        temp[i] = arr[i];
    }
}
void searchingFun(int *arr, int &total)
{
    int num = 0;
    cout << endl;
    cout << " ENTER A NUMBER YOU WANT TO DELETE";
    cin >> num;
    cout << endl;
    for (int i = 0; i < total; i++)
    {
        if (num == arr[i])
        {
            if (i == total - 1)
            {
                cout << " THIS IS LAST NUMBER ";
                cout << endl;
            }
            else
            {
                arr[i] = arr[i + 1];
            }
            total--;
        }
    }
    outputFun(arr, total);
}