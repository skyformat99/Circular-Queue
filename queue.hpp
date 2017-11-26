//
//  queue.hpp
//  ring_queue
//  Created by Guorui Xiao on 2017/11/25.
//  Copyright © 2017年 Guorui Xiao. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>

#include <iostream>

// Forward declaration
template <typename ItemType, int MAX_SIZE>
class RingQueue;



template <typename ItemType, int MAX_SIZE>
class RingQueue{
    
    // Nested Forward declaration of RingQueue<ItemType,MAX_SIZE>::iterator
    // This is needed if one plans to turn this home-made iterator into
    // one of the special categories of iterators (e.g., input, output,
    // forward, etc.).
public:
    class iterator;
    
    
    
    // Aliases.
    typedef ItemType* pointer;
    typedef ItemType& reference;
    
    
    
    // Definition of RingQueue<ItemType,MAX_SIZE>::iterator
public:
    class iterator{
    private:
        // A link to the parent container
        RingQueue* parent;
        
        // The position within the RingQueue is determined
        // by how far ahead we are from the begining of the
        // queue.
        int offset;
        
    private:  // Private constructor???
        iterator(RingQueue* _parent, int _offset = 0 ) : parent(_parent), offset(_offset) { } friend class RingQueue<ItemType,MAX_SIZE>;
        
    public:
        reference operator*() {
            int index = (parent->begin_index + offset)& (MAX_SIZE);
            return parent->buffer[index] ;
        }
        
        iterator& operator++(){
            offset++;
            if ((parent->begin_index + offset - 1) >= parent->ring_size){
                offset -= (parent->ring_size + 1);
            }
            
            
            return *this;
        }
        
        iterator operator++( int unused ){
            //SWAP
            iterator x (parent, offset);
            offset++;
            if ((parent->begin_index + offset - 1) >= parent->ring_size){
                offset -= (parent->ring_size + 1);
            }
            
            return x;
        }
        
        bool operator==( const iterator& rhs ) const {
            return (parent == rhs.parent)&&(offset == rhs.offset);
        }
        
        bool operator!=( const iterator& rhs ) const {
            return (parent != rhs.parent)||(offset != rhs.offset);
        }
        
    };
    
    
    
    /**
     class const_iterator{
     private:
     RingQueue* parent;
     int offset;
     
     private:
     // Only RingQueue objects can create const_iterators...
     const_iterator() ;
     
     public:
     // ... however, const_iterators can be 'copied'.
     const_iterator( const const_iterator& ) ;
     
     friend class RingQueue<ItemType,MAX_SIZE>;
     };
     */
    
    
    
    // Friendship goes both ways here.
    friend class iterator;
    // friend class const_iterator;  // not implemented... yet.
    
    
    
private:
    // A fixed-size static array with constant capacity that represents
    // the RingQueue
    ItemType buffer[MAX_SIZE];
    
    // The starting index. It changes according to a very
    // specific set of rules (below).
    int begin_index;
    
    // The actual size of the RingQueue. Not to be confused with
    // its capacity.
    int ring_size;
    
    
    
    // A helper function that computes the index of 'the end'
    // of the RingQueue
    int end_index() const {
        // Replace the line(s) below with your code.
        return (begin_index + ring_size)%(MAX_SIZE);
    }
    
    
    
public:
    // Constructor
    RingQueue() : begin_index(0), ring_size(0) { }
    
    // Accessors. Note: 'back()' is not considered part of the array.
    ItemType front() const {
        if ( ring_size == 0 ) {
            std::cerr<< "Warning: Empty ring!\n";
            throw;
        };
        
        return buffer[begin_index];
    }
    ItemType back() const {
        if ( ring_size == 0 ) {
            std::cerr<< "Warning: Empty ring!\n";
            throw;
        };
        int end = end_index();

        return buffer[end];
    }
    
    
    
    // Mutators
    void push_back( const ItemType& value ){
        int end = end_index();
        buffer[end] = value;
        //update
        ring_size++;
        if (ring_size > MAX_SIZE){
            begin_index++;
            if (begin_index > MAX_SIZE) begin_index -= MAX_SIZE;
            ring_size--;
        }
        return;
    }
    
    
    void pop_front(){
        begin_index++;
        ring_size--;
        return;
    }
    
    // Functions that return iterators
    iterator begin() {
        return iterator(this,0);
    }
    iterator end() {
        // Replace the line(s) below with your code.
        
        return iterator(this,  end_index()-2);
    }
    
    // Miscellaneous functions
    size_t size() const {
        return (ring_size);
    }
    
    // Debugging functions
    void dump_queue() const {
        std::cout << "Raw queue...\n";
        for ( size_t i = 0 ; i < MAX_SIZE ; ++i )
            std::cout << "Val: " << buffer[i] << ", at: " << buffer+i << '\n';
        std::cout << '\n';
        return;
    }
    
};









//template <typename type, size_t capacity>
//class RingQueue {
//public:
//    //default constructor; how to init array?
//    RingQueue();
//
//    //modifyers
//    void push_back(type val);
//    void push_front(type val);
//
//
//private:
//    type buffer[capacity] = {0};
//    unsigned int beging_index;
//    unsigned int ring_size;
//};
//
//
//
//
//
//template <typename type, size_t capacity>
//RingQueue<type,capacity>::RingQueue(): ring_size(0), beging_index(0){};
//
//template <typename type, size_t capacity>
//void RingQueue<type,capacity>::push_back(type val){
//    unsigned int end_index = (beging_index + ring_size)%(capacity);
//    buffer[end_index] = val;
//    //update
//    ring_size++;
//    if (ring_size > capacity){
//        beging_index++;
//        ring_size--;
//    }
//
//}
//
//template <typename type, size_t capacity>
//void RingQueue<type, capacity>::push_front(type val){
//    if(ring_size == capacity){
//        buffer[beging_index] = val;
//    }
//    int i = beging_index;
//    for (; i < capacity; i++){
//        type temp = buffer[i];
//        buffer[i+1] = temp;
//
//    }
//}
//














#endif /* queue_hpp */

