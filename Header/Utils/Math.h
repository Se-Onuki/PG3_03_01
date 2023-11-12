#pragma once
#include "Vector2.h"
#include <cmath>

inline Vector2 operator+(const Vector2 &a, const Vector2 &b) {
	return Vector2{ a.x + b.x, a.y + b.y };
}
inline Vector2& operator+=(Vector2 &a, const Vector2 &b) {
	return a = Vector2{ a.x + b.x, a.y + b.y };
}

inline Vector2 operator-(const Vector2 &a, const Vector2 &b) {
	return Vector2{ a.x - b.x, a.y - b.y };
}
inline Vector2 operator*(const Vector2 &a, const float b) {
	return Vector2{ a.x * b, a.y * b };
}
inline Vector2 operator/(const Vector2 &a, const float b) {
	return Vector2{ a.x / b, a.y / b };
}

inline float LengthSQ(const Vector2 &vec) {
	return std::powf(vec.x, 2) + std::powf(vec.y, 2);
}

inline float Length(const Vector2 &vec) {
	return std::sqrtf(LengthSQ(vec));
}

inline Vector2 Normalize(const Vector2 &vec) {
	const float length = Length(vec);
	if (length == 0.f) {
		return Vector2{ 0.f,0.f };
	}

	return vec / length;
}