#pragma once

#include <iostream>

constexpr std::size_t INIT_RES_SIZE = 16;

//using size_t = std::size_t;

template<typename T> class array_iterator;

template<typename T>
class array {
public:
    //default constructor
    array() : m_size(0), m_reserved_size(INIT_RES_SIZE) {
	m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
    }

    //initialize array with elements in initializer
    array(std::initializer_list<T> init_list) : m_size(init_list.size()), m_reserved_size(INIT_RES_SIZE) {
	if (m_size > m_reserved_size) {
	    m_reserved_size = m_size;
	}
	m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
	typename std::initializer_list<T>::iterator it;
	std::size_t i = 0;
	for (it = init_list.begin(); it != init_list.end(); ++it) {
	    new (m_elements + i) T(*it);
            ++i;
	}
    }

    //copy constructor
    array(const array& rhs) : m_size(rhs.m_size), m_reserved_size(rhs.m_reserved_size) {
        m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
	// TODO Copy elements into m_elements
	for (int i = 0; i < rhs.m_size; ++i) {
	   new (m_elements + i) T(rhs.m_elements[i]);
	}
    }

    //move constructor
    array(array&& rhs) : m_size(rhs.m_size), m_reserved_size(rhs.m_reserved_size), m_elements(rhs.m_elements) {
        //rhs.m_reserved_size = 0;
	rhs.m_elements = nullptr;
    }

    //construct with initial "reserved" size
    array(std::size_t num_res) : m_size(0), m_reserved_size(num_res) {
        m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
    }

    //construct with n copies of t
    array(std::size_t n, const T& t) : m_size(n), m_reserved_size(INIT_RES_SIZE) {
	if (n > INIT_RES_SIZE) {
	    m_reserved_size = n;
	}
	m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
	//TODO Copy t into m_elements
	for (int i = 0; i < m_size; ++i) {
	    //*(m_elements + i) = t;
	    m_elements[i] = t;
	}
    }

    //destructor
    // TODO Check if correct
    ~array() {
        if (m_elements != nullptr) {
	    for (int i = 0; i < m_size; ++i) {
	        (m_elements + i)->~T();
	    }
	    free(m_elements);
	}
    }

    //ensure enough memory for n elements
    void reserve(std::size_t n) {
    }

    //add to end of vector
    void push_back(const T&);

    //add to front of vector
    void push_front(const T&) {
       //check if resize is needed
       //shift array by 1
       //add element to 
    
    }

    //remove last element
    void pop_back() {
        // up to ~T() to clear up memory and change assocciated variables.
	// Skipping nullptr check since array always initializes and calls malloc()
	if (m_size > 0) {
	    m_elements[m_size - 1].~T();
            --m_size;
	}
    }

    //remove first element
    void pop_front() {
        //Call destructor, shift array to left, decrease m_size;    
    }

    //return reference to first element
    T& front() const {
        return *(m_elements);
    }

    //return reference to last element
    T& back() const {
        return *(m_elements + m_size - 1);
    }

    //return reference to specified element
    // Array on right hand
    const T& operator[](std::size_t index) const {
        return m_elements[index];
    }

    //return reference to specified element
    T& operator[](std::size_t index) {
       return m_elements[index];
    }

    //return number of elements
    std::size_t length() const {
        return m_size;
    }

    //returns true if empty
    bool empty() const {
        return (m_size == 0);
    }

    //remove all elements
    void clear() {
        // Call destructor on every element and change m_size to 0;
    }

    //obtain iterator to first element
    array_iterator<T> begin() const;

    //obtain iterator to one beyond element
    array_iterator<T> end() const;

    //remove specified element
    void erase(const array_iterator<T>&);

    //insert element right before itr
    void insert(const T&, const array_iterator<T>&);

    // TODO Add copy operator overload
    // TODO Add move operator overload
private:
    T* m_elements;              //points to actual elements
    std::size_t m_size;              //number of elements
    std::size_t m_reserved_size;     //number of reserved elements
};

template<typename T>
class array_iterator {
public:
    array_iterator();
    array_iterator(T*);
    array_iterator(const array_iterator&);
    T& operator*() const;
    array_iterator operator++();
    array_iterator operator++(int __unused);
    bool operator != (const array_iterator&) const;
    bool operator == (const array_iterator&) const;

private:
    T* m_current;
    // I want my array class to be able to access m_current even though it's private
    // 'friend' allows this to happen
    friend class array<T>;
};
