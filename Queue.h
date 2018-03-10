#pragma once
/**
 * @class Queue
 * @file Queue.h
 * @date 10.03.2018 
 * @author Levon Ghukasyan
 */

#include <cstdint>

template<class T>
class Queue
{
public:
    //!@brief  constructor
    Queue(uint32_t dimention = 2);
    //!@brief destructor
    ~Queue();

    ///{@brief deleted constructors and assignment operators
public:
    Queue(const Queue& other) = delete;
    const Queue & operator= (const Queue& other) = delete;
    Queue(Queue&& other)= delete;
    Queue& operator= (Queue&& other) = delete;
    ///}

public:
    //!@brief push element to the Queue
    void push(T*);
    //!@brief pop element from the Queue
    T* pop();
    //! returns the front elemento of the Queue
    T* front();
    //!@brief checks if Queue is empty 
    bool empty() const;
    //!@brief checks if Queue is full full
    bool full() const;

    ///{@brief utility/helper functions to fix the heap
    ///this functionalities are needed whaen the new element added or removed 
private:
    ///@brief function to fix the order of the Queue if new element added to back
    void reheapup(int, int);
    ///@brief function to fix the order of the Queue if new element added to front
    void reheapdown(int, int);
    void swap(T* &, T* &);
    ///}


private:
    int m_back;
    T** m_array;
    int m_size;
    static const int SIZE = 10;
    uint32_t m_dimention;
};

#include "_Queue_impl.hpp"
