#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct DynamicArray darray;

typedef enum DynamicArrayObjectKind
{
    INTEGER,
    FLOAT,
    STRING,
    ARRAY
} darray_obj_kind;

typedef union DynamicArrayObjectData
{
    int a_int;
    float a_float;
    char *a_str;
    darray *a_arr;
} darray_obj_data;

typedef struct DynamicArrayObject
{
    darray_obj_kind kind;
    darray_obj_data data;
} darray_obj;

typedef struct DynamicArray
{
    size_t size;
    size_t capacity;
    darray_obj **objects; // pointer to array of pointers pointing to darray objects
} darray;

darray *initialize_darray(size_t capacity);
void print_darray_obj(darray_obj *obj);
void set_array_obj(darray *arr, int index, darray_obj *obj);
darray_obj *get_array_obj(darray *arr, int index);
void append(darray *arr, darray_obj *obj);
darray_obj *create_int(int value);
darray_obj *create_float(float value);
darray_obj *create_string(char *value);
darray_obj *create_array(darray *arr);

#endif