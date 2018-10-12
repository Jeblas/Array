#pragma once

#include <iostream>

constexpr std::size_t INIT_RES_SIZE = 1;

template<typename T> class array_iterator;

template<typename T>
class array {
public:
    //default constructor
    array() : m_size(0), m_reserved_size(INIT_RES_SIZE) {
        m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
    }

    //initialize array with elements in initializer
    // initial reserved size = m_size. This is what vector does.
    array(std::initializer_list<T> init_list) : m_size(init_list.size()), m_reserved_size(init_list.size()) {
        if (m_size > m_reserved_size) {
            m_reserved_size = m_size;
        }
        m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
        typename std::initializer_list<T>::iterator it;
        std::size_t i = 0;
        for (it = init_list.begin(); it != init_list.end(); ++it) {
            //TODO Copy T() or move T()??
            new (m_elements + i) T(*it);
            ++i;
        }
    }

    //copy constructor
    array(const array& rhs) : m_size(rhs.m_size), m_reserved_size(rhs.m_reserved_size) {
        m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
        for (int i = 0; i < rhs.m_size; ++i) {
            new (m_elements + i) T(rhs.m_elements[i]);
        }
    }

    //move constructor
    array(array&& rhs) : m_size(rhs.m_size), m_reserved_size(rhs.m_reserved_size), m_elements(rhs.m_elements) {
        rhs.m_elements = nullptr;
    }

    //construct with initial "reserved" size
    array(std::size_t num_res) : m_size(num_res), m_reserved_size(num_res) {
        m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
        // Vector populates elements with a default constructor.
        for (int i = 0; i < m_size; ++i) {
            new (m_elements + i) T();
        }
    }

    //construct with n copies of t
    // TODO might need to change m_reserved_size(n)
    array(std::size_t n, const T& t) : m_size(n), m_reserved_size(INIT_RES_SIZE) {
        if (n > INIT_RES_SIZE) {
            m_reserved_size = n;
        }

        m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
        for (int i = 0; i < m_size; ++i) {
            new (m_elements + i) T(t);
        }
    }

    //destructor
    ~array() {
        if (m_elements != nullptr) {
            for (int i = 0; i < m_size; ++i) {
                (m_elements + i)->~T();
            }
            free(m_elements);
        }
    }

    //ensure enough memory for n elements
    // TODO Does m_size = n?
    void reserve(std::size_t n) {
        if (n > m_reserved_size) {
            T* old_elements = m_elements;
            m_reserved_size = n;
            m_elements = (T*)malloc(sizeof(T) * n);

            for (int i = 0; i < m_size; ++i) {
                new (m_elements + i) T(std::move(old_elements[i]));
                old_elements[i].~T();
            }
            free(old_elements);
        }
    }

    //add to end of vector
    void push_back(const T& t) {
        if (m_size == m_reserved_size) {
            reserve(m_reserved_size * 2);
        }
        new (m_elements + m_size) T(t);
        ++m_size;
    }

    //add to front of vector
    void push_front(const T& t) {
        if (m_size == m_reserved_size) {
            T* old_elements = m_elements;
            m_reserved_size *= 2;
            m_elements = (T*)malloc(sizeof(T) * m_reserved_size);

	    for (std::size_t i = m_size; i>0; --i) {
	        new (m_elements + i) T(std::move(old_elements[i - 1]));
                m_elements[i - 1].~T();
	    }
            free(old_elements);
        } else {
	    for (std::size_t i = m_size; i>0; --i) {
	        new (m_elements + i) T(std::move(m_elements[i - 1]));
                m_elements[i - 1].~T();
	    }
	}
        new (m_elements) T(t);
        ++m_size;
    }

    //remove last element
    void pop_back() {
        // up to ~T() to clear up memory and change assocciated variables.
        // Skipping nullptr check since array always initializes and calls malloc()
        if (m_size > 0) {
            --m_size;
            m_elements[m_size].~T();
        }
    }

