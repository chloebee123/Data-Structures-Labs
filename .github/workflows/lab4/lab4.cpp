#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_ITEMS 10

template <class T>
class OrderedList
{

private:
    T *arr[MAX_ITEMS]; // Array of pointers | all the pointers are pointing to nullptr
public:
    OrderedList()
    {
        T item;
        srand((unsigned)time(0));
        for (int i = 0; i < MAX_ITEMS; i++)
        {

            item = (rand() % 100) + 1;
            arr[i] = new T;
            *arr[i] = item;
            cout << *arr[i] << endl;
        }
        sort(MAX_ITEMS);
    }
    void addItem(T item)
    {

        // make an if list if full error
        if (isFull() == true)
        {
            cout << "ERROR: LIST FULL"<< endl;
        }
        T temp1 = item;
        T temp2;
        if(isFull() == false){
        for (int i = 0; i <= MAX_ITEMS; i++)
        {
            if (arr[i] == 0 && isFull() == false)
            {
                arr[i] = new T;
                *arr[i] = temp1;
                bool inserted = true;
                break;
            }
            else if (*arr[i] > item || *arr[i] == 0)
            {
                temp2 = *arr[i];
                *arr[i] = temp1;
                temp1 = temp2;

            }
            
            else
            {
                continue;
            }
        }
        }
    }
    void removeItem(T item)
    {
        // checking if in order
        bool removed = false;
        int poi = NULL;
        int n = sizeof(arr) / sizeof(arr[0]);
        bool cont = inOrder(*arr, n);
        // checking if nullptr in list btw items
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            if (*arr[i] == item)
            {
                *arr[i] = NULL;
                removed = true;
                poi = i;
            }
        }
        // error for item doesn't exist
        if (removed == false)
        {
            cout << "ERROR: ITEM NOT FOUND" << endl;
        }
        else
        {
            for (int i = poi; i < MAX_ITEMS; i++)
            {
                *arr[i] = *arr[i + 1];
                if (*arr[i] >= 100)
                {
                    *arr[i] = NULL;
                }
            }
        }
    }
    bool inOrder(int *nums, int size, int i = 0)
    {

        while (i < size)
        {
            if (nums[i] < nums[i + 1])
            {
                i++;
                return inOrder(nums, size, i);
            }

            else
            {
                if (nums[i] == NULL)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    void display()
    {
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            if (arr[i] == NULL)
            {
                break;
            }
            else
            {
                cout << i << " = " << *arr[i] << endl;
            }
        }
    }
    bool isEmpty()
    {
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            if (arr[i] != NULL)
            {
                cout << "FALSE" << endl;
                return false;
            }
        }
        cout << "TRUE" << endl;
        return true;
    }
    bool isFull()
    {
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            if (*arr[i] == 0)
            {

                return false;
            }
        }

        return true;
    }
    void makeEmpty()
    {
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            arr[i] = NULL;
        }
    }

    void sort(int size)
    { //O(N^2)
        int j;
        int temp;
        for (int i = 1; i < size; i++)
        {
            j = i;
            while (j > 0 && *arr[j] < *arr[j - 1])
            {
                //cout << "*arr[j] " << *arr[j] << "*arr[j - 1] " << *arr[j - 1] << endl;
                temp = *arr[j];
                *arr[j] = *arr[j - 1];
                *arr[j - 1] = temp;
                --j;
            }
        }
    }

    bool operator<(const T &rhs);
    bool operator>(const T &rhs);
    bool operator==(const T &rhs);
};
template <class T>
class Backwards : public OrderedList<T>
{
private:
    T *arr[MAX_ITEMS];

public:
    Backwards()
    {
        T item;
        srand((unsigned)time(0));
        for (int i = 0; i < MAX_ITEMS; i++)
        {

            item = (rand() % 100) + 1;
            arr[i] = new T;
            *arr[i] = item;
            cout << *arr[i] << endl;
        }
        sort(MAX_ITEMS);
    }
    void removeItem(T item)
    {
        // checking if in order
        bool removed = false;
        int poi = NULL;
        int n = sizeof(arr) / sizeof(arr[0]);
        bool cont = inOrder(*arr, n);
        // checking if nullptr in list btw items
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            if (*arr[i] == item)
            {
                *arr[i] = NULL;
                removed = true;
                poi = i;
            }
        }
        // error for item doesn't exist
        if (removed == false)
        {
            cout << "ERROR: ITEM NOT FOUND" << endl;
        }
        else
        {
            for (int i = poi; i < MAX_ITEMS; i++)
            {
                arr[i] = arr[i + 1];
                if (*arr[i] >= 100)
                {
                    *arr[i] = NULL;
                }
            }
        }
    }
    bool inOrder(int *nums, int size, int i = 0)
    {

        while (i < size)
        {
            if (nums[i] < nums[i + 1])
            {
                i++;
                return inOrder(nums, size, i);
            }

            else
            {
                if (nums[i] == NULL)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    void display()
    {
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            if (arr[i] == NULL)
            {
                break;
            }
            else
            {
                cout << i << " = " << *arr[i] << endl;
            }
        }
    }
    bool isEmpty()
    {
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            if (arr[i] != NULL)
            {
                return false;
            }
        }
        return true;
    }
    bool isFull()
    {
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            if (arr[i] == 0)
            {
                return false;
            }
        }
        return true;
    }
    void makeEmpty()
    {
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            arr[i] = NULL;
        }
    }
    void addItem(T item)
    {
        if (isFull() == true)
        {
            cout << "ERROR: LIST FULL" << endl;
        }
        T temp1 = item;
        T temp2;
        int insertVal = 100;
        bool bigger = false;
        bool inserted = false;
        if (isFull() == false)
        {
            for (int i = MAX_ITEMS - 1; i >= 0; i--)
            {
                if (bigger == true && *arr[i] < item)
                {
                    insertVal = i;
                    break;
                }
                if (arr[i + 1] == NULL && arr[i - 1] != NULL && *arr[i - 1] < item)
                {
                    arr[i + 1] = new T;
                    *arr[i + 1] = temp1;
                    break;
                }
                else if (*arr[i] > item)
                {
                    bigger = true;
                }
            }
            for (int j = inserted; j < MAX_ITEMS - 1; j++)
            {
                temp2 = *arr[j];
                *arr[j] = temp1;
                temp1 = temp2;
            }
        }
    }
    void sort(int size)
    { //O(N^2)
        int j;
        int temp;
        for (int i = 1; i < size; i++)
        {
            j = i;
            while (j > 0 && *arr[j] < *arr[j - 1])
            {
                //cout << "*arr[j] " << *arr[j] << "*arr[j - 1] " << *arr[j - 1] << endl;
                temp = *arr[j];
                *arr[j] = *arr[j - 1];
                *arr[j - 1] = temp;
                --j;
            }
        }
    }
};

