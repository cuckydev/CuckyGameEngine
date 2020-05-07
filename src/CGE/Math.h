#pragma once

/*
Project: CuckyGameEngine

File: CGE/Math.h
Purpose: Declare the CuckyGameEngine math interface

Authors: Regan Green (cuckydev)
*/

//Standard library
#include <cmath>
#include <algorithm>

#include <iostream>

//CuckyGameEngine namespace
namespace CGE
{
	//Math namespace
	namespace Math
	{
		//Vector types
		template <unsigned dimension, class T>
		struct Vector
		{
			//Dimensions
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
					return Vector<dimension, T>{d[1] * rhs[2] - d[2] * rhs[1], 0, 0};
			}
			
			T Magnitude() const
			{
				T result;
				for (const T &i : d)
					result += i * i;
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
				for (T &i : d)
					i /= magnitude;
			}
		};
	}
}
