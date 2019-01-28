#include <stdio.h>

class DynArray
{
  public:
     int count;
     int capacity;
     int* array;   //link to the array

     DynArray()
     {
       count = 0;
       make_array(16);
     }

     void make_array(int new_capacity)
     {
          if (new_capacity < 16) new_capacity = 16;
          int* new_array = new int[new_capacity];

          for (int i = 0; i < new_capacity ; i++)      //new array to zero
          {    new_array[i] = 0;
          }

          for (int i = 0; i < count ; i++)             // copy array into new array to the 'count'
          {    new_array[i] = array[i];
          }

          for (int i = count; i < new_capacity ; i++)  // zero the end of the array
          {    new_array[i] = 0;
          }
          capacity = new_capacity;
          array = new_array;
     }

    int get_item(int index)
    {
          if (index >= count) return -1;
          return array[index];
    }

     void append(int value)
     {
            if (count == capacity)
            {
               int new_capacity = capacity * 2;  // array expansion formula
               make_array(new_capacity);
            }
            array[count] = value;
            count += 1;
     }

     void insert(int value, int index)
     {
          if (index == count)
          {
               append(value);
               return;
          }
          if (get_item(index) == -1)
               throw "Item was not found";        //item was not found

          if (count == capacity)
          {
               int new_capacity = capacity * 2;   // array expansion formula
               make_array(new_capacity);
          }

          for (int i = count; i > index; i--)     //copy to the right
          {
              array[i] =  array[i-1];
          }
          array[index] = value;
          count += 1;
     }

     void remove(int index)
     {
          if (get_item(index) == -1)
               throw "Item was not found";        //item was not found

          for (int i = index; i < count; i++)     //copy to the left
          {
              array[i] =  array[i+1];
          }

          if (count <= capacity / 2 && capacity != 16)  //if less than 50%
          {
               int new_capacity =  capacity * 2 / 3;   //array reduction formula
               make_array(new_capacity);
          }
          count -= 1;
     }
};
