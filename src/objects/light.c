#include "light.h"

t_object    *new_light(t_point3 origin, t_color color)
{
    t_object    *object;

    object = galloc(sizeof(t_object));
    if (!object)
        return (0);
    object->data = galloc(sizeof(t_light));
    if (!object->data)
    {
        gfree(object);
        return (0);
    
    ((t_light *)object->data)->origin = origin;
    ((t_light *)object->data)->color = color;
    object->type = o_light;
    return (object);
}
