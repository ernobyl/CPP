#pragma once

template <class T>
class Array
{
	private:
		T*				_data;
		unsigned int	_size;

	public:
		/* Construction with no parameter: Creates an empty array */
		Array() : _data(nullptr), _size(0) {};

		/* Construction with an unsigned int n as a parameter: Creates an array of n elements
			initialized by default.
			Tip: Try to compile int * a = new int(); then display *a. */
		Array(unsigned int n) : _data(new T[n]()), _size(n) {};

		/* Copy constructor. Modifying either the
			original array or its copy after copying musn’t affect the other array. */
		Array(const Array& other) : _data(nullptr), _size(0) { *this = other; };

		/* Copy assignment operator. Modifying either the
			original array or its copy after copying musn’t affect the other array. */
		Array &operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] _data;
				_size = other._size;
				_data = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
					_data[i] = other._data[i];
			}
			return *this;
		};

		/* Destructor */
		~Array() { delete[] _data; };

		/* Operator[] to access elements (with bounds checking) */
    	T& operator[](unsigned int index)
		{
        	if (index >= _size)
            	throw std::out_of_range("Index out of bounds");
        	return _data[index];
    	}

		/* Read only operator[] to access elements */
    	const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
    	}

		/* A member function size() that returns the number of elements in the array. This
			member function takes no parameter and musn’t modify the current instance. */
		unsigned int size() const { return _size; };
};