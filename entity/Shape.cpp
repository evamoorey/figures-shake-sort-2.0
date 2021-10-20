//------------------------------------------------------------------------------
// Shape.cpp - contains procedures for processing figures (and input/output).
//------------------------------------------------------------------------------

#include <stdexcept>
#include "Shape.h"

//------------------------------------------------------------------------------
// Input parameters for figure from file.
Shape *Shape::In(FILE *file) {
  Shape *shape;
  int k;
  fscanf(file, "%d", &k);
  switch (k) {
	case 1:shape = new Sphere;
	  break;
	case 2:shape = new Parallelepiped;
	  break;
	case 3:shape = new Tetrahedron;
	  break;
	default:throw std::invalid_argument("Incorrect number of shape.");
  }
  shape->In(file);
  return shape;

}

// Random values for figure.
Shape *Shape::InRnd() {
  Shape *shape;
  int k = rand() % 3 + 1;
  switch (k) {
	case 1: shape = new Sphere;
	  break;
	case 2: shape = new Parallelepiped;
	  break;
	case 3: shape = new Tetrahedron;
	  break;
	default: shape = 0;
  }
  shape->InRnd();
  return shape;
}