    //remove first element
    void pop_front() {
        //Call destructor, shift array to left, decrease m_size;   
        if (m_size > 0) {
            //m_elements -> ~T();
            for (int i = 1; i < m_size; ++i) {
                m_elements[i-1] = std::move(m_elements[i]);
            }
            --m_size;
            m_elements[m_size].~T();
        }
    }

    //return reference to first element
    T& front() const {
        return m_elements[0];
    }

    //return reference to last element
    T& back() const {
        return m_elements[m_size - 1];
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
        for (int i = 0; i < m_size; ++i) {
            m_elements[i].~T();
        }
        m_size = 0;
    }

    //obtain iterator to first element
    array_iterator<T> begin() const {
        return array_iterator<T>(m_elements);
    }

    //obtain iterator to one beyond element
    array_iterator<T> end() const {
        return array_iterator<T>(m_elements + m_size);
    }

    //remove specified element
    void erase(const array_iterator<T>& ai) {
        // remove element a iterator location, move other elements left
        array_iterator<T> end(this->end());
        array_iterator<T> it(ai);
        ++it;
        while(it != end) {
            *(it.m_current - 1) = std::move(*it.m_current);
            ++it;
        }
        --m_size;
        m_elements[m_size].~T();
        
    }

    //TODO
    //insert element right before itr
    void insert(const T& t, const array_iterator<T>& ai) {
        // move elements right by 1 and insert value
	array_iterator<T> it(ai);
        if (m_size == m_reserved_size) {
            T* old_elements = m_elements;
            m_reserved_size *= 2;
            m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
	    
	    std::size_t count= 0;
            for (array_iterator<T> it(ai); it != ai; ++it) {
	        //move each element from the old_element to
	//	new (m_elements)
	    }


	    for (std::size_t i = m_size; i>0; --i) {
	        new (m_elements + i) T(std::move(old_elements[i - 1]));
                m_elements[i - 1].~T();
	    }
            free(old_elements);
        } else {
	    for (std::size_t i = m_size; i>0; --i) {
	        new (m_elements + i) T(std::move(m_elements[i - 1]));
                m_elements[i - 1].~T();
	    }
	}
        new (m_elements) T(t);
        ++m_size;
    }

    //Copy Assignment operator overload
    array& operator=(const array& rhs) {
        if (this != &rhs) {
            m_size = rhs.size;
            m_reserved_size = rhs.m_reserved_size;
            m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
            for (int i = 0; i < rhs.m_size; ++i) {
                new (m_elements + i) T(rhs.m_elements[i]);
            }
        }
        return *this;
    }
    //Move assignment operator overload
    array& operator=(array&& rhs) {
        if (this != &rhs) {
            m_size = rhs.m_size;
            m_reserved_size = rhs.m_reserved_size;
            m_elements = rhs.m_elements;
            rhs.m_elements = nullptr;
        }
        return *this;
    }
    //TODO Extra credit for push_back(const T&&)
private:
    T* m_elements;              //points to actual elements
    std::size_t m_size;              //number of elements
    std::size_t m_reserved_size;     //number of reserved elements
};

template<typename T>
class array_iterator {
public:
    array_iterator() {
        m_current = nullptr;
    }

    array_iterator(T* start) {
        m_current = start;
    }

    array_iterator(const array_iterator& it) {
        m_current = it.m_current;
    }

    T& operator*() const {
        return *m_current;
    }

    // Pre
    array_iterator operator++() {
        ++(m_current);
        return *this;
    }

    // Post
    array_iterator operator++(int __unused) {
        array_iterator<T> temp = array_iterator<T>(*this);
        ++(m_current);
        return temp;
    }

    bool operator != (const array_iterator& rhs) const {
        return (m_current != rhs.m_current);
    }

    bool operator == (const array_iterator& rhs) const {
        return (m_current == rhs.m_current);
    }


private:
    T* m_current;
    // I want my array class to be able to access m_current even though it's private
    // 'friend' allows this to happen
    friend class array<T>;
};
