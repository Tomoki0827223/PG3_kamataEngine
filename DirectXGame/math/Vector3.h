#pragma once
#include <format>
#include <cassert>
#include <imgui.h>
#include <cmath>

/// <summary>
/// 3次元ベクトル
/// </summary>
struct Vector3 final {
    float x, y, z;

    // コンストラクタ
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    // ベクトルの長さを計算
    float Length() const {
        return std::sqrtf(x * x + y * y + z * z);
    }

    // ベクトルの長さの二乗を計算
    float LengthSquared() const {
        return x * x + y * y + z * z;
    }

    // ベクトルの正規化
    Vector3 Normalize() const {
        float len = Length();
        if (len > 0) {
            return *this / len;
        }
        return *this;
    }

    // 内積を計算
    float Dot(const Vector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // 外積を計算
    Vector3 Cross(const Vector3& other) const {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // 演算子オーバーロード
    Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3 operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3 operator/(float scalar) const {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    Vector3& operator+=(const Vector3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vector3& operator-=(const Vector3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vector3& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vector3& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    bool operator==(const Vector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Vector3& other) const {
        return !(*this == other);
    }

    // インデックス演算子の追加
    float& operator[](int index) {
        assert(index >= 0 && index < 3);
        if (index == 0) return x;
        if (index == 1) return y;
        return z;
    }

    const float& operator[](int index) const {
        assert(index >= 0 && index < 3);
        if (index == 0) return x;
        if (index == 1) return y;
        return z;
    }


};
