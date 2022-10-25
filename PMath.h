#pragma once
#include <DirectXMath.h>

namespace PMgene::Math
{
	//****************************************************************************
	//Vector3

	struct Vector3 : public DirectX::XMFLOAT3
	{
		// Constructors
		Vector3() noexcept : XMFLOAT3(0.f, 0.f, 0.f)
		{
		}

		constexpr Vector3(float ix, float iy, float iz) noexcept : XMFLOAT3(ix, iy, iz)
		{
		}

		Vector3(const float ix) noexcept : XMFLOAT3(ix, ix, ix)
		{
		}

		explicit Vector3(const XMFLOAT3& V) noexcept : XMFLOAT3()
		{
			this->x = V.x;
			this->y = V.y;
			this->z = V.z;
		}

		// Comparison operators
		bool operator ==(const Vector3& V) const noexcept;
		bool operator !=(const Vector3& V) const noexcept;

		// Assignment operators
		Vector3& operator+=(const Vector3& V) noexcept;
		Vector3& operator-=(const Vector3& V) noexcept;
		Vector3& operator*=(const Vector3& V) noexcept;
		Vector3& operator*=(float S) noexcept;
		Vector3& operator/=(float S) noexcept;

		// Unary operators
		Vector3 operator+() const noexcept { return *this; }
		Vector3 operator-() const noexcept;

		// Vector operations
		[[nodiscard]] float Length() const noexcept;

		[[nodiscard]] float Dot(const Vector3& V) const noexcept;
		void Cross(const Vector3& V, Vector3& result) const noexcept;
		[[nodiscard]] Vector3 Cross(const Vector3& V) const noexcept;

		void Normalize() noexcept;
		void Normalize(Vector3& result) const noexcept;
		
		// Constants
		static const Vector3 Zero;
		static const Vector3 One;
		static const Vector3 UnitX;
		static const Vector3 UnitY;
		static const Vector3 UnitZ;
	};

	// Binary operators
	Vector3 operator+(const Vector3& V1, const Vector3& V2) noexcept;
	Vector3 operator-(const Vector3& V1, const Vector3& V2) noexcept;
	Vector3 operator*(const Vector3& V1, const Vector3& V2) noexcept;
	Vector3 operator*(const Vector3& V, float S) noexcept;
	Vector3 operator/(const Vector3& V1, const Vector3& V2) noexcept;
	Vector3 operator/(const Vector3& V, float S) noexcept;
	Vector3 operator*(float S, const Vector3& V) noexcept;

	//****************************************************************************
}
