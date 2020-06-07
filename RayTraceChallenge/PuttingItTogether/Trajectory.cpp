#pragma once
#include "Trajectory.h"

namespace Trajectory {

	void Projectile::tick(const Environment& env) {
		position += velocity;
		velocity = velocity + env.gravity + env.wind;
	}

}