template <class T>
class Blank : public OrderedList<T>
{
private:
    T *arr[MAX_ITEMS];

public:
    Blank()
    {
        T item;
        srand((unsigned)time(0));
        for (int i = 0; i < MAX_ITEMS; i++)
        {

            item = (rand() % 100) + 1;
            arr[i] = new T;
            *arr[i] = item;
            cout << *arr[i] << endl;
        }
        sort(MAX_ITEMS);
    }
    void addItem(T item)
    {
        T temp1;
        T temp2;
        T temp3 = item;
        int nullVal;
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            if (arr[i] == NULL && *arr[i + 1] > item && *arr[i - 1] < item)
            {
                arr[i] = new T;
                *arr[i] = temp3;
                break;
            }
        }
    }
    void removeItem(T item)
    {
        // checking if in order
        bool removed = false;
        int poi = NULL;
        int n = sizeof(arr) / sizeof(arr[0]);
        bool cont = inOrder(*arr, n);
        // checking if nullptr in list btw items
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            if (*arr[i] == item)
            {
                *arr[i] = NULL;
                removed = true;
                poi = i;
            }
            if (*arr[i] >= 100)
            {
                *arr[i] = NULL;
            }
        }
        // error for item doesn't exist
        if (removed == false)
        {
            cout << "ERROR: ITEM NOT FOUND" << endl;
        }
    }
    void sort(int size)
    { //O(N^2)
        int j;
        int temp;
        for (int i = 1; i < size; i++)
        {
            j = i;
            while (j > 0 && *arr[j] < *arr[j - 1])
            {
                //cout << "*arr[j] " << *arr[j] << "*arr[j - 1] " << *arr[j - 1] << endl;
                temp = *arr[j];
                *arr[j] = *arr[j - 1];
                *arr[j - 1] = temp;
                --j;
            }
        }
    }
};
int main()
{
    OrderedList<int> list;
    //first test case
    cout << "FIRST TEST CASE:" << endl;
    list.display();
    cout << "REMOVE 5:" << endl;
    list.removeItem(5);
    cout << "REMOVE 19:" << endl;
    list.removeItem(19);
    cout << "REMOVE 94:" << endl;
    list.removeItem(94);
    cout << "REMOVE 4:" << endl;
    list.removeItem(4);
    cout << "REMOVE 69:" << endl;
    list.removeItem(69);
    cout << "REMOVE 84:" << endl;
    list.removeItem(84);
    cout << "REMOVE 17:" << endl;
    list.removeItem(17);
    cout << "REMOVE 40:" << endl;
    list.removeItem(40);
    cout << "REMOVE 99:" << endl;
    list.removeItem(99);
    cout << "DISPLAY: " << endl;
    list.display();
    cout << "ADD ITEM 18: " << endl;
    list.addItem(18);
    list.display();
    cout << endl;
    //second test case
    Backwards<int> list2;
    cout << "SECOND TEST CASE:" << endl;
    list2.display();
    cout << "REMOVE 5: " << endl;
    list2.removeItem(5);
    cout << "REMOVE 19:" << endl;
    list2.removeItem(19);
    cout << "REMOVE 94:" << endl;
    list2.removeItem(94);
    cout << "REMOVE 7: " << endl;
    list2.removeItem(7);
    cout << "REMOVE 55:" << endl;
    list2.removeItem(55);
    cout << "REMOVE 69:" << endl;
    list2.removeItem(69);
    cout << "ADD ITEM 18:" << endl;
    list2.addItem(18);
    list2.display();

    // third test case
    Blank<int> list3;
    cout << "THIRD TEST CASE:" << endl;
    list2.display();
    cout << "REMOVE 5: " << endl;
    list2.removeItem(5);
    cout << "REMOVE 19:" << endl;
    list2.removeItem(19);
    cout << "REMOVE 94:" << endl;
    list2.removeItem(94);
    cout << "REMOVE 4: " << endl;
    list2.removeItem(4);
    cout << "REMOVE 77:" << endl;
    list2.removeItem(77);
    cout << "REMOVE 90:" << endl;
    list2.removeItem(90);
    cout << "REMOVE 88: " << endl;
    list2.removeItem(88);
    cout << "REMOVE 59:" << endl;
    list2.removeItem(59);
    cout << "REMOVE 74:" << endl;
    list2.removeItem(74);    
    cout << "ADD ITEM 18: " << endl;
    list2.addItem(18);
    list2.display();


    list.display();
    cout << "Is Full ? = " << list.isFull() << endl;
    cout << "Is Empty ? = " << list.isEmpty() << endl;
    cout << "Making Empty..." << endl;
    list.makeEmpty();
    cout << "Is Empty ? = " << list.isEmpty() << endl;
   
    cout << "end" << endl;
    return 0;
}