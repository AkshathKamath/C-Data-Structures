#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

int main()
{
    darray *arr = initialize_darray(1);
    darray_obj *obj1 = create_int(5);
    append(arr, obj1);
    darray_obj *obj2 = create_float(3.14);
    append(arr, obj2);
    darray_obj *obj3 = create_string("Hi, my name is AK!");
    append(arr, obj3);

    darray *finalArr = initialize_darray(1);
    darray_obj *obj4 = create_string("This is the first Object");
    append(finalArr, obj4);
    darray_obj *obj5 = create_array(arr);
    append(finalArr, obj5);

    for (int i = 0; i < finalArr->size; i++)
    {
        print_darray_obj(finalArr->objects[i]);
    }
    return 1;
}