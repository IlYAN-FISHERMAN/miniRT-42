#include "intersect.h"

t_intersect *new_intersect(t_ray ray, float t, t_object *object)
{
    t_intersect *intersect;

    intersect = galloc(sizeof(t_intersect));
    if (!intersect)
        return (NULL);
    intersect->ray = ray;
    intersect->t = t;
    intersect->object = object;
    intersect->pos = ray_at(ray, t);
    return (intersect);
}