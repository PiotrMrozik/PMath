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
		if (S == 0.0f)
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
	//Quaternion

	inline bool Quaternion::operator ==(const Quaternion& q) const noexcept
	{
		const XMVECTOR q1 = XMLoadFloat4(this);
		const XMVECTOR q2 = XMLoadFloat4(&q);
		return XMQuaternionEqual(q1, q2);
	}

	inline bool Quaternion::operator !=(const Quaternion& q) const noexcept
	{
		const XMVECTOR q1 = XMLoadFloat4(this);
		const XMVECTOR q2 = XMLoadFloat4(&q);
		return XMQuaternionNotEqual(q1, q2);
	}

	inline Quaternion& Quaternion::operator+=(const Quaternion& q) noexcept
	{
		const XMVECTOR q1 = XMLoadFloat4(this);
		const XMVECTOR q2 = XMLoadFloat4(&q);
		XMStoreFloat4(this, XMVectorAdd(q1, q2));
		return *this;
	}

	inline Quaternion& Quaternion::operator-=(const Quaternion& q) noexcept
	{
		const XMVECTOR q1 = XMLoadFloat4(this);
		const XMVECTOR q2 = XMLoadFloat4(&q);
		XMStoreFloat4(this, XMVectorSubtract(q1, q2));
		return *this;
	}

	inline Quaternion& Quaternion::operator*=(const Quaternion& q) noexcept
	{
		using namespace DirectX;
		const XMVECTOR q1 = XMLoadFloat4(this);
		const XMVECTOR q2 = XMLoadFloat4(&q);
		XMStoreFloat4(this, XMQuaternionMultiply(q1, q2));
		return *this;
	}

	inline Quaternion& Quaternion::operator*=(float S) noexcept
	{
		const XMVECTOR q = XMLoadFloat4(this);
		XMStoreFloat4(this, XMVectorScale(q, S));
		return *this;
	}

	inline Quaternion& Quaternion::operator/=(const Quaternion& q) noexcept
	{
		const XMVECTOR q1 = XMLoadFloat4(this);
		XMVECTOR q2 = XMLoadFloat4(&q);
		q2 = XMQuaternionInverse(q2);
		XMStoreFloat4(this, XMQuaternionMultiply(q1, q2));
		return *this;
	}

	inline Quaternion Quaternion::operator-() const noexcept
	{
		const XMVECTOR q = XMLoadFloat4(this);

		Quaternion R;
		XMStoreFloat4(&R, XMVectorNegate(q));
		return R;
	}

	inline Quaternion operator+(const Quaternion& Q1, const Quaternion& Q2) noexcept
	{
		const XMVECTOR q1 = XMLoadFloat4(&Q1);
		const XMVECTOR q2 = XMLoadFloat4(&Q2);

		Quaternion R;
		XMStoreFloat4(&R, XMVectorAdd(q1, q2));
		return R;
	}

	inline Quaternion operator-(const Quaternion& Q1, const Quaternion& Q2) noexcept
	{
		const XMVECTOR q1 = XMLoadFloat4(&Q1);
		const XMVECTOR q2 = XMLoadFloat4(&Q2);

		Quaternion R;
		XMStoreFloat4(&R, XMVectorSubtract(q1, q2));
		return R;
	}

	inline Quaternion operator*(const Quaternion& Q1, const Quaternion& Q2) noexcept
	{
		const XMVECTOR q1 = XMLoadFloat4(&Q1);
		const XMVECTOR q2 = XMLoadFloat4(&Q2);

		Quaternion R;
		XMStoreFloat4(&R, XMQuaternionMultiply(q1, q2));
		return R;
	}

	inline Quaternion operator*(const Quaternion& Q, float S) noexcept
	{
		const XMVECTOR q = XMLoadFloat4(&Q);

		Quaternion R;
		XMStoreFloat4(&R, XMVectorScale(q, S));
		return R;
	}

	inline Quaternion operator/(const Quaternion& Q1, const Quaternion& Q2) noexcept
	{
		const XMVECTOR q1 = XMLoadFloat4(&Q1);
		XMVECTOR q2 = XMLoadFloat4(&Q2);
		q2 = XMQuaternionInverse(q2);

		Quaternion R;
		XMStoreFloat4(&R, XMQuaternionMultiply(q1, q2));
		return R;
	}

	inline Quaternion operator*(float S, const Quaternion& Q) noexcept
	{
		const XMVECTOR q1 = XMLoadFloat4(&Q);

		Quaternion R;
		XMStoreFloat4(&R, XMVectorScale(q1, S));
		return R;
	}

	inline float Quaternion::Length() const noexcept
	{
		const XMVECTOR q = XMLoadFloat4(this);
		return XMVectorGetX(XMQuaternionLength(q));
	}

	inline void Quaternion::Normalize() noexcept
	{
		const XMVECTOR q = XMLoadFloat4(this);
		XMStoreFloat4(this, XMQuaternionNormalize(q));
	}

	inline void Quaternion::Conjugate() noexcept
	{
		const XMVECTOR q = XMLoadFloat4(this);
		XMStoreFloat4(this, XMQuaternionConjugate(q));
	}

	inline void Quaternion::Inverse(Quaternion& result) const noexcept
	{
		using namespace DirectX;
		const XMVECTOR q = XMLoadFloat4(this);
		XMStoreFloat4(&result, XMQuaternionInverse(q));
	}

	inline float Quaternion::Dot(const Quaternion& q) const noexcept
	{
		const XMVECTOR q1 = XMLoadFloat4(this);
		const XMVECTOR q2 = XMLoadFloat4(&q);
		return XMVectorGetX(XMQuaternionDot(q1, q2));
	}

	inline Vector3 Quaternion::ToEuler() const noexcept
	{
		const float xx = x * x;
		const float yy = y * y;
		const float zz = z * z;

		const float m31 = 2.f * x * z + 2.f * y * w;
		const float m32 = 2.f * y * z - 2.f * x * w;
		const float m33 = 1.f - 2.f * xx - 2.f * yy;

		const float cy = sqrtf(m33 * m33 + m31 * m31);
		const float cx = atan2f(-m32, cy);
		if (cy > 16.f * FLT_EPSILON)
		{
			const float m12 = 2.f * x * y + 2.f * z * w;
			const float m22 = 1.f - 2.f * xx - 2.f * zz;

			return Vector3(cx, atan2f(m31, m33), atan2f(m12, m22));
		}
		const float m11 = 1.f - 2.f * yy - 2.f * zz;
		const float m21 = 2.f * x * y - 2.f * z * w;

		return Vector3(cx, 0.f, atan2f(-m21, m11));
	}

	inline Quaternion Quaternion::CreateFromAxisAngle(const Vector3& axis, float angle) noexcept
	{
		const XMVECTOR a = XMLoadFloat3(&axis);

		Quaternion R;
		XMStoreFloat4(&R, XMQuaternionRotationAxis(a, angle));
		return R;
	}

	inline Quaternion Quaternion::CreateFromYawPitchRoll(float yaw, float pitch, float roll) noexcept
	{
		Quaternion R;
		XMStoreFloat4(&R, XMQuaternionRotationRollPitchYaw(pitch, yaw, roll));
		return R;
	}

	inline Quaternion Quaternion::CreateFromYawPitchRoll(const Vector3& angles) noexcept
	{
		Quaternion R;
		XMStoreFloat4(&R, XMQuaternionRotationRollPitchYawFromVector(angles));
		return R;
	}

	inline Quaternion Quaternion::CreateFromRotationMatrix(const Matrix& M) noexcept
	{
		const XMMATRIX M0 = XMLoadFloat4x4(&M);

		Quaternion R;
		XMStoreFloat4(&R, XMQuaternionRotationMatrix(M0));
		return R;
	}

	inline void Quaternion::Lerp(const Quaternion& q1, const Quaternion& q2, float t, Quaternion& result) noexcept
	{
		const XMVECTOR Q0 = XMLoadFloat4(&q1);
		const XMVECTOR Q1 = XMLoadFloat4(&q2);

		const XMVECTOR dot = XMVector4Dot(Q0, Q1);

		XMVECTOR R;
		if (XMVector4GreaterOrEqual(dot, XMVectorZero()))
		{
			R = XMVectorLerp(Q0, Q1, t);
		}
		else
		{
			const XMVECTOR tv = XMVectorReplicate(t);
			const XMVECTOR t1v = XMVectorReplicate(1.f - t);
			const XMVECTOR X0 = XMVectorMultiply(Q0, t1v);
			const XMVECTOR X1 = XMVectorMultiply(Q1, tv);
			R = XMVectorSubtract(X0, X1);
		}

		XMStoreFloat4(&result, XMQuaternionNormalize(R));
	}

	inline Quaternion Quaternion::Lerp(const Quaternion& q1, const Quaternion& q2, float t) noexcept
	{
		const XMVECTOR Q0 = XMLoadFloat4(&q1);
		const XMVECTOR Q1 = XMLoadFloat4(&q2);

		const XMVECTOR dot = XMVector4Dot(Q0, Q1);

		XMVECTOR R;
		if (XMVector4GreaterOrEqual(dot, XMVectorZero()))
		{
			R = XMVectorLerp(Q0, Q1, t);
		}
		else
		{
			const XMVECTOR tv = XMVectorReplicate(t);
			const XMVECTOR t1v = XMVectorReplicate(1.f - t);
			const XMVECTOR X0 = XMVectorMultiply(Q0, t1v);
			const XMVECTOR X1 = XMVectorMultiply(Q1, tv);
			R = XMVectorSubtract(X0, X1);
		}

		Quaternion result;
		XMStoreFloat4(&result, XMQuaternionNormalize(R));
		return result;
	}

	inline void Quaternion::Slerp(const Quaternion& q1, const Quaternion& q2, float t, Quaternion& result) noexcept
	{
		const XMVECTOR Q0 = XMLoadFloat4(&q1);
		const XMVECTOR Q1 = XMLoadFloat4(&q2);
		XMStoreFloat4(&result, XMQuaternionSlerp(Q0, Q1, t));
	}

	inline Quaternion Quaternion::Slerp(const Quaternion& q1, const Quaternion& q2, float t) noexcept
	{
		const XMVECTOR Q0 = XMLoadFloat4(&q1);
		const XMVECTOR Q1 = XMLoadFloat4(&q2);

		Quaternion result;
		XMStoreFloat4(&result, XMQuaternionSlerp(Q0, Q1, t));
		return result;
	}

	inline Quaternion Quaternion::Concatenate(const Quaternion& q1, const Quaternion& q2) noexcept
	{
		const XMVECTOR Q0 = XMLoadFloat4(&q1);
		const XMVECTOR Q1 = XMLoadFloat4(&q2);

		Quaternion result;
		XMStoreFloat4(&result, XMQuaternionMultiply(Q1, Q0));
		return result;
	}

	inline float Quaternion::Angle(const Quaternion& q1, const Quaternion& q2) noexcept
	{
		const XMVECTOR Q0 = XMLoadFloat4(&q1);
		const XMVECTOR Q1 = XMLoadFloat4(&q2);

		// We can use the conjugate here instead of inverse assuming q1 & q2 are normalized.
		XMVECTOR R = XMQuaternionMultiply(XMQuaternionConjugate(Q0), Q1);

		const float rs = XMVectorGetW(R);
		R = XMVector3Length(R);
		return 2.f * atan2f(XMVectorGetX(R), rs);
	}


	//****************************************************************************
	//Matrix

	inline bool Matrix::operator ==(const Matrix& M) const noexcept
	{
		const XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_11));
		const XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_21));
		const XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_31));
		const XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_41));

		const XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._11));
		const XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._21));
		const XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._31));
		const XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._41));

		return (XMVector4Equal(x1, y1)
			&& XMVector4Equal(x2, y2)
			&& XMVector4Equal(x3, y3)
			&& XMVector4Equal(x4, y4)) != 0;
	}

	inline bool Matrix::operator !=(const Matrix& M) const noexcept
	{
		const XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_11));
		const XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_21));
		const XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_31));
		const XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_41));

		const XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._11));
		const XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._21));
		const XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._31));
		const XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._41));

		return (XMVector4NotEqual(x1, y1)
			|| XMVector4NotEqual(x2, y2)
			|| XMVector4NotEqual(x3, y3)
			|| XMVector4NotEqual(x4, y4)) != 0;
	}

	inline Matrix::Matrix(const XMFLOAT4X3& M) noexcept
	{
		_11 = M._11;
		_12 = M._12;
		_13 = M._13;
		_14 = 0.f;
		_21 = M._21;
		_22 = M._22;
		_23 = M._23;
		_24 = 0.f;
		_31 = M._31;
		_32 = M._32;
		_33 = M._33;
		_34 = 0.f;
		_41 = M._41;
		_42 = M._42;
		_43 = M._43;
		_44 = 1.f;
	}

	inline Matrix& Matrix::operator=(const XMFLOAT3X3& M) noexcept
	{
		_11 = M._11;
		_12 = M._12;
		_13 = M._13;
		_14 = 0.f;
		_21 = M._21;
		_22 = M._22;
		_23 = M._23;
		_24 = 0.f;
		_31 = M._31;
		_32 = M._32;
		_33 = M._33;
		_34 = 0.f;
		_41 = 0.f;
		_42 = 0.f;
		_43 = 0.f;
		_44 = 1.f;
		return *this;
	}

	inline Matrix& Matrix::operator=(const XMFLOAT4X3& M) noexcept
	{
		_11 = M._11;
		_12 = M._12;
		_13 = M._13;
		_14 = 0.f;
		_21 = M._21;
		_22 = M._22;
		_23 = M._23;
		_24 = 0.f;
		_31 = M._31;
		_32 = M._32;
		_33 = M._33;
		_34 = 0.f;
		_41 = M._41;
		_42 = M._42;
		_43 = M._43;
		_44 = 1.f;
		return *this;
	}

	inline Matrix& Matrix::operator+=(const Matrix& M) noexcept
	{
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_41));

		const XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._11));
		const XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._21));
		const XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._31));
		const XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._41));

		x1 = XMVectorAdd(x1, y1);
		x2 = XMVectorAdd(x2, y2);
		x3 = XMVectorAdd(x3, y3);
		x4 = XMVectorAdd(x4, y4);

		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_41), x4);
		return *this;
	}

	inline Matrix& Matrix::operator-=(const Matrix& M) noexcept
	{
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_41));

		const XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._11));
		const XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._21));
		const XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._31));
		const XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._41));

		x1 = XMVectorSubtract(x1, y1);
		x2 = XMVectorSubtract(x2, y2);
		x3 = XMVectorSubtract(x3, y3);
		x4 = XMVectorSubtract(x4, y4);

		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_41), x4);
		return *this;
	}

	inline Matrix& Matrix::operator*=(const Matrix& M) noexcept
	{
		const XMMATRIX M1 = XMLoadFloat4x4(this);
		const XMMATRIX M2 = XMLoadFloat4x4(&M);
		const XMMATRIX X = XMMatrixMultiply(M1, M2);
		XMStoreFloat4x4(this, X);
		return *this;
	}

	inline Matrix& Matrix::operator*=(float S) noexcept
	{
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_41));

		x1 = XMVectorScale(x1, S);
		x2 = XMVectorScale(x2, S);
		x3 = XMVectorScale(x3, S);
		x4 = XMVectorScale(x4, S);

		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_41), x4);
		return *this;
	}

	inline Matrix& Matrix::operator/=(float S) noexcept
	{
		assert(S != 0.f);
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_41));

		const float rs = 1.f / S;

		x1 = XMVectorScale(x1, rs);
		x2 = XMVectorScale(x2, rs);
		x3 = XMVectorScale(x3, rs);
		x4 = XMVectorScale(x4, rs);

		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_41), x4);
		return *this;
	}

	inline Matrix& Matrix::operator/=(const Matrix& M) noexcept
	{
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_41));

		const XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._11));
		const XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._21));
		const XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._31));
		const XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._41));

		x1 = XMVectorDivide(x1, y1);
		x2 = XMVectorDivide(x2, y2);
		x3 = XMVectorDivide(x3, y3);
		x4 = XMVectorDivide(x4, y4);

		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&_41), x4);
		return *this;
	}

	inline Matrix Matrix::operator-() const noexcept
	{
		XMVECTOR v1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_11));
		XMVECTOR v2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_21));
		XMVECTOR v3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_31));
		XMVECTOR v4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&_41));

		v1 = XMVectorNegate(v1);
		v2 = XMVectorNegate(v2);
		v3 = XMVectorNegate(v3);
		v4 = XMVectorNegate(v4);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._11), v1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._21), v2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._31), v3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._41), v4);
		return R;
	}

	inline Matrix operator+(const Matrix& M1, const Matrix& M2) noexcept
	{
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._41));

		const XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._11));
		const XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._21));
		const XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._31));
		const XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._41));

		x1 = XMVectorAdd(x1, y1);
		x2 = XMVectorAdd(x2, y2);
		x3 = XMVectorAdd(x3, y3);
		x4 = XMVectorAdd(x4, y4);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._41), x4);
		return R;
	}

	inline Matrix operator-(const Matrix& M1, const Matrix& M2) noexcept
	{
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._41));

		const XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._11));
		const XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._21));
		const XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._31));
		const XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._41));

		x1 = XMVectorSubtract(x1, y1);
		x2 = XMVectorSubtract(x2, y2);
		x3 = XMVectorSubtract(x3, y3);
		x4 = XMVectorSubtract(x4, y4);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._41), x4);
		return R;
	}

	inline Matrix operator*(const Matrix& M1, const Matrix& M2) noexcept
	{
		const XMMATRIX m1 = XMLoadFloat4x4(&M1);
		const XMMATRIX m2 = XMLoadFloat4x4(&M2);
		const XMMATRIX X = XMMatrixMultiply(m1, m2);

		Matrix R;
		XMStoreFloat4x4(&R, X);
		return R;
	}

	inline Matrix operator*(const Matrix& M, float S) noexcept
	{
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._41));

		x1 = XMVectorScale(x1, S);
		x2 = XMVectorScale(x2, S);
		x3 = XMVectorScale(x3, S);
		x4 = XMVectorScale(x4, S);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._41), x4);
		return R;
	}

	inline Matrix operator/(const Matrix& M, float S) noexcept
	{
		assert(S != 0.f);

		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._41));

		const float rs = 1.f / S;

		x1 = XMVectorScale(x1, rs);
		x2 = XMVectorScale(x2, rs);
		x3 = XMVectorScale(x3, rs);
		x4 = XMVectorScale(x4, rs);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._41), x4);
		return R;
	}

	inline Matrix operator/(const Matrix& M1, const Matrix& M2) noexcept
	{
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._41));

		const XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._11));
		const XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._21));
		const XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._31));
		const XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._41));

		x1 = XMVectorDivide(x1, y1);
		x2 = XMVectorDivide(x2, y2);
		x3 = XMVectorDivide(x3, y3);
		x4 = XMVectorDivide(x4, y4);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._41), x4);
		return R;
	}

	inline Matrix operator*(float S, const Matrix& M) noexcept
	{
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M._41));

		x1 = XMVectorScale(x1, S);
		x2 = XMVectorScale(x2, S);
		x3 = XMVectorScale(x3, S);
		x4 = XMVectorScale(x4, S);

		Matrix R;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&R._41), x4);
		return R;
	}

	inline bool Matrix::Decompose(Vector3& scale, Quaternion& rotation, Vector3& translation) noexcept
	{
		XMVECTOR s, r, t;

		if (!XMMatrixDecompose(&s, &r, &t, *this))
			return false;

		XMStoreFloat3(&scale, s);
		XMStoreFloat4(&rotation, r);
		XMStoreFloat3(&translation, t);

		return true;
	}

	inline Matrix Matrix::Transpose() const noexcept
	{
		const XMMATRIX M = XMLoadFloat4x4(this);
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixTranspose(M));
		return R;
	}

	inline void Matrix::Transpose(Matrix& result) const noexcept
	{
		const XMMATRIX M = XMLoadFloat4x4(this);
		XMStoreFloat4x4(&result, XMMatrixTranspose(M));
	}

	inline Matrix Matrix::Invert() const noexcept
	{
		const XMMATRIX M = XMLoadFloat4x4(this);
		Matrix R;
		XMVECTOR det;
		XMStoreFloat4x4(&R, XMMatrixInverse(&det, M));
		return R;
	}

	inline void Matrix::Invert(Matrix& result) const noexcept
	{
		const XMMATRIX M = XMLoadFloat4x4(this);
		XMVECTOR det;
		XMStoreFloat4x4(&result, XMMatrixInverse(&det, M));
	}

	inline float Matrix::Determinant() const noexcept
	{
		const XMMATRIX M = XMLoadFloat4x4(this);
		return XMVectorGetX(XMMatrixDeterminant(M));
	}

	inline Vector3 Matrix::ToEuler() const noexcept
	{
		const float cy = sqrtf(_33 * _33 + _31 * _31);
		const float cx = atan2f(-_32, cy);
		if (cy > 16.f * FLT_EPSILON)
		{
			return Vector3(cx, atan2f(_31, _33), atan2f(_12, _22));
		}
		return Vector3(cx, 0.f, atan2f(-_21, _11));
	}

	inline Matrix Matrix::CreateTranslation(const Vector3& position) noexcept
	{
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixTranslation(position.x, position.y, position.z));
		return R;
	}

	inline Matrix Matrix::CreateTranslation(float x, float y, float z) noexcept
	{
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixTranslation(x, y, z));
		return R;
	}

	inline Matrix Matrix::CreateScale(const Vector3& scales) noexcept
	{
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixScaling(scales.x, scales.y, scales.z));
		return R;
	}

	inline Matrix Matrix::CreateScale(float xs, float ys, float zs) noexcept
	{
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixScaling(xs, ys, zs));
		return R;
	}

	inline Matrix Matrix::CreateScale(float scale) noexcept
	{
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixScaling(scale, scale, scale));
		return R;
	}

	inline Matrix Matrix::CreateRotationX(float radians) noexcept
	{
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixRotationX(radians));
		return R;
	}

	inline Matrix Matrix::CreateRotationY(float radians) noexcept
	{
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixRotationY(radians));
		return R;
	}

	inline Matrix Matrix::CreateRotationZ(float radians) noexcept
	{
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixRotationZ(radians));
		return R;
	}

	inline Matrix Matrix::CreateFromAxisAngle(const Vector3& axis, float angle) noexcept
	{
		using namespace DirectX;
		Matrix R;
		const XMVECTOR a = XMLoadFloat3(&axis);
		XMStoreFloat4x4(&R, XMMatrixRotationAxis(a, angle));
		return R;
	}

	inline Matrix Matrix::CreatePerspectiveFieldOfView(float fov, float aspectRatio, float nearPlane,
	                                                   float farPlane) noexcept
	{
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixPerspectiveFovRH(fov, aspectRatio, nearPlane, farPlane));
		return R;
	}

	inline Matrix Matrix::CreatePerspective(float width, float height, float nearPlane, float farPlane) noexcept
	{
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixPerspectiveRH(width, height, nearPlane, farPlane));
		return R;
	}

	inline Matrix Matrix::CreateOrthographic(float width, float height, float zNearPlane, float zFarPlane) noexcept
	{
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixOrthographicRH(width, height, zNearPlane, zFarPlane));
		return R;
	}

	inline Matrix Matrix::CreateLookAt(const Vector3& eye, const Vector3& target, const Vector3& up) noexcept
	{
		Matrix R;
		const XMVECTOR eyev = XMLoadFloat3(&eye);
		const XMVECTOR targetv = XMLoadFloat3(&target);
		const XMVECTOR upv = XMLoadFloat3(&up);
		XMStoreFloat4x4(&R, XMMatrixLookAtRH(eyev, targetv, upv));
		return R;
	}

	inline Matrix Matrix::CreateWorld(const Vector3& position, const Vector3& forward, const Vector3& up) noexcept
	{
		const XMVECTOR zaxis = XMVector3Normalize(XMVectorNegate(XMLoadFloat3(&forward)));
		XMVECTOR yaxis = XMLoadFloat3(&up);
		const XMVECTOR xaxis = XMVector3Normalize(XMVector3Cross(yaxis, zaxis));
		yaxis = XMVector3Cross(zaxis, xaxis);

		Matrix R;
		XMStoreFloat3(reinterpret_cast<XMFLOAT3*>(&R._11), xaxis);
		XMStoreFloat3(reinterpret_cast<XMFLOAT3*>(&R._21), yaxis);
		XMStoreFloat3(reinterpret_cast<XMFLOAT3*>(&R._31), zaxis);
		R._14 = R._24 = R._34 = 0.f;
		R._41 = position.x;
		R._42 = position.y;
		R._43 = position.z;
		R._44 = 1.f;
		return R;
	}

	inline Matrix Matrix::CreateFromQuaternion(const Quaternion& rotation) noexcept
	{
		const XMVECTOR quatv = XMLoadFloat4(&rotation);
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixRotationQuaternion(quatv));
		return R;
	}

	inline Matrix Matrix::CreateFromYawPitchRoll(float yaw, float pitch, float roll) noexcept
	{
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixRotationRollPitchYaw(pitch, yaw, roll));
		return R;
	}

	inline Matrix Matrix::CreateFromYawPitchRoll(const Vector3& angles) noexcept
	{
		Matrix R;
		XMStoreFloat4x4(&R, XMMatrixRotationRollPitchYawFromVector(angles));
		return R;
	}


	inline void Matrix::Lerp(const Matrix& M1, const Matrix& M2, float t, Matrix& result) noexcept
	{
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._41));

		const XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._11));
		const XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._21));
		const XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._31));
		const XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._41));

		x1 = XMVectorLerp(x1, y1, t);
		x2 = XMVectorLerp(x2, y2, t);
		x3 = XMVectorLerp(x3, y3, t);
		x4 = XMVectorLerp(x4, y4, t);

		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&result._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&result._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&result._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&result._41), x4);
	}

	inline Matrix Matrix::Lerp(const Matrix& M1, const Matrix& M2, float t) noexcept
	{
		XMVECTOR x1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._11));
		XMVECTOR x2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._21));
		XMVECTOR x3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._31));
		XMVECTOR x4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M1._41));

		const XMVECTOR y1 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._11));
		const XMVECTOR y2 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._21));
		const XMVECTOR y3 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._31));
		const XMVECTOR y4 = XMLoadFloat4(reinterpret_cast<const XMFLOAT4*>(&M2._41));

		x1 = XMVectorLerp(x1, y1, t);
		x2 = XMVectorLerp(x2, y2, t);
		x3 = XMVectorLerp(x3, y3, t);
		x4 = XMVectorLerp(x4, y4, t);

		Matrix result;
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&result._11), x1);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&result._21), x2);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&result._31), x3);
		XMStoreFloat4(reinterpret_cast<XMFLOAT4*>(&result._41), x4);
		return result;
	}

	inline Matrix Matrix::Transform(const Matrix& M, const Quaternion& rotation) noexcept
	{
		using namespace DirectX;
		const XMVECTOR quatv = XMLoadFloat4(&rotation);

		const XMMATRIX M0 = XMLoadFloat4x4(&M);
		const XMMATRIX M1 = XMMatrixRotationQuaternion(quatv);

		Matrix result;
		XMStoreFloat4x4(&result, XMMatrixMultiply(M0, M1));
		return result;
	}
}
