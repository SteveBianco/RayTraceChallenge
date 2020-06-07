#pragma once
#include "Tuple.h"

namespace Trajectory {
	struct Environment {
		Vector gravity;
		Vector wind;
	};

	struct Projectile {
		Point position;
		Vector velocity;

		void tick(const Environment& env);
	};
}