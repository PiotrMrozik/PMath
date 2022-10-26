#pragma once

#include "PMath.h"

using namespace DirectX;

namespace PMgene::Math
{
	const Vector3 Vector3::Zero = {0.f, 0.f, 0.f};
	const Vector3 Vector3::One = {1.f, 1.f, 1.f};
	const Vector3 Vector3::UnitX = {1.f, 0.f, 0.f};
	const Vector3 Vector3::UnitY = {0.f, 1.f, 0.f};
	const Vector3 Vector3::UnitZ = {0.f, 0.f, 1.f};

	const Quaternion Quaternion::Identity = {0.f, 0.f, 0.f, 1.f};

	const Matrix Matrix::Identity = {
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f
	};
}
