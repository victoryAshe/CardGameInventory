#pragma once

#include <iostream>

template<typename T>
class CircleArray
{
public:
	CircleArray()
	{
		// Allocate memory.
		ReAllocate(capacity);
	}

	~CircleArray()
	{
		// free memory.
		if (data)
		{
			delete[] data;
			data = nullptr;
		}
	}

public:
	// Reallocate the data memory.
	void ReAllocate(size_t newCapacity)
	{
		// 1. allocate new memory space to move.
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);

		// 2. Copy existing memory to the new memory space.
		if (data)
		{
			memcpy(newBlock, data, sizeof(T) * capacity);
		}

		// 3. free existing array memory space.
		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

	// Insert Value.
	void Insert(const T& value)
	{
		// Check lack of capcity.
		if (size == capacity)
		{
			// ReAllocate *2.
			ReAllocate(capacity * 2);
		}

		// Insert Value.
		data[size++] = value;
	}

	// Insert R-Value-Reference.
	void Insert(T&& value)
	{
		// Check lack of capacity.
		if (size == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// Move and Insert.
		data[size++] = std::move(value);
	}

	// Array operator overloading.
	T& operator[](int index)
	{
		if (index >= 0) return data[index % size];
		else return data[index + size];
	}

	// Functions for Range-based loop 
	// returns the beginning position of the array
	T* begin()
	{
		return data;
	}

	// returns the last(last data position+1) position of the array
	T* end()
	{
		return data + size;
	}


	// Getter.
	size_t Size() const { return size; }
	size_t Capacity() const { return capacity; }

private:
	T* data = nullptr;

	// the item count.
	size_t size = 0;

	// the memory size of the array.
	size_t capacity = 2;
};

