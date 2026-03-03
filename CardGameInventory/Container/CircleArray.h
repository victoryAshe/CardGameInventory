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

		// 2. Move
		int count = std::min(size, static_cast<int>(newCapacity));
		for (int i = 0; i < count; ++i)
		{
			newBlock[i] = std::move(data[i]);
		}

		// 3. Free memory.
		delete[] data;

		data = newBlock;
		capacity = newCapacity;
		size = count;
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
		data[size] = std::move(value);
		++size;
	}

	// Array operator overloading.
	T& operator[](int index)
	{
		// Exception Handling.
		if (size == 0)
		{
			std::cerr << "CircleArray is empty: Out of bounds.\n";
			__debugbreak();
		}

		index %= size;
		if (index < 0) index += size;
		return data[index];
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
	int Size() const { return size; }
	size_t Capacity() const { return capacity; }

private:
	T* data = nullptr;

	// the item count.
	int size = 0;

	// the memory size of the array.
	size_t capacity = 2;
};

