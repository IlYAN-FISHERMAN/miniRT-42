#ifndef COLOR_H
# define COLOR_H

# include "../../libs/betterft/betterft.h"

typedef struct s_color
{
	t_byte	r;
	t_byte	g;
	t_byte	b;
}	t_color;


//  color: Create a new color
//	Use byte_clamp to ensure the values are between 0 and 255
//  @param r The red byte
//  @param g The green byte
//  @param b The blue byte
//  @return A new struct color
t_color	color(t_byte r, t_byte g, t_byte b);

// byte_clamp: Clamp a value between a byte range
// @param value The value to clamp
// @return The clamped value in t_byte format
t_byte	byte_clamp(float value);

// color_hex: Convert a t_color to a hexadecimal value
// @param c The color to convert
// @return The hexadecimal value of the color
int	color_hex(t_color c);

// color_add: Add two colors together
// @param c The first color
// @param d The second color
// @return The sum of the two colors
t_color	color_add(t_color c, t_color d);

// color_mult: Multiply two colors together
// @param c The first color
// @param d The second color
// @return The product of the two colors
t_color	color_mult(t_color c, t_color d);

// color_scalar: Multiply a color by a scalar
// @param c The color
// @param scalar The scalar
// @return The product of the color and the scalar
t_color	color_scalar(t_color c, float scalar);

#endif