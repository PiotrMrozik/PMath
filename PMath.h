#pragma once
#include <cstring>
#include <DirectXMath.h>

using namespace DirectX;

namespace PMgene::Math
{
	struct Vector3;
	struct Quaternion;
	struct Matrix;


	//****************************************************************************
	//Vector3

	struct Vector3 : public XMFLOAT3
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




	//------------------------------------------------------------------------------
		// Quaternion
	struct Quaternion : public XMFLOAT4
	{
		Quaternion() noexcept : XMFLOAT4(0, 0, 0, 1.f) {}
		constexpr Quaternion(float ix, float iy, float iz, float iw) noexcept : XMFLOAT4(ix, iy, iz, iw) {}
		Quaternion(const Vector3& v, float scalar) noexcept : XMFLOAT4(v.x, v.y, v.z, scalar) {}
		explicit Quaternion(FXMVECTOR V) noexcept : XMFLOAT4() { XMStoreFloat4(this, V); }
		explicit Quaternion(const XMFLOAT4& q) noexcept : XMFLOAT4()
		{ this->x = q.x; this->y = q.y; this->z = q.z; this->w = q.w; }

		Quaternion(const Quaternion&) = default;
		Quaternion& operator=(const Quaternion&) = default;

		Quaternion(Quaternion&&) = default;
		Quaternion& operator=(Quaternion&&) = default;

		operator XMVECTOR() const noexcept { return XMLoadFloat4(this); }

		// Comparison operators
		bool operator == (const Quaternion& q) const noexcept;
		bool operator != (const Quaternion& q) const noexcept;

		// Assignment operators
		Quaternion& operator= (const XMVECTORF32& F) noexcept { x = F.f[0]; y = F.f[1]; z = F.f[2]; w = F.f[3]; return *this; }
		Quaternion& operator+= (const Quaternion& q) noexcept;
		Quaternion& operator-= (const Quaternion& q) noexcept;
		Quaternion& operator*= (const Quaternion& q) noexcept;
		Quaternion& operator*= (float S) noexcept;
		Quaternion& operator/= (const Quaternion& q) noexcept;

		// Unary operators
		Quaternion operator+ () const  noexcept { return *this; }
		Quaternion operator- () const noexcept;

		// Quaternion operations
		float Length() const noexcept;

		void Normalize() noexcept;

		void Conjugate() noexcept;

		void Inverse(Quaternion& result) const noexcept;

		float Dot(const Quaternion& Q) const noexcept;

		// Computes rotation about y-axis (y), then x-axis (x), then z-axis (z)
		Vector3 ToEuler() const noexcept;

		// Static functions
		static Quaternion CreateFromAxisAngle(const Vector3& axis, float angle) noexcept;

		// Rotates about y-axis (yaw), then x-axis (pitch), then z-axis (roll)
		static Quaternion CreateFromYawPitchRoll(float yaw, float pitch, float roll) noexcept;

		// Rotates about y-axis (angles.y), then x-axis (angles.x), then z-axis (angles.z)
		static Quaternion CreateFromYawPitchRoll(const Vector3& angles) noexcept;

		static Quaternion CreateFromRotationMatrix(const Matrix& M) noexcept;

		static void Lerp(const Quaternion& q1, const Quaternion& q2, float t, Quaternion& result) noexcept;
		static Quaternion Lerp(const Quaternion& q1, const Quaternion& q2, float t) noexcept;

		static void Slerp(const Quaternion& q1, const Quaternion& q2, float t, Quaternion& result) noexcept;
		static Quaternion Slerp(const Quaternion& q1, const Quaternion& q2, float t) noexcept;
		
		static Quaternion Concatenate(const Quaternion& q1, const Quaternion& q2) noexcept;
	
		static float Angle(const Quaternion& q1, const Quaternion& q2) noexcept;

		// Constants
		static const Quaternion Identity;
	};

	// Binary operators
	Quaternion operator+ (const Quaternion& Q1, const Quaternion& Q2) noexcept;
	Quaternion operator- (const Quaternion& Q1, const Quaternion& Q2) noexcept;
	Quaternion operator* (const Quaternion& Q1, const Quaternion& Q2) noexcept;
	Quaternion operator* (const Quaternion& Q, float S) noexcept;
	Quaternion operator/ (const Quaternion& Q1, const Quaternion& Q2) noexcept;
	Quaternion operator* (float S, const Quaternion& Q) noexcept;



	//****************************************************************************
	// 4x4 Matrix
	struct Matrix : public XMFLOAT4X4
	{
		Matrix() noexcept
			: XMFLOAT4X4(1.f, 0, 0, 0,
			             0, 1.f, 0, 0,
			             0, 0, 1.f, 0,
			             0, 0, 0, 1.f)
		{
		}

		constexpr Matrix(float m00, float m01, float m02, float m03,
		                 float m10, float m11, float m12, float m13,
		                 float m20, float m21, float m22, float m23,
		                 float m30, float m31, float m32, float m33) noexcept
			: XMFLOAT4X4(m00, m01, m02, m03,
			             m10, m11, m12, m13,
			             m20, m21, m22, m23,
			             m30, m31, m32, m33)
		{
		}

