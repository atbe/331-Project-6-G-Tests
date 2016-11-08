/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MaxHeap.h
 * Author: onsayse
 *
 * Created on November 2, 2016, 5:03 PM
 */

#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cmath>
using namespace std;
template <typename T>
class myMaxHeap
{
private:
    long currentsize;
    vector<T> data;

    void percolateDown(int hole)  {

    }

    void percolateUp(int hole) {
    }

    void heapCreate() {
    } // end heapCreate

public:
   //Exceptions HeapOverflow and HeapUnderflow go here...


   //constructor
    myMaxHeap(vector<T> &input) {
    }

     };
   //rest of the methods defined in requirements document...


#endif /* MAXHEAP_H */

