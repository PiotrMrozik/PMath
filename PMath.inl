#pragma once

#include "PMath.h"

using namespace DirectX;

namespace PMgene::Math
{
	//****************************************************************************
	//Vector3

	inline bool Vector3::operator==(const Vector3& V) const noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR v2 = XMLoadFloat3(&V);
		return XMVector3Equal(v1, v2);
	}

	inline bool Vector3::operator !=(const Vector3& V) const noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR v2 = XMLoadFloat3(&V);
		return XMVector3NotEqual(v1, v2);
	}

	inline Vector3& Vector3::operator+=(const Vector3& V) noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR v2 = XMLoadFloat3(&V);
		const XMVECTOR X = XMVectorAdd(v1, v2);
		XMStoreFloat3(this, X);
		return *this;
	}

	inline Vector3& Vector3::operator-=(const Vector3& V) noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR v2 = XMLoadFloat3(&V);
		const XMVECTOR X = XMVectorSubtract(v1, v2);
		XMStoreFloat3(this, X);
		return *this;
	}

	inline Vector3& Vector3::operator*=(const Vector3& V) noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR v2 = XMLoadFloat3(&V);
		const XMVECTOR X = XMVectorMultiply(v1, v2);
		XMStoreFloat3(this, X);
		return *this;
	}

	inline Vector3& Vector3::operator*=(float S) noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR X = XMVectorScale(v1, S);
		XMStoreFloat3(this, X);
		return *this;
	}

	inline Vector3& Vector3::operator/=(float S) noexcept
	{
		if(S==0.0f)
		{
			return *this;
		}
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR X = XMVectorScale(v1, 1.f / S);
		XMStoreFloat3(this, X);
		return *this;
	}

	inline Vector3 Vector3::operator-() const noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR X = XMVectorNegate(v1);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	inline Vector3 operator+(const Vector3& V1, const Vector3& V2) noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(&V1);
		const XMVECTOR v2 = XMLoadFloat3(&V2);
		const XMVECTOR X = XMVectorAdd(v1, v2);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	inline Vector3 operator-(const Vector3& V1, const Vector3& V2) noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(&V1);
		const XMVECTOR v2 = XMLoadFloat3(&V2);
		const XMVECTOR X = XMVectorSubtract(v1, v2);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	inline Vector3 operator*(const Vector3& V1, const Vector3& V2) noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(&V1);
		const XMVECTOR v2 = XMLoadFloat3(&V2);
		const XMVECTOR X = XMVectorMultiply(v1, v2);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	inline Vector3 operator*(const Vector3& V, float S) noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(&V);
		const XMVECTOR X = XMVectorScale(v1, S);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	inline Vector3 operator/(const Vector3& V1, const Vector3& V2) noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(&V1);
		const XMVECTOR v2 = XMLoadFloat3(&V2);
		const XMVECTOR X = XMVectorDivide(v1, v2);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	inline Vector3 operator/(const Vector3& V, float S) noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(&V);
		const XMVECTOR X = XMVectorScale(v1, 1.f / S);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	inline Vector3 operator*(float S, const Vector3& V) noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(&V);
		const XMVECTOR X = XMVectorScale(v1, S);
		Vector3 R;
		XMStoreFloat3(&R, X);
		return R;
	}

	inline float Vector3::Length() const noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR X = XMVector3Length(v1);
		return XMVectorGetX(X);
	}

	inline float Vector3::Dot(const Vector3& V) const noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR v2 = XMLoadFloat3(&V);
		const XMVECTOR X = XMVector3Dot(v1, v2);
		return XMVectorGetX(X);
	}

	inline void Vector3::Cross(const Vector3& V, Vector3& result) const noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR v2 = XMLoadFloat3(&V);
		const XMVECTOR R = XMVector3Cross(v1, v2);
		XMStoreFloat3(&result, R);
	}

	inline Vector3 Vector3::Cross(const Vector3& V) const noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR v2 = XMLoadFloat3(&V);
		const XMVECTOR R = XMVector3Cross(v1, v2);

		Vector3 result;
		XMStoreFloat3(&result, R);
		return result;
	}

	inline void Vector3::Normalize() noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR X = XMVector3Normalize(v1);
		XMStoreFloat3(this, X);
	}

	inline void Vector3::Normalize(Vector3& result) const noexcept
	{
		const XMVECTOR v1 = XMLoadFloat3(this);
		const XMVECTOR X = XMVector3Normalize(v1);
		XMStoreFloat3(&result, X);
	}

	//****************************************************************************
}
