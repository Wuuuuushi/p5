#ifndef __PROJ5_PRIORITY_QUEUE_HPP
#define __PROJ5_PRIORITY_QUEUE_HPP

#include <cstddef>
#include <vector>
#include <stdexcept>
#include <iostream>

namespace shindler::ics46::project5 {


template <typename T>
class PriorityQueue {
   private:
    std::vector<T> priorityQueue{};
    size_t Index{};
    void minHeapDelete(size_t index);
    void minHeapPush(size_t index);

   public:
     PriorityQueue();

     ~PriorityQueue();

    // In general, a copy constructor and assignment operator
    // are good things to have.
    // For this quarter, I am not requiring these.
    //	PriorityQueue(const PriorityQueue & pq);
    //	PriorityQueue & operator=(const PriorityQueue & pq);
    // You do not need to implement these
    PriorityQueue(const PriorityQueue &) = delete;
    PriorityQueue(PriorityQueue &&) = delete;
    PriorityQueue &operator=(const PriorityQueue &) = delete;
    PriorityQueue &operator=(PriorityQueue &&) = delete;

    [[nodiscard]] size_t size() const noexcept;
    [[nodiscard]] bool empty() const noexcept;

    void push(const T& elem);

    // Note:  no non-const version of this one.  This is on purpose because
    // the interior contents should not be able to be modified due to the
    // heap property.  This isn't true of all priority queues but
    // for this project, we will do this.
    // min() should throw std::out_of_range if the queue
    // is empty.
    [[nodiscard]] const T& min() const;

    // popMin() should throw std::out_of_range if the queue
    // is empty.
    void popMin();
};

template <typename T>
PriorityQueue<T>::PriorityQueue() {
    Index = 0;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    // TODO: Implement this
}

template <typename T>
size_t PriorityQueue<T>::size() const noexcept {
    // TODO: Implement this
    return Index;
}

template <typename T>
bool PriorityQueue<T>::empty() const noexcept {
    // TODO: Implement this
    return (Index == 0);
}



template <typename T>
void PriorityQueue<T>::push(const T& elem) {
    priorityQueue.push_back(elem); // Set the size to plus 1 when adding a new element
    minHeapPush(Index);
    Index++;
}

template <typename T>
const T& PriorityQueue<T>::min() const {
    if (Index != 0)
    {
        return priorityQueue[0];
    }
    else
    {
        throw std::runtime_error("ERROR");
    } 
}

template<typename T>
void PriorityQueue<T>::minHeapPush(size_t index)
{
    while (index > 0)
    {
        size_t parentIndex = (index - 1)/2;
        if (priorityQueue[index] < priorityQueue[parentIndex])
        {
            T swapElem{priorityQueue[index]};
            priorityQueue[index] = priorityQueue[parentIndex];
            priorityQueue[parentIndex] = swapElem;
            index = parentIndex;
        }
        else
        {
            break;
        }
    }
}

template<typename T>
void PriorityQueue<T>::minHeapDelete(size_t index){


    size_t leftChild = 2 * index + 1;
    size_t rightChild = 2 * index + 2;

    // Check if left child is smaller than the current element
    if (leftChild < Index && priorityQueue[leftChild] < priorityQueue[index]) {
        T swapElem = priorityQueue[leftChild];
        priorityQueue[leftChild] = priorityQueue[index];
        priorityQueue[index] = swapElem;
        minHeapDelete(leftChild);
    }

    // Check if right child is smaller than the current element
    if (rightChild < Index && priorityQueue[rightChild] < priorityQueue[index]) {
        T swapElem = priorityQueue[rightChild];
        priorityQueue[rightChild] = priorityQueue[index];
        priorityQueue[index] = swapElem;
        minHeapDelete(rightChild);
    }
}

// template<typename T>
// void PriorityQueue<T>::minHeapDelete(size_t index){
    
//         size_t leftChild = 2 * index + 1; //Find index for the left child of the parent index
//         size_t rightChild = 2 * index + 2; //Find index for the right child of the parent index
//         if (leftChild < Index and rightChild < Index ) //If the left child is in range and is smaller than the parent then swap and check if the swapped index has a smaller value
//         {
//             if(priorityQueue[leftChild] < priorityQueue[rightChild])
//                 {
//                     if (priorityQueue[leftChild] < priorityQueue[index])
//                     {
//                     T swapElem{priorityQueue[leftChild]};
//                     priorityQueue[leftChild] = priorityQueue[index];
//                     priorityQueue[index] = swapElem;
//                     minHeapDelete(leftChild);
//                     }
//                 }
//             else
//             {
//                 if(priorityQueue[rightChild] < priorityQueue[index])
//                 {
//                 T swapElem{priorityQueue[rightChild]};
//                 priorityQueue[rightChild] = priorityQueue[index];
//                 priorityQueue[index] = swapElem;
//                 minHeapDelete(rightChild);
//                 }
//             }
//         }
//         else if (leftChild < Index)
//         {
//             if (priorityQueue[leftChild] < priorityQueue[index])
//             {
//                 T swapElem{priorityQueue[leftChild]};
//                 priorityQueue[leftChild] = priorityQueue[index];
//                 priorityQueue[index] = swapElem;
//                 minHeapDelete(leftChild);
//             }
//         }
//         else if (rightChild < Index)
//         {
//             if (priorityQueue[rightChild] < priorityQueue[index])
//             {
//                 T swapElem{priorityQueue[rightChild]};
//                 priorityQueue[rightChild] = priorityQueue[index];
//                 priorityQueue[index] = swapElem;
//                 minHeapDelete(rightChild);
//             }
//         }
// }

template <typename T>
void PriorityQueue<T>::popMin() {
    if (Index == 0)
    {
        throw std::runtime_error("ERROR");
    }
    else
    {
        priorityQueue[0] = priorityQueue[Index - 1];
        priorityQueue.pop_back(); //Delete the last entry
        Index--;
        minHeapDelete(0);
    }
    
}

}  // namespace shindler::ics46::project5

#endif
