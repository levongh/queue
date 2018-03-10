template<class T>
Queue<T>::Queue(uint32_t dimention)
{
    if(dimention < 2) {
        dimention = 2;
    }
    m_dimention = dimention;
    m_back = 0;
    m_size = SIZE;
    m_array = new T * [m_size];
}

template<class T>
bool Queue<T>::empty() const
{
    return (m_back <= 0);
}

template<class T>
bool Queue<T>::full() const
{
    return (m_back >= m_size);
}

template<class T>
T* Queue<T>::pop()
{
    if(empty()) {
        throw "The queue is empty";
    }
    T* rval = m_array[0];
    m_array[0] = m_array[m_back - 1];
    --m_back;
    reheapdown(0, m_back - 1);
    return rval;
}

template<class T>
T* Queue<T>::front()
{
    if(empty()) {
        throw "The queue is empty";
    }
    return m_array[0];
}

template<class T>
void Queue<T>::push(T* data)
{
    if(full()) {
        int nsize = m_size + SIZE;
        T* *narr=new T * [nsize];
        //TODO
        for(int i = 0; i < m_size; ++i) {
            narr[i] = m_array[i];
        }
        delete[] m_array;
        m_array = narr;
        m_size = nsize;
    }
    m_array[m_back++] = data;
    reheapup(0, m_back - 1);
}

template<class T>
void Queue<T>::reheapup(int root, int bottom)
{
    int parent;
    if(bottom > root) {
        parent=(bottom-1) / m_dimention;
        if(*m_array[parent] > *m_array[bottom]) {
            swap(m_array[parent], m_array[bottom]);
            reheapup(root, parent);
        }
    }
}

template<class T>
void Queue<T>::reheapdown(int root, int bottom)
{
    int minchild, firstchild, child;
    firstchild = root * m_dimention + 1;
    if(firstchild <= bottom) {
        minchild = firstchild;
        for(int i = 2; i <= m_dimention; ++i) {
            child = root * m_dimention + i;
            if(child <= bottom) {
                if(*m_array[child] < *m_array[minchild]) {
                    minchild=child;
                }
            }
        }
        if(*m_array[root] > *m_array[minchild]) {
            swap(m_array[root], m_array[minchild]);
            reheapdown(minchild, bottom);
        }
    }
}

template<class T>
void Queue<T>::swap(T* &a, T* &b)
{
    T* c;
    c = a;
    a = b;
    b = c;
}

template<class T>
Queue<T>::~Queue()
{
    delete[] m_array;
}
