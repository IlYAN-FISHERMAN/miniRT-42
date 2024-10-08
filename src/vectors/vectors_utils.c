#include "vectors.h"

t_vector3   vreflect(t_vector3 v, t_vector3 normal)
{
    return (vsub(v, vmul(normal, 2 * vdot(v, normal))));
}
