//
//  main.cpp
//  ring_queue
//
//  Created by Guorui Xiao on 2017/11/25.
//  Copyright © 2017年 Guorui Xiao. All rights reserved.
//

#include <iostream>
#include "queue.hpp"

int main(){
    RingQueue<int,7> rq;
    rq.dump_queue();
    
    for ( int i = 0 ; i < 8 ; ++i )
        rq.push_back(i+1);
    
    rq.dump_queue();
    rq.pop_front();
    
    std::cout << "Queue via size: \n";
    
    // RingQueue<int,7>::iterator it = rq.begin() ;
    auto it = rq.begin() ;
    
    
    for ( size_t i = 0 ; i < rq.size() ; ++i ) {
        std::cout << "Value: " << *it << ", address: " << &(*it) << '\n';
        ++it;
    }
    std::cout << '\n';
    
    
    
    // Uncomment the block below only when you have a working
    // implementation of RingQueue<ItemType,int>::end().
    // If the implementation is not correct, it might result in
    // an infinite loop.

     std::cout << "Queue via iterators: \n";
     for ( auto it = rq.begin() ; it != rq.end() ; ++it ) {
     std::cout << "Value: " << *it << ", address: " << &(*it) << '\n';
         
         
     }
     std::cout << '\n';
    
    
    
    
    rq.dump_queue();
    
    return 0;
}



/**
 +++++++++++++++++++++++++++++++++++++++++++++++
 The output of your program [once the missing
 code is added] should look more or less like
 the output below.
 
 Note:
 It is dependent on the device where
 this driver is executed. However, it
 should be clear that the difference
 between consecutive memory addresses
 is equal to the number reported by
 'size_of( int )'.
 +++++++++++++++++++++++++++++++++++++++++++++++
 
 Raw queue...
 Val: 2, at: 0x7ffcdeeaab40
 Val: 0, at: 0x7ffcdeeaab44
 Val: 4198285, at: 0x7ffcdeeaab48
 Val: 0, at: 0x7ffcdeeaab4c
 Val: 0, at: 0x7ffcdeeaab50
 Val: 0, at: 0x7ffcdeeaab54
 Val: 0, at: 0x7ffcdeeaab58
 
 Raw queue...
 Val: 8, at: 0x7ffcdeeaab40
 Val: 2, at: 0x7ffcdeeaab44
 Val: 3, at: 0x7ffcdeeaab48
 Val: 4, at: 0x7ffcdeeaab4c
 Val: 5, at: 0x7ffcdeeaab50
 Val: 6, at: 0x7ffcdeeaab54
 Val: 7, at: 0x7ffcdeeaab58
 
 Queue via size:
 Value: 3, address: 0x7ffcdeeaab48
 Value: 4, address: 0x7ffcdeeaab4c
 Value: 5, address: 0x7ffcdeeaab50
 Value: 6, address: 0x7ffcdeeaab54
 Value: 7, address: 0x7ffcdeeaab58
 Value: 8, address: 0x7ffcdeeaab40
 
 Queue via iterators:
 Value: 3, address: 0x7ffcdeeaab48
 Value: 4, address: 0x7ffcdeeaab4c
 Value: 5, address: 0x7ffcdeeaab50
 Value: 6, address: 0x7ffcdeeaab54
 Value: 7, address: 0x7ffcdeeaab58
 Value: 8, address: 0x7ffcdeeaab40
 
 Raw queue...
 Val: 8, at: 0x7ffcdeeaab40
 Val: 2, at: 0x7ffcdeeaab44
 Val: 3, at: 0x7ffcdeeaab48
 Val: 4, at: 0x7ffcdeeaab4c
 Val: 5, at: 0x7ffcdeeaab50
 Val: 6, at: 0x7ffcdeeaab54
 Val: 7, at: 0x7ffcdeeaab58
 */






