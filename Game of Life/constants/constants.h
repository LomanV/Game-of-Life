#pragma once

#include <cstdint>
#include "../vector2d/vector2d.h"

namespace vctr {
	const double ZERO_VECTOR_NORM(1e-30);
	const Vector2D ZERO_VECTOR(0,0);
}

namespace game {
	const unsigned int BOARD_SIZE(1000);
	const unsigned int UNIT_SIZE(1);
}

namespace states {
	const std::uint8_t DEAD(0);
	const std::uint8_t ALIVE(1);
}
