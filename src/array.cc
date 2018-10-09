//
// Created by bpswe on 9/24/2018.
//
#include "array.h"
//using size_t = std::size_t;
template <typename T>
//default constructor
array<T>::array() {
    m_reserved_size = 16;
    m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
    m_size = 0;
}

//initializer constructor
template <typename T>
array<T>::array(std::initializer_list<T> init_list) {
    m_reserved_size = 16;
    if (init_list.size() > m_reserved_size) {
        m_reserved_size = init_list.size();
    }
    m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
}

//copy constructor
template <typename T>
array<T>::array(const array&) {

}

//move constructor
template <typename T>
array<T>::array(array&& rhs) {
    m_reserved_size =  rhs.m_reserved_size;
    m_size = rhs.m_size;
    m_elements = rhs.m_elements;

    rhs.m_reserved_size = 0;
    rhs.m_elements = nullptr;
}

template <typename T>
array<T>::array(std::size_t init_reserved) : m_reserved_size(init_reserved), m_size(0) {
    m_elements = (T*)malloc(sizeof(T) * m_reserved_size);
}

template <typename T>
array<T>::array(std::size_t n, const T& t) {

}

template <typename T>
array<T>::~array() {
    // for each element in m_elments  free the data.
    // free m_elements
}
