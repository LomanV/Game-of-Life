#include <iostream>

namespace excptn {
	const std::out_of_range BAD_VECTOR_ACCESS("Could not access Vector3D's i-th coordinates for i≠0,1");
	const std::out_of_range ZERO_VECTOR_UNITARY("Could not normalise zero vector");
}