		explicit Matrix(const Vector3& r0, const Vector3& r1, const Vector3& r2) noexcept
			: XMFLOAT4X4(r0.x, r0.y, r0.z, 0,
			             r1.x, r1.y, r1.z, 0,
			             r2.x, r2.y, r2.z, 0,
			             0, 0, 0, 1.f)
		{
		}

		explicit Matrix(const XMFLOAT4X4& M) noexcept : XMFLOAT4X4() { memcpy(this, &M, sizeof(XMFLOAT4X4)); }
		Matrix(const XMFLOAT4X3& M) noexcept;


		explicit Matrix(CXMMATRIX M) noexcept : XMFLOAT4X4() { XMStoreFloat4x4(this, M); }

		Matrix(const Matrix&) = default;
		Matrix& operator=(const Matrix&) = default;

		Matrix(Matrix&&) = default;
		Matrix& operator=(Matrix&&) = default;
		

		// Comparison operators
		bool operator ==(const Matrix& M) const noexcept;
		bool operator !=(const Matrix& M) const noexcept;

		// Assignment operators
		Matrix& operator=(const XMFLOAT3X3& M) noexcept;
		Matrix& operator=(const XMFLOAT4X3& M) noexcept;
		Matrix& operator+=(const Matrix& M) noexcept;
		Matrix& operator-=(const Matrix& M) noexcept;
		Matrix& operator*=(const Matrix& M) noexcept;
		Matrix& operator*=(float S) noexcept;
		Matrix& operator/=(float S) noexcept;

		Matrix& operator/=(const Matrix& M) noexcept;
		// Element-wise divide

		// Unary operators
		Matrix operator+() const noexcept { return *this; }
		Matrix operator-() const noexcept;

		[[nodiscard]] Vector3 Translation() const noexcept { return Vector3(_41, _42, _43); }

		// Matrix operations
		bool Decompose(Vector3& scale, Quaternion& rotation, Vector3& translation) noexcept;

		Matrix Transpose() const noexcept;
		void Transpose(Matrix& result) const noexcept;

		Matrix Invert() const noexcept;
		void Invert(Matrix& result) const noexcept;

		float Determinant() const noexcept;

		// Computes rotation about y-axis (y), then x-axis (x), then z-axis (z)
		Vector3 ToEuler() const noexcept;

		
		static Matrix CreateTranslation(const Vector3& position) noexcept;
		static Matrix CreateTranslation(float x, float y, float z) noexcept;

		static Matrix CreateScale(const Vector3& scales) noexcept;
		static Matrix CreateScale(float xs, float ys, float zs) noexcept;
		static Matrix CreateScale(float scale) noexcept;

		static Matrix CreateRotationX(float radians) noexcept;
		static Matrix CreateRotationY(float radians) noexcept;
		static Matrix CreateRotationZ(float radians) noexcept;

		static Matrix CreateFromAxisAngle(const Vector3& axis, float angle) noexcept;

		static Matrix CreatePerspectiveFieldOfView(float fov, float aspectRatio, float nearPlane,
		                                           float farPlane) noexcept;
		static Matrix CreatePerspective(float width, float height, float nearPlane, float farPlane) noexcept;
		
		static Matrix CreateOrthographic(float width, float height, float zNearPlane, float zFarPlane) noexcept;
		
		static Matrix CreateLookAt(const Vector3& position, const Vector3& target, const Vector3& up) noexcept;
		static Matrix CreateWorld(const Vector3& position, const Vector3& forward, const Vector3& up) noexcept;

		static Matrix CreateFromQuaternion(const Quaternion& quat) noexcept;

		// Rotates about y-axis (yaw), then x-axis (pitch), then z-axis (roll)
		static Matrix CreateFromYawPitchRoll(float yaw, float pitch, float roll) noexcept;

		// Rotates about y-axis (angles.y), then x-axis (angles.x), then z-axis (angles.z)
		static Matrix CreateFromYawPitchRoll(const Vector3& angles) noexcept;

		static void Lerp(const Matrix& M1, const Matrix& M2, float t, Matrix& result) noexcept;
		static Matrix Lerp(const Matrix& M1, const Matrix& M2, float t) noexcept;

		
		static Matrix Transform(const Matrix& M, const Quaternion& rotation) noexcept;

		// Constants
		static const Matrix Identity;
	};

	// Binary operators
	Matrix operator+(const Matrix& M1, const Matrix& M2) noexcept;
	Matrix operator-(const Matrix& M1, const Matrix& M2) noexcept;
	Matrix operator*(const Matrix& M1, const Matrix& M2) noexcept;
	Matrix operator*(const Matrix& M, float S) noexcept;
	Matrix operator/(const Matrix& M, float S) noexcept;
	Matrix operator/(const Matrix& M1, const Matrix& M2) noexcept;
	// Element-wise divide
	Matrix operator*(float S, const Matrix& M) noexcept;
}
