#ifndef VECTOR2STRUCTS_HPP
#define VECTOR2STRUCTS_HPP
// custom types for improved readability

typedef struct position {
	int x, y;
}position;

typedef struct dimensions {
	int w, h;
}dimensions;

typedef struct forceVector {
	int x = 0;
	int	y = 0;
}forceVector;

#endif