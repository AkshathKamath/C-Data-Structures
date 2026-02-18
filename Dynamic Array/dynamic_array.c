#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamic_array.h"

darray *initialize_darray(size_t capacity)
{
    darray *obj = malloc(sizeof(darray));
    if (obj == NULL)
    {
        return NULL;
    }
    obj->capacity = capacity;
    obj->size = 0;
    obj->objects = malloc(sizeof(darray_obj *) * capacity);
    if (obj->objects == NULL)
    {
        free(obj);
        return NULL;
    }

    return obj;
}

darray_obj *create_int(int value)
{
    darray_obj *obj = malloc(sizeof(darray_obj));
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = INTEGER;
    obj->data.a_int = value;

    return obj;
}

darray_obj *create_float(float value)
{
    darray_obj *obj = malloc(sizeof(darray_obj));
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = FLOAT;
    obj->data.a_float = value;

    return obj;
}

darray_obj *create_string(char *value)
{
    darray_obj *obj = malloc(sizeof(darray_obj));
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = STRING;
    obj->data.a_str = malloc(sizeof(strlen(value) + 1) * sizeof(char *));
    strcpy(obj->data.a_str, value);

    return obj;
}

darray_obj *create_array(darray *arr)
{
    darray_obj *obj = malloc(sizeof(darray_obj));
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = ARRAY;
    obj->data.a_arr = arr;

    return obj;
}

void append(darray *arr, darray_obj *obj)
{
    if (arr->size == arr->capacity)
    {
        darray_obj **temp = realloc(arr->objects, arr->capacity * 2 * sizeof(darray_obj *));
        if (temp == NULL)
        {
            return;
        }
        arr->objects = temp;
        arr->capacity = 2 * arr->capacity;
    }
    arr->objects[arr->size++] = obj;
    return;
}

darray_obj *get_array_obj(darray *arr, int index)
{
    if (index >= arr->size)
    {
        return NULL;
    }
    print_darray_obj(arr->objects[index]);
    return arr->objects[index];
}

void set_array_obj(darray *arr, int index, darray_obj *obj)
{
    if (index >= arr->size)
    {
        return;
    }
    arr->objects[index] = obj;
    return;
}

void print_darray_obj(darray_obj *obj)
{
    switch (obj->kind)
    {
    case INTEGER:
    {
        printf("%d\n", obj->data.a_int);
        break;
    }
    case FLOAT:
    {
        printf("%f\n", obj->data.a_float);
        break;
    }
    case STRING:
    {
        printf("%s\n", obj->data.a_str);
        break;
    }
    case ARRAY:
    {
        darray *arr = obj->data.a_arr;
        for (int i = 0; i < arr->size; i++)
        {
            print_darray_obj(arr->objects[i]);
        }
        break;
    }
    default:
        break;
    }
}