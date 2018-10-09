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
        // TODO Add elements from init_list to m_elements
    }

    //copy constructor
    array(const array& rhs) : m_size(rhs.m_size), m_reserved_size(rhs.m_reserved_size) {
        m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
	// TODO Copy elements into m_elements
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
    void reserve(std::size_t n);

    //add to end of vector
    void push_back(const T&);

    //add to front of vector
    void push_front(const T&);

    //remove last element
    void pop_back();

    //remove first element
    void pop_front();

    //return reference to first element
    T& front() const;

    //return reference to last element
    T& back() const;

    //return reference to specified element
    const T& operator[](std::size_t) const;

    //return reference to specified element
    T& operator[](std::size_t);

    //return number of elements
    std::size_t length() const;

    //returns true if empty
    bool empty() const;

    //remove all elements
    void clear();

    //obtain iterator to first element
    array_iterator<T> begin() const;

    //obtain iterator to one beyond element
    array_iterator<T> end() const;

    //remove specified element
    void erase(const array_iterator<T>&);

    //insert element right before itr
    void insert(const T&, const array_iterator<T>&);

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
