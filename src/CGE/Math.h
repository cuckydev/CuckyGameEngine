#pragma once

/*
Project: CuckyGameEngine

File: CGE/Math.h
Purpose: Declare the CuckyGameEngine math interface

Authors: Regan Green (cuckydev)
*/

//Standard library
#include <string>

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
				for (unsigned i = 0; i < dimension; i++)
					result[i] = d[i] + rhs[i];
				return result;
			}
			
			Vector operator-(const Vector &rhs) const
			{
				Vector result;
				for (unsigned i = 0; i < dimension; i++)
					result[i] = d[i] - rhs[i];
				return result;
			}
			
			Vector operator*(const Vector &rhs) const
			{
				Vector result;
				for (unsigned i = 0; i < dimension; i++)
					result[i] = d[i] * rhs[i];
				return result;
			}
			
			Vector operator*(const T &rhs) const
			{
				Vector result;
				for (unsigned i = 0; i < dimension; i++)
					result[i] = d[i] * rhs;
				return result;
			}
			
			Vector operator/(const Vector &rhs) const
			{
				Vector result;
				for (unsigned i = 0; i < dimension; i++)
					result[i] = d[i] / rhs[i];
				return result;
			}
			
			Vector operator/(const T &rhs) const
			{
				Vector result;
				for (unsigned i = 0; i < dimension; i++)
					result[i] = d[i] / rhs;
				return result;
			}
			
			//Assignment operators
			void operator+=(const Vector &rhs)
			{
				for (unsigned i = 0; i < dimension; i++)
					d[i] += rhs[i];
			}
			
			void operator-=(const Vector &rhs)
			{
				for (unsigned i = 0; i < dimension; i++)
					d[i] -= rhs[i];
			}
			
			void operator*=(const Vector &rhs)
			{
				for (unsigned i = 0; i < dimension; i++)
					d[i] *= rhs[i];
			}
			
			void operator*=(const T &rhs)
			{
				for (unsigned i = 0; i < dimension; i++)
					d[i] *= rhs;
			}
			
			void operator/=(const Vector &rhs)
			{
				for (unsigned i = 0; i < dimension; i++)
					d[i] /= rhs[i];
			}
			
			void operator/=(const T &rhs)
			{
				for (unsigned i = 0; i < dimension; i++)
					d[i] /= rhs;
			}
			
			//Comparision operators
			bool operator==(const T &rhs) const
			{
				for (unsigned i = 0; i < dimension; i++)
				{
					if (d[i] != rhs[i])
						return false;
				}
				return true;
			}
			
			bool operator!=(const T &rhs) const
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
		};
	}
}
