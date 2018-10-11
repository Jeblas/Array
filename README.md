- copy constructor uses placement new : new (m_elements + i) T(old_elements[i]);
- copy assignment - m_elements[i] = T(old_elements[i]);
- move assignment = m_elemtents[i] = std::move(old_elements[i]);
- move constructor = new (m_elements + i) T(std::move(old_elemnts[i]));


- TODO check to confirm that destucts are called when makeing a copy of m_elements


