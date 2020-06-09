#pragma once

/*
Project: CuckyGameEngine

File: CGE/Math.h
Purpose: Declare the CuckyGameEngine math interface

Authors: Regan "cuckydev" Green
*/

//Standard library
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>

//CuckyGameEngine namespace
namespace CGE
{
	//Math namespace
	namespace Math
	{
		//Vector struct
		template <unsigned dimension, class T>
		struct Vector
		{
			//Vector values
			T d[dimension] = {0};
			
			//Operator overloads
			T& operator[](unsigned i) { return d[i]; }
			const T& operator[](unsigned i) const { return d[i]; }
			
			//Arithmetic operators
			Vector operator+(const Vector &rhs) const
			{
				Vector result;
				std::transform(d, d + dimension, rhs.d, result.d, std::plus<T>());
				return result;
			}
			
			Vector operator-(const Vector &rhs) const
			{
				Vector result;
				std::transform(d, d + dimension, rhs.d, result.d, std::minus<T>());
				return result;
			}
			
			Vector operator*(const Vector &rhs) const
			{
				Vector result;
				std::transform(d, d + dimension, rhs.d, result.d, std::multiplies<T>());
				return result;
			}
			
			Vector operator*(const T &rhs) const
			{
				Vector result;
				std::transform(d, d + dimension, result.d, std::bind2nd(std::multiplies<T>(), rhs));
				return result;
			}
			
			Vector operator/(const Vector &rhs) const
			{
				Vector result;
				std::transform(d, d + dimension, rhs.d, result.d, std::divides<T>());
				return result;
			}
			
			Vector operator/(const T &rhs) const
			{
				Vector result;
				std::transform(d, d + dimension, result.d, std::bind2nd(std::divides<T>(), rhs));
				return result;
			}
			
			//Assignment operators
			void operator+=(const Vector &rhs)
			{
				std::transform(d, d + dimension, rhs.d, d, std::plus<T>());
			}
			
			void operator-=(const Vector &rhs)
			{
				std::transform(d, d + dimension, rhs.d, d, std::minus<T>());
			}
			
			void operator*=(const Vector &rhs)
			{
				std::transform(d, d + dimension, rhs.d, d, std::multiplies<T>());
			}
			
			void operator*=(const T &rhs)
			{
				std::transform(d, d + dimension, d, std::bind2nd(std::multiplies<T>(), rhs));
			}
			
			void operator/=(const Vector &rhs)
			{
				std::transform(d, d + dimension, rhs.d, d, std::divides<T>());
			}
			
			void operator/=(const T &rhs)
			{
				std::transform(d, d + dimension, d, std::bind2nd(std::divides<T>(), rhs));
			}
			
			//Comparision operators
			bool operator==(const Vector &rhs) const
			{
				for (unsigned i = 0; i < dimension; i++)
				{
					if (d[i] != rhs[i])
						return false;
				}
				return true;
			}
			
			bool operator!=(const Vector &rhs) const
			{
				for (unsigned i = 0; i < dimension; i++)
				{
					if (d[i] == rhs[i])
						return false;
				}
				return true;
			}
			
			//Vector operations
			Vector Lerp(const Vector &rhs, const float &t) const
			{
				Vector result;
				for (unsigned i = 0; i < dimension; i++)
					result[i] = d[i] + (rhs[i] - d[i]) * t;
				return result;
			}
			
			T Dot(const Vector &rhs) const
			{
				T result = 0;
				for (unsigned i = 0; i < dimension; i++)
					result += d[i] * rhs[i];
				return result;
			}
			
			auto Cross(const Vector &rhs) const
			{
				if constexpr (dimension == 2)
					return d[0] * rhs[1] - d[0] * rhs[2]; //Scalar
				if constexpr (dimension == 3)
					return Vector{d[1] * rhs[2] - d[2] * rhs[1], d[2] * rhs[0] - d[0] * rhs[2], d[0] * rhs[1] - d[1] * rhs[0]};
			}
			
			T Magnitude() const
			{
				T result = std::accumulate(d, d + dimension, 0, [](auto sum, auto x) { return sum + (x * x); });
				return std::sqrt(result);
			}
			
			Vector Normalized() const
			{
				Vector result;
				T magnitude = Magnitude();
				std::transform(d, d + dimension, result.d, std::bind2nd(std::divides<T>(), magnitude));
				return result;
			}
			
			void Normalize()
			{
				T magnitude = Magnitude();
				std::transform(d, d + dimension, d, std::bind2nd(std::divides<T>(), magnitude));
			}
		};
		
		//Quaternion struct
		template <class T>
		struct Quaternion
		{
			//Quaternion values
			T x, y, z, w;
			
			//TODO: make this
		};
		
		//Matrix struct
		template <class T>
		struct Matrix
		{
			//Matrix values
			T m[16] = {
				1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1,
			};
		};
		
		//Matrix constructors
		template <class T>
		auto IdentityMatrix = Matrix<T>{
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1,
		};
		
		template <class T>
		Matrix<T> PerspectiveMatrix(const T &y_fov, const T &aspect_ratio, const T &near, const T &far)
		{
			//Get some common variables from given properties
			T scale = std::tan(y_fov * 0.5 * std::acos(-1) / 180) * near; 
			T r = aspect_ratio * scale;
			T l = -r; 
			T t = scale;
			T b = -t; 
			
			//Construct matrix
			return Matrix<T>{
				2 * near / (r - l), 0, 0, 0,
				0, 2 * near / (t - b), 0, 0,
				(r + l) / (r - l), (t + b) / (t - b), -(far + near) / (far - near), -1, 
				0, 0, -2 * far * near / (far - near), 0,
			};
		};
		
		template <class T>
		Matrix<T> OrthoMatrix(const T &bottom, const T &top, const T &left, const T &right, const T &near, const T &far)
		{
			//Construct matrix
			return Matrix<T>{
				2 / (right - left), 0, 0, 0,
				0, 2 / (top - bottom), 0, 0,
				0, 0, -2 / (far - near), 0,
				-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1,
			};
		};
	}
}
