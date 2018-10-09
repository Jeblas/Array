#include "array.h"
#include "simple_string.h"

//default constructor
//template class array<simple_string>;
/*
template <typename T>
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
array<T>::array(const array& rhs) : m_reserved_size(rhs.m_reserved_size), m_size(rhs.m_size) {

}

//move constructor
template <typename T>
array<T>::array(array&& rhs ) : m_reserved_size(rhs.m_reserved_size), m_size(rhs.m_size), m_elements(rhs.m_elements) {

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
//    m_elements = nullptr;
//}
    if (m_elements != nullptr) {
	//for (int i = 0; i < m_size; ++i) {
	    //(m_elements + i) -> ~T();
	  //  free (m_elements + i);

	//}
        free(m_elements);

    }
}

// TODO 
template <typename T>
void array<T>::reserve(std::size_t n) {

}

template <typename T>
void array<T>::push_back(const T& element) {

}

template <typename T>
void array<T>::push_front(const T& element) {
    
}

template <typename T>
void array<T>::pop_back() {

}

template <typename T>
void array<T>::pop_front() {

}

template <typename T>
T& array<T>::front() const{
    return (*m_elements);
}

template <typename T>
T& array<T>::back() const{
    return *(m_elements + m_size);  
}

*/